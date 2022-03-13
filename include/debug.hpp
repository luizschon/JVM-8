#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#include "class_file.hpp"

void print_all(class_file &class_f);
void print_pool(class_file &class_f);
void print_utf8_pool(class_file &class_f);
void print_integer_pool(class_file &class_f);
void print_float_pool(class_file &class_f);
void print_long_pool(class_file &class_f);
void print_double_pool(class_file &class_f);
void print_class_pool(class_file &class_f);
void print_string_pool(class_file &class_f);
void print_fieldref_pool(class_file &class_f);
void print_methodref_pool(class_file &class_f);
void print_interface_methodref_pool(class_file &class_f);
void print_name_and_type_pool(class_file &class_f);
void print_method_handle_pool(class_file &class_f);
void print_method_type_pool(class_file &class_f);
void print_invoke_dynamic_pool(class_file &class_f);

// class_file.cpp
void print_class_data(class_file &class_f);
void print_interfaces(class_file &class_f);
void print_fields(class_file &class_f);
void print_methods(class_file &class_f);
void print_attributes(class_file &class_f);

#endif // _DEBUG_HPP