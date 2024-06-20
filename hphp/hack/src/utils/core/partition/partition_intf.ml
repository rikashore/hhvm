(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

module type S = sig
  (* The set we are partitioning over. Sets are treated atomically,
     meaning we compute partitions without knowing the relationships
     between different sets in the partition. *)
  type set

  (** Abstract representation of a partition *)
  type t

  (** Operations on sets are represented in disjunctive normal form (DNF).
      This means it is a list of disjunctions (unions) that contain
      a list of conjunctions (intersections).

      (A & B) | C, where A, B, C are sets is represented as:
        [[A; B]; [C]]
      *)
  type dnf = set list list

  (* Smart Constructors for a partition*)

  (** A completely empty partition where both the left and right are empty *)
  val mk_bottom : t

  (** A partition where the set is assumed to be fully within the left side
     of the partition *)
  val mk_left : set -> t

  (** A partition where the set is assumed to be fully within the right side
     of the partition *)
  val mk_right : set -> t

  (** A partition that spans across the left and right partitions *)
  val mk_span : set -> t

  (** Unions two partitions together producing another partition *)
  val join : t -> t -> t

  (** Intersects two partitions together producing another partition *)
  val meet : t -> t -> t

  (** If the partition is fully within the left, span or right we can
     simplify the DNF to be [set], otherwise return [t] unchanged *)
  val simplify : t -> set -> t

  (* Accessors *)

  (** Returns the component of the partition that
      is definitely within the left side of the partition *)
  val left : t -> dnf

  (** Returns the component of the partition that is definitely
      spans across the left and right side of the partition *)
  val span : t -> dnf

  (** Returns the component of the partition that
      is definitely within the right side of the partition *)
  val right : t -> dnf

  (** Given a product function from sets to a set and a list of partitions,
      Returns a new partition that is the "product" of the given partitions
      such that:
      A set in the new partition is a set obtained by taking one set from each
      given partition and combining them using the given product function.
      There is a set in the new partition for every such combination.
      Combinations of sets only from the left side of the input partitions are
      on the left of the new partition.
      Combinations of sets containing at least one set from the right side of
      an input partition are on the right of the new partition.
      All other combinations of sets are in the span of the new partition. *)
  val product : (set list -> set) -> t list -> t

  module Infix_ops : sig
    val ( ||| ) : t -> t -> t

    val ( &&& ) : t -> t -> t
  end
end

module type Partition = sig
  (* Compute the cartesian product of lists *)
  val cartesian : 'a list list -> 'a list list

  module type S = S

  (* Constructs a partition representation over the given [AtomicSet] *)
  module Make (M : sig
    type t

    val compare : t -> t -> int
  end) : S with type set := M.t
end
