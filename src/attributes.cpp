#include "../include/attributes.hpp"

exception_table_info::exception_table_info(bytestream_it &iterator)
{
    start_pc = get_bytes<u2>(iterator);
    end_pc = get_bytes<u2>(iterator); 
    handler_pc = get_bytes<u2>(iterator);
    catch_type = get_bytes<u2>(iterator); 
}

bootstrap_methods_info::bootstrap_methods_info(bytestream_it &iterator)
{
    bootstrap_method_ref = get_bytes<u2>(iterator);
    num_bootstrap_arguments = get_bytes<u2>(iterator);

    for (int i = 0; i < num_bootstrap_arguments; i++)
        bootstrap_arguments.push_back(get_bytes<u2>(iterator));
}

ConstantValue_attribute::ConstantValue_attribute(attr_info &attr) 
: attribute_name_index(attr.attr_name_idx), attribute_length(attr.attr_length) 
{
    auto iterator = attr.info.begin();
    constantvalue_index = get_bytes<u2>(iterator);
}

Code_attribute::Code_attribute(attr_info &attr)
: attribute_name_index(attr.attr_name_idx), attribute_length(attr.attr_length)
{
    auto iterator = attr.info.begin();
    max_stack = get_bytes<u2>(iterator);
    max_locals = get_bytes<u2>(iterator);
    code_length = get_bytes<u4>(iterator);

    for (int i = 1; i <= code_length; i++)
        code.push_back(get_bytes<u1>(iterator));

    exception_table_length = get_bytes<u2>(iterator);
    attributes_count = get_bytes<u2>(iterator);

    for (int i = 0; i < attributes_count; i++)
        attributes.push_back(attr_info(iterator));
}

Exception_attribute::Exception_attribute(attr_info &attr)
: attribute_name_index(attr.attr_name_idx), attribute_length(attr.attr_length)
{
    auto iterator = attr.info.begin();
    number_of_exceptions = get_bytes<u2>(iterator);
    
    for (int i = 1; i <= sizeof(u2); i++)
        exception_index_table.push_back(get_bytes<u2>(iterator));
}

BootstrapMethods_attribute::BootstrapMethods_attribute(attr_info& attr) 
: attribute_name_index(attr.attr_name_idx), attribute_length(attr.attr_length)
{
    auto iterator = attr.info.begin();
    num_bootstrap_methods = get_bytes<u2>(iterator);
    
    for (int i = 0; i < num_bootstrap_methods; i++)
       bootstrap_methods.push_back(bootstrap_methods_info(iterator)); 
}

SourceFile_attribute::SourceFile_attribute(attr_info &attr)
: attribute_name_index(attr.attr_name_idx), attribute_length(attr.attr_length) {
    auto iterator = attr.info.begin();
    sourcefile_index = get_bytes<u2>(iterator);
}