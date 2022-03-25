#ifndef _BYTECODE_HPP
#define _BYTECODE_HPP

#include "types.hpp"
#include "constant_pool_info.hpp"
#include <functional>
#include <map>

typedef map<u1, function<void(int&, cp_info_vector&, bytestream&)>> bytecode_map;
typedef map<u1, string> mnemonic_map;

// Instructions implementation
void nop(int&, cp_info_vector&, bytestream&);
void aaload(int&, cp_info_vector&, bytestream&);
void aastore(int&, cp_info_vector&, bytestream&);
void aconst_null(int&, cp_info_vector&, bytestream&);
void aload_0(int&, cp_info_vector&, bytestream&);
void aload_1(int&, cp_info_vector&, bytestream&);
void aload_2(int&, cp_info_vector&, bytestream&);
void aload_3(int&, cp_info_vector&, bytestream&);
void idiv(int&, cp_info_vector&, bytestream&);
void irem(int&, cp_info_vector&, bytestream&);
void lrem(int&, cp_info_vector&, bytestream&);
void ineg(int&, cp_info_vector&, bytestream&);
void lneg(int&, cp_info_vector&, bytestream&);
void ishl(int&, cp_info_vector&, bytestream&);
void lshl(int&, cp_info_vector&, bytestream&);
void ishr(int&, cp_info_vector&, bytestream&);
void lshr(int&, cp_info_vector&, bytestream&);
void iushr(int&, cp_info_vector&, bytestream&);
void lushr(int&, cp_info_vector&, bytestream&);
void iand(int&, cp_info_vector&, bytestream&);
void land(int&, cp_info_vector&, bytestream&);
void ior(int&, cp_info_vector&, bytestream&);
void lor(int&, cp_info_vector&, bytestream&);
void ixor(int&, cp_info_vector&, bytestream&);
void lxor(int&, cp_info_vector&, bytestream&);
void lcmp(int&, cp_info_vector&, bytestream&);
void l2i(int&, cp_info_vector&, bytestream&);
void l2f(int&, cp_info_vector&, bytestream&);
void l2d(int&, cp_info_vector&, bytestream&);
void i2l(int&, cp_info_vector&, bytestream&);
void i2f(int&, cp_info_vector&, bytestream&);
void i2d(int&, cp_info_vector&, bytestream&);
void i2b(int&, cp_info_vector&, bytestream&);
void i2c(int&, cp_info_vector&, bytestream&);
void i2s(int&, cp_info_vector&, bytestream&);
void arraylength(int&, cp_info_vector&, bytestream&);
void astore_0(int&, cp_info_vector&, bytestream&);
void astore_1(int&, cp_info_vector&, bytestream&);
void astore_2(int&, cp_info_vector&, bytestream&);
void astore_3(int&, cp_info_vector&, bytestream&);
void athrow(int&, cp_info_vector&, bytestream&);
void baload(int&, cp_info_vector&, bytestream&);
void bastore(int&, cp_info_vector&, bytestream&);
void caload(int&, cp_info_vector&, bytestream&);
void castore(int&, cp_info_vector&, bytestream&);
void areturn(int&, cp_info_vector&, bytestream&);
void ireturn(int&, cp_info_vector&, bytestream&);
void lreturn(int&, cp_info_vector&, bytestream&);
void _return(int&, cp_info_vector&, bytestream&);
void freturn(int&, cp_info_vector&, bytestream&);
void monitorexit(int&, cp_info_vector&, bytestream&);
void monitorenter(int&, cp_info_vector&, bytestream&);
void d2f(int&, cp_info_vector&, bytestream&);
void d2i(int&, cp_info_vector&, bytestream&);
void d2l(int&, cp_info_vector&, bytestream&);
void dadd(int&, cp_info_vector&, bytestream&);
void daload(int&, cp_info_vector&, bytestream&);
void dastore(int&, cp_info_vector&, bytestream&);
void dcmpl(int&, cp_info_vector&, bytestream&);
void dcmpg(int&, cp_info_vector&, bytestream&);
void dconst_0(int&, cp_info_vector&, bytestream&);
void dconst_1(int&, cp_info_vector&, bytestream&);
void ddiv(int&, cp_info_vector&, bytestream&);
void dload_0(int&, cp_info_vector&, bytestream&);
void dload_1(int&, cp_info_vector&, bytestream&);
void dload_2(int&, cp_info_vector&, bytestream&);
void dload_3(int&, cp_info_vector&, bytestream&);
void dmul(int&, cp_info_vector&, bytestream&);
void dneg(int&, cp_info_vector&, bytestream&);
void drem(int&, cp_info_vector&, bytestream&);
void dreturn(int&, cp_info_vector&, bytestream&);
void dstore_0(int&, cp_info_vector&, bytestream&);
void dstore_1(int&, cp_info_vector&, bytestream&);
void dstore_2(int&, cp_info_vector&, bytestream&);
void dstore_3(int&, cp_info_vector&, bytestream&);
void dsub(int&, cp_info_vector&, bytestream&);
void dup(int&, cp_info_vector&, bytestream&);
void dup_x1(int&, cp_info_vector&, bytestream&);
void dup_x2(int&, cp_info_vector&, bytestream&);
void dup2(int&, cp_info_vector&, bytestream&);
void dup2_x1(int&, cp_info_vector&, bytestream&);
void dup2_x2(int&, cp_info_vector&, bytestream&);
void f2d(int&, cp_info_vector&, bytestream&);
void f2i(int&, cp_info_vector&, bytestream&);
void f2l(int&, cp_info_vector&, bytestream&);
void fadd(int&, cp_info_vector&, bytestream&);
void faload(int&, cp_info_vector&, bytestream&);
void fastore(int&, cp_info_vector&, bytestream&);
void fcmpl(int&, cp_info_vector&, bytestream&);
void fcmpg(int&, cp_info_vector&, bytestream&);
void fconst_0(int&, cp_info_vector&, bytestream&);
void fconst_1(int&, cp_info_vector&, bytestream&);
void fconst_2(int&, cp_info_vector&, bytestream&);
void fdiv(int&, cp_info_vector&, bytestream&);
void fload_0(int&, cp_info_vector&, bytestream&);
void fload_1(int&, cp_info_vector&, bytestream&);
void fload_2(int&, cp_info_vector&, bytestream&);
void fload_3(int&, cp_info_vector&, bytestream&);
void frem(int&, cp_info_vector&, bytestream&);
void fstore_0(int&, cp_info_vector&, bytestream&);
void fstore_1(int&, cp_info_vector&, bytestream&);
void fstore_2(int&, cp_info_vector&, bytestream&);
void fstore_3(int&, cp_info_vector&, bytestream&);
void fsub(int&, cp_info_vector&, bytestream&);
void iconst_m1(int&, cp_info_vector&, bytestream&);
void iconst_0(int&, cp_info_vector&, bytestream&);
void iconst_1(int&, cp_info_vector&, bytestream&);
void iconst_2(int&, cp_info_vector&, bytestream&);
void iconst_3(int&, cp_info_vector&, bytestream&);
void iconst_4(int&, cp_info_vector&, bytestream&);
void iconst_5(int&, cp_info_vector&, bytestream&);
void lconst_0(int&, cp_info_vector&, bytestream&);
void lconst_1(int&, cp_info_vector&, bytestream&);
void ldiv(int&, cp_info_vector&, bytestream&);
void istore_0(int&, cp_info_vector&, bytestream&);
void istore_1(int&, cp_info_vector&, bytestream&);
void istore_2(int&, cp_info_vector&, bytestream&);
void istore_3(int&, cp_info_vector&, bytestream&);
void lstore_0(int&, cp_info_vector&, bytestream&);
void lstore_1(int&, cp_info_vector&, bytestream&);
void lstore_2(int&, cp_info_vector&, bytestream&);
void lstore_3(int&, cp_info_vector&, bytestream&);
void lload_0(int&, cp_info_vector&, bytestream&);
void lload_1(int&, cp_info_vector&, bytestream&);
void lload_2(int&, cp_info_vector&, bytestream&);
void lload_3(int&, cp_info_vector&, bytestream&);
void iload_0(int&, cp_info_vector&, bytestream&);
void iload_1(int&, cp_info_vector&, bytestream&);
void iload_2(int&, cp_info_vector&, bytestream&);
void iload_3(int&, cp_info_vector&, bytestream&);
void iaload(int&, cp_info_vector&, bytestream&);
void laload(int&, cp_info_vector&, bytestream&);
void saload(int&, cp_info_vector&, bytestream&);
void iastore(int&, cp_info_vector&, bytestream&);
void lastore(int&, cp_info_vector&, bytestream&);
void sastore(int&, cp_info_vector&, bytestream&);
void pop(int&, cp_info_vector&, bytestream&);
void pop2(int&, cp_info_vector&, bytestream&);
void iadd(int&, cp_info_vector&, bytestream&);
void ladd(int&, cp_info_vector&, bytestream&);
void isub(int&, cp_info_vector&, bytestream&);
void lsub(int&, cp_info_vector&, bytestream&);
void imul(int&, cp_info_vector&, bytestream&);
void lmul(int&, cp_info_vector&, bytestream&);
void dload(int&, cp_info_vector&, bytestream&);
void aload(int&, cp_info_vector&, bytestream&);
void astore(int&, cp_info_vector&, bytestream&);
void bipush(int&, cp_info_vector&, bytestream&);
void fload(int&, cp_info_vector&, bytestream&);
void dstore(int&, cp_info_vector&, bytestream&);
void ret(int&, cp_info_vector&, bytestream&);
void newarray(int&, cp_info_vector&, bytestream&);
void fstore(int&, cp_info_vector&, bytestream&);
void ldc(int&, cp_info_vector&, bytestream&);
void iload(int&, cp_info_vector&, bytestream&);
void lload(int&, cp_info_vector&, bytestream&);
void istore(int&, cp_info_vector&, bytestream&);
void lstore(int&, cp_info_vector&, bytestream&);
void _goto(int&, cp_info_vector&, bytestream&);
void jsr(int&, cp_info_vector&, bytestream&);
void getstatic(int&, cp_info_vector&, bytestream&);
void putstatic(int&, cp_info_vector&, bytestream&);
void putfield(int&, cp_info_vector&, bytestream&);
void getfield(int&, cp_info_vector&, bytestream&);
void invokevirtual(int&, cp_info_vector&, bytestream&);
void invokespecial(int&, cp_info_vector&, bytestream&);
void invokestatic(int&, cp_info_vector&, bytestream&);
void _new(int&, cp_info_vector&, bytestream&);
void anewarray(int&, cp_info_vector&, bytestream&);
void checkcast(int&, cp_info_vector&, bytestream&);
void instanceof(int&, cp_info_vector&, bytestream&);
void ifnull(int&, cp_info_vector&, bytestream&);
void ifnonnull(int&, cp_info_vector&, bytestream&);
void ifeq(int&, cp_info_vector&, bytestream&);
void ifne(int&, cp_info_vector&, bytestream&);
void iflt(int&, cp_info_vector&, bytestream&);
void ifge(int&, cp_info_vector&, bytestream&);
void ifgt(int&, cp_info_vector&, bytestream&);
void ifle(int&, cp_info_vector&, bytestream&);
void if_icmpeq(int&, cp_info_vector&, bytestream&);
void if_icmpne(int&, cp_info_vector&, bytestream&);
void if_icmplt(int&, cp_info_vector&, bytestream&);
void if_icmpge(int&, cp_info_vector&, bytestream&);
void if_icmpgt(int&, cp_info_vector&, bytestream&);
void if_icmple(int&, cp_info_vector&, bytestream&);
void if_acmpeq(int&, cp_info_vector&, bytestream&);
void if_acmpne(int&, cp_info_vector&, bytestream&);
void fmul(int&, cp_info_vector&, bytestream&);
void fneg(int&, cp_info_vector&, bytestream&);
void iinc(int&, cp_info_vector&, bytestream&);
void ldc_w(int&, cp_info_vector&, bytestream&);
void ldc2_w(int&, cp_info_vector&, bytestream&);
void multianewarray(int&, cp_info_vector&, bytestream&);
void invokeinterface(int&, cp_info_vector&, bytestream&);
void invokedynamic(int&, cp_info_vector&, bytestream&);
void goto_w(int&, cp_info_vector&, bytestream&);
void jsr_w(int&, cp_info_vector&, bytestream&);
void tableswitch(int&, cp_info_vector&, bytestream&);
void lookupswitch(int&, cp_info_vector&, bytestream&);
void wide(int&, cp_info_vector&, bytestream&);
void break_point(int&, cp_info_vector&, bytestream&);
void impdep_1(int&, cp_info_vector&, bytestream&);
void impdep_2(int&, cp_info_vector&, bytestream&);

