#ifndef _CLASS_FILE_HPP
#define _CLASS_FILE_HPP

#include <fstream>
#include "types_definition.hpp"

using namespace std;

/**
 * Reads a byte from current position in a given file.
 * @param file a binary file 
 * @return one byte from file
 */
u1 read_u1(ifstream &file);

/**
 * Reads two bytes from current position in a given file.
 * @param file a binary file
 * @return two bytes from file
 */
u2 read_u2(ifstream &file);

/**
 * Reads four bytes from current position in a given file.
 * @param file a binary file
 * @return four bytes from file
 */
u4 read_u4(ifstream &file);

/**
 * Reads eight bytes from current position in a given file.
 * @param file a binary file
 * @return eight bytes from file
 */
u8 read_u8(ifstream &file);

// finish docs
ifstream open_file(int argc, char** argv);

// finish docs
void get_metadata(class_file &class_f, ifstream &file);

// finish docs
void get_constant_pool(class_file &class_f, ifstream &file);

// finish docs
cp_info* create_pool(void* data);

// finish docs
void add_to_pool(cp_info* pool, void* data);

// finish docs
void delete_pool(cp_info* pool);

// finish docs
void get_class_data(class_file &class_f, ifstream &file);

// finish docs
void get_interfaces(class_file &class_f, ifstream &file);

// finish docs
void get_fields(class_file &class_f, ifstream &file);

// finish docs
void get_methods(class_file &class_f, ifstream &file);

// finish docs
void get_attributes(class_file &class_f, ifstream &file);

#endif // _CLASS_FILE_HPP