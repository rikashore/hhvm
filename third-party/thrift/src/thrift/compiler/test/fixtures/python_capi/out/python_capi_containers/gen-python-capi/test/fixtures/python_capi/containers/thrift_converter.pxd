
#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#


cdef extern from "thrift/compiler/test/fixtures/python_capi/gen-cpp2/containers_types.h":
    cdef cppclass cTemplateLists "::test::fixtures::python_capi::TemplateLists":
        cTemplateLists()
    cdef cppclass cTemplateSets "::test::fixtures::python_capi::TemplateSets":
        cTemplateSets()

cdef cTemplateLists TemplateLists_convert_to_cpp(object inst) except*
cdef object TemplateLists_from_cpp(const cTemplateLists& c_struct)

cdef cTemplateSets TemplateSets_convert_to_cpp(object inst) except*
cdef object TemplateSets_from_cpp(const cTemplateSets& c_struct)

