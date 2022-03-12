#ifndef _IO_HPP
#define _IO_HPP

#include <fstream>
#include "types_definition.hpp"

using namespace std;

/**
 * Reads a byte from current position in a given file.
 * @param file a binary file 
 * @return one byte from file
 */
u1 read_u1(fstream &file);

/**
 * Reads two bytes from current position in a given file.
 * @param file a binary file
 * @return two bytes from file
 */
u2 read_u2(fstream &file);

/**
 * Reads four bytes from current position in a given file.
 * @param file a binary file
 * @return four bytes from file
 */
u4 read_u4(fstream &file);

/**
 * Reads eight bytes from current position in a given file.
 * @param file a binary file
 * @return eight bytes from file
 */
u8 read_u8(fstream &file);

#endif // _IO_HPP