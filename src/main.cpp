#include "../include/libraries.hpp"
using namespace std;

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
        cout << "Reading bytecodes..." << endl;

    string line, filename = cmd_args.filename;
    ifstream file(filename, ios::binary);

    u4 magic = read_u4(file);
    cout << "0x" << setfill('0') << setw(8) << uppercase << hex << magic;

    return 0;
}