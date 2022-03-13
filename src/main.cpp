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
    class_file* class_f = new class_file;
    auto file = open_file(argc, argv);
    get_metadata(*class_f, file);
    get_constant_pool(*class_f, file);
    get_class_data(*class_f, file);

    delete class_f;

    return 0;
}