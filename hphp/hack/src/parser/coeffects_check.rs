// Copyright (c) 2019, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use bitflags::bitflags;
use core_utils_rust as utils;
use naming_special_names_rust::{coeffects, coeffects::Ctx, members, user_attributes};
use oxidized::{
    aast,
    aast::Hint_,
    aast_defs::Hint,
    aast_visitor::{visit, AstParams, Node, Visitor},
    ast, ast_defs,
    pos::Pos,
};
use parser_core_types::{
    syntax_error,
    syntax_error::{Error as ErrorMsg, SyntaxError},
};

fn is_pure(ctxs: &Option<ast::Contexts>) -> bool {
    match ctxs {
        Some(c) => c.1.len() == 0,
        None => false,
    }
}

fn is_mutating_unop(unop: &ast_defs::Uop) -> bool {
    use ast_defs::Uop::*;
    match unop {
        Upincr | Uincr | Updecr | Udecr => true,
        _ => false,
    }
}

// This distinguishes between specified not-pure contexts and unspecified contexts (both of which are not pure).
// The latter is important because for e.g. lambdas without contexts, they should inherit from enclosing functions.
fn is_pure_with_inherited_val(c: &Context, ctxs: &Option<ast::Contexts>) -> bool {
    match ctxs {
        Some(_) => is_pure(ctxs),
        None => c.is_pure(),
    }
}

fn has_defaults_with_inherited_val(c: &Context, ctxs: &Option<ast::Contexts>) -> bool {
    match ctxs {
        Some(_) => has_defaults(ctxs),
        None => c.has_defaults(),
    }
}

fn has_defaults_implicitly(hints: &Vec<Hint>) -> bool {
    for hint in hints {
        let Hint(_, h) = hint;
        match &**h {
            Hint_::Happly(ast_defs::Id(_, id), _) => {
                let (_, name) = utils::split_ns_from_name(&id);
                match coeffects::ctx_str_to_enum(name) {
                    Some(c) => match c {
                        Ctx::Defaults => {
                            return true;
                        }
                        _ => {
                            continue;
                        }
                    },
                    None => {
                        return true;
                    }
                }
            }
            aast::Hint_::HfunContext(_) => {
                continue;
            }
            aast::Hint_::Haccess(Hint(_, hint), sids) => match &**hint {
                Hint_::Happly(ast_defs::Id(..), _) if !sids.is_empty() => {
                    continue;
                }
                Hint_::Hvar(_) if sids.len() == 1 => {
                    continue;
                }
                _ => {
                    return true;
                }
            },
            _ => {
                return true;
            }
        }
    }
    false
}

fn has_defaults(ctxs: &Option<ast::Contexts>) -> bool {
    match ctxs {
        None => true,
        Some(c) => {
            if c.1.is_empty() {
                false
            } else {
                has_defaults_implicitly(&c.1)
            }
        }
    }
}

fn is_constructor(s: &ast_defs::Id) -> bool {
    let ast_defs::Id(_, name) = s;
    return name == members::__CONSTRUCT;
}

fn has_ignore_coeffect_local_errors_attr(attrs: &Vec<aast::UserAttribute<(), ()>>) -> bool {
    for attr in attrs.iter() {
        let ast_defs::Id(_, name) = &attr.name;
        if user_attributes::ignore_coeffect_local_errors(name) {
            return true;
        }
    }
    false
}

bitflags! {
    pub struct ContextFlags: u8 {
        const IN_METHODISH = 1 << 0;
        const IS_PURE = 1 << 1;
        const IS_CONSTRUCTOR = 1 << 2;
        const IGNORE_COEFFECT_LOCAL_ERRORS = 1 << 3;
        const HAS_DEFAULTS = 1 << 4;
    }
}

struct Context {
    bitflags: ContextFlags,
}

impl Context {
    fn in_methodish(&self) -> bool {
        return self.bitflags.contains(ContextFlags::IN_METHODISH);
    }

    fn is_pure(&self) -> bool {
        return self.bitflags.contains(ContextFlags::IS_PURE);
    }

    fn is_constructor(&self) -> bool {
        return self.bitflags.contains(ContextFlags::IS_CONSTRUCTOR);
    }

    fn ignore_coeffect_local_errors(&self) -> bool {
        return self
            .bitflags
            .contains(ContextFlags::IGNORE_COEFFECT_LOCAL_ERRORS);
    }

    fn has_defaults(&self) -> bool {
        return self.bitflags.contains(ContextFlags::HAS_DEFAULTS);
    }

    fn set_in_methodish(&mut self, in_methodish: bool) {
        self.bitflags.set(ContextFlags::IN_METHODISH, in_methodish);
    }

