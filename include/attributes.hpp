#ifndef _ATTRIBUTES_HPP
#define _ATTRIBUTES_HPP

#include "constant_pool_info.hpp"
#include "types_definition.hpp"
#include <fstream>
#include <memory>
// #include "stack_map_frame.hpp"

#define RANGE(x,y,n) ((n >= x && n <= y) ? n : -1)

typedef enum {
    ConstantValue, 
    Code,
    LineNumberTable,
    StackMapTable,
    Exception,
    BootstrapMethods,
    SourceFile,
    Unknown
} Attribute_Types;

class Attribute {
public:
    Attribute(ifstream &file, cp_info_vector &constant_pool);
    u2 attribute_name_index;
    u4 attribute_length;
    Attribute_Types tag;
    virtual ~Attribute() {}
};

typedef vector<shared_ptr<Attribute>> attr_info_vector;

// See p.95 - jvm8

struct exception_table_info {
    exception_table_info(ifstream&);
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

struct bootstrap_methods_info {
    bootstrap_methods_info(ifstream&);
    u2 bootstrap_method_ref;
    u2 num_bootstrap_arguments;
    vector<u2> bootstrap_arguments;
};

struct ConstantValue_attribute {
    ConstantValue_attribute(ifstream&, cp_info_vector&);
    u2 constantvalue_index;
    void dump_to_file(cp_info_vector&, ofstream&);
};

struct Code_attribute {
    Code_attribute(ifstream&, cp_info_vector&);
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    vector<u1> code;
    u2 exception_table_length;
    vector<exception_table_info> exception_table;
    u2 attributes_count;
    attr_info_vector attributes;
    void dump_to_file(cp_info_vector&, ofstream&);
};

struct LineNumberTable_attribute {
    LineNumberTable_attribute(ifstream&, cp_info_vector&);
    u2 attribute_name_index;
    u4 attribute_length;
    u2 line_number_table_length;
    struct line_num_table_item { 
        u2 start_pc;
        u2 line_number;
    };
    vector<line_num_table_item> line_number_table;
    void dump_to_file(cp_info_vector&, ofstream&);
};

// struct StackMapTable_attribute {
//     u2 number_of_entries;
//     vector<stack_map_frame> entries;
// };

struct Exception_attribute {
    Exception_attribute(ifstream&, cp_info_vector&);
    u2 number_of_exceptions;
    vector<u2> exception_index_table;
    void dump_to_file(cp_info_vector&, ofstream&);
};

struct BootstrapMethods_attribute {
    BootstrapMethods_attribute(ifstream&, cp_info_vector&);
    u2 num_bootstrap_methods;
    vector<bootstrap_methods_info> bootstrap_methods;
    void dump_to_file(cp_info_vector&, ofstream&);
};

struct SourceFile_attribute {
    SourceFile_attribute(ifstream&, cp_info_vector&);
    u2 sourcefile_index;
    void dump_to_file(cp_info_vector&, ofstream&);
};

// gamer attribute - finish other attributes
struct Unknown_attribute {
    Unknown_attribute(ifstream&, u4);
    bytestream info;
};

class Attribute_Info : public Attribute {
public:
    Attribute_Info(ifstream&, cp_info_vector&);
    Attribute_Info(bytestream_it&, cp_info_vector&);
    ~Attribute_Info();

    union {
        ConstantValue_attribute* _constantvalue;
        Code_attribute* _code;
        LineNumberTable_attribute* _linenumbertable;
        // StackMapTable_attribute* _stackmaptable;
        Exception_attribute* _exception;
        BootstrapMethods_attribute* _bootstrapmethods;
        SourceFile_attribute* _sourcefile;
        Unknown_attribute* _unknown;
    };

    void dump_info_to_file(cp_info_vector&, ofstream&, unsigned int&);
};

#endif // _ATTRIBUTES_HPP