// Instructions 
void aload_0_debug(int&, cp_info_vector&, bytestream&);
void aload_1_debug(int&, cp_info_vector&, bytestream&);
void aload_2_debug(int&, cp_info_vector&, bytestream&);
void aload_3_debug(int&, cp_info_vector&, bytestream&);
void idiv_debug(int&, cp_info_vector&, bytestream&);
void irem_debug(int&, cp_info_vector&, bytestream&);
void lrem_debug(int&, cp_info_vector&, bytestream&);
void ineg_debug(int&, cp_info_vector&, bytestream&);
void lneg_debug(int&, cp_info_vector&, bytestream&);
void ishl_debug(int&, cp_info_vector&, bytestream&);
void lshl_debug(int&, cp_info_vector&, bytestream&);
void ishr_debug(int&, cp_info_vector&, bytestream&);
void lshr_debug(int&, cp_info_vector&, bytestream&);
void iushr_debug(int&, cp_info_vector&, bytestream&);
void lushr_debug(int&, cp_info_vector&, bytestream&);
void iand_debug(int&, cp_info_vector&, bytestream&);
void land_debug(int&, cp_info_vector&, bytestream&);
void ior_debug(int&, cp_info_vector&, bytestream&);
void lor_debug(int&, cp_info_vector&, bytestream&);
void ixor_debug(int&, cp_info_vector&, bytestream&);
void lxor_debug(int&, cp_info_vector&, bytestream&);
void lcmp_debug(int&, cp_info_vector&, bytestream&);
void l2i_debug(int&, cp_info_vector&, bytestream&);
void l2f_debug(int&, cp_info_vector&, bytestream&);
void l2d_debug(int&, cp_info_vector&, bytestream&);
void i2l_debug(int&, cp_info_vector&, bytestream&);
void i2f_debug(int&, cp_info_vector&, bytestream&);
void i2d_debug(int&, cp_info_vector&, bytestream&);
void i2b_debug(int&, cp_info_vector&, bytestream&);
void i2c_debug(int&, cp_info_vector&, bytestream&);
void i2s_debug(int&, cp_info_vector&, bytestream&);
void arraylength_debug(int&, cp_info_vector&, bytestream&);
void astore_0_debug(int&, cp_info_vector&, bytestream&);
void astore_1_debug(int&, cp_info_vector&, bytestream&);
void astore_2_debug(int&, cp_info_vector&, bytestream&);
void astore_3_debug(int&, cp_info_vector&, bytestream&);
void athrow_debug(int&, cp_info_vector&, bytestream&);
void baload_debug(int&, cp_info_vector&, bytestream&);
void bastore_debug(int&, cp_info_vector&, bytestream&);
void caload_debug(int&, cp_info_vector&, bytestream&);
void castore_debug(int&, cp_info_vector&, bytestream&);
void areturn_debug(int&, cp_info_vector&, bytestream&);
void ireturn_debug(int&, cp_info_vector&, bytestream&);
void lreturn_debug(int&, cp_info_vector&, bytestream&);
void _return_debug(int&, cp_info_vector&, bytestream&);
void freturn_debug(int&, cp_info_vector&, bytestream&);
void monitorexit_debug(int&, cp_info_vector&, bytestream&);
void monitorenter_debug(int&, cp_info_vector&, bytestream&);
void d2f_debug(int&, cp_info_vector&, bytestream&);
void d2i_debug(int&, cp_info_vector&, bytestream&);
void d2l_debug(int&, cp_info_vector&, bytestream&);
void dadd_debug(int&, cp_info_vector&, bytestream&);
void daload_debug(int&, cp_info_vector&, bytestream&);
void dastore_debug(int&, cp_info_vector&, bytestream&);
void dcmpl_debug(int&, cp_info_vector&, bytestream&);
void dcmpg_debug(int&, cp_info_vector&, bytestream&);
void dconst_0_debug(int&, cp_info_vector&, bytestream&);
void dconst_1_debug(int&, cp_info_vector&, bytestream&);
void ddiv_debug(int&, cp_info_vector&, bytestream&);
void dload_0_debug(int&, cp_info_vector&, bytestream&);
void dload_1_debug(int&, cp_info_vector&, bytestream&);
void dload_2_debug(int&, cp_info_vector&, bytestream&);
void dload_3_debug(int&, cp_info_vector&, bytestream&);
void dmul_debug(int&, cp_info_vector&, bytestream&);
void dneg_debug(int&, cp_info_vector&, bytestream&);
void drem_debug(int&, cp_info_vector&, bytestream&);
void dreturn_debug(int&, cp_info_vector&, bytestream&);
void dstore_0_debug(int&, cp_info_vector&, bytestream&);
void dstore_1_debug(int&, cp_info_vector&, bytestream&);
void dstore_2_debug(int&, cp_info_vector&, bytestream&);
void dstore_3_debug(int&, cp_info_vector&, bytestream&);
void dsub_debug(int&, cp_info_vector&, bytestream&);
void dup_debug(int&, cp_info_vector&, bytestream&);
void dup_x1_debug(int&, cp_info_vector&, bytestream&);
void dup_x2_debug(int&, cp_info_vector&, bytestream&);
void dup2_debug(int&, cp_info_vector&, bytestream&);
void dup2_x1_debug(int&, cp_info_vector&, bytestream&);
void dup2_x2_debug(int&, cp_info_vector&, bytestream&);
void f2d_debug(int&, cp_info_vector&, bytestream&);
void f2i_debug(int&, cp_info_vector&, bytestream&);
void f2l_debug(int&, cp_info_vector&, bytestream&);
void fadd_debug(int&, cp_info_vector&, bytestream&);
void faload_debug(int&, cp_info_vector&, bytestream&);
void fastore_debug(int&, cp_info_vector&, bytestream&);
void fcmpl_debug(int&, cp_info_vector&, bytestream&);
void fcmpg_debug(int&, cp_info_vector&, bytestream&);
void fconst_0_debug(int&, cp_info_vector&, bytestream&);
void fconst_1_debug(int&, cp_info_vector&, bytestream&);
void fconst_2_debug(int&, cp_info_vector&, bytestream&);
void fdiv_debug(int&, cp_info_vector&, bytestream&);
void fload_0_debug(int&, cp_info_vector&, bytestream&);
void fload_1_debug(int&, cp_info_vector&, bytestream&);
void fload_2_debug(int&, cp_info_vector&, bytestream&);
void fload_3_debug(int&, cp_info_vector&, bytestream&);
void frem_debug(int&, cp_info_vector&, bytestream&);
void fstore_0_debug(int&, cp_info_vector&, bytestream&);
void fstore_1_debug(int&, cp_info_vector&, bytestream&);
void fstore_2_debug(int&, cp_info_vector&, bytestream&);
void fstore_3_debug(int&, cp_info_vector&, bytestream&);
void fsub_debug(int&, cp_info_vector&, bytestream&);
void iconst_m1_debug(int&, cp_info_vector&, bytestream&);
void iconst_0_debug(int&, cp_info_vector&, bytestream&);
void iconst_1_debug(int&, cp_info_vector&, bytestream&);
void iconst_2_debug(int&, cp_info_vector&, bytestream&);
void iconst_3_debug(int&, cp_info_vector&, bytestream&);
void iconst_4_debug(int&, cp_info_vector&, bytestream&);
void iconst_5_debug(int&, cp_info_vector&, bytestream&);
void lconst_0_debug(int&, cp_info_vector&, bytestream&);
void lconst_1_debug(int&, cp_info_vector&, bytestream&);
void ldiv_debug(int&, cp_info_vector&, bytestream&);
void istore_0_debug(int&, cp_info_vector&, bytestream&);
void istore_1_debug(int&, cp_info_vector&, bytestream&);
void istore_2_debug(int&, cp_info_vector&, bytestream&);
void istore_3_debug(int&, cp_info_vector&, bytestream&);
void lstore_0_debug(int&, cp_info_vector&, bytestream&);
void lstore_1_debug(int&, cp_info_vector&, bytestream&);
void lstore_2_debug(int&, cp_info_vector&, bytestream&);
void lstore_3_debug(int&, cp_info_vector&, bytestream&);
void lload_0_debug(int&, cp_info_vector&, bytestream&);
void lload_1_debug(int&, cp_info_vector&, bytestream&);
void lload_2_debug(int&, cp_info_vector&, bytestream&);
void lload_3_debug(int&, cp_info_vector&, bytestream&);
void iload_0_debug(int&, cp_info_vector&, bytestream&);
void iload_1_debug(int&, cp_info_vector&, bytestream&);
void iload_2_debug(int&, cp_info_vector&, bytestream&);
void iload_3_debug(int&, cp_info_vector&, bytestream&);
void iaload_debug(int&, cp_info_vector&, bytestream&);
void laload_debug(int&, cp_info_vector&, bytestream&);
void iastore_debug(int&, cp_info_vector&, bytestream&);
void lastore_debug(int&, cp_info_vector&, bytestream&);
void pop_debug(int&, cp_info_vector&, bytestream&);
void pop2_debug(int&, cp_info_vector&, bytestream&);
void swap_debug(int&, cp_info_vector&, bytestream&);
void iadd_debug(int&, cp_info_vector&, bytestream&);
void ladd_debug(int&, cp_info_vector&, bytestream&);
void isub_debug(int&, cp_info_vector&, bytestream&);
void lsub_debug(int&, cp_info_vector&, bytestream&);
void imul_debug(int&, cp_info_vector&, bytestream&);
void lmul_debug(int&, cp_info_vector&, bytestream&);
void dload_debug(int&, cp_info_vector&, bytestream&);
void aload_debug(int&, cp_info_vector&, bytestream&);
void astore_debug(int&, cp_info_vector&, bytestream&);
void bipush_debug(int&, cp_info_vector&, bytestream&);
void fload_debug(int&, cp_info_vector&, bytestream&);
void dstore_debug(int&, cp_info_vector&, bytestream&);
void ret_debug(int&, cp_info_vector&, bytestream&);
void newarray_debug(int&, cp_info_vector&, bytestream&);
void fstore_debug(int&, cp_info_vector&, bytestream&);
void ldc_debug(int&, cp_info_vector&, bytestream&);
void iload_debug(int&, cp_info_vector&, bytestream&);
void lload_debug(int&, cp_info_vector&, bytestream&);
void istore_debug(int&, cp_info_vector&, bytestream&);
void lstore_debug(int&, cp_info_vector&, bytestream&);
void _goto_debug(int&, cp_info_vector&, bytestream&);
void jsr_debug(int&, cp_info_vector&, bytestream&);
void getstatic_debug(int&, cp_info_vector&, bytestream&);
void putstatic_debug(int&, cp_info_vector&, bytestream&);
void putfield_debug(int&, cp_info_vector&, bytestream&);
void getfield_debug(int&, cp_info_vector&, bytestream&);
void invokevirtual_debug(int&, cp_info_vector&, bytestream&);
void invokespecial_debug(int&, cp_info_vector&, bytestream&);
void invokestatic_debug(int&, cp_info_vector&, bytestream&);
void _new_debug(int&, cp_info_vector&, bytestream&);
void anewarray_debug(int&, cp_info_vector&, bytestream&);
void checkcast_debug(int&, cp_info_vector&, bytestream&);
void instanceof_debug(int&, cp_info_vector&, bytestream&);
void ifnull_debug(int&, cp_info_vector&, bytestream&);
void ifnonnull_debug(int&, cp_info_vector&, bytestream&);
void ifeq_debug(int&, cp_info_vector&, bytestream&);
void ifne_debug(int&, cp_info_vector&, bytestream&);
void iflt_debug(int&, cp_info_vector&, bytestream&);
void ifge_debug(int&, cp_info_vector&, bytestream&);
void ifgt_debug(int&, cp_info_vector&, bytestream&);
void ifle_debug(int&, cp_info_vector&, bytestream&);
void if_icmpeq_debug(int&, cp_info_vector&, bytestream&);
void if_icmpne_debug(int&, cp_info_vector&, bytestream&);
void if_icmplt_debug(int&, cp_info_vector&, bytestream&);
void if_icmpge_debug(int&, cp_info_vector&, bytestream&);
void if_icmpgt_debug(int&, cp_info_vector&, bytestream&);
void if_icmple_debug(int&, cp_info_vector&, bytestream&);
void if_acmpeq_debug(int&, cp_info_vector&, bytestream&);
void if_acmpne_debug(int&, cp_info_vector&, bytestream&);
void fmul_debug(int&, cp_info_vector&, bytestream&);
void fneg_debug(int&, cp_info_vector&, bytestream&);
void iinc_debug(int&, cp_info_vector&, bytestream&);
void sipush_debug(int&, cp_info_vector&, bytestream&);
void ldc_w_debug(int&, cp_info_vector&, bytestream&);
void ldc2_w_debug(int&, cp_info_vector&, bytestream&);
void multianewarray_debug(int&, cp_info_vector&, bytestream&);
void invokeinterface_debug(int&, cp_info_vector&, bytestream&);
void invokedynamic_debug(int&, cp_info_vector&, bytestream&);
void goto_w_debug(int&, cp_info_vector&, bytestream&);
void jsr_w_debug(int&, cp_info_vector&, bytestream&);
void tableswitch_debug(int&, cp_info_vector&, bytestream&);
void lookupswitch_debug(int&, cp_info_vector&, bytestream&);
void wide_debug(int&, cp_info_vector&, bytestream&);
void break_point_debug(int&, cp_info_vector&, bytestream&);
void impdep_1_debug(int&, cp_info_vector&, bytestream&);
void impdep_2_debug(int&, cp_info_vector&, bytestream&);

