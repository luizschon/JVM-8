#include "../../include/instructions/loads.hpp"
#include <iostream>

void aaload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto frame = stack_f->top();

    if (frame.operand_stack.empty())
    {
        cout << "NullPointerException" << endl;
        return;
    }
}

void aload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void aload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void aload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void aload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void aload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void baload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void caload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void daload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dload_0;

    dload_0._double = 0.0;

    top_frame.operand_stack.push(dload_0);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dload_0: " << dload_0._double << endl;
}

void dload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dload_1;

    dload_1._double = 1.0;

    top_frame.operand_stack.push(dload_1);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dload_1: " << dload_1._double << endl;
}

void dload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dload_2;

    dload_2._double = 2.0;

    top_frame.operand_stack.push(dload_2);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dload_2: " << dload_2._double << endl;
}

void dload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t dload_3;

    dload_3._double = 3.0;

    top_frame.operand_stack.push(dload_3);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "dload_3: " << dload_3._double << endl;
}

void faload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t index;

    index._byte = code[++top_frame.pc];

    top_frame.operand_stack.push(index);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "fload: " << index._byte << endl;
}

void fload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    operand_t index;
    // runtim
    // index._byte = code[++top_frame.pc];

    top_frame.operand_stack.push(index);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "fload_0: " << index._byte << endl;
}

void fload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iaload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto index = code[++top_frame.pc];
    auto value = top_frame.local_variables_array[index];

    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void iload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void laload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto value = top_frame.local_variables_array[1];
    
    top_frame.operand_stack.push(value);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void lload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void saload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}