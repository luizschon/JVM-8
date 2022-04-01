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

    // TODO: put in class loader logic -------------
    class_file* class_f = new class_file;
    auto file = open_file(opts.filename);

    get_metadata(*class_f, file);
    get_constant_pool(*class_f, file);
    get_class_data(*class_f, file);
    // ---------------------------------------------

    if (opts.read_bytecode)
        print_all(*class_f, argv[1]);
    else
        JVMInterpreter.run();
        execute(class_f, /* bytestream &code */);
        
    delete class_f;

    return 0;
}