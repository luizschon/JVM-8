#ifndef _FRAME_HPP
#define _FRAME_HPP

#include "class_file.hpp"
#include "types.hpp"
#include <cstddef>
#include <stack>
#include <string>
#include <vector>

/// A single local variable can hold a value of type boolean , byte , char , short , int ,
/// float , reference , or returnAddress . A pair of local variables can hold a value
/// of type long or double .
struct operand_t;
struct reference;

/// The type of a local variable can be boolean, byte, char, short, int,
/// float, long, double, reference or returnAddress
typedef struct operand_t {
    union {
        u1 _boolean;
        u1 _byte;
        u1 _char;
        u2 _short;
        u4 _int;
        u4 _float;
        s8 _long;
        double _double;
        string* _string; // ver se esse tipo pode virar reference

        u4 *_return_address;
        reference *_reference; //parece que também é ponteiro
    };
} operand_t;

typedef struct reference {
    vector<operand_t> array;
} reference;

/**
 * @brief A frame with local variables array, operand stack and reference to run-time constant pool 
 */
typedef struct frame_t {
    frame_t(cp_info_vector* constant_pool);
    // array de variaveis locais
    vector<operand_t> local_variables_array = {};

    // pilha de operandos
    stack<operand_t> operand_stack = {};

    // jvms8 - p.16
    // referencia para o pool de constantes da classe do metodo corrente
    cp_info_vector* run_time_constant_pool;

    // executa o frame corrente dado o conteudo do metodo
    u4 pc = 0;
    void execute_frame(method_info, stack<frame_t>*);
    void insert_into_local(u4, operand_t&);
} frame_t;

#endif // _FRAME_HPP