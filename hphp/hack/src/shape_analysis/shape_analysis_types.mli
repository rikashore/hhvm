(*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude
module A = Ast_defs
module T = Typing_defs
module LMap = Local_id.Map
module KMap = Typing_continuations.Map
module HT = Hips_types

(** Useful extension to sets *)
module CommonSet (S : Caml.Set.S) : sig
  val unions_map : f:(S.elt -> S.t) -> S.t -> S.t
end

module Error : sig
  type t [@@deriving show]

  val mk : string -> t
end

(** A generic exception for all shape analysis specific failures *)
exception Shape_analysis_exn of Error.t

(** Container to collect potential dicts that can be addressed with the shape
    analysis. *)
type potential_targets = {
  expressions_to_modify: Pos.t list;
  hints_to_modify: Pos.t list;
}

type mode =
  | DumpConstraints  (** Dump constraints generated by analysing the program *)
  | DumpDerivedConstraints  (** Dump constraints deduced by the solver *)
  | SimplifyConstraints
      (** Partially solve key constraints within functions and methods and
          report back summaries about which `dict`s might be `shape`s and which
          functions/methods they depend on. *)
  | Codemod
      (** Same as simplify constraints, but outputs JSON that represents
          instructions to codemod source code. *)
  | SolveConstraints
      (** Globally solve the key constraints and report back `dict`s that can
          be `shape`s along with the `shape` keys *)
  | CloseConstraints
      (** Close and dump constraints generated by analysing the program *)

type options = {
  mode: mode;
      (** The mode of oepration. See the `mode` type documentation for distinct
          modes. *)
  verbosity: int;
      (** Controls how much debug information to output. 0 means no extra debug
          information. Particularly, tests use 0. *)
}

type entity_ =
  | Literal of Pos.t
  | Variable of int
  | Inter of HT.entity
[@@deriving eq, ord]

type entity = entity_ option

type shape_keys = T.locl_phase T.shape_field_type T.TShapeMap.t

type marker_kind =
  | Allocation  (** A dict allocation such as `dict[]` or `dict['a' => 42]` *)
  | Parameter
      (** A dict parameter to a function or method such as `function
          f(dict<string,int> $d): void {...}` *)
  | Return
      (** A dict return of a function or method such as `function
          f(): dict<string,int> {...}` *)
  | Debug
      (** A dict argument to a function or method such as `$d = dict[]; f($d)`
       *)
  | Constant  (** A dict constant such as `const dict<string, mixed> DICT` *)
[@@deriving ord, show]

module Codemod : sig
  type kind =
    | Allocation  (** Codemod `dict[...]` syntax to `shape(...)` syntax. *)
    | Hint
        (** Codemod to change the `dict<key,ty>` hint to `shape(...)` hint. *)
  [@@deriving show { with_path = false }]
end

(** When embedded in a constraint, it conveys the degree of certainty for that
    constraint. This is useful in determining if a field is optional. *)
type certainty =
  | Definite
  | Maybe
[@@deriving show]

(** Indicates whether the constraint provides information or requires it. *)
type variety =
  | Has
  | Needs
[@@deriving show]

type constraint_ =
  | Marks of marker_kind * Pos.t  (** Marks a point of interest *)
  | Static_key of variety * certainty * entity_ * T.TShapeMap.key * T.locl_ty
      (** Records a static field that is available along with the Hack type of
          that key *)
  | Has_dynamic_key of entity_
      (** Records that an entity is accessed with a dynamic key *)
  | Subsets of entity_ * entity_
      (** Records that the first keys of the first entity are all present in
          the second. *)

(** Interprocedural constraint: currently only `Arg((f, 0), p)`, which models
    a function call f(p, _, ...). *)
type inter_constraint_ = entity_ HT.inter_constraint_

type shape_result =
  | Shape_like_dict of Pos.t * marker_kind * shape_keys
      (** A dict that acts like a shape along with its keys, types the keys
          point to, and the keys are optional. The marker kind distinguishes
          for what we are reporting a result. *)
  | Dynamically_accessed_dict of entity_
      (** A dict that is accessed or used dynamically. This is important
          in inter-procedural setting where a locally static dict calls a
          function where the parameter is accessed dynamically. In that case,
          the original result on static access should be invalidated. *)

(** Local variable environment. Its values are `entity`, i.e., `entity_
    option`, so that we can avoid pattern matching in constraint extraction. *)
type lenv = entity LMap.t KMap.t

(** Dressing on top of constraints that are solely used to help debug constraints *)
type 'constraint_ decorated = {
  hack_pos: Pos.t;  (** Hack source code position that led to the constraint *)
  origin: int;
      (** The origin of the constraint from Shape_analysis_walker.ml *)
  constraint_: 'constraint_;  (** The constraint proper *)
}

module DecoratedConstraintSet : Caml.Set.S with type elt = constraint_ decorated

module DecoratedInterConstraintSet :
  Caml.Set.S with type elt = inter_constraint_ decorated

(** Tuple of sets of decorated intra- and inter-procedural constraints *)
type decorated_constraints =
  DecoratedConstraintSet.t * DecoratedInterConstraintSet.t

type env = {
  constraints: DecoratedConstraintSet.t;
      (** Append-only set of intra-procedural constraints *)
  inter_constraints: DecoratedInterConstraintSet.t;
      (** Append-only set of inter-procedural constraints *)
  lenv: lenv;  (** Local variable information *)
  return: entity;  (** Entity for the return of a callable *)
  tast_env: Tast_env.env;
      (** TAST env associated with the definition being analysed *)
  errors: Error.t list;
      (** An append only stash of errors. If this list is non-empty, the
          analysis was performed in a best effort fashion. *)
}

module PointsToSet : Caml.Set.S with type elt = entity_ * entity_

module EntityMap : Caml.Map.S with type key = entity_

module EntitySet : sig
  include Caml.Set.S with type elt = entity_

  val unions_map : f:(elt -> t) -> t -> t
end

module ConstraintSet : Caml.Set.S with type elt = constraint_

(** A shape result paired with how many analysis errors were encountered while
    obtaining that result. The error count is intended as a rough measure of
    confidence in the result. *)
type analysis_result = {
  result: shape_result;
  error_count: int;
}

(** Either an analysis result or an error. In either case, the event is paired
    with an identifier for its origin. *)
type log = {
  location: string;
  result: (analysis_result, Error.t) Either.t;
}

type any_constraint = (constraint_, inter_constraint_) HT.any_constraint_

val compare_any_constraint : any_constraint -> any_constraint -> int
