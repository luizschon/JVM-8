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
    void run(class_file&);
private:
    method_area load_class(class_file&);
    void load_class_variables(class_container&);
};


#endif // _INTERPRETER_HPP