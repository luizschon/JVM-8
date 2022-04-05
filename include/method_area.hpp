#ifndef _METHOD_AREA_HPP
#define _METHOD_AREA_HPP

#include "class_file.hpp"
#include "frame.hpp"
#include <map>

// Constant Pool 
#define CONSTANT_EMPTY   0
#define CONSTANT_FLOAT   4
#define CONSTANT_INT     3
#define CONSTANT_LONG    5
#define CONSTANT_DOUBLE  6
#define CONSTANT_CLASS   7
#define CONSTANT_STRING  8

// Primitives
#define CONSTANT_BOOL   90
#define CONSTANT_BYTE   91
#define CONSTANT_CHAR   92
#define CONSTANT_SHORT  93
#define CONSTANT_ARRAY  94

typedef struct class_container {
    class_container(class_file *class_f) : class_f(class_f) {}
    class_file* class_f;
    map<string, operand_t*> *class_fields;
    ~class_container() { delete class_f; delete class_fields; } // ver isso aqui depois
} class_container;

typedef struct method_area {
    map<string, class_container*> loaded_classes;
    map<string, class_container*> static_classes;
} method_area;

method_info* find_main(method_area* method_area);
void load_class_variables(class_container* class_container);
class_file load_parent_classes(string c_path);

#endif // _METHOD_AREA_HPP