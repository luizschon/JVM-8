#ifndef _INTERPRETER_HPP
#define _INTERPRETER_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include "method_area.hpp"
#include <map>

using namespace std;

class JVMInterpreter {
    u8 pc;
    
public:
    void run(class_file*);
private:
    method_area methodArea;
    method_area load_class(class_file*);
    void load_class_variables(class_container&);
    operand_t* check_string_create_type(string);
    class_file load_parent_classes(string);
};

#endif // _INTERPRETER_HPP