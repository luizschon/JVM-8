#ifndef _ATTRIBUTES_HPP
#define _ATTRIBUTES_HPP

#include "class_file.hpp"
#include "types_definition.hpp"
// #include "stack_map_frame.hpp"

#define RANGE(x,y,n) ((n >= x && n <= y) ? n : -1)

// See p.95 - jvm8

struct exception_table_info {
    exception_table_info(bytestream_it&);
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

struct bootstrap_methods_info {
    bootstrap_methods_info(bytestream_it&);
    u2 bootstrap_method_ref;
    u2 num_bootstrap_arguments;
    vector<u2> bootstrap_arguments;
};

struct ConstantValue_attribute {
    ConstantValue_attribute(attr_info&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
};

struct Code_attribute {
    Code_attribute(attr_info&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    vector<u1> code;
    u2 exception_table_length;
    vector<exception_table_info> exception_table;
    u2 attributes_count;
    vector<attr_info> attributes;
};

// struct StackMapTable_attribute {
//     u2 attribute_name_index;
//     u4 attribute_length;
//     u2 number_of_entries;
//     vector<stack_map_frame> entries;
// };

struct Exception_attribute {
    Exception_attribute(attr_info&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    vector<u2> exception_index_table;
};

struct BootstrapMethods_attribute {
    BootstrapMethods_attribute(attr_info&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 num_bootstrap_methods;
    vector<bootstrap_methods_info> bootstrap_methods;
};

struct SourceFile_attribute {
    SourceFile_attribute(attr_info&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 sourcefile_index;
};

#endif // _ATTRIBUTES_HPP