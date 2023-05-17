(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)
open Hh_prelude

module Candidate : sig
  (**
In `foo(param_a, param_b, param_c)`
                         ^
                         |
                        selection

  `positions` is the positions of each of the params
  `insertion_index` is 2 (in bounds by construction)
  `pos` is the span from the start of `param_a` to the end of `param_c`
 *)
  type t = private {
    positions: Pos.t list;
    insertion_index: int;
    pos: Pos.t;
  }

  val create_exn : positions:Pos.t list -> insertion_index:int -> t
end = struct
  type t = {
    positions: Pos.t list;
    insertion_index: int;
    pos: Pos.t;
  }

  let create_exn ~positions ~insertion_index =
    if insertion_index >= List.length positions then begin
      HackEventLogger.invariant_violation_bug
        ~data:
          (Printf.sprintf
             "insertion index: %d positions length: %d"
             insertion_index
             (List.length positions))
        "flip around comma: insertion index out of bounds";
      failwith "flip around comma: insertion index out of bounds"
    end else
      let pos =
        let first = List.hd_exn positions in
        let last = List.last_exn positions in
        Pos.merge first last
      in
      { insertion_index; positions; pos }
end

let source_slice ~source_text pos =
  let offset =
    let (first_line, first_col) = Pos.line_column pos in
    Full_fidelity_source_text.position_to_offset
      source_text
      (first_line, first_col + 1)
  in
  Full_fidelity_source_text.sub source_text offset (Pos.length pos)

let list_flip ~insertion_index l =
  let rec aux i = function
    | h1 :: h2 :: tail when i = insertion_index - 1 -> h2 :: h1 :: tail
    | h :: tail -> h :: aux (i + 1) tail
    | [] -> []
  in
  aux 0 l

let find_insertion_index ~(cursor : Pos.t) (positions : Pos.t list) : int option
    =
  let is_after_cursor pos = Pos.start_offset pos > Pos.start_offset cursor in
  let is_before_cursor pos = Pos.start_offset pos < Pos.start_offset cursor in
  if positions |> List.exists ~f:is_before_cursor then
    positions |> List.findi ~f:(fun _i -> is_after_cursor) |> Option.map ~f:fst
  else
    None

let find_candidate ~(cursor : Pos.t) (positions : Pos.t list) :
    Candidate.t option =
  find_insertion_index ~cursor positions
  |> Option.map ~f:(fun insertion_index ->
         Candidate.create_exn ~insertion_index ~positions)

let pos_of_expr = Tuple3.get2

let pos_of_shape_field_name =
  Ast_defs.(
    function
    | SFlit_int (pos, _) -> pos
    | SFlit_str (pos, _) -> pos
    | SFclass_const (_, (pos, _)) -> pos)

let pos_of_type_hint : 'a Aast_defs.type_hint -> Pos.t = function
  | (_, Some (pos, _)) -> pos
  | (_, None) -> Pos.none

let option_or_thunk opt ~f =
  match opt with
  | Some _ -> opt
  | None -> f ()

