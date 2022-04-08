#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "class_file.hpp"
#include "types.hpp"
#include <stack>

/// A single local variable can hold a value of type boolean , byte , char , short , int ,
/// float , reference , or returnAddress . A pair of local variables can hold a value
/// of type long or double .

/// TODO: finish reference and returnAddress types
/// The type of a local variable can be boolean, byte, char, short, int,
/// float, long, double, reference or returnAddress
typedef struct local_variable_t {
    union {
        u1 _boolean;
        u1 _byte;
        u1 _char;
        u2 _short;
        u4 _int;
        u4 _float;
        // reference
        // returnAddress
        u8 _long;
        u8 _double;
    };
} local_variable_t;

typedef struct operand_t {
    union {
        u1 _boolean;
        u1 _byte;
        u1 _char;
        u2 _short;
        u4 _int;
        u4 _float;
        // reference
        // returnAddress
        u8 _long;
        u8 _double;
    };
} operand_t;

/**
 * @brief A frame with local variables array, operand stack and reference to run-time constant pool 
 */
typedef struct frame_t {
    frame_t(cp_info_vector* constant_pool);
    // array de variaveis locais
    vector<local_variable_t> local_variables_array = {};

    // pilha de operandos
    stack<operand_t> operand_stack = {};

    // jvms8 - p.16
    // referencia para o pool de constantes da classe do metodo corrente
    cp_info_vector* run_time_constant_pool;

    // executa o frame corrente dado o conteudo do metodo
    void execute_frame(method_info);
} frame_t;

#endif // _FRAME_HPP