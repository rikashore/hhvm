(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)
(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude

type pos_id = Pos.t * string [@@deriving eq, show]

type package = {
  name: pos_id;
  uses: pos_id list;
  includes: pos_id list;
  soft_includes: pos_id list;
}
[@@deriving eq, show]

type package_relationship =
  | Unrelated
  | Includes
  | Soft_includes
  | Equal

module Info = struct
  type t = {
    glob_to_package: package SMap.t;
    existing_packages: package SMap.t;
  }
  [@@deriving show]

  let empty = { glob_to_package = SMap.empty; existing_packages = SMap.empty }

  let get_package_for_module (info : t) (md : string) : package option =
    let matching_pkgs =
      SMap.fold
        (fun glob pkg acc ->
          if Str.string_match (Str.regexp glob) md 0 then
            (glob, pkg) :: acc
          else
            acc)
        info.glob_to_package
        []
    in
    let sorted_pkgs =
      List.sort
        ~compare:(fun (md1, _) (md2, _) -> String.compare md1 md2)
        matching_pkgs
      |> List.rev
    in
    match sorted_pkgs with
    | [] -> None
    | (_, pkg) :: _ -> Some pkg

  let package_exists (info : t) (pkg : string) : bool =
    SMap.mem pkg info.existing_packages

  let get_package (info : t) (pkg : string) : package option =
    SMap.find_opt pkg info.existing_packages

  let from_packages (packages : package list) : t =
    List.fold packages ~init:empty ~f:(fun acc pkg ->
        let existing_packages =
          SMap.add (snd pkg.name) pkg acc.existing_packages
        in
        let acc = { acc with existing_packages } in
        List.fold pkg.uses ~init:acc ~f:(fun acc (_, glob) ->
            let glob_to_package = SMap.add glob pkg acc.glob_to_package in
            let acc = { acc with glob_to_package } in
            acc))
end

let get_package_pos pkg = fst pkg.name

let get_package_name pkg = snd pkg.name

let includes pkg1 pkg2 =
  List.exists
    ~f:(fun (_, name) -> String.equal name @@ get_package_name pkg2)
    pkg1.includes

let soft_includes pkg1 pkg2 =
  List.exists
    ~f:(fun (_, name) -> String.equal name @@ get_package_name pkg2)
    pkg1.soft_includes

let relationship pkg1 pkg2 =
  if equal_package pkg1 pkg2 then
    Equal
  else if includes pkg1 pkg2 then
    Includes
  else if soft_includes pkg1 pkg2 then
    Soft_includes
  else
    Unrelated
