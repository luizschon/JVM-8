#ifndef _METHOD_AREA_HPP
#define _METHOD_AREA_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include <map>

struct class_container {
    class_file &class_f;
    map<string, operand_t> class_fields;
};

struct method_area {
    map<string, operand_t> loaded_classes;
    map<string, operand_t> static_classes;
};

#endif // _METHOD_AREA_HPP