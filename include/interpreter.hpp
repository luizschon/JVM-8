#ifndef _INTERPRETER_HPP
#define _INTERPRETER_HPP

#include "class_file.hpp"
#include "constant_pool_info.hpp"
#include "frame.hpp"
#include "bytecode.hpp"
#include <map>

using namespace std;

class JVMInterpreter {
    u8 pc;
    struct method_area {
        struct class_info {
            stack_frame stack_f; // referencia para cp_info_vector, stack de op, vector de var locais
            class_file* class_f; // cp_info_vector de runtime, methods.code, fields, methods
        };
        map<string, class_info> string_class; // string = this_class
    };
    
public:
    void run();
};

// botar no frame ?
void execute_instr(class_file &class_f, bytestream &code);

#endif // _INTERPRETER_HPP