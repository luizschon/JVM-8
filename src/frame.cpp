#include "../include/frame.hpp"
#include "../include/utils.hpp"
#include "../include/bytecode.hpp"
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
void frame_t::execute_frame(method_info method, stack<frame_t> *stack_f)
{
    for (auto attr : method.attr)
    {
        auto attr_info = to_attr_info(attr);
        if (attr_info->tag == Code)
        {
            auto code = attr_info->_code->code;

            // for testing purposes
            while (pc < code.size())
            {
                auto bytecode = code[pc];
                if (bytecodes.count(bytecode))
                {
                    auto execute_bytecode = bytecodes.at(bytecode);
                    execute_bytecode(*run_time_constant_pool, code, stack_f); // change to pointer maybe
                }
                else
                {
                    ios_base::fmtflags f(cout.flags());
                    cout << "Bytecode nao encontrado: 0x" << hex << (u4) bytecode << endl;
                    cout.flags(f);
                }
                cout << "PC:" << pc << endl;
            }
        }
    }
}