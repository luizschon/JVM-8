#ifndef _DEBUG_HPP
#define _DEBUG_HPP

#include "class_file.hpp"

void print_all_pool(class_file &class_f);
void print_utf8_pool(class_file &class_f);
void print_integer_pool(class_file &class_f);
void print_float_pool(class_file &class_f);
void print_long_pool(class_file &class_f);
void print_double_pool(class_file &class_f);
void print_class_pool(class_file &class_f);
void print_string_pool(class_file &class_f);
void print_fieldrefpool(class_file &class_f);
void print_methodref_pool(class_file &class_f);
void print_interface_methodref_pool(class_file &class_f);
void print_name_and_type_pool(class_file &class_f);
void print_method_handle_pool(class_file &class_f);
void print_method_type_pool(class_file &class_f);
void print_invoke_dynamic(class_file &class_f);

#endif // _DEBUG_HPP