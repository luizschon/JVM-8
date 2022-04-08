#ifndef _METHOD_AREA_HPP
#define _METHOD_AREA_HPP

#include "frame.hpp"
#include <map>

/**
 * @brief A class container with constant pool, method data, attributes and constructor code
 */
typedef struct class_container {
    // pool_constantes;
    cp_info_vector constant_pool;
    
    // atributos_metodos;
    // dados_dos_metodos;
    //! Maps the name of the methods to their info
    map<string, method_info> methods;

    // codigo_de_construtores;
} class_container;

/**
 * @brief A mapping of class name to its content 
 */
typedef map<string, class_container> method_area;

#endif // _METHOD_AREA_HPP