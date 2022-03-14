#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#include "class_file.hpp"
#include "constant_pool_info.hpp"

void print_all(class_file &class_f, string file_name);
void print_general_info(class_file &class_f, ofstream &outfile);

void print_pool(class_file &class_f, ofstream &outfile);
void print_utf8_pool(CONSTANT_utf8_info &info, ofstream &outfile);
void print_integer_pool(CONSTANT_integer_info &info, ofstream &outfile);
void print_float_pool(CONSTANT_float_info &info, ofstream &outfile);
void print_long_pool(CONSTANT_long_info &info, ofstream &outfile);
void print_double_pool(CONSTANT_double_info &info, ofstream &outfile);
void print_class_pool(CONSTANT_class_info &info, ofstream &outfile);
void print_string_pool(CONSTANT_string_info &info, ofstream &outfile);
void print_fieldref_pool(CONSTANT_fieldref_info &info, ofstream &outfile);
void print_methodref_pool(CONSTANT_methodref_info &info, ofstream &outfile);
void print_interface_methodref_pool(CONSTANT_interface_methodref_info &info, ofstream &outfile);
void print_name_and_type_pool(CONSTANT_name_and_type_info &info, ofstream &outfile);
void print_method_handle_pool(CONSTANT_method_handle_info &info, ofstream &outfile);
void print_method_type_pool(CONSTANT_method_type_info &info, ofstream &outfile);
void print_invoke_dynamic_pool(CONSTANT_invoke_dynamic_info &info, ofstream &outfile);

// class_file.cpp
void print_interfaces(class_file &class_f, ofstream &outfile);
void print_fields(class_file &class_f, ofstream &outfile);
void print_methods(class_file &class_f, ofstream &outfile);
void print_attributes(class_file &class_f, ofstream &outfile);

#endif // _DEBUG_HPP