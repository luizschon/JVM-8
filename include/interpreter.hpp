#ifndef _INTERPRETER_HPP
#define _INTERPRETER_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include "bytecode.hpp"

class JVMInterpreter {
    u8 pc;
    //method_area
    
public:
    void run()
};

/**
 * @brief execute the interpretation of .class file
 * 
 */
void execute(class_file &class_f, bytestream &code);

#endif // _INTERPRETER_HPP