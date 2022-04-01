#ifndef _CMD_ARGUMENTS_HPP
#define _CMD_ARGUMENTS_HPP

#include <iostream>

using namespace std;

/**
 * @brief Auxiliary class to read and format input file
 * 
 */
class CmdArgs 
{
private:
    void print_usage()
    {
        cerr << "ERRO DE USO" << endl;
    }

public:
    string filename = "";
    bool read_bytecode = false;

    void init(int argc, char** argv) {
        try
        {
            read_args(argc, argv);
        }
        catch (const invalid_argument& exp)
        {
            cerr << exp.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    void read_args(int argc, char** argv) 
    {
        string temp_str = "";

        if (argc <= 1) 
        {
            print_usage();
            throw runtime_error("Wrong number of arguments");
        }
        
        for (auto i = 1; i < argc - 1; i++) 
        {
            temp_str = static_cast<string>(argv[i]);

            if (temp_str.compare("-r") == 0 || temp_str.compare("--read-bytecode") == 0)
                read_bytecode = true;
        } 
        
        filename = static_cast<string>(argv[argc - 1]);
    }
};

#endif // _CMD_ARGUMENTS_HPP