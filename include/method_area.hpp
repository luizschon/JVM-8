#ifndef _METHOD_AREA_HPP
#define _METHOD_AREA_HPP

#include "class_file.hpp"

struct class_container {
    class_file &class_f;
    map<string, operand> class_fields;
};

struct method_area {
    map<string, operand> loaded_classes;
    map<string, operand> static_classes;
};

#endif // _METHOD_AREA_HPP