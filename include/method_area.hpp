#ifndef _METHOD_AREA_HPP
#define _METHOD_AREA_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include <map>

typedef struct class_container {
    class_file class_f;
    map<u2, operand_t*> *class_fields;
} class_container;

typedef struct method_area {
    map<u2, class_container*> loaded_classes;
    map<u2, class_container*> static_classes;
} method_area;

#endif // _METHOD_AREA_HPP