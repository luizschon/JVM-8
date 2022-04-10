#include "../../include/instructions/conversions.hpp"

void i2l(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void i2f(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void i2d(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void l2i(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.operand_stack.top();
    value._int = (u4) value._long;

    top_frame.operand_stack.pop();
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void l2f(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.operand_stack.top();
    value._float = (float) value._long;

    top_frame.operand_stack.pop();
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void l2d(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.operand_stack.top();
    value._double = (double) value._long;

    top_frame.operand_stack.pop();
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void f2i(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void f2l(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void f2d(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void d2i(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void d2l(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void d2f(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void i2b(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void i2c(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void i2s(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}