const mnemonic_map mnemonic = {
    {0x00, "nop"}, {0x32, "aaload"}, {0x53, "aastore"}, {0x01, "aconst_null"}, {0x2A, "aload_0"},
    {0x2B, "aload_1"}, {0x2C, "aload_2"}, {0x2D, "aload_3"}, {0x6C, "idiv"}, {0x70, "irem"},
    {0x71, "lrem"}, {0x74, "ineg"}, {0x75, "lneg"}, {0x78, "ishl"}, {0x79, "lshl"}, {0x7A, "ishr"},
    {0x7B, "lshr"}, {0x7C, "iushr"}, {0x7D, "lushr"}, {0x7E, "iand"}, {0x7F, "land"}, {0x80, "ior"},
    {0x81, "lor"}, {0x82, "ixor"}, {0x83, "lxor"}, {0x94, "lcmp"}, {0x88, "l2i"}, {0x89, "l2f"},
    {0x8A, "l2d"}, {0x85, "i2l"}, {0x86, "i2f"}, {0x87, "i2d"}, {0x91, "i2b"}, {0x92, "i2c"},
    {0x93, "i2s"}, {0xBE, "arraylength"}, {0x4B, "astore_0"}, {0x4C, "astore_1"}, {0x4D, "astore_2"},
    {0x4E, "astore_3"}, {0xBF, "athrow"}, {0x33, "baload"}, {0x54, "bastore"}, {0x34, "caload"},
    {0x55, "castore"}, {0xB0, "areturn"}, {0xAC, "ireturn"}, {0xAD, "lreturn"}, {0xB1, "return"},
    {0xAE, "freturn"},{0xC3, "monitorexit"},{0xC2, "monitorenter"},{0x90, "d2f"},{0x8E, "d2i"},{0x8F, "d2l"},
    {0x63, "dadd"},{0x31, "daload"},{0x52, "dastore"},{0x97, "dcmpl"},{0x98, "dcmpg"},{0x0E, "dconst_0"},
    {0x0F, "dconst_1"},{0x6F, "ddiv"},{0x26, "dload_0"},{0x27, "dload_1"},{0x28, "dload_2"},{0x29, "dload_3"},
    {0x6B, "dmul"},{0x77, "dneg"},{0x73, "drem"},{0xAF, "dreturn"},{0x47, "dstore_0"}, {0x48, "dstore_1"},
    {0x49, "dstore_2"},{0x4A, "dstore_3"},{0x67, "dsub"}, {0x59, "dup"}, {0x5A, "dup_x1"}, {0x5B, "dup_x2"},
    {0x5C, "dup2"}, {0x5D, "dup2_x1"},  {0x5E, "dup2_x2"}, {0x8D, "f2d"}, {0x8B, "f2i"}, {0x8C, "f2l"}, 
    {0x62, "fadd"}, {0x30, "faload"}, {0x51, "fastore"}, {0x95, "fcmpl"}, {0x96, "fcmpg"},
    {0x0B, "fconst_0"}, {0x0C, "fconst_1"}, {0x0D, "fconst_2"}, {0x6E, "fdiv"}, {0x22, "fload_0"}, 
    {0x23, "fload_1"}, {0x24, "fload_2"}, {0x25, "fload_3"},  {0x72, "frem"} , {0x43, "fstore_0"},
    {0x44, "fstore_1"}, {0x45, "fstore_2"}, {0x46, "fstore_3"}, {0x66, "fsub"}, {0x02, "iconst_m1"}, 
    {0x03, "iconst_0"}, {0x04, "iconst_1"},{0x05, "iconst_2"}, {0x06, "iconst_3"}, {0x07, "iconst_4"}, 
    {0x08, "iconst_5"}, {0x09, "lconst_0"},{0x0A, "lconst_1"}, {0x6D, "ldiv"}, {0x3B, "istore_0"}, 
    {0x3C, "istore_1"}, {0x3D, "istore_2"}, {0x3E, "istore_3"}, {0x3F, "lstore_0"}, {0x40, "lstore_1"}, 
    {0x41, "lstore_2"}, {0x42, "lstore_3"}, {0x1E, "lload_0"}, {0x1F, "lload_1"}, {0x20, "lload_2"}, 
    {0x21, "lload_3"}, {0x1A, "iload_0"},{0x1B, "iload_1"}, {0x1C, "iload_2"}, {0x1D, "iload_3"}, {0x2E, "iaload"}, 
    {0x2F, "laload"}, {0x35, "saload"}, {0x4F, "iastore"}, {0x50, "lastore"}, {0x56, "sastore"}, {0x57, "pop"}, 
    {0x58, "pop2"}, {0x5F, "swap"},{0x60, "iadd"}, {0x61, "ladd"}, {0x64, "isub"}, {0x65, "lsub"}, {0x68, "imul"}, 
    {0x69, "lmul"},
};

