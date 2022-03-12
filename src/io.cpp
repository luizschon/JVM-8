#include "../include/io.hpp"

using namespace std;

u1 read_u1(ifstream &file) 
{
    u1 data = 0;
    file.read(reinterpret_cast<char *>(&data), 1);
    return data;
}

u2 read_u2(ifstream &file)
{
    u1 byte = 0;
    u2 data = 0;  
    for (int i = 0; i < sizeof(u2); i++)
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}

u4 read_u4 (ifstream &file)
{
    u1 byte = 0;
    u4 data = 0;
    for (int i = 0; i < sizeof(u4); i++) 
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}

u8 read_u8(ifstream &file) 
{
    u1 byte = 0;
    u8 data = 0;
    for (int i = 0; i < sizeof(u8); i++) 
    {
        file.read(reinterpret_cast<char *>(&byte), 1);
        data <<= 8;
        data |= byte;
    }
    return data;
}