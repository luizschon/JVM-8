#include "../include/bytecode.hpp"
#include "../include/dump_class_file.hpp"
#include <iostream>

using namespace std;
extern ofstream outfile;

void bipush_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 byte = code[++code_index];
    outfile << " " << (int)byte;
}

void iinc_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 index = code[++code_index];
    u1 _const = code[++code_index];

    outfile << " #" << (int)index << " <" << (int)_const << ">  ";
}

void iinc_wide_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 indexbyte1 = code[++code_index];
    u1 indexbyte2 = code[++code_index];
    u1 constbyte1 = code[++code_index];
    u1 constbyte2 = code[++code_index];
    u2 index = ((u2)indexbyte1 << 8) | indexbyte2;
    u2 _const = ((u2)constbyte1 << 8) | constbyte2;

    outfile << " #" << (int)index << " <" << (int)_const << ">  ";
}

void invoke_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    reference_debug(code_index, constant_pool, code);
    u1 count = code[++code_index];
    u1 zero = code[++code_index];
}

void jump_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 branchbyte1  = code[++code_index] ;
    u1 branchbyte2  = code[++code_index];
    u2 branchoffset = ((u2)branchbyte1 << 8) | branchbyte2;
    outfile << " " << branchoffset;
}

void jump_wide_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 branchbyte1  = code[++code_index]; 
    u1 branchbyte2  = code[++code_index];
    u1 branchbyte3  = code[++code_index];
    u1 branchbyte4  = code[++code_index];
    u4 branchoffset = ((u4)branchbyte1 << 24) | ((u4)branchbyte2 << 16) | ((u4)branchbyte3 << 8) | branchbyte4;
    outfile << " " << branchoffset;
}

void index_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 index = code[++code_index];
    outfile << " #" << (int)index;
}

void index_wide_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 indexbyte1 = code[++code_index];
    u1 indexbyte2 = code[++code_index];
    u2 index = ((u2)indexbyte1 << 8) | indexbyte2;

    outfile << " #" << (int)index;
}

void lookupswitch_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 padding = (++code_index) % 4;
    auto defaultbyte1 = code[padding + code_index++] << 24;
    auto defaultbyte2 = code[padding + code_index++] << 16;
    auto defaultbyte3 = code[padding + code_index++] << 8;
    auto defaultbyte4 = code[padding + code_index++];
    auto defaultbytes = defaultbyte1 | defaultbyte2 | defaultbyte3 | defaultbyte4;

    auto npairs1 = code[padding + code_index++] << 24;
    auto npairs2 = code[padding + code_index++] << 16;
    auto npairs3 = code[padding + code_index++] << 8;
    auto npairs4 = code[padding + code_index++];
    auto npairs  = npairs1 | npairs2 | npairs3 | npairs4;

    u4 howManyBytes = 1 + padding + 8;

    for (uint n = 0; (signed) n < (signed) npairs; n++)
    {
        auto matchbyte1 = code[code_index + howManyBytes++] << 24;
        auto matchbyte2 = code[code_index + howManyBytes++] << 16;
        auto matchbyte3 = code[code_index + howManyBytes++] << 8;
        auto matchbyte4 = code[code_index + howManyBytes++];
        auto matchbytes = matchbyte1 | matchbyte2 | matchbyte3 | matchbyte4; 
        
        auto offset1 = code[code_index + howManyBytes++] << 24;
        auto offset2 = code[code_index + howManyBytes++] << 16;
        auto offset3 = code[code_index + howManyBytes++] << 8;
        auto offset4 = code[code_index + howManyBytes++];
        auto offset = offset1 | offset2 | offset3 | offset4;

        outfile << matchbytes << ": " << code_index + offset << " ("<< offset << ")";
        howManyBytes += 8;
    }
    outfile << "default: " << code_index + defaultbytes << " ("<< defaultbytes<< ")";
    code_index += howManyBytes;
}

