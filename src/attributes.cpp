#include "../include/attributes.hpp"
#include "../include/dump_class_file.hpp"
#include <iostream>

using namespace std;

Attribute::Attribute(ifstream &file, cp_info_vector &constant_pool)
{
    attribute_name_index = read_bytes<u2>(file);
    attribute_length = read_bytes<u4>(file);

    cout << "attr_name_idx: " << attribute_name_index << endl;
    cout << "attr_length: " << attribute_length << endl;

    string attribute_name = get_utf8_content(*(constant_pool[attribute_name_index - 1]->_utf8));
    cout << "attr_name: " << attribute_name << endl;

    if (attribute_name == "ConstantValue") {
        tag = ConstantValue;
    } else if (attribute_name == "Code" ) {
        tag = Code;
    } else if (attribute_name == "StackMapTable" ) {
        tag = StackMapTable;
    } else if (attribute_name == "Exception" ) {
        tag = Exception;
    } else if (attribute_name == "BootstrapMethods" ) {
        tag = BootstrapMethods;
    } else if (attribute_name == "SourceFile" ) {
        tag = SourceFile;
    } else {
        tag = Unknown;
        cout << "UNKNOWN ATTRIBUTE NAME IN ATTRIBUTES.CPP, SKIPPING" << endl;
    }
}

Attribute_Info::Attribute_Info(ifstream &file, cp_info_vector &constant_pool)
: Attribute(file, constant_pool)
{
    switch (tag)
    {
        case ConstantValue:
            _constantvalue = new ConstantValue_attribute(file, constant_pool);
            break;
        case Code:
            _code = new Code_attribute(file, constant_pool);
            break;
        case StackMapTable:
            // TODO StackMapTable
            break;
        case Exception:
            _exception = new Exception_attribute(file, constant_pool);
            break;
        case BootstrapMethods:
            _bootstrapmethods = new BootstrapMethods_attribute(file, constant_pool);
            break;
        case SourceFile:
            _sourcefile = new SourceFile_attribute(file, constant_pool);
            break;
        case Unknown:
            _unknown = new Unknown_attribute(file, attribute_length);
            break;
    }
}

Attribute_Info::~Attribute_Info()
{
    switch (tag)
    {
        case ConstantValue: delete _constantvalue; break;
        case Code: delete _code; break;
        case StackMapTable: /* delete _stackmaptable */; break;
        case Exception: delete _exception; break;
        case BootstrapMethods: delete _bootstrapmethods; break;
        case SourceFile: delete _sourcefile; break;
        case Unknown: delete _unknown; break;
    }
}

exception_table_info::exception_table_info(ifstream &file)
{
    start_pc = read_bytes<u2>(file);
    end_pc = read_bytes<u2>(file); 
    handler_pc = read_bytes<u2>(file);
    catch_type = read_bytes<u2>(file); 
}

bootstrap_methods_info::bootstrap_methods_info(ifstream &file)
{
    bootstrap_method_ref = read_bytes<u2>(file);
    num_bootstrap_arguments = read_bytes<u2>(file);

    for (int i = 0; i < num_bootstrap_arguments; i++)
        bootstrap_arguments.push_back(read_bytes<u2>(file));
}

ConstantValue_attribute::ConstantValue_attribute(ifstream &file, cp_info_vector& constant_pool) 
{
    constantvalue_index = read_bytes<u2>(file);
}

Code_attribute::Code_attribute(ifstream &file, cp_info_vector& constant_pool)
{
    max_stack = read_bytes<u2>(file);
    max_locals = read_bytes<u2>(file);
    code_length = read_bytes<u4>(file);

    for (int i = 1; i <= code_length; i++)
        code.push_back(read_bytes<u1>(file));

    exception_table_length = read_bytes<u2>(file);
    attributes_count = read_bytes<u2>(file);

    for (int i = 0; i < attributes_count; i++)
    {
        shared_ptr<Attribute> new_el(new Attribute_Info(file, constant_pool));
        attributes.push_back(new_el);
    }
}

Exception_attribute::Exception_attribute(ifstream &file, cp_info_vector& constant_pool)
{
    number_of_exceptions = read_bytes<u2>(file);
    
    for (int i = 1; i <= sizeof(u2); i++)
        exception_index_table.push_back(read_bytes<u2>(file));
}

BootstrapMethods_attribute::BootstrapMethods_attribute(ifstream &file, cp_info_vector& constant_pool) 
{
    num_bootstrap_methods = read_bytes<u2>(file);
    
    for (int i = 0; i < num_bootstrap_methods; i++)
       bootstrap_methods.push_back(bootstrap_methods_info(file)); 
}

SourceFile_attribute::SourceFile_attribute(ifstream &file, cp_info_vector& constant_pool)
{
    sourcefile_index = read_bytes<u2>(file);
    cout << "Constructor read this:" << sourcefile_index << endl;
}

Unknown_attribute::Unknown_attribute(ifstream &file, u4 length)
{
    for (int i = 0; i < length; i++)
        info.push_back(read_bytes<u1>(file));
}