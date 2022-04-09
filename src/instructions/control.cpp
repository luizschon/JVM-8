#include "../../include/instructions/control.hpp"

void _goto(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void jsr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ret(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void tableswitch(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lookupswitch(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ireturn(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lreturn(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void freturn(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dreturn(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void areturn(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void _return(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    stack_f->top().pc++;
    stack_f->pop();
}
