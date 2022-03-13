#pragma once
#include "../include/types_definition.hpp"
#include "../include/class_file.hpp"

attr_info::attr_info(ifstream &file) 
{
    attr_name_idx = read_u2(file);
    attr_length = read_u4(file);

    for (int i = 0; i < attr_length; i++) 
        info.push_back(read_u1(file));
}

field_info::field_info(ifstream &file) 
{
    access_flags = read_u2(file);
    name_idx = read_u2(file);
    descriptor_idx = read_u2(file);
    attr_count = read_u2(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}

method_info::method_info(ifstream &file) 
{
    access_flags = read_u2(file);
    name_idx = read_u2(file);
    descriptor_idx = read_u2(file);
    attr_count = read_u2(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}

class_file::~class_file() 
{
    delete_pool(constant_pool);
}

CONSTANT_class_info::CONSTANT_class_info(ifstream &file) 
{
    tag = CONSTANT_Class;
    name_idx = read_u2(file);
}

CONSTANT_fieldref_info::CONSTANT_fieldref_info(ifstream &file) 
{
    tag = CONSTANT_Fieldref;
    class_idx = read_u2(file);
    name_and_type_idx = read_u2(file);
}

CONSTANT_methodref_info::CONSTANT_methodref_info(ifstream &file) 
{
    tag = CONSTANT_Methodref;
    class_idx = read_u2(file);
    name_and_type_idx = read_u2(file);
}

CONSTANT_interface_methodref_info::CONSTANT_interface_methodref_info(ifstream &file) 
{
    tag = CONSTANT_InterfaceMethodref;
    class_idx = read_u2(file);
    name_and_type_idx = read_u2(file);
}

CONSTANT_name_and_type_info::CONSTANT_name_and_type_info(ifstream &file) 
{
    tag = CONSTANT_NameAndType;
    name_idx = read_u2(file);
    descriptor_idx = read_u2(file);
}

CONSTANT_utf8_info::CONSTANT_utf8_info(ifstream &file) 
{
    tag = CONSTANT_Utf8;
    length = read_u2(file);

    for (int i = 0; i < length; i++)
        bytes.push_back(read_u1(file));
}

CONSTANT_string_info::CONSTANT_string_info(ifstream &file) 
{
    tag = CONSTANT_String;
    str_idx = read_u2(file);
}

CONSTANT_integer_info::CONSTANT_integer_info(ifstream &file) 
{
    tag = CONSTANT_Integer;
    bytes = read_u4(file);
}

CONSTANT_float_info::CONSTANT_float_info(ifstream &file) 
{
    tag = CONSTANT_Float;
    bytes = read_u4(file);
}

CONSTANT_long_info::CONSTANT_long_info(ifstream &file) 
{
    tag = CONSTANT_Long;
    high_bytes = read_u4(file);
    low_bytes = read_u4(file);
}

CONSTANT_double_info::CONSTANT_double_info(ifstream &file) 
{
    tag = CONSTANT_Double;
    high_bytes = read_u4(file);
    low_bytes = read_u4(file);
}

CONSTANT_method_handle_info::CONSTANT_method_handle_info(ifstream &file) 
{
    tag = CONSTANT_MethodHandle;
    reference_kind = read_u1(file);
    reference_index = read_u2(file);
}

CONSTANT_method_type_info::CONSTANT_method_type_info(ifstream &file) 
{
    tag = CONSTANT_MethodType;
    descriptor_index = read_u2(file);
}

CONSTANT_invoke_dynamic_info::CONSTANT_invoke_dynamic_info(ifstream &file) 
{
    tag = CONSTANT_InvokeDynamic;
    bootstrap_method_attr_index = read_u2(file);
    name_and_type_index = read_u2(file);
}