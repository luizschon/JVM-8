#include "../include/constant_pool_info.hpp"
#include "../include/class_file.hpp"

CONSTANT_class_info::CONSTANT_class_info(ifstream &file) 
{
    tag = CONSTANT_Class;
    name_idx = read_bytes<u2>(file);
}

CONSTANT_fieldref_info::CONSTANT_fieldref_info(ifstream &file) 
{
    tag = CONSTANT_Fieldref;
    class_idx = read_bytes<u2>(file);
    name_and_type_idx = read_bytes<u2>(file);
}

CONSTANT_methodref_info::CONSTANT_methodref_info(ifstream &file) 
{
    tag = CONSTANT_Methodref;
    class_idx = read_bytes<u2>(file);
    name_and_type_idx = read_bytes<u2>(file);
}

CONSTANT_interface_methodref_info::CONSTANT_interface_methodref_info(ifstream &file) 
{
    tag = CONSTANT_InterfaceMethodref;
    class_idx = read_bytes<u2>(file);
    name_and_type_idx = read_bytes<u2>(file);
}

CONSTANT_name_and_type_info::CONSTANT_name_and_type_info(ifstream &file) 
{
    tag = CONSTANT_NameAndType;
    name_idx = read_bytes<u2>(file);
    descriptor_idx = read_bytes<u2>(file);
}

CONSTANT_utf8_info::CONSTANT_utf8_info(ifstream &file) 
{
    tag = CONSTANT_Utf8;
    length = read_bytes<u2>(file);

    for (int i = 0; i < length; i++)
        bytes.push_back(read_bytes<u1>(file));
}

CONSTANT_string_info::CONSTANT_string_info(ifstream &file) 
{
    tag = CONSTANT_String;
    str_idx = read_bytes<u2>(file);
}

CONSTANT_integer_info::CONSTANT_integer_info(ifstream &file) 
{
    tag = CONSTANT_Integer;
    bytes = read_bytes<u4>(file);
}

CONSTANT_float_info::CONSTANT_float_info(ifstream &file) 
{
    tag = CONSTANT_Float;
    bytes = read_bytes<u4>(file);
}

CONSTANT_long_info::CONSTANT_long_info(ifstream &file) 
{
    tag = CONSTANT_Long;
    high_bytes = read_bytes<u4>(file);
    low_bytes = read_bytes<u4>(file);
}

CONSTANT_double_info::CONSTANT_double_info(ifstream &file) 
{
    tag = CONSTANT_Double;
    high_bytes = read_bytes<u4>(file);
    low_bytes = read_bytes<u4>(file);
}

CONSTANT_method_handle_info::CONSTANT_method_handle_info(ifstream &file) 
{
    tag = CONSTANT_MethodHandle;
    reference_kind = read_bytes<u1>(file);
    reference_index = read_bytes<u2>(file);
}

CONSTANT_method_type_info::CONSTANT_method_type_info(ifstream &file) 
{
    tag = CONSTANT_MethodType;
    descriptor_index = read_bytes<u2>(file);
}

CONSTANT_invoke_dynamic_info::CONSTANT_invoke_dynamic_info(ifstream &file) 
{
    tag = CONSTANT_InvokeDynamic;
    bootstrap_method_attr_index = read_bytes<u2>(file);
    name_and_type_index = read_bytes<u2>(file);
}

CP_Info::CP_Info(u1 tag) : tag((CONSTANT_Types)tag)
{
    if ((CONSTANT_Types)tag == CONSTANT_Empty)
        _empty = new CONSTANT_empty();
}

CP_Info::CP_Info(u1 tag, ifstream &file) : tag((CONSTANT_Types)tag) 
{
    switch ((CONSTANT_Types)tag) 
    {
        case CONSTANT_Utf8:
            _utf8 = new CONSTANT_utf8_info(file);
            break;
        case CONSTANT_Integer:
            _integer = new CONSTANT_integer_info(file);
            break;
        case CONSTANT_Float:
            _float = new CONSTANT_float_info(file);
            break;
        case CONSTANT_Long:
            _long = new CONSTANT_long_info(file);
            break;
        case CONSTANT_Double:
            _double = new CONSTANT_double_info(file);
            break;
        case CONSTANT_Class:
            _class = new CONSTANT_class_info(file);
            break;
        case CONSTANT_String:
            _string = new CONSTANT_string_info(file);
            break;
        case CONSTANT_Fieldref:
            _fieldref = new CONSTANT_fieldref_info(file);
            break;
        case CONSTANT_Methodref:
            _methodref = new CONSTANT_methodref_info(file);
            break;
        case CONSTANT_InterfaceMethodref:
            _interface_methodref = new CONSTANT_interface_methodref_info(file);
            break;
        case CONSTANT_NameAndType:
            _name_and_type = new CONSTANT_name_and_type_info(file);
            break;
        case CONSTANT_MethodHandle:
            _method_handle = new CONSTANT_method_handle_info(file);
            break;
        case CONSTANT_MethodType:
            _method_type = new CONSTANT_method_type_info(file);
            break;
        case CONSTANT_InvokeDynamic:
            _invoke_dynamic= new CONSTANT_invoke_dynamic_info(file);
            break; 
        default:
            break;
    }
}

CP_Info::~CP_Info() 
{
    switch ((CONSTANT_Types)tag) 
    {
        case CONSTANT_Utf8:
            delete _utf8;
            break;
        case CONSTANT_Integer:
            delete _integer;
            break;
        case CONSTANT_Float:
            delete _float;
            break;
        case CONSTANT_Long:
            delete _long;
            break;
        case CONSTANT_Double:
            delete _double;
            break;
        case CONSTANT_Class:
            delete _class;
            break;
        case CONSTANT_String:
            delete _string;
            break;
        case CONSTANT_Fieldref:
            delete _fieldref;
            break;
        case CONSTANT_Methodref:
            delete _methodref;
            break;
        case CONSTANT_InterfaceMethodref:
            delete _interface_methodref;
            break;
        case CONSTANT_NameAndType:
            delete _name_and_type;
            break;
        case CONSTANT_MethodHandle:
            delete _method_handle;
            break;
        case CONSTANT_MethodType:
            delete _method_type;
            break;
        case CONSTANT_InvokeDynamic:
            delete _invoke_dynamic;
            break;
        case CONSTANT_Empty:
            delete _empty;
            break;
    }
}