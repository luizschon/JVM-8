#include "../../include/instructions/math.hpp"
#include <iostream>
#include <math.h>

void iadd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ladd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fadd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dadd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t byte;

    auto value1 = top_frame.operand_stack.top();
    top_frame.operand_stack.pop();

    auto value2 = top_frame.operand_stack.top();
    top_frame.operand_stack.pop();

    operand_t result;
    result._double = value1._double + value2._double;

    top_frame.operand_stack.push(result);

    top_frame.pc++;
    stack_f->pop();
    stack_f->push(top_frame);
    
    cout << "[DADD] result: " << result._double << endl;
}


void isub(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lsub(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fsub(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dsub(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    double value1 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    double value2 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    operand_t result;
    result._double = value1 - value2;
    top_frame.operand_stack.push(result);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void imul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lmul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fmul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dmul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    double value1 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    double value2 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    operand_t result;
    result._double = value1 * value2;
    top_frame.operand_stack.push(result);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[DMUL] result: " << result._double << endl;
}

void idiv(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ldiv(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fdiv(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ddiv(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    top_frame.pc++;

    auto value1 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();
    auto value2 = top_frame.operand_stack.top()._double;

    operand_t result;
    result._double = value2 / value1;

    top_frame.operand_stack.push(result);

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[DDIV] value1: " << value1 << " value2: " << value2 << " result: " << result._double << endl;
}

void irem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lrem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void frem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void drem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    double value1 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    double value2 = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    operand_t result;
    result._double = fmod(value1, value2);
    top_frame.operand_stack.push(result);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[DREM] result: " << result._double << endl;
}

void ineg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lneg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fneg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dneg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    double value = top_frame.operand_stack.top()._double;
    top_frame.operand_stack.pop();

    operand_t result;
    result._double = -value;
    top_frame.operand_stack.push(result);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[DNEG] result: " << result._double << endl;
}

void ishl(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lshl(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ishr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lshr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iushr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lushr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iand(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void land(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ior(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lor(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ixor(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lxor(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iinc(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

