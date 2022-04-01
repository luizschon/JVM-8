#include "../include/class_file.hpp"
#include "../include/constant_pool_info.hpp"
#include "../include/attributes.hpp"
#include "../include/utils.hpp"

using namespace std;

attr_info::attr_info(ifstream &file) 
{
    attr_name_idx = read_bytes<u2>(file);
    attr_length = read_bytes<u4>(file);

    for (int i = 0; i < attr_length; i++) 
        info.push_back(read_bytes<u1>(file));
}

attr_info::attr_info(bytestream_it &iterator) 
{
    attr_name_idx = get_bytes<u2>(iterator);
    attr_length = get_bytes<u4>(iterator);
    for (int i = 0; i < attr_length; i++)
        info.push_back(get_bytes<u1>(iterator));
}

field_info::field_info(ifstream &file, cp_info_vector &constant_pool) 
{
    access_flags = read_bytes<u2>(file);
    name_idx = read_bytes<u2>(file);
    descriptor_idx = read_bytes<u2>(file);
    attr_count = read_bytes<u2>(file);

    for (int i = 0; i < attr_count; i++)
    {
        shared_ptr<Attribute> new_attr(new Attribute_Info(file, constant_pool));
        attr.push_back(new_attr);
    }
}

method_info::method_info(ifstream &file, cp_info_vector &constant_pool) 
{
    access_flags = read_bytes<u2>(file);
    name_idx = read_bytes<u2>(file);
    descriptor_idx = read_bytes<u2>(file);
    attr_count = read_bytes<u2>(file);

    for (int i = 0; i < attr_count; i++)
    {
        shared_ptr<Attribute> new_attr(new Attribute_Info(file, constant_pool));
        attr.push_back(new_attr);
    }
}
