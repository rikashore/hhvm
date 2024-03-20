(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

(** A relative position specifier in a class. Can later be
evaluated to an actual position in a file. *)
type 'p pos =
  | Precomputed of 'p  (** Use the precomputed position. *)
  | Classish_end_of_body of string
      (** Position at the end of the class body. Will return a zero-length
          position just before the closing brace. *)
  | Classish_start_of_body of string
      (** Position at the start of the class body. Will return a zero-length
          position just after the opening brace. *)
  | Classish_closing_brace of string
      (** Position encompassing the full range of the closing brace of
          the class body. *)
[@@deriving eq, ord, show]

(** Positional information for a single class *)
type 'p classish_positions = {
  classish_start_of_body: 'p;
  classish_end_of_body: 'p;
  classish_closing_brace: 'p;
}

(** Positional information for a collection of classes *)
type 'p t = 'p classish_positions SMap.t
