#include "../include/libraries.hpp"

using namespace std;

/**
 * @brief Entry point of the JVM
 * 
 * @param argc number of args
 * @param argv vector of args
 * @return int 
 */
int main(int argc, char** argv) 
{
    CmdArgs opts;
    opts.init(argc, argv);

    ClassLoader loader;
    loader.load(opts.filename);

    if (opts.read_bytecode)
        print_all(*loader.get_class_file(), opts.filename);
    else
    {
        JVMInterpreter interpreter;
        // interpreter.run(*loader.get_class_file());
    }

    return 0;
}