void multianewarray_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 indexbyte1 = code[++code_index];
    u1 indexbyte2 = code[++code_index];
    u1 dimensions = code[++code_index]; // operand stack
    u2 index = (indexbyte1 << 8) | indexbyte2;
    
    outfile << " #" << (int)index;
    auto reference = to_cp_info(constant_pool[index - 1]);
    outfile << " <" << reference->get_content(constant_pool) << ">  ";
}

void newarray_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 atype = code[++code_index];
    map<u1, string> types = {
        {4,  "T_BOOLEAN"},
        {5,  "T_CHAR"},
        {6,  "T_FLOAT"},
        {7,  "T_DOUBLE"},
        {8,  "T_BYTE"},
        {9,  "T_SHORT"},
        {10, "T_INT"}, 
        {11, "T_LONG"}
    };
    outfile << " " << types[atype];
}

void reference_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code) 
{
    u1 index = code[++code_index];

    outfile << " #" << (int)index;
    auto reference = to_cp_info(constant_pool[index - 1]);
    outfile << " <" << reference->get_content(constant_pool) << ">  ";
}

void reference_wide_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 indexbyte1 = code[++code_index];
    u1 indexbyte2 = code[++code_index];
    u2 index = ((u2)indexbyte1 << 8) | indexbyte2;

    outfile << " #" << index;
    auto reference = to_cp_info(constant_pool[index - 1]);
    outfile << " <" << reference->get_content(constant_pool) << ">  ";
}

void sipush_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u1 byte1 = code[++code_index];
    u1 byte2 = code[++code_index];
    u2 short_val = ((u1)byte1 << 8) | byte2; 
    outfile << " " << (int)short_val;
}

void tableswitch_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code)
{
    u4 padding = (++code_index) % 4;
    auto defaultbyte1 = code[padding + code_index++] << 24;
    auto defaultbyte2 = code[padding + code_index++] << 16;
    auto defaultbyte3 = code[padding + code_index++] << 8;
    auto defaultbyte4 = code[padding + code_index++];
    auto defaultbytes = defaultbyte1 | defaultbyte2 | defaultbyte3 | defaultbyte4;

    auto lowbytes1 = code[padding + code_index++] << 24;
    auto lowbytes2 = code[padding + code_index++] << 16;
    auto lowbytes3 = code[padding + code_index++] << 8;
    auto lowbytes4 = code[padding + code_index++];
    auto lowbytes  = lowbytes1 | lowbytes2 | lowbytes3 | lowbytes4;

    auto howManyBytes = 1 + padding + 12;

    auto offsets = defaultbytes - lowbytes + 1;

    for (auto n = 0; n < offsets; n++)
    {
        auto highbytes1 = code[howManyBytes + code_index++] << 24;
        auto highbytes2 = code[howManyBytes + code_index++] << 16;
        auto highbytes3 = code[howManyBytes + code_index++] << 8;
        auto highbytes4 = code[howManyBytes + code_index++];
        auto highbytes  = highbytes1 | highbytes2 | highbytes3 | highbytes4;
        
        outfile << lowbytes << ": " << code_index + highbytes << " (" << highbytes << ")" << endl;
        lowbytes++;
        howManyBytes += 4;
    }
}

void wide_debug(int &code_index, cp_info_vector &constant_pool, bytestream &code) 
{
    u1 bytecode   = code[++code_index];
    u1 indexbyte1 = code[++code_index];
    u1 indexbyte2 = code[++code_index];

    if (!mnemonic.count(bytecode))
    {
        cout << "Instrução não encontrada" << endl;
        return;
    }

    if (bytecode == 0x84) // iinc
        iinc_wide_debug(code_index, constant_pool, code);
    else if (bytecode == 0x19) // aload
        reference_wide_debug(code_index, constant_pool, code);
    else
        index_wide_debug(code_index, constant_pool, code);

    outfile << endl;
}