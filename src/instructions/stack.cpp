#include "../../include/instructions/stack.hpp"

void pop(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void pop2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
}

void dup(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.operand_stack.top();
    
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void dup_x1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dup_x2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dup2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dup2_x1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dup2_x2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void swap(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}