// debug functions
const bytecode_map debug = {
    {0x00, nop_debug}, {0x32, aaload_debug},
    {0x2A, aload_0_debug}, {0x2B, aload_1_debug}, {0x2C, aload_2_debug}, {0x2D, aload_3_debug},
    {0x6C, idiv_debug}, {0x70, irem_debug}, {0x71, lrem_debug}, {0x74, ineg_debug}, {0x75, lneg_debug},
    {0x78, ishl_debug}, {0x79, lshl_debug}, {0x7A, ishr_debug}, {0x7B, lshr_debug}, {0x7C, iushr_debug},
    {0x7D, lushr_debug}, {0x7E, iand_debug}, {0x7F, land_debug}, {0x80, ior_debug}, {0x81, lor_debug},
    {0x82, ixor_debug}, {0x83, lxor_debug}, {0x94, lcmp_debug}, {0x88, l2i_debug}, {0x89, l2f_debug},
    {0x8A, l2d_debug}, {0x85, i2l_debug}, {0x86, i2f_debug}, {0x87, i2d_debug}, {0x91, i2b_debug},
    {0x92, i2c_debug}, {0x93, i2s_debug}, {0xBE, arraylength_debug}, {0x4B, astore_0_debug}, {0x4C, astore_1_debug}, 
    {0x4D, astore_2_debug}, {0x4E, astore_3_debug}, {0xBF, athrow_debug}, {0x33, baload_debug}, 
    {0x54, bastore_debug}, {0x34, caload_debug}, {0x55, castore_debug}, {0xB0, areturn_debug}, 
    {0xAC, ireturn_debug}, {0xAD, lreturn_debug}, {0xB1, _return_debug}, {0xAE, freturn_debug},
    {0xC3, monitorexit_debug}, {0xC2, monitorenter_debug}, {0x90, d2f_debug}, {0x8E, d2i_debug},
    {0x8F, d2l_debug}, {0x63, dadd_debug}, {0x31, daload_debug}, {0x52, dastore_debug}, {0x97, dcmpl_debug},
    {0x98, dcmpg_debug}, {0x0E, dconst_0_debug}, {0x0F, dconst_1_debug}, {0x6F, ddiv_debug},
    {0x26, dload_0_debug}, {0x27, dload_1_debug}, {0x28, dload_2_debug}, {0x29, dload_3_debug},
    {0x6B, dmul_debug}, {0x77, dneg_debug}, {0x73, drem_debug}, {0xAF, dreturn_debug},
    {0x47, dstore_0_debug}, {0x48, dstore_1_debug}, {0x49, dstore_2_debug}, {0x4A, dstore_3_debug},
    {0x67, dsub_debug}, {0x59, dup_debug}, {0x5A, dup_x1_debug}, {0x5B, dup_x2_debug}, {0x5C, dup2_debug},
    {0x5D, dup2_x1_debug}, {0x5E, dup2_x2_debug}, {0x8D, f2d_debug}, {0x8B, f2i_debug}, {0x8C, f2l_debug},
    {0x62, fadd_debug}, {0x30, faload_debug}, {0x51, fastore_debug}, {0x95, fcmpl_debug}, {0x96, fcmpg_debug},
    {0x0B, fconst_0_debug}, {0x0C, fconst_1_debug}, {0x0D, fconst_2_debug}, {0x6E, fdiv_debug}, {0x22, fload_0_debug},
    {0x23, fload_1_debug}, {0x24, fload_2_debug}, {0x25, fload_3_debug}, {0x72, frem_debug}, {0x43, fstore_0_debug},
    {0x44, fstore_1_debug}, {0x45, fstore_2_debug}, {0x46, fstore_3_debug}, {0x66, fsub_debug}, {0x02, iconst_m1_debug},
    {0x03, iconst_0_debug}, {0x04, iconst_1_debug}, {0x05, iconst_2_debug}, {0x06, iconst_3_debug}, {0x07, iconst_4_debug},
    {0x08, iconst_5_debug}, {0x09, lconst_0_debug}, {0x0A, lconst_1_debug}, {0x6D, ldiv_debug}, {0x3B, istore_0_debug},
    {0x3C, istore_1_debug}, {0x3D, istore_2_debug}, {0x3E, istore_3_debug}, {0x3F, lstore_0_debug}, {0x40, lstore_1_debug},
    {0x41, lstore_2_debug}, {0x42, lstore_3_debug}, {0x1E, lload_0_debug}, {0x1F, lload_1_debug}, {0x20, lload_2_debug},
    {0x21, lload_3_debug}, {0x1A, iload_0_debug}, {0x1B, iload_1_debug}, {0x1C, iload_2_debug}, {0x1D, iload_3_debug},
    {0x2E, iaload_debug}, {0x2F, laload_debug}, {0x4F, iastore_debug}, {0x50, lastore_debug}, {0x57, pop_debug}, {0x58, pop2_debug},
    {0x5F, swap_debug}, {0x60, iadd_debug}, {0x61, ladd_debug}, {0x64, isub_debug},
    {0x65, lsub_debug}, {0x68, imul_debug}, {0x69, lmul_debug}, {0x18, dload_debug}, {0x19, aload_debug},
    {0x3A, astore_debug}, {0x10, bipush_debug}, {0x17, fload_debug}, {0x39, dstore_debug},
    {0xA9, ret_debug}, {0xBC, newarray_debug}, {0x38, fstore_debug}, {0x12, ldc_debug}, {0x15, iload_debug},
    {0x16, lload_debug}, {0x36, istore_debug}, {0x37, lstore_debug}, {0xA7, _goto_debug},
    {0xA8, jsr_debug}, {0xB2, getstatic_debug}, {0xB3, putstatic_debug}, {0xB5, putfield_debug},
    {0xB4, getfield_debug}, {0xB6, invokevirtual_debug}, {0xB7, invokespecial_debug}, {0xB8, invokestatic_debug},
    {0xBB, _new_debug}, {0xBD, anewarray_debug}, {0xC0, checkcast_debug}, {0xC1, instanceof_debug},
    {0xC6, ifnull_debug}, {0xC7, ifnonnull_debug}, {0x99, ifeq_debug}, {0x9A, ifne_debug},
    {0x9B, iflt_debug}, {0x9C, ifge_debug}, {0x9D, ifgt_debug}, {0x9E, ifle_debug}, {0x9F, if_icmpeq_debug},
    {0xA0, if_icmpne_debug}, {0xA1, if_icmplt_debug}, {0xA2, if_icmpge_debug}, {0xA3, if_icmpgt_debug},
    {0xA4, if_icmple_debug}, {0xA5, if_acmpeq_debug}, {0xA6, if_acmpne_debug}, {0x6A, fmul_debug},
    {0x76, fneg_debug}, {0x84, iinc_debug}, {0x11, sipush_debug}, {0x13, ldc_w_debug}, {0x14, ldc2_w_debug},
    {0xC5, multianewarray_debug}, {0xB9, invokeinterface_debug}, {0xBA, invokedynamic_debug}, {0xC8, goto_w_debug},
    {0xC9, jsr_w_debug}, {0xAA, tableswitch_debug}, {0xAB, lookupswitch_debug}, {0xC4, wide_debug},
    {0xCA, break_point_debug},  /* reserved */ {0xFE, impdep_1_debug}, /* reserved */ {0xFF, impdep_2_debug}, /* reserved */
};

// bytecode functions
// const bytecode_map bytecode = {
//     {0x00, nop}, {0x32, aaload}, {0x53, aastore}, {0x01, aconst_null},
//     {0x2A, aload_0}, {0x2B, aload_1}, {0x2C, aload_2}, {0x2D, aload_3},
//     {0x6C, idiv}, {0x70, irem}, {0x71, lrem}, {0x74, ineg}, {0x75, lneg},
//     {0x78, ishl}, {0x79, lshl}, {0x7A, ishr}, {0x7B, lshr}, {0x7C, iushr},
//     {0x7D, lushr}, {0x7E, iand}, {0x7F, land}, {0x80, ior}, {0x81, lor},
//     {0x82, ixor}, {0x83, lxor}, {0x94, lcmp}, {0x88, l2i}, {0x89, l2f},
//     {0x8A, l2d}, {0x85, i2l}, {0x86, i2f}, {0x87, i2d}, {0x91, i2b},
//     {0x92, i2c}, {0x93, i2s}, {0xBE, arraylength}, {0x4B, astore_0}, {0x4C, astore_1}, 
//     {0x4D, astore_2}, {0x4E, astore_3}, {0xBF, athrow}, {0x33, baload}, 
//     {0x54, bastore}, {0x34, caload}, {0x55, castore}, {0xB0, areturn}, 
//     {0xAC, ireturn}, {0xAD, lreturn}, {0xB1, _return}, {0xAE, freturn},
//     {0xC3, monitorexit}, {0xC2, monitorenter}, {0x90, d2f}, {0x8E, d2i},
//     {0x8F, d2l}, {0x63, dadd}, {0x31, daload}, {0x52, dastore}, {0x97, dcmpl},
//     {0x98, dcmpg}, {0x0E, dconst_0}, {0x0F, dconst_1}, {0x6F, ddiv},
//     {0x26, dload_0}, {0x27, dload_1}, {0x28, dload_2}, {0x29, dload_3},
//     {0x6B, dmul}, {0x77, dneg}, {0x73, drem}, {0xAF, dreturn},
//     {0x47, dstore_0}, {0x48, dstore_1}, {0x49, dstore_2}, {0x4A, dstore_3},
//     {0x67, dsub}, {0x59, dup}, {0x5A, dup_x1}, {0x5B, dup_x2}, {0x5C, dup2},
//     {0x5D, dup2_x1}, {0x5E, dup2_x2}, {0x8D, f2d}, {0x8B, f2i}, {0x8C, f2l},
//     {0x62, fadd}, {0x30, faload}, {0x51, fastore}, {0x95, fcmpl}, {0x96, fcmpg},
//     {0x0B, fconst_0}, {0x0C, fconst_1}, {0x0D, fconst_2}, {0x6E, fdiv}, {0x22, fload_0},
//     {0x23, fload_1}, {0x24, fload_2}, {0x25, fload_3}, {0x72, frem}, {0x43, fstore_0},
//     {0x44, fstore_1}, {0x45, fstore_2}, {0x46, fstore_3}, {0x66, fsub}, {0x02, iconst_m1},
//     {0x03, iconst_0}, {0x04, iconst_1}, {0x05, iconst_2}, {0x06, iconst_3}, {0x07, iconst_4},
//     {0x08, iconst_5}, {0x09, lconst_0}, {0x0A, lconst_1}, {0x6D, ldiv}, {0x3B, istore_0},
//     {0x3C, istore_1}, {0x3D, istore_2}, {0x3E, istore_3}, {0x3F, lstore_0}, {0x40, lstore_1},
//     {0x41, lstore_2}, {0x42, lstore_3}, {0x1E, lload_0}, {0x1F, lload_1}, {0x20, lload_2},
//     {0x21, lload_3}, {0x1A, iload_0}, {0x1B, iload_1}, {0x1C, iload_2}, {0x1D, iload_3},
//     {0x2E, iaload}, {0x2F, laload}, {0x35, saload}, {0x4F, iastore}, {0x50, lastore},
//     {0x56, sastore}, {0x57, pop}, {0x58, pop2},
//     {0x5F, swap}, {0x60, iadd}, {0x61, ladd}, {0x64, isub},
//     {0x65, lsub}, {0x68, imul}, {0x69, lmul}, {0x18, dload}, {0x19, aload},
//     {0x3A, astore}, {0x10, bipush}, {0x17, fload}, {0x39, dstore},
//     {0xA9, ret}, {0xBC, newarray}, {0x38, fstore}, {0x12, ldc}, {0x15, iload},
//     {0x16, lload}, {0x36, istore}, {0x37, lstore}, {0xA7, _goto},
//     {0xA8, jsr}, {0xB2, getstatic}, {0xB3, putstatic}, {0xB5, putfield},
//     {0xB4, getfield}, {0xB6, invokevirtual}, {0xB7, invokespecial}, {0xB8, invokestatic},
//     {0xBB, _new}, {0xBD, anewarray}, {0xC0, checkcast}, {0xC1, instanceof},
//     {0xC6, ifnull}, {0xC7, ifnonnull}, {0x99, ifeq}, {0x9A, ifne},
//     {0x9B, iflt}, {0x9C, ifge}, {0x9D, ifgt}, {0x9E, ifle}, {0x9F, if_icmpeq},
//     {0xA0, if_icmpne}, {0xA1, if_icmplt}, {0xA2, if_icmpge}, {0xA3, if_icmpgt},
//     {0xA4, if_icmple}, {0xA5, if_acmpeq}, {0xA6, if_acmpne}, {0x6A, fmul},
//     {0x76, fneg}, {0x84, iinc}, {0x11, sipush}, {0x13, ldc_w}, {0x14, ldc2_w},
//     {0xC5, multianewarray}, {0xB9, invokeinterface}, {0xBA, invokedynamic}, {0xC8, goto_w},
//     {0xC9, jsr_w}, {0xAA, tableswitch}, {0xAB, lookupswitch}, {0xC4, wide},
//     {0xCA, break_point},  /* reserved */ {0xFE, impdep_1}, /* reserved */ {0xFF, impdep_2}, /* reserved */
// };

#endif // _BYTECODE_HPP