#include "../include/attributes.hpp"
#include "../include/dump_class_file.hpp"
#include <algorithm>
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

void Attribute_Info::dump_info_to_file(cp_info_vector &constant_pool, ofstream &outfile, unsigned int &counter) 
{
    outfile << "### [" << counter++ << "] " << get_utf8_content(*(constant_pool[attribute_name_index - 1]->_utf8)) << endl;
    outfile << "- Generic info " << endl;
    outfile << "  - Attribute name index `" << attribute_name_index << "`";
    outfile << " `<" << get_utf8_content(*(constant_pool[attribute_name_index - 1]->_utf8)) << ">`" << endl;
    outfile << "  - Attribute length `" << attribute_length << "`" << endl << endl;

    outfile << "- Specific info" << endl;
    switch (tag) 
    {
        case ConstantValue: _constantvalue->dump_to_file(constant_pool, outfile); break;
        case Code: _code->dump_to_file(constant_pool, outfile); break;
        case StackMapTable: /* _stackmaptable->print(constant_pool); */ break;
        case Exception: _exception->dump_to_file(constant_pool, outfile); break;
        case BootstrapMethods: _bootstrapmethods->dump_to_file(constant_pool, outfile); break;
        case SourceFile: _sourcefile->dump_to_file(constant_pool, outfile); break;
        default: break;
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

void ConstantValue_attribute::dump_to_file(cp_info_vector &constant_pool, ofstream &outfile)
{
    outfile << "  - Constant value index `" << constantvalue_index << "`" << endl;
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

void Code_attribute::dump_to_file(cp_info_vector &constant_pool, ofstream &outfile)
{
    outfile << "  - Maximum stack size `" << max_stack << "`" << endl;
    outfile << "  - Maximum local variables `" << max_locals << "`" << endl;
    outfile << "  - Code length `" << code_length << "`" << endl;
    outfile << "  - BYTECODES" << endl;

    // const vector<string> damned = {"nop", "iconst_1", "iconst_2", "iconst_3", "iconst_4",
    // "iconst_m1"};

    // JVM ignores some instructions, discover why
    const vector<string> damned = {":)"};

    int pos = 0;
    for (auto byte : code)
    {
        pos++;
        for (auto& p : mnemonic)
            if (p.first == byte && !count(damned.begin(), damned.end(), p.second))
                outfile << "    - " << pos << " `" << p.second << "`" << endl;
    }

    // for (auto attr : attributes)
    // {
    //     cout << attr->attribute_name_index << endl;
    //     cout << attr->attribute_length << endl;
    //     cout << attr->tag << endl;
    // }
    
    cout << endl << endl;
}

Exception_attribute::Exception_attribute(ifstream &file, cp_info_vector& constant_pool)
{
    number_of_exceptions = read_bytes<u2>(file);
    
    for (int i = 1; i <= sizeof(u2); i++)
        exception_index_table.push_back(read_bytes<u2>(file));
}

void Exception_attribute::dump_to_file(cp_info_vector &constant_pool, ofstream &outfile)
{
    outfile << "  - Number of exceptions: " << number_of_exceptions << endl;
    outfile << "  - TODO: PRINTAR EXCEPTION_TABLE" << endl;
}

BootstrapMethods_attribute::BootstrapMethods_attribute(ifstream &file, cp_info_vector& constant_pool) 
{
    num_bootstrap_methods = read_bytes<u2>(file);
    
    for (int i = 0; i < num_bootstrap_methods; i++)
       bootstrap_methods.push_back(bootstrap_methods_info(file)); 
}

void BootstrapMethods_attribute::dump_to_file(cp_info_vector &constant_pool, ofstream &outfile)
{
    outfile << "  - Number of bootstrap methods: " << num_bootstrap_methods << endl;
    outfile << "  - TODO: PRINTAR EXCEPTION_TABLE" << endl;
}

SourceFile_attribute::SourceFile_attribute(ifstream &file, cp_info_vector& constant_pool)
{
    sourcefile_index = read_bytes<u2>(file);
}

void SourceFile_attribute::dump_to_file(cp_info_vector &constant_pool, ofstream &outfile)
{
    outfile << "  - Source file name index `" << sourcefile_index << "`";
    outfile << " `<" << get_utf8_content(*(constant_pool[sourcefile_index - 1]->_utf8)) << ">`" << endl;
}

Unknown_attribute::Unknown_attribute(ifstream &file, u4 length)
{
    for (int i = 0; i < length; i++)
        info.push_back(read_bytes<u1>(file));
}