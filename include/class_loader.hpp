#ifndef _CLASS_LOADER_HPP
#define _CLASS_LOADER_HPP

#include "class_file.hpp"

class ClassLoader {
private:
    class_file* class_f = nullptr;
    ifstream file;
    void get_metadata();
    void get_constant_pool();
    void get_class_data();
    void get_interfaces();
    void get_fields();
    void get_methods();
    void get_attributes();

public:
    void load(string&);
    inline class_file* get_class_file() { return this->class_f; }
    ~ClassLoader();
};

#endif // _CLASS_LOADER_HPP