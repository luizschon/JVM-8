#ifndef _CONSTANT_POOL_INFO_HPP
#define _CONSTANT_POOL_INFO_HPP

#include <memory>
#include <type_traits>
#include <vector>
#include "types_definition.hpp"

using namespace std;

// Constant Pool Tags
typedef enum {
    CONSTANT_Utf8               =  1,
    CONSTANT_Integer            =  3,
    CONSTANT_Float              =  4,
    CONSTANT_Long               =  5,
    CONSTANT_Double             =  6,
    CONSTANT_Class              =  7,
    CONSTANT_String             =  8,
    CONSTANT_Fieldref           =  9,
    CONSTANT_Methodref          = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_NameAndType        = 12,
    CONSTANT_MethodHandle       = 15,
    CONSTANT_MethodType         = 16,
    CONSTANT_InvokeDynamic      = 18
} CONSTANT_Types;

struct CONSTANT_utf8_info {
    CONSTANT_utf8_info(ifstream &file);
    u1 tag; // 1
    u2 length;
    vector<u1> bytes;
};

struct CONSTANT_integer_info {
    CONSTANT_integer_info(ifstream &file);
    u1 tag; // 3
    u4 bytes;
};

struct CONSTANT_float_info {
    CONSTANT_float_info(ifstream &file);
    u1 tag; // 4
    u4 bytes;
};

struct CONSTANT_long_info {
    CONSTANT_long_info(ifstream &file);
    u1 tag; // 5
    u4 high_bytes;
    u4 low_bytes;
};

struct CONSTANT_double_info {
    CONSTANT_double_info(ifstream &file);
    u1 tag; // 6
    u4 high_bytes;
    u4 low_bytes;
};

struct CONSTANT_class_info {
    CONSTANT_class_info(ifstream &file);
    u1 tag; // 7
    u2 name_idx;
};

struct CONSTANT_string_info {
    CONSTANT_string_info(ifstream &file);
    u1 tag; // 8
    u2 str_idx;
};

struct CONSTANT_fieldref_info {
    CONSTANT_fieldref_info(ifstream &file);
    u1 tag; // 9
    u2 class_idx;
    u2 name_and_type_idx;
};

struct CONSTANT_methodref_info {
    CONSTANT_methodref_info(ifstream &file);
    u1 tag; // 10
    u2 class_idx;
    u2 name_and_type_idx;
};

struct CONSTANT_interface_methodref_info {
    CONSTANT_interface_methodref_info(ifstream &file);
    u1 tag; // 11
    u2 class_idx;
    u2 name_and_type_idx;
};

struct CONSTANT_name_and_type_info {
    CONSTANT_name_and_type_info(ifstream &file);
    u1 tag; // 12
    u2 name_idx;
    u2 descriptor_idx;
};

struct CONSTANT_method_handle_info {
    CONSTANT_method_handle_info(ifstream &file);
    u1 tag; // 15 
    u1 reference_kind;
    u2 reference_index;
};

struct CONSTANT_method_type_info {
    CONSTANT_method_type_info(ifstream &file);
    u1 tag; // 16
    u2 descriptor_index;
};

struct CONSTANT_invoke_dynamic_info {
    CONSTANT_invoke_dynamic_info(ifstream &file);
    u1 tag; // 18
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

class CP_Info {
public:
    CP_Info(u1 tag, ifstream &file);
    ~CP_Info();

    CONSTANT_Types tag;

    union {
        CONSTANT_utf8_info* _utf8;
        CONSTANT_integer_info* _integer;
        CONSTANT_float_info* _float;
        CONSTANT_long_info* _long;
        CONSTANT_double_info* _double;
        CONSTANT_class_info* _class;
        CONSTANT_string_info* _string;
        CONSTANT_fieldref_info* _fieldref;
        CONSTANT_methodref_info* _methodref;
        CONSTANT_interface_methodref_info* _interface_methodref;
        CONSTANT_name_and_type_info* _name_and_type;
        CONSTANT_method_handle_info* _method_handle;
        CONSTANT_method_type_info* _method_type;
        CONSTANT_invoke_dynamic_info* _invoke_dynamic;
    };
};

typedef vector<shared_ptr<CP_Info>> cp_info_vector;

#endif // _CONSTANT_POOL_INFO_HPP