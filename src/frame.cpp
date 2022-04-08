#include "../include/frame.hpp"
#include "../include/utils.hpp"
#include <iostream>

/**
 * @brief Construct a new frame t::frame t object
 * @param constant_pool the reference to the runtime constant pool
 */
frame_t::frame_t(cp_info_vector* constant_pool)
{
    run_time_constant_pool = constant_pool;
}

/// TODO: finish execute logic
/**
 * @brief Executes frame with given method 
 * @param method the method of the frame
 */
void frame_t::execute_frame(method_info method)
{
    for (auto attr : method.attr)
    {
        // cout << this->run_time_constant_pool[attr->attribute_name_index - 1] << endl;
    }
    // u1 opcode = method_code->code[pc]; // NOTE: method_code armazena os opcode
    // func[op_code](this);               // chama a funcao do respectivo indice opcode // seg fault aqui
}