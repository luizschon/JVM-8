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
    class_file* class_f = new class_file;
    auto file = open_file(argc, argv);

    get_metadata(*class_f, file);
    get_constant_pool(*class_f, file);
    get_class_data(*class_f, file);
    print_all(*class_f, argv[1]);
    
    delete class_f;

    return 0;
}