#include "../../include/instructions/constants.hpp"
#include "../../include/utils.hpp"
#include <iostream>

void aconst_null(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void bipush(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t byte;

    byte._byte = code[++top_frame.pc];

    top_frame.operand_stack.push(byte);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "bipush: " << byte._byte << endl;
}

void dconst_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dconst;

    dconst._double = 0.0;

    top_frame.operand_stack.push(dconst);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dconst_0: " << dconst._double << endl;
}

void dconst_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dconst;

    dconst._double = 1.0;

    top_frame.operand_stack.push(dconst);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dconst_1: " << dconst._double << endl;
}

void fconst_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t fconst_0;

    fconst_0._double = 0.0;

    top_frame.operand_stack.push(fconst_0);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "fconst_0: " << fconst_0._double << endl;
}

void fconst_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t fconst_1;

    fconst_1._double = 1.0;

    top_frame.operand_stack.push(fconst_1);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "fconst_1: " << fconst_1._double << endl;
}

void fconst_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t fconst_2;

    fconst_2._double = 2.0;

    top_frame.operand_stack.push(fconst_2);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "fconst_2: " << fconst_2._double << endl;
}

void iconst_m1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_4(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iconst_5(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lconst_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lconst_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ldc(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ldc_w(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ldc2_w(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    auto reference = to_cp_info(constant_pool[index - 1]);

    operand_t value;
    if (reference->tag == CONSTANT_Double)
        value._double = calc_double(reference->_double->high_bytes, reference->_double->low_bytes);
    if (reference->tag == CONSTANT_Long)
        value._long = calc_long(reference->_long->high_bytes, reference->_long->low_bytes);
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[LDC2_W] value: " << value._double << endl;
}

void nop(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    cout << "Mi nombre is nop" << endl;
    return;
}

void sipush(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}
