#ifndef _INTERPRETER_HPP
#define _INTERPRETER_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include "method_area.hpp"
#include <map>

using namespace std;

/**
 * @brief The JVM interpreter that runs a given class
 */
class JVMInterpreter {
public:
    void run(class_file*);
private:
    method_area load_classes(class_file*);
    method_info get_main_method(method_area);
};

#endif // _INTERPRETER_HPP