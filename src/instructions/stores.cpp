#include "../../include/instructions/stores.hpp"
#include <iostream>

void astore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void astore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void astore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void astore_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void astore_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dstore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dstore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dstore_1;

    dstore_1._double = 1.0;

    top_frame.operand_stack.push(dstore_1);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dstore_1: " << dstore_1._double << endl;
}

void dstore_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dstore_2;

    dstore_2._double = 2.0;

    top_frame.operand_stack.push(dstore_2);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dstore_2: " << dstore_2._double << endl;
}

void dstore_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dstore_3;

    dstore_3._double = 3.0;

    top_frame.operand_stack.push(dstore_3);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dstore_3: " << dstore_3._double << endl;
}

void lstore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lstore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.operand_stack.top();

    top_frame.operand_stack.pop();
    top_frame.insert_into_local(1, value);
    top_frame.insert_into_local(2, value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[LSTORE_1] value: " << value._long << endl;
}

void lstore_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lstore_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void aastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void bastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void castore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void sastore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto index = code[++top_frame.pc];
    auto value = top_frame.operand_stack.top();

    while (top_frame.local_variables_array.size() < index + 1)
        top_frame.local_variables_array.push_back(operand_t());

    top_frame.operand_stack.pop();
    // top_frame.local_variables_array.insert(index, value);
    top_frame.local_variables_array[index] = value;
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void lstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto index = code[++top_frame.pc];
    auto value = top_frame.operand_stack.top();

    while (top_frame.local_variables_array.size() < index + 1)
        top_frame.local_variables_array.push_back(operand_t());

    top_frame.operand_stack.pop();
    top_frame.local_variables_array[index] = value;
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void dstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}