let visitor ~(cursor : Pos.t) =
  let find_in_positions = find_candidate ~cursor in
  let find_in_positions_params params =
    let is_easy_to_flip param =
      Aast_defs.(
        (not param.param_is_variadic)
        && Option.is_none param.param_readonly
        && Option.is_none param.param_visibility
        && (match param.param_callconv with
           | Ast_defs.Pnormal -> true
           | Ast_defs.Pinout _ -> false)
        && List.is_empty param.param_user_attributes)
    in
    let pos_of_expr_opt = function
      | Some (_, pos, _) -> pos
      | None -> Pos.none
    in
    if List.for_all params ~f:is_easy_to_flip then
      params
      |> List.map
           ~f:
             Aast_defs.(
               fun param ->
                 List.fold
                   ~init:param.param_pos
                   ~f:Pos.merge
                   [
                     pos_of_expr_opt param.param_expr;
                     pos_of_type_hint param.param_type_hint;
                   ])
      |> find_in_positions
    else
      None
  in
  object
    inherit [Candidate.t option] Tast_visitor.reduce as super

    method zero = None

    method plus = Option.first_some

    method! on_method_ env meth =
      if Pos.contains meth.Aast_defs.m_span cursor then
        option_or_thunk (super#on_method_ env meth) ~f:(fun () ->
            find_in_positions_params meth.Aast_defs.m_params)
      else
        None

    method! on_class_ env class_ =
      if Pos.contains class_.Aast_defs.c_span cursor then
        super#on_class_ env class_
      else
        None

    method! on_fun_ env fun_ =
      if Pos.contains fun_.Aast_defs.f_span cursor then
        option_or_thunk (super#on_fun_ env fun_) ~f:(fun () ->
            find_in_positions_params fun_.Aast_defs.f_params)
      else
        None

    method! on_expr_ env expr =
      option_or_thunk (super#on_expr_ env expr) ~f:(fun () ->
          match expr with
          | Aast_defs.Call (_, _, params, _) ->
            params
            |> List.map
                 ~f:
                   Ast_defs.(
                     function
                     | (Pinout inout_pos, expr) ->
                       Pos.merge inout_pos (pos_of_expr expr)
                     | (Pnormal, expr) -> pos_of_expr expr)
            |> find_in_positions
          | Aast_defs.ValCollection (_, _, exprs)
          | Aast_defs.List exprs
          | Aast_defs.Tuple exprs ->
            exprs |> List.map ~f:pos_of_expr |> find_in_positions
          | Aast_defs.KeyValCollection (_, _, fields) ->
            fields
            |> List.map ~f:(fun (e1, e2) ->
                   Pos.merge (pos_of_expr e1) (pos_of_expr e2))
            |> find_in_positions
          | Aast_defs.Shape fields ->
            fields
            |> List.map ~f:(fun (field_name, expr) ->
                   Pos.merge
                     (pos_of_shape_field_name field_name)
                     (pos_of_expr expr))
            |> find_in_positions
          | _ -> None)
  end

let edit_of_candidate
    ~path ~source_text Candidate.{ insertion_index; positions; pos } =
  let text =
    positions
    |> List.map ~f:(source_slice ~source_text)
    |> list_flip ~insertion_index
    |> String.concat ~sep:", "
  in
  let change =
    Lsp.
      {
        TextEdit.range =
          Lsp_helpers.hack_pos_to_lsp_range ~equal:Relative_path.equal pos;
        newText = text;
      }
  in
  let changes = SMap.singleton path [change] in
  Lsp.WorkspaceEdit.{ changes }

let command_or_action_of_candidate ~path ~source_text candidate =
  let action =
    Lsp.CodeAction.EditOnly (edit_of_candidate ~path ~source_text candidate)
  in
  let code_action =
    {
      Lsp.CodeAction.title = "Flip around comma";
      kind = Lsp.CodeActionKind.refactor;
      diagnostics = [];
      action;
    }
  in
  Lsp.CodeAction.Action code_action

let find ~(range : Lsp.range) ~path ~entry ctx =
  let is_selection =
    Lsp.(
      range.start.line < range.end_.line
      || range.start.line = range.end_.line
         && range.start.character < range.end_.character)
  in
  if not is_selection then
    match entry.Provider_context.source_text with
    | Some source_text ->
      let line_to_offset line =
        Full_fidelity_source_text.position_to_offset source_text (line, 0)
      in
      let tast =
        (Tast_provider.compute_tast_and_errors_quarantined ~ctx ~entry)
          .Tast_provider.Compute_tast_and_errors.tast
      in
      let cursor =
        Lsp_helpers.lsp_range_to_pos
          ~line_to_offset
          entry.Provider_context.path
          range
      in
      (visitor ~cursor)#go ctx tast
      |> Option.map ~f:(command_or_action_of_candidate ~path ~source_text)
      |> Option.to_list
    | _ -> []
  else
    []
