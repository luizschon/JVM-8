#include "../include/bytecode.hpp"
#include "../include/frame.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <string.h>
#include <math.h>

void aaload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto frame = stack_f->top();

    if (frame.operand_stack.empty())
    {
        cout << "NullPointerException" << endl;
        return;
    }
}

void aconst_null(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void athrow(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void baload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

void caload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void checkcast(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

void dup(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

/// TODO: finish getstatic
void getstatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    u1 indexbyte1 = code[++top_frame.pc];
    u1 indexbyte2 = code[++top_frame.pc];
    u2 index = ((u2)indexbyte1 << 8) | indexbyte2;

    auto reference = to_cp_info(constant_pool[index - 1]);
    string class_name = reference->get_content(constant_pool);

    cout << "[GETSTATIC] Class name: " << class_name << endl;

    top_frame.pc++;
    stack_f->pop();
    stack_f->push(top_frame);

    // se for a classe default do Java: System -> nao empilhar
    if (class_name == "java/lang/System")
        return;

    cout << "------ getstatic -------" << endl;
}

void goto_w(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void ifnull(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifnonnull(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void instanceof(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

void lload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lload_3(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void _return(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    stack_f->top().pc++;
    stack_f->pop();
}

void iaload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void laload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void faload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void daload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void saload(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void istore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dstore(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void invokevirtual(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    auto methodref = to_cp_info(constant_pool[index - 1]);

    string class_name = methodref->_methodref->get_class_name(constant_pool);
    string method_name = methodref->_methodref->get_method_name(constant_pool);
    string descriptor = methodref->_methodref->get_method_descriptor(constant_pool);

    // cout << "CLASS NAME: " << class_name << endl;
    // cout << "METHOD NAME: " << method_name << endl;
    // cout << "METHOD DESCRIPTOR: " << descriptor << endl;

    if (strstr(class_name.c_str(), "java/"))
    {
        if (class_name == "java/io/PrintStream" && (method_name == "println" || method_name == "print"))
        {
            if (descriptor != "()V")
            {
                if(method_name == "println")
                    cout << endl;
                cout << endl;
                // system.out.println("ARGS");
            }
        }
        // if(class_name == "java/lang/String" && method_name == "length")
        // {
            
        // }
    }
    top_frame.pc++;
    stack_f->pop();
    stack_f->push(top_frame);
}

void invokespecial(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void invokestatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void invokeinterface(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void invokedynamic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

void jsr(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lstore_0(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lstore_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void nop(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    cout << "Mi nombre is nop" << endl;
    return;
}

void pop(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void pop2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void swap(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iadd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ladd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fadd(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void imul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lmul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fmul(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void irem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void lrem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void frem(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

}

void l2f(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void l2d(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

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

void lcmp(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fcmpl(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void fcmpg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dcmpl(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void dcmpg(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifeq(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifne(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void iflt(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifge(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifgt(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void ifle(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmpeq(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmpne(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmplt(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmpge(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmpgt(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_icmple(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_acmpeq(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void if_acmpne(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void _goto(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

void putstatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void getfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void putfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void _new(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void newarray(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void anewarray(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void arraylength(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void multianewarray(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}


void monitorenter(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void monitorexit(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void wide(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}


void jsr_w(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void sipush(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

// reserved
void break_point(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    return;
}

void impdep_1(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    return;
}

void impdep_2(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    return;
}