    fn set_is_pure(&mut self, is_pure: bool) {
        self.bitflags.set(ContextFlags::IS_PURE, is_pure);
    }

    fn set_is_constructor(&mut self, is_constructor: bool) {
        self.bitflags
            .set(ContextFlags::IS_CONSTRUCTOR, is_constructor);
    }

    fn set_ignore_coeffect_local_errors(&mut self, ignore_coeffect_local_errors: bool) {
        self.bitflags.set(
            ContextFlags::IGNORE_COEFFECT_LOCAL_ERRORS,
            ignore_coeffect_local_errors,
        );
    }

    fn set_has_defaults(&mut self, has_defaults: bool) {
        self.bitflags.set(ContextFlags::HAS_DEFAULTS, has_defaults);
    }
}

struct Checker {
    errors: Vec<SyntaxError>,
}

impl Checker {
    fn new() -> Self {
        Self { errors: vec![] }
    }

    fn add_error(&mut self, pos: &Pos, msg: ErrorMsg) {
        let (start_offset, end_offset) = pos.info_raw();
        self.errors
            .push(SyntaxError::make(start_offset, end_offset, msg));
    }

    fn check_pure_fn_contexts(&mut self, c: &mut Context, e: &aast::Expr<(), ()>) {
        if !c.is_pure()
            || c.is_constructor()
            || c.ignore_coeffect_local_errors()
            || c.has_defaults()
        {
            return;
        }
        if let Some((bop, lhs, _)) = e.2.as_binop() {
            if let ast_defs::Bop::Eq(_) = bop {
                self.check_is_obj_property_write_expr(&e, &lhs);
            }
        }
        if let Some((unop, expr)) = e.2.as_unop() {
            if is_mutating_unop(&unop) {
                self.check_is_obj_property_write_expr(&e, &expr);
            }
        }
    }

    fn check_is_obj_property_write_expr(
        &mut self,
        top_level_expr: &aast::Expr<(), ()>,
        expr: &aast::Expr<(), ()>,
    ) {
        if let Some(_) = expr.2.as_obj_get() {
            self.add_error(
                &top_level_expr.1,
                syntax_error::write_props_without_capability,
            );
            return;
        } else if let Some((arr, _)) = expr.2.as_array_get() {
            self.check_is_obj_property_write_expr(top_level_expr, &arr);
        }
    }
}

impl<'ast> Visitor<'ast> for Checker {
    type P = AstParams<Context, ()>;

    fn object(&mut self) -> &mut dyn Visitor<'ast, P = Self::P> {
        self
    }

    fn visit_method_(&mut self, c: &mut Context, m: &aast::Method_<(), ()>) -> Result<(), ()> {
        c.set_in_methodish(true);
        c.set_is_pure(is_pure(&m.ctxs));
        c.set_is_constructor(is_constructor(&m.name));
        c.set_ignore_coeffect_local_errors(has_ignore_coeffect_local_errors_attr(
            &m.user_attributes,
        ));
        c.set_has_defaults(has_defaults(&m.ctxs));
        m.recurse(
            &mut Context {
                bitflags: c.bitflags,
            },
            self,
        )
    }

    fn visit_fun_def(&mut self, c: &mut Context, d: &aast::FunDef<(), ()>) -> Result<(), ()> {
        c.set_is_pure(is_pure(&d.fun.ctxs));
        c.set_has_defaults(has_defaults(&d.fun.ctxs));
        c.set_is_constructor(is_constructor(&d.fun.name));
        d.recurse(
            &mut Context {
                bitflags: c.bitflags,
            },
            self,
        )
    }

    fn visit_fun_(&mut self, c: &mut Context, f: &aast::Fun_<(), ()>) -> Result<(), ()> {
        c.set_in_methodish(true);
        c.set_is_pure(is_pure_with_inherited_val(c, &f.ctxs));
        c.set_ignore_coeffect_local_errors(has_ignore_coeffect_local_errors_attr(
            &f.user_attributes,
        ));
        c.set_has_defaults(has_defaults_with_inherited_val(c, &f.ctxs));
        f.recurse(
            &mut Context {
                bitflags: c.bitflags,
            },
            self,
        )
    }

    fn visit_expr(&mut self, c: &mut Context, p: &aast::Expr<(), ()>) -> Result<(), ()> {
        if c.in_methodish() {
            self.check_pure_fn_contexts(c, &p);
        }
        p.recurse(c, self)
    }
}

pub fn check_program(program: &aast::Program<(), ()>) -> Vec<SyntaxError> {
    let mut checker = Checker::new();
    let bitflags = ContextFlags::from_bits_truncate(0 as u8);
    let mut context = Context { bitflags };
    visit(&mut checker, &mut context, program).unwrap();
    checker.errors
}
