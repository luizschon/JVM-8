#include "../include/bytecode.hpp"
#include "../include/frame.hpp"

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

void bipush(int &code_index, cp_info_vector &constant_pool, bytestream &code, stack_frame &frames)
{
    s4 byte = code[++code_index];
    
    frame_t frame;
    if (frames.empty())
    {
        frame.push_op(byte);
        frames.push(frame);
    }
    else
    {
        frame = frames.pop(); 
        frame.push_op(byte);
        frames.push(frame);
    }
}

void nop(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{
    return;
}

void aconst_null(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{
    
}

void iconst_m1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_4(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iconst_5(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lconst_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lconst_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fconst_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fconst_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fconst_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dconst_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dconst_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void sipush(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ldc(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ldc_w(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ldc2_w(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iload_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iload_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iload_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iload_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lload_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lload_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lload_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lload_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fload_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fload_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fload_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fload_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dload_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dload_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dload_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dload_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aload_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aload_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aload_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aload_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iaload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void laload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void faload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void daload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void baload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void caload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void saload(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void istore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lstore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fstore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dstore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void astore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void istore_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void istore_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void istore_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void istore_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lstore_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lstore_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lstore_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lstore_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fstore_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fstore_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fstore_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fstore_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dstore_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dstore_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dstore_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dstore_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void astore_0(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void astore_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void astore_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void astore_3(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void aastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void bastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void castore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void sastore(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void pop(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void pop2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup_x1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup_x2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup2_x1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dup2_x2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void swap(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iadd(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ladd(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fadd(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dadd(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void isub(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lsub(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fsub(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dsub(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void imul(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lmul(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fmul(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dmul(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void idiv(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ldiv(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fdiv(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ddiv(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void irem(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lrem(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void frem(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void drem(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ineg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lneg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fneg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dneg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ishl(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lshl(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ishr(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lshr(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iushr(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lushr(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iand(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void land(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ior(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lor(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ixor(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lxor(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iinc(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2l(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2f(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2d(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void l2i(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void l2f(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void l2d(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void f2i(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void f2l(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void f2d(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void d2i(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void d2l(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void d2f(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2b(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2c(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void i2s(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lcmp(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fcmpl(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void fcmpg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dcmpl(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dcmpg(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifeq(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifne(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void iflt(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifge(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifgt(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifle(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmpeq(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmpne(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmplt(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmpge(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmpgt(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_icmple(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_acmpeq(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void if_acmpne(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void _goto(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void jsr(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ret(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void tableswitch(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lookupswitch(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ireturn(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void lreturn(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void freturn(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void dreturn(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void areturn(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void _return(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void getstatic(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void putstatic(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void getfield(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void putfield(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void invokevirtual(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void invokespecial(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void invokestatic(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void invokeinterface(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void invokedynamic(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void _new(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void newarray(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void anewarray(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void arraylength(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void athrow(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void checkcast(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void instanceof(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void monitorenter(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void monitorexit(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void wide(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void multianewarray(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifnull(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void ifnonnull(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void goto_w(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

void jsr_w(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{

}

// reserved
void break_point(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{
    return;
}

void impdep_1(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{
    return;
}

void impdep_2(int &code_index, cp_info_vector &constant_pool , bytestream &code)
{
    return;
}
