#ifndef _DUMP_CLASS_FILE_HPP
#define _DUMP_CLASS_FILE_HPP

#include "class_file.hpp"
#include "constant_pool_info.hpp"

#define CLASS 0
#define FIELD 1
#define METHOD 2

// Writes the values from class file in an output markdown file 
void print_all(class_file &class_f, string file_name);
void print_general_info(class_file &class_f, ofstream &outfile);
string get_utf8_content(CONSTANT_utf8_info&);

// Writes the values from the rest of the constant pool in the output file
string get_version(u2 major, u2 minor);
string get_access_flags(u2 access_flags, int type);
void print_pool(cp_info_vector&, ofstream&);
void print_attributes_vector(attr_info_vector&, cp_info_vector&, ofstream&);

// Writes remaining values from the rest of the class file in the output file
void print_interfaces(class_file &class_f, ofstream &outfile);
void print_fields(class_file &class_f, ofstream &outfile);
void print_methods(class_file &class_f, ofstream &outfile);
void print_class_attributes(class_file &class_f, ofstream &outfile);

#endif // _DUMP_CLASS_FILE