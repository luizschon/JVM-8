#include "../include/constant_pool_info.hpp"
#include "../include/class_file.hpp"

attr_info::attr_info(ifstream &file) 
{
    attr_name_idx = read_u2(file);
    attr_length = read_u4(file);

    for (int i = 0; i < attr_length; i++) 
        info.push_back(read_u1(file));
}

field_info::field_info(ifstream &file) 
{
    access_flags = read_u2(file);
    name_idx = read_u2(file);
    descriptor_idx = read_u2(file);
    attr_count = read_u2(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}

method_info::method_info(ifstream &file) 
{
    access_flags = read_u2(file);
    name_idx = read_u2(file);
    descriptor_idx = read_u2(file);
    attr_count = read_u2(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}