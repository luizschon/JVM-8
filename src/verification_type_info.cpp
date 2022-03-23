#include "../include/class_file.hpp"
#include "../include/verification_type_info.hpp"

Top_variable_info::Top_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Integer_variable_info::Integer_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Float_variable_info::Float_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Double_variable_info::Double_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Long_variable_info::Long_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Null_variable_info::Null_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

UninitializedThis_variable_info::UninitializedThis_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)) {}

Object_variable_info::Object_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)), cpool_index(get_bytes<u2>(iterator)) {}

Uninitialized_variable_info::Uninitialized_variable_info(bytestream_it &iterator)
: tag(get_bytes<u1>(iterator)), offset(get_bytes<u2>(iterator))  {}

verification_type_info::verification_type_info(bytestream_it &iterator) 
{
    switch ((Variable_Types)(*iterator)) {
        case ITEM_Top:
            _top_var = Top_variable_info(iterator);
            break;
        case ITEM_Integer:
            _integer = Integer_variable_info(iterator);
            break;
        case ITEM_Float:
            _float = Float_variable_info(iterator);
            break;
        case ITEM_Double:
            _double = Double_variable_info(iterator);
            break;
        case ITEM_Long:
            _long = Long_variable_info(iterator);
            break;
        case ITEM_Null:
            _null = Null_variable_info(iterator);
            break;
        case ITEM_UninitializedThis:
            _uninitialized_this = UninitializedThis_variable_info(iterator);
            break;
        case ITEM_Object:
            _object = Object_variable_info(iterator);
            break;
        case ITEM_Uninitialized:
            _uninitialized_var = Uninitialized_variable_info(iterator);
            break;
        default:
            break;
    }
}