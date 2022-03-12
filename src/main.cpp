#include "../include/libraries.hpp"
#include <ios>
using namespace std;

// was only tested with u2 but should work with u1, u4, u8
unsigned int hex_to_int(unsigned int num) 
{
    return stoi(to_string(num), nullptr, 16);
}

typedef struct method_ref_info {
    u1 tag; 
    u2 class_idx;
    u2 name_and_type_idx;
} method_ref_info;

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) 
{
    CmdArgs cmd_args;
    cmd_args.init(argc, argv);

    if (cmd_args.read_bytecode)
        cout << setw(50) << left << "Reading bytecodes" << setfill('-') << endl;

    // open given file
    string line, filename = cmd_args.filename;
    ifstream file(filename, ios::binary);

    // reads class file fields
    u4 magic            = read_u4(file); // signature (0xCAFEBABE) 
    u2 minor_ver        = read_u2(file); // minor version
    u2 major_ver        = read_u2(file); // major version
    u2 const_pool_count = read_u2(file); // constant pool count

    cout << setw(50) << left << "Signature " << right << " 0x" << uppercase << hex << magic << endl;
    cout << setw(50) << left << "Minor version " << right << " " << hex_to_int(minor_ver) << endl;
    cout << setw(50) << left << "Major version " << right << " " << hex_to_int(major_ver) << endl;
    cout << setw(50) << left << "Constant Pool Count " << right << " " << hex_to_int(const_pool_count) << endl;

    return 0;
}