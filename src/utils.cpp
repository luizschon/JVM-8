#include "../include/utils.hpp"
#include "../include/class_file.hpp"
#include "../include/dump_class_file.hpp"
#include <cmath>
#include <limits>
#include <sstream>

double calc_double(u4 high, u4 low)
{
    u8 bits = calc_long(high, low);
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
        u8 m = (e == 0) ? ((bits & 0xfffffffffffffL) << 1) : ((bits & 0xfffffffffffffL) | 0x10000000000000L);
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

long long calc_long(u4 high, u4 low)
{
    auto l = ((u8) high << 32) | low;
    return (long long) l;
}

ifstream open_file(string &filename)
{
    ifstream file(filename, ios::binary);
    return file;
}

string get_name(cp_info_vector &constant_pool, u2 idx)
{
    return to_cp_info(constant_pool[idx - 1])->_class->get_content(constant_pool);
}