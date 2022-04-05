#include "../include/bytecode.hpp"
#include "../include/frame.hpp"
#include <iostream>

void aaload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &frames)
{
    auto frame = frames.pop();
    
    if (frame.operands.empty())
    {
        cout << "NullPointerException" << endl;
        return;
    }

    auto arrayref = frame.pop_op();
    auto index = frame.pop_op();
    
    if (arrayref >= frame.local_variable_array.size())
    {
        cout << "ArrayIndexOutOfBoundsException" << endl;
        return;
    }

    auto value = frame.local_variable_array[arrayref];
    frame.push_op(value);
    frames.push(frame);
}

void bipush(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    // s4 byte = code[++code_index];
    
    // frame_t frame;
    // if (stack_f.empty())
    // {
    //     frame.push_op(byte);
    //     stack_f.push(frame);
    // }
    // else
    // {
    //     frame = stack_f.pop(); 
    //     frame.push_op(byte);
    //     stack_f.push(frame);
    // }
}

void nop(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    return;
}

void aconst_null(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    
}

void iconst_m1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_4(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iconst_5(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lconst_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lconst_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fconst_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fconst_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fconst_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dconst_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dconst_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void sipush(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ldc(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ldc_w(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ldc2_w(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iload_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iload_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iload_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iload_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lload_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lload_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lload_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lload_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fload_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fload_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fload_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fload_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dload_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dload_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dload_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dload_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aload_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aload_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aload_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aload_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iaload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void laload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void faload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void daload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void baload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void caload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void saload(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void istore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lstore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fstore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dstore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void astore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void istore_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void istore_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void istore_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void istore_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lstore_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lstore_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lstore_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lstore_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fstore_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fstore_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fstore_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fstore_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dstore_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dstore_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dstore_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dstore_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void astore_0(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void astore_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void astore_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void astore_3(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void aastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void bastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void castore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void sastore(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void pop(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void pop2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup_x1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup_x2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup2_x1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dup2_x2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void swap(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iadd(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ladd(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fadd(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dadd(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void isub(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lsub(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fsub(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dsub(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void imul(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lmul(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fmul(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dmul(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void idiv(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ldiv(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fdiv(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ddiv(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void irem(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lrem(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void frem(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void drem(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ineg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lneg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fneg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dneg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ishl(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lshl(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ishr(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lshr(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iushr(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lushr(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iand(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void land(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ior(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lor(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ixor(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lxor(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iinc(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2l(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2f(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2d(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void l2i(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void l2f(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void l2d(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void f2i(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void f2l(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void f2d(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void d2i(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void d2l(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void d2f(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2b(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2c(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void i2s(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lcmp(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fcmpl(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void fcmpg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dcmpl(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dcmpg(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifeq(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifne(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void iflt(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifge(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifgt(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifle(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmpeq(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmpne(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmplt(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmpge(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmpgt(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_icmple(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_acmpeq(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void if_acmpne(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void _goto(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void jsr(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ret(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void tableswitch(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lookupswitch(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ireturn(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void lreturn(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void freturn(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void dreturn(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void areturn(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void _return(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void getstatic(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void putstatic(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void getfield(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void putfield(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void invokevirtual(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void invokespecial(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void invokestatic(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void invokeinterface(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void invokedynamic(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void _new(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void newarray(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void anewarray(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void arraylength(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void athrow(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void checkcast(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void instanceof(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void monitorenter(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void monitorexit(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void wide(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void multianewarray(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifnull(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void ifnonnull(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void goto_w(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

void jsr_w(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{

}

// reserved
void break_point(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    return;
}

void impdep_1(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    return;
}

void impdep_2(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &stack_f)
{
    return;
}
