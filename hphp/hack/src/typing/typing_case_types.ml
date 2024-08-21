(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Hh_prelude
open Typing_defs
open Typing_env_types
module Cls = Folded_class
module Env = Typing_env
module SN = Naming_special_names

let strip_ns id =
  id |> Utils.strip_ns |> Hh_autoimport.strip_HH_namespace_if_autoimport

(** Modelled after data types in HHVM. See hphp/runtime/base/datatype.h *)
module Tag = struct
  type ctx = env

  type class_kind =
    | Class
    | FinalClass
    | Interface
  [@@deriving eq]

  type t =
    | DictData
    | VecData
    | KeysetData
    | StringData
    | ResourceData
    | BoolData
    | IntData
    | FloatData
    | NullData
    | ObjectData
    | InstanceOf of {
        name: string;
        kind: class_kind;
      }
    | LabelData  (** Corresponds to EnumClassLabel *)
    | BuiltInData
        (** Catch all for data types that are built into the runtime but not
            exposed in the type system. Used primarily for soundly representing
            the mixed type *)
  [@@deriving eq]

  let describe = function
    | DictData -> "dicts"
    | VecData -> "vecs"
    | KeysetData -> "keysets"
    | StringData -> "strings"
    | ResourceData -> "resources"
    | BoolData -> "booleans"
    | IntData -> "ints"
    | FloatData -> "floats"
    | NullData -> "the value null"
    | ObjectData -> "objects"
    | InstanceOf { name; kind = FinalClass } ->
      Printf.sprintf "instances of the final class %s" @@ strip_ns name
    | InstanceOf { name; kind = Class } ->
      Printf.sprintf "instances of the class %s" @@ strip_ns name
    | InstanceOf { name; kind = Interface } ->
      Printf.sprintf "instances of the interface %s" @@ strip_ns name
    | LabelData -> "enum class labels"
    | BuiltInData -> "built-in values"

  let relation tag1 ~ctx:env tag2 =
    let open ApproxSet.Set_relation in
    if equal tag1 tag2 then
      Equal
    else
      match (tag1, tag2) with
      | (ObjectData, InstanceOf _) -> Superset
      | (InstanceOf _, ObjectData) -> Subset
      | ( InstanceOf { name = cls1; kind = kind1 },
          InstanceOf { name = cls2; kind = kind2 } ) ->
        let open Option.Let_syntax in
        let is_instance_of sub sup =
          let* cls = Decl_entry.to_option (Env.get_class env sub) in
          return @@ Cls.has_ancestor cls sup
        in

        Option.value ~default:Unknown
        @@ let* cls1_instance_of_cls2 = is_instance_of cls1 cls2 in
           if cls1_instance_of_cls2 then
             return Subset
           else
             let* cls2_instance_of_cls1 = is_instance_of cls2 cls1 in
             if cls2_instance_of_cls1 then
               return Superset
             else (
               match (kind1, kind2) with
               | (FinalClass, _)
               | (_, FinalClass) ->
                 return Disjoint
               | (Interface, _)
               | (_, Interface) ->
                 return Unknown
               | (Class, Class) -> return Disjoint
             )
      | _ -> Disjoint

  let all_nonnull_tags =
    [
      DictData;
      VecData;
      KeysetData;
      StringData;
      ResourceData;
      BoolData;
      IntData;
      FloatData;
      ObjectData;
      LabelData;
      BuiltInData;
    ]

  let all_tags = NullData :: all_nonnull_tags
end

(** Tracks the reason why a particular tag is assumed to be a part of the
    data type of a type. Tracking is optional, depending on if an origin
    type is provided or not.
*)
module DataTypeReason = struct
  (** More information about where a particular tag comes from.
    For example, for tag DictData, subreasons might be Shapes or NoSubreason *)
  type subreason =
    | NoSubreason
    | Shapes
    | Tuples
    | Functions
    | Nullable
    | Nums
    | Arraykeys
    | SpecialInterface of string
    | Cyclic

  type trail_kind =
    | VariantOfCaseType of string
    | GenericUpperbound of string
    | UpperboundOfNewType of string
    | UpperboundOfEnum of string
    | SealedInterface of string
    | Requirement of string
    | ExpansionOfTypeConstant of {
        root_ty: locl_ty;
        name: string;
      }

  type 'phase trail = {
    origin: 'phase ty;
        (** Type used to derive the tag that this DataTypeReason.t is attached to. *)
    instances: (trail_kind * Reason.t) list;
    expansions: Type_expansions.t;
  }

  type 'phase t = subreason * 'phase trail

  let append ~(trail : 'ph trail) ~(reason : Reason.t) (kind : trail_kind) :
      ('ph trail, _) result =
    match kind with
    | VariantOfCaseType name
    | GenericUpperbound name
    | UpperboundOfNewType name
    | UpperboundOfEnum name
    | SealedInterface name
    | Requirement name ->
      Type_expansions.add_and_check_cycles
        trail.expansions
        {
          Type_expansions.name = Type_expansions.Expandable.Type_alias name;
          use_pos = Reason.to_pos reason;
          def_pos = None;
        }
      |> Result.map ~f:(fun expansions ->
             {
               trail with
               instances = (kind, reason) :: trail.instances;
               expansions;
             })
      |> Result.map_error ~f:(fun _cycle -> trail)
    | ExpansionOfTypeConstant _ ->
      Ok { trail with instances = (kind, reason) :: trail.instances }

  let case_type ~trail reason name =
    append ~trail ~reason @@ VariantOfCaseType name

  let generic ~trail reason name =
    append ~trail ~reason @@ GenericUpperbound name

  let newtype ~trail reason name =
    append ~trail ~reason @@ UpperboundOfNewType name

  let enum ~trail reason name = append ~trail ~reason @@ UpperboundOfEnum name

  let type_constant ~trail reason root_ty name =
    append ~trail ~reason @@ ExpansionOfTypeConstant { root_ty; name }

  let sealed_interface ~trail reason name =
    append ~trail ~reason @@ SealedInterface name

  let requirement ~trail reason name = append ~trail ~reason @@ Requirement name

  let to_message
      env ~f ((subreason, { origin; instances = trail; expansions = _ }), tag) =
    let ty_str =
      Typing_print.full_strip_ns_decl ~verbose_fun:false env origin
    in
    let pos = Reason.to_pos (get_reason origin) in
    let prefix = f ty_str in
    let tag_str = Tag.describe tag in
    let subreason_str =
      match subreason with
      | NoSubreason -> ""
      | Shapes -> " because shapes are dicts at runtime"
      | Tuples -> " because tuples are vecs at runtime"
      | Functions -> " because a function could be any value at runtime"
      | Nullable -> " because it is a nullable type"
      | Nums -> " because nums are ints or floats"
      | Arraykeys -> " because arraykeys are ints or strings"
      | Cyclic -> " because it is a cyclic type"
      | SpecialInterface name ->
        Printf.sprintf
          " because `%s` is a special interface that includes non-object values"
        @@ strip_ns name
    in
    let msg = prefix ^ Markdown_lite.md_bold tag_str ^ subreason_str in

    let trail_kind_msg = function
      | VariantOfCaseType name ->
        Printf.sprintf "  via this variant of the case type `%s`"
        @@ strip_ns name
      | GenericUpperbound name ->
        Printf.sprintf "  via this constraint on the generic `%s`" @@ name
      | UpperboundOfNewType name ->
        Printf.sprintf "  via the constraint on the newtype `%s`"
        @@ strip_ns name
      | UpperboundOfEnum name ->
        Printf.sprintf "  via the constraint on the enum `%s`" @@ strip_ns name
      | SealedInterface name ->
        Printf.sprintf "  via the sealed interface `%s`" @@ strip_ns name
      | Requirement name ->
        Printf.sprintf "  via this requirement on `%s`" @@ strip_ns name
      | ExpansionOfTypeConstant { root_ty; name } ->
        let name =
          Printf.sprintf "%s::%s" (Typing_print.full_strip_ns env root_ty) name
        in
        Printf.sprintf "  via the expansion of the type constant `%s`" @@ name
    in
    let trail_result =
      List.fold trail ~init:[] ~f:(fun acc (kind, reason) ->
          Reason.to_string (trail_kind_msg kind) reason @ acc)
    in
    (pos, msg) :: trail_result

  let make subreason trail : 'phase t = (subreason, trail)

  let make_trail origin : 'phase trail =
    { origin; instances = []; expansions = Type_expansions.empty }
end

module DataType = struct
  module Set = struct
    include ApproxSet.Make (struct
      type ctx = Tag.ctx

      type 'phase t = 'phase DataTypeReason.t * Tag.t

      let relation (_, tag1) ~ctx (_, tag2) = Tag.relation tag1 ~ctx tag2
    end)

    let singleton ~reason tag = singleton (reason, tag)

    let of_list ~reason tags =
      List.map ~f:(fun tag -> (reason, tag)) tags |> of_list
  end

  type 'phase t = 'phase Set.t

  (** `mixed` should cover all possible data types.
      Update [Tag.all_tags] if additional tags are added to [Tag.t] *)
  let mixed ~reason = Set.of_list ~reason Tag.all_tags

  (** Check [trail] for a cycle. If [trail] is an [Error], then
    a cycle has been detected and this will produce an error and return
    the result of [default]. If not, it will just call [f env trail] *)
  let cycle_handler
      ~(env : env)
      ~(f : env -> 'ph DataTypeReason.trail -> 'res)
      ~(default : reason:'ph DataTypeReason.t -> 'res)
      ~(trail : ('ph DataTypeReason.trail, 'ph DataTypeReason.trail) result) : _
      =
    match trail with
    | Result.Ok trail -> f env trail
    | Result.Error trail -> default ~reason:DataTypeReason.(make Cyclic trail)

  let prim_to_datatypes ~trail (prim : Aast.tprim) : 'phase t =
    let open Tag in
    let open Aast in
    let reason = DataTypeReason.(make NoSubreason trail) in
    match prim with
    | Tint -> Set.singleton ~reason IntData
    | Tnull -> Set.singleton ~reason NullData
    | Tvoid -> Set.singleton ~reason NullData
    | Tbool -> Set.singleton ~reason BoolData
    | Tfloat -> Set.singleton ~reason FloatData
    | Tstring -> Set.singleton ~reason StringData
    | Tresource -> Set.singleton ~reason ResourceData
    | Tnum ->
      Set.of_list ~reason:DataTypeReason.(make Nums trail) [IntData; FloatData]
    | Tarraykey ->
      Set.of_list
        ~reason:DataTypeReason.(make Arraykeys trail)
        [IntData; StringData]
    | Tnoreturn -> Set.empty

  let fun_to_datatypes ~trail : 'phase t =
    mixed ~reason:DataTypeReason.(make Functions trail)

  let nonnull_to_datatypes ~trail : 'phase t =
    Set.of_list
      ~reason:DataTypeReason.(make NoSubreason trail)
      Tag.all_nonnull_tags

  let tuple_to_datatypes ~trail : 'phase t =
    Set.singleton ~reason:DataTypeReason.(make Tuples trail) Tag.VecData

  let shape_to_datatypes ~trail : 'phase t =
    Set.singleton ~reason:DataTypeReason.(make Shapes trail) Tag.DictData

  let label_to_datatypes ~trail : _ t =
    Set.singleton ~reason:DataTypeReason.(make NoSubreason trail) Tag.LabelData

  module Class : sig
    val to_datatypes :
      trail:'phase DataTypeReason.trail -> env -> string -> env * 'phase t
  end = struct
    (* Set of interfaces that contain non-object members *)
    let special_interfaces =
      SSet.of_list
        [
          SN.Classes.cStringish;
          SN.Classes.cXHPChild;
          SN.Collections.cTraversable;
          SN.Collections.cKeyedTraversable;
          SN.Collections.cContainer;
          SN.Collections.cKeyedContainer;
        ]

    (** The [special_interfaces] contain additional data type tags beside
     [ObjectData]. These special interfaces are handled in [Typing_subtype].
     To avoid duplicating the logic, we check if a certain tag should be included
     by doing a subtype test against the interface type. If the type
     corresponding to a tag is a subtype then it will be included in the list.
    *)
    let special_interface_to_datatypes env (interface : string) :
        env * Tag.t list =
      let open Tag in
      let open Typing_make_type in
      let r = Typing_reason.none in
      let tag_to_type =
        [
          (DictData, dict r (nothing r) (nothing r));
          (VecData, vec r (nothing r));
          (KeysetData, keyset r (nothing r));
          (StringData, string r);
          (ResourceData, resource r);
          (BoolData, bool r);
          (IntData, int r);
          (FloatData, float r);
          (NullData, null r);
        ]
      in
      let (env, interface_ty) =
        match interface with
        | name
          when String.equal name SN.Collections.cTraversable
               || String.equal name SN.Collections.cContainer ->
          let (env, targ) = Env.fresh_type env Pos.none in
          let ty = Typing_make_type.class_type Reason.none name [targ] in
          (env, ty)
        | name
          when String.equal name SN.Collections.cKeyedTraversable
               || String.equal name SN.Collections.cKeyedContainer ->
          let (env, targ1) = Env.fresh_type env Pos.none in
          let (env, targ2) = Env.fresh_type env Pos.none in
          let ty =
            Typing_make_type.class_type Reason.none name [targ1; targ2]
          in
          (env, ty)
        | name
          when String.equal name SN.Classes.cStringish
               || String.equal name SN.Classes.cXHPChild ->
          (env, Typing_make_type.class_type Reason.none name [])
        | name ->
          failwithf
            "Unexpected special interface `%s` when determining data types"
            name
            ()
      in
      let tags =
        List.fold
          tag_to_type
          ~init:[]
          ~f:
            begin
              fun acc (tag, tag_ty) ->
                if Typing_utils.can_sub_type env tag_ty interface_ty then
                  tag :: acc
                else
                  acc
            end
      in
      (env, tags)

    let special_interface_cache : Tag.t list String.Table.t =
      String.Table.create ()

    let rec to_datatypes
        ~(trail : 'phase DataTypeReason.trail) (env : env) (cls : string) :
        'phase t =
      let open Tag in
      let cycle_handler f = cycle_handler ~env ~f in
      let reason = DataTypeReason.(make NoSubreason trail) in
      match cls with
      | cls when String.equal cls SN.Collections.cDict ->
        Set.singleton ~reason DictData
      | cls when String.equal cls SN.Collections.cKeyset ->
        Set.singleton ~reason KeysetData
      | cls when String.equal cls SN.Collections.cVec ->
        Set.singleton ~reason VecData
      | cls when String.equal cls SN.Collections.cAnyArray ->
        Set.of_list ~reason [DictData; KeysetData; VecData]
      | name ->
        Env.get_class env name
        |> Decl_entry.map_or
             ~default:(Set.singleton ~reason ObjectData)
             ~f:(fun cls ->
               let open Ast_defs in
               match Cls.kind cls with
               | Cclass _ when Cls.final cls ->
                 Set.singleton ~reason @@ InstanceOf { name; kind = FinalClass }
               | Cclass _ ->
                 Set.singleton ~reason @@ InstanceOf { name; kind = Class }
               | Ctrait
               | Cinterface -> begin
                 let default ~reason =
                   if is_c_trait (Cls.kind cls) then
                     Set.singleton ~reason ObjectData
                   else
                     Set.singleton ~reason
                     @@ InstanceOf { name; kind = Interface }
                 in
                 match Cls.sealed_whitelist cls with
                 | None ->
                   let reqs = Cls.all_ancestor_reqs cls in
                   if List.is_empty reqs then
                     default ~reason
                   else
                     List.fold
                       ~init:(default ~reason)
                       ~f:(fun acc (_, required_ty) ->
                         match
                           Typing_utils.try_unwrap_class_type required_ty
                         with
                         | None -> acc
                         | Some (r, (_p, req_cls), _paraml) ->
                           let trail =
                             DataTypeReason.requirement
                               ~trail
                               (Reason.localize r)
                               name
                           in
                           cycle_handler ~trail ~default @@ fun env trail ->
                           Set.inter acc @@ to_datatypes ~trail env req_cls)
                       reqs
                 | Some whitelist ->
                   let trail =
                     DataTypeReason.sealed_interface
                       ~trail
                       (Reason.witness_from_decl (Cls.pos cls))
                       name
                   in
                   SSet.fold
                     (fun whitelist_cls acc ->
                       cycle_handler ~trail ~default @@ fun env trail ->
                       Set.union acc @@ to_datatypes ~trail env whitelist_cls)
                     whitelist
                     Set.empty
                   |> Set.inter (default ~reason)
               end
               | Cenum
               | Cenum_class _ ->
                 Set.singleton ~reason ObjectData)

    let to_datatypes ~trail (env : env) (cls : string) : env * 'phase t =
      if SSet.mem cls special_interfaces then
        let (env, tags) =
          match Hashtbl.find special_interface_cache cls with
          | Some tags -> (env, tags)
          | None ->
            let (env, tags) = special_interface_to_datatypes env cls in
            let (_ : [ `Duplicate | `Ok ]) =
              Hashtbl.add special_interface_cache ~key:cls ~data:tags
            in
            (env, tags)
        in
        let set1 =
          Set.of_list
            ~reason:DataTypeReason.(make (SpecialInterface cls) trail)
            tags
        in
        let set2 = to_datatypes ~trail env cls in
        (env, Set.union set1 set2)
      else
        (env, to_datatypes ~trail env cls)
  end

  let fromPredicate ~trail (env : env) (predicate : type_predicate) :
      env * 'phase t =
    let open Tag in
    let reason = DataTypeReason.(make NoSubreason trail) in
    let from_tag tag =
      match tag with
      | BoolTag -> (env, Set.singleton ~reason BoolData)
      | IntTag -> (env, Set.singleton ~reason IntData)
      | StringTag -> (env, Set.singleton ~reason StringData)
      | ArraykeyTag -> (env, Set.of_list ~reason [IntData; StringData])
      | FloatTag -> (env, Set.singleton ~reason FloatData)
      | NumTag -> (env, Set.of_list ~reason [IntData; FloatData])
      | ResourceTag -> (env, Set.singleton ~reason ResourceData)
      | NullTag -> (env, Set.singleton ~reason NullData)
      | ClassTag id -> Class.to_datatypes ~trail env id
    in
    match snd predicate with
    | IsTag tag -> from_tag tag
    | IsTupleOf _ -> (env, Set.singleton ~reason VecData)
    | IsShapeOf _ -> (env, Set.singleton ~reason DictData)

  let rec fromTy ~trail (env : env) (ty : locl_ty) : env * 'phase t =
    let (env, ty) = Env.expand_type env ty in
    let reason = DataTypeReason.(make NoSubreason trail) in
    let cycle_handler ty =
      cycle_handler
        ~default:(fun ~reason -> (env, mixed ~reason))
        ~f:(fun env trail -> fromTy ~trail env ty)
    in
    match get_node ty with
    | Tprim prim -> (env, prim_to_datatypes ~trail prim)
    | Tnonnull -> (env, nonnull_to_datatypes ~trail)
    | Tdynamic -> (env, mixed ~reason)
    | Tany _ -> (env, mixed ~reason)
    | Toption ty ->
      let (env, data_types) = fromTy ~trail env ty in
      let data_types =
        Set.union
          data_types
          (Set.singleton
             ~reason:DataTypeReason.(make Nullable trail)
             Tag.NullData)
      in
      (env, data_types)
    (* For now say it has the same tags as `nonnull`.
     * We should be able to be more precise, but need to
     * validate what are all the data types that are valid callables *)
    | Tfun _ -> (env, fun_to_datatypes ~trail)
    | Ttuple _ -> (env, tuple_to_datatypes ~trail)
    | Tshape _ -> (env, shape_to_datatypes ~trail)
    | Tlabel _ -> (env, label_to_datatypes ~trail)
    | Tvar _ -> (env, mixed ~reason)
    | Tgeneric (name, tyl) ->
      let upper_bounds =
        Env.get_upper_bounds env name tyl |> Typing_set.elements
      in
      let (env, sets) =
        List.fold_map
          ~init:env
          ~f:(fun env upper_bound_ty ->
            let trail =
              DataTypeReason.generic ~trail (get_reason upper_bound_ty) name
            in
            cycle_handler ~env ~trail upper_bound_ty)
          upper_bounds
      in
      let result_opt = List.reduce ~f:Set.inter sets in
      let res =
        Option.value_or_thunk result_opt ~default:(fun () -> mixed ~reason)
      in
      (env, res)
    | Tunion tyl ->
      List.fold tyl ~init:(env, Set.empty) ~f:(fun (env, acc) ty ->
          let (env, dty) = fromTy ~trail env ty in
          let dty = Set.union acc dty in
          (env, dty))
    | Tintersection tyl ->
      let (env, sets) =
        List.fold_map ~init:env ~f:(fun env ty -> fromTy ~trail env ty) tyl
      in
      let result_opt = List.reduce ~f:Set.inter sets in
      let res =
        Option.value_or_thunk result_opt ~default:(fun () -> mixed ~reason)
      in
      (env, res)
    | Tvec_or_dict _ -> (env, Set.of_list ~reason [Tag.VecData; Tag.DictData])
    | Taccess (root_ty, id) ->
      let ety_env = empty_expand_env in
      let ((env, _, _cycles), ty) =
        Typing_utils.expand_typeconst
          ety_env
          env
          root_ty
          id
          ~allow_abstract_tconst:true
      in
      let trail =
        DataTypeReason.type_constant ~trail (get_reason ty) root_ty (snd id)
      in
      cycle_handler ~env ~trail ty
    | Tdependent (_, ty) -> fromTy ~trail env ty
    | Tnewtype (name, _, as_ty)
      when String.equal name Naming_special_names.Classes.cSupportDyn ->
      fromTy ~trail env as_ty
    | Tnewtype (name, _, _)
      when String.equal name Naming_special_names.Classes.cEnumClassLabel ->
      (env, label_to_datatypes ~trail)
    | Tnewtype (name, ty_args, as_ty) -> begin
      (* A Tnewtype is either an opaque alias (defined with keyword `newtype`)
       * or a case type.
       * For opaque type aliases, we look at the upper bound, but for case types,
       * we expand. *)
      match Env.get_typedef env name with
      | Decl_entry.Found
          { td_type = variants; td_vis = Aast.CaseType; td_tparams; _ } ->
        (* Here we should expand the case type instead of looking at the upper bound.
         * If we do not expand, then we will over approximate the datatype.
         * Consider:
         *
         *  case type Type1 = bool | int;
         *  case type Type2 = Type1 | string;
         *
         * If we do not expand we will reject the definition of `Type2`
         * because we will believe the datatype for `Type1` contains `string`.
         * By expanding we can allow this definition. *)
        let localize env ty =
          Typing_utils.localize
            ~ety_env:
              (* The this_ty does not need to be set because case types cannot
               * appear within classes thus cannot use the this type.
               * If we ever change that this could need to be changed *)
              {
                empty_expand_env with
                substs = Decl_subst.make_locl td_tparams ty_args;
              }
            env
            ty
        in
        let tyl =
          match get_node variants with
          | Tunion tyl -> tyl
          | _ -> [variants]
        in
        List.fold tyl ~init:(env, Set.empty) ~f:(fun (env, acc) variant ->
            let ((env, _ty_err_opt), variant) = localize env variant in
            let trail =
              DataTypeReason.case_type ~trail (get_reason variant) name
            in
            let (env, dty) = cycle_handler ~env ~trail variant in
            let data_types = Set.union acc dty in
            (env, data_types))
      | _ ->
        let trail_f =
          if Env.is_enum env name || Env.is_enum_class env name then
            DataTypeReason.enum ~trail
          else
            DataTypeReason.newtype ~trail
        in
        let trail = trail_f (get_reason as_ty) name in
        cycle_handler ~env ~trail as_ty
    end
    | Tunapplied_alias _ ->
      Typing_defs.error_Tunapplied_alias_in_illegal_context ()
    | Tclass ((_, cls), _, _) -> Class.to_datatypes ~trail env cls
    | Tneg predicate ->
      let (env, right) = fromPredicate ~trail env predicate in
      (env, Set.diff (mixed ~reason) right)

  let fromHint env hint =
    let decl_ty = Decl_hint.hint env.decl_env hint in
    let ((env, _), ty) =
      Typing_utils.localize_no_subst env ~ignore_errors:true decl_ty
    in
    let trail = DataTypeReason.make_trail decl_ty in
    fromTy ~trail env ty

  let fromTy env ty : env * locl_phase t =
    let trail = DataTypeReason.make_trail ty in
    fromTy ~trail env ty
end

type runtime_data_type = decl_phase DataType.t

let data_type_from_hint = DataType.fromHint

let check_overlapping env ~pos ~name data_type1 data_type2 =
  let open DataType in
  match Set.disjoint env data_type1 data_type2 with
  | Set.Sat -> None
  | Set.Unsat { left; relation; right } ->
    let rec why
        (((_, { DataTypeReason.origin = ty1; _ }), tag1) as left)
        relation
        (((_, { DataTypeReason.origin = ty2; _ }), tag2) as right) =
      let primary_why ~f =
        DataTypeReason.to_message
          env
          left
          ~f:(Printf.sprintf "This is the type `%s`, which includes ")
        @ DataTypeReason.to_message env right ~f
      in
      let secondary_why ~f =
        let describe tag = Markdown_lite.md_bold @@ Tag.describe tag in
        let ty_str ty =
          Markdown_lite.md_codify
          @@ Typing_print.full_strip_ns_decl ~verbose_fun:false env ty
        in
        [
          ( Pos_or_decl.of_raw_pos pos,
            f (describe tag1) (describe tag2)
            ^ Printf.sprintf
                ", %s and %s cannot be in the same case type"
                (ty_str ty1)
                (ty_str ty2) );
        ]
      in
      let open ApproxSet.Set_relation in
      match relation with
      | Superset -> why right Subset left
      | Equal ->
        primary_why
          ~f:(Printf.sprintf "It overlaps with `%s`, which also includes ")
      | Subset ->
        primary_why ~f:(Printf.sprintf "It overlaps with `%s`, which includes ")
        @ secondary_why ~f:(Printf.sprintf "Because %s are also %s")
      | Unknown ->
        primary_why
          ~f:(Printf.sprintf "It may overlap with `%s`, which includes ")
        @ secondary_why
            ~f:
              (Printf.sprintf
                 "Because it is possible for values to be both %s and %s")
      (* Disjoint will only occur here if one of the types involved was a negated type.
         These types cannot appear inside case type declarations and thus should never
         hit this code path. If negated types every become denotable this code will
         need to change. *)
      | Disjoint ->
        let desc = "Reporting a case type is disjoint when it should not be" in
        let telemetry =
          Telemetry.(create () |> string_ ~key:"casetype name" ~value:name)
        in
        Errors.invariant_violation pos telemetry desc ~report_to_user:false;
        []
    in

    let err =
      Typing_error.Primary.CaseType.Overlapping_variant_types
        { pos; name; why = lazy (why left relation right) }
    in
    Some err

(** Given the variants of a case type (encoded as a locl_ty) and another locl_ty [intersecting_ty]
  produce a new locl_ty containing only the types in the variant that map to an intersecting
  data type. For example:
   Given

    [variants] = int | vec<int> | Vector<int>
    [intersecting_ty] = Container<string>

   This function will return the type `vec<int> | Vector<int>` because both `vec<int>` and
  `Vector<int>` overlap with the tag associated with `Container<string>`.

  Note that this function only considers the data type associated to each type and not
  the type itself. So even though `vec<int>` and `Container<string>` do not intersect at
  the type level, they do intersect when considering only the runtime data types. *)
let filter_variants_using_datatype env reason variants intersecting_ty =
  let (env, tags) = DataType.fromTy env intersecting_ty in
  let (env, vtags) = List.fold_map variants ~init:env ~f:DataType.fromTy in
  let tyl =
    List.filter_map
      ~f:(fun (variant, variant_tags) ->
        if DataType.Set.are_disjoint env variant_tags tags then
          None
        else
          Some variant)
      (List.zip_exn variants vtags)
  in
  Typing_utils.union_list env reason tyl

(** Look up case type via [name]. If the case type exist returns the list of
  variant types. If the case type doesn't exist, returns [None]. *)
let get_variant_tys env name ty_args :
    Typing_env_types.env * locl_ty list option =
  match Env.get_typedef env name with
  | Decl_entry.Found
      { td_type = variants; td_vis = Aast.CaseType; td_tparams; _ } ->
    let ((env, _ty_err_opt), variants) =
      Typing_utils.localize_disjoint_union
        ~ety_env:
          {
            empty_expand_env with
            substs =
              (if List.is_empty ty_args then
                SMap.empty
              else
                Decl_subst.make_locl td_tparams ty_args);
          }
        env
        variants
    in
    let tyl =
      match get_node variants with
      | Tunion tyl -> tyl
      | _ -> [variants]
    in
    (env, Some tyl)
  | _ -> (env, None)

module AtomicDataTypes = struct
  type t = unit DataType.t

  type atomic_ty =
    | Primitive of Aast.tprim
    | Function
    | Nonnull
    | Tuple
    | Shape
    | Label
    | Class of string

  let trail = DataTypeReason.make_trail (Typing_make_type.bool Reason.none)

  let function_ = DataType.fun_to_datatypes ~trail

  let nonnull = DataType.nonnull_to_datatypes ~trail

  let tuple = DataType.tuple_to_datatypes ~trail

  let shape = DataType.shape_to_datatypes ~trail

  let mixed = DataType.mixed ~reason:DataTypeReason.(make NoSubreason trail)

  let label = DataType.label_to_datatypes ~trail

  let of_ty env : atomic_ty -> env * _ DataType.t = function
    | Primitive prim -> (env, DataType.prim_to_datatypes ~trail prim)
    | Function -> (env, function_)
    | Nonnull -> (env, nonnull)
    | Tuple -> (env, tuple)
    | Shape -> (env, shape)
    | Label -> (env, label)
    | Class name -> DataType.Class.to_datatypes ~trail env name

  let of_tag env tag : env * _ DataType.t =
    match tag with
    | BoolTag -> of_ty env (Primitive Aast.Tbool)
    | IntTag -> of_ty env (Primitive Aast.Tint)
    | StringTag -> of_ty env (Primitive Aast.Tstring)
    | ArraykeyTag -> of_ty env (Primitive Aast.Tarraykey)
    | FloatTag -> of_ty env (Primitive Aast.Tfloat)
    | NumTag -> of_ty env (Primitive Aast.Tnum)
    | ResourceTag -> of_ty env (Primitive Aast.Tresource)
    | NullTag -> of_ty env (Primitive Aast.Tnull)
    | ClassTag id -> of_ty env (Class id)

  let complement dt = DataType.Set.diff mixed dt

  let are_disjoint env dt1 dt2 = DataType.Set.are_disjoint env dt1 dt2
end
