#pragma once
#include "../include/class_file.hpp"
#include "../include/constant_pool_info.hpp"
#include "../include/cmd_arguments.hpp"
#include <iomanip>
#include <limits>
#include <math.h>
#include <memory>

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

field_info::field_info(ifstream &file) 
{
    access_flags = read_bytes<u2>(file);
    name_idx = read_bytes<u2>(file);
    descriptor_idx = read_bytes<u2>(file);
    attr_count = read_bytes<u2>(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}

method_info::method_info(ifstream &file) 
{
    access_flags = read_bytes<u2>(file);
    name_idx = read_bytes<u2>(file);
    descriptor_idx = read_bytes<u2>(file);
    attr_count = read_bytes<u2>(file);

    for (int i = 0; i < attr_count; i++)
        attr.push_back(attr_info(file));
}

double calc_double(u4 high, u4 low) 
{
    long bits = calc_long(high, low);
    if (bits == 0x7ff0000000000000L)
        return numeric_limits<double>::infinity();
    else if (bits == 0xfff0000000000000L)
        return -numeric_limits<double>::infinity();
    else if (bits >= 0x7ff0000000000001L && bits <= 0x7fffffffffffffffL)
        return numeric_limits<double>::quiet_NaN();
    else if (bits >= 0xfff0000000000001L && bits <= 0xffffffffffffffffL)
        return numeric_limits<double>::quiet_NaN();
    else
    {
        int s = ((bits >> 63) == 0) ? 1 : -1;
        int e = (bits >> 52) & 0x7ffL;
        long m = (e == 0) ? 
            (bits & 0xfffffffffffffL) << 1 : 
            (bits & 0xfffffffffffffL) | 0x10000000000000L;
        
        return s * m * pow(2, e - 1075);
    }
}

float calc_float(u4 bytes)
{
    if (bytes == 0x7f800000)
        return numeric_limits<float>::infinity();
    else if (bytes == 0xff800000)
        return -numeric_limits<float>::infinity();
    else if (bytes >= 0x7f800001 && bytes <= 0x7fffffff)
        return numeric_limits<float>::signaling_NaN();
    else if (bytes >= 0xff800001 && bytes <= 0xffffffff)
        return numeric_limits<float>::signaling_NaN();
    else
    {
        int s = ((bytes >> 31) == 0) ? 1 : -1;
        int e = ((bytes >> 23) & 0xff);
        int m = (e == 0) ? 
            (bytes & 0x7fffff) << 1 :
            (bytes & 0x7fffff) | 0x800000;

        return s * m * pow(2, e - 150);
    }
}

long calc_long(u4 high, u4 low)
{
    auto l = ((u8) high << 32) | low;
    return (long) l;
}

// finish docs
ifstream open_file(int argc, char** argv)
{
    CmdArgs cmd_args;
    cmd_args.init(argc, argv);

    // open given file and return
    string filename = cmd_args.filename;
    ifstream file(filename, ios::binary);
    return file;
}

void get_metadata(class_file &class_f, ifstream &file) 
{
    class_f.magic         = read_bytes<u4>(file); // signature (0xCAFEBABE) 
    class_f.minor_version = read_bytes<u2>(file);
    class_f.major_version = read_bytes<u2>(file);
}

void get_constant_pool(class_file &class_f, ifstream &file)
{
    class_f.constant_pool_count = read_bytes<u2>(file); 
    int iteration_counter = class_f.constant_pool_count - 1;
    while (iteration_counter--)
    {
        u1 tag = read_bytes<u1>(file);
        if ((CONSTANT_Types)tag == CONSTANT_Double || (CONSTANT_Types)tag == CONSTANT_Long)
            iteration_counter--;
        shared_ptr<CP_Info> new_el(new CP_Info(tag, file));
        class_f.constant_pool.push_back(new_el);
    }
}

void get_class_data(class_file &class_f, ifstream &file)
{
    class_f.access_flag = read_bytes<u2>(file);
    class_f.this_class  = read_bytes<u2>(file);
    class_f.super_class = read_bytes<u2>(file);
    
    get_interfaces(class_f, file);
    get_fields(class_f, file);
    get_methods(class_f, file);
    get_attributes(class_f, file);
}

void get_interfaces(class_file &class_f, ifstream &file)
{
    class_f.interfaces_count = read_bytes<u2>(file);
    
    for (int i = 0; i < class_f.interfaces_count; i++)
        class_f.interfaces.push_back(read_bytes<u2>(file));
}

void get_fields(class_file &class_f, ifstream &file)
{
    class_f.fields_count = read_bytes<u2>(file);

    for(int i = 0; i < class_f.fields_count; i++)
        class_f.fields.push_back(field_info(file));
}

void get_methods(class_file &class_f, ifstream &file)
{
    class_f.methods_count = read_bytes<u2>(file);

    for(int i = 0; i < class_f.methods_count; i++)
        class_f.methods.push_back(method_info(file));
}

void get_attributes(class_file &class_f, ifstream &file)
{
    class_f.attributes_count = read_bytes<u2>(file);

    for (int i = 0; i < class_f.attributes_count; i++)
        class_f.attributes.push_back(attr_info(file));
}