#ifndef _BYTECODE_HPP
#define _BYTECODE_HPP

#include "constant_pool_info.hpp"
#include "types.hpp"
#include "frame.hpp"
#include <functional>
#include <map>

#include <iostream>

// Instructions implementation
void aaload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aaload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void nop             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aconst_null     (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_m1       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_4        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iconst_5        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lconst_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lconst_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fconst_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fconst_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fconst_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dconst_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dconst_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void bipush          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void sipush          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ldc             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ldc_w           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ldc2_w          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iload           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lload           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fload           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dload           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aload           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iload_0         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iload_1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iload_2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iload_3         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lload_0         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lload_1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lload_2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lload_3         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fload_0         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fload_1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fload_2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fload_3         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dload_0         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dload_1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dload_2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dload_3         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aload_0         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aload_1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aload_2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aload_3         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iaload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void laload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void faload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void daload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void baload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void caload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void saload          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void istore          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lstore          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fstore          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dstore          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void astore          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void istore_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void istore_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void istore_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void istore_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lstore_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lstore_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lstore_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lstore_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fstore_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fstore_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fstore_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fstore_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dstore_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dstore_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dstore_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dstore_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void astore_0        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void astore_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void astore_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void astore_3        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void aastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void bastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void castore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void sastore         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void pop             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void pop2            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup_x1          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup_x2          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup2            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup2_x1         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dup2_x2         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void swap            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iadd            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ladd            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fadd            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dadd            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void isub            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lsub            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fsub            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dsub            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void imul            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lmul            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fmul            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dmul            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void idiv            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ldiv            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fdiv            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ddiv            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void irem            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lrem            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void frem            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void drem            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ineg            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lneg            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fneg            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dneg            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ishl            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lshl            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ishr            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lshr            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iushr           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lushr           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iand            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void land            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ior             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lor             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ixor            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lxor            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iinc            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2l             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2f             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2d             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void l2i             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void l2f             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void l2d             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void f2i             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void f2l             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void f2d             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void d2i             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void d2l             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void d2f             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2b             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2c             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void i2s             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lcmp            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fcmpl           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void fcmpg           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dcmpl           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dcmpg           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifeq            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifne            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void iflt            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifge            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifgt            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifle            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmpeq       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmpne       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmplt       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmpge       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmpgt       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_icmple       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_acmpeq       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void if_acmpne       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void _goto           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void jsr             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ret             (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void tableswitch     (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lookupswitch    (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ireturn         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void lreturn         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void freturn         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void dreturn         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void areturn         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void _return         (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void getstatic       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void putstatic       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void getfield        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void putfield        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void invokevirtual   (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void invokespecial   (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void invokestatic    (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void invokeinterface (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void invokedynamic   (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void _new            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void newarray        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void anewarray       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void arraylength     (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void athrow          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void checkcast       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void instanceof      (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void monitorenter    (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void monitorexit     (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void wide            (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void multianewarray  (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifnull          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void ifnonnull       (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void goto_w          (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void jsr_w           (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);

// reserved
void break_point     (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void impdep_1        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);
void impdep_2        (cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f);

// Debug Instructions
void bipush_debug         (int&, cp_info_vector&, bytestream&);
void iinc_debug           (int&, cp_info_vector&, bytestream&);
void iinc_wide_debug      (int&, cp_info_vector&, bytestream&);
void invoke_debug         (int&, cp_info_vector&, bytestream&);
void jump_debug           (int&, cp_info_vector&, bytestream&);
void jump_wide_debug      (int&, cp_info_vector&, bytestream&);
void index_debug          (int&, cp_info_vector&, bytestream&);
void index_wide_debug     (int&, cp_info_vector&, bytestream&);
void lookupswitch_debug   (int&, cp_info_vector&, bytestream&);
void multianewarray_debug (int&, cp_info_vector&, bytestream&);
void newarray_debug       (int&, cp_info_vector&, bytestream&);
void reference_debug      (int&, cp_info_vector&, bytestream&);
void reference_wide_debug (int&, cp_info_vector&, bytestream&);
void sipush_debug         (int&, cp_info_vector&, bytestream&);
void tableswitch_debug    (int&, cp_info_vector&, bytestream&);
void wide_debug           (int&, cp_info_vector&, bytestream&);

typedef map<u1, string> mnemonic_map;

const mnemonic_map mnemonic = {
    {0x00, "nop"},             {0x01, "aconst_null"},     {0x02, "iconst_m1"},     {0x03, "iconst_0"},
    {0x04, "iconst_1"},        {0x05, "iconst_2"},        {0x06, "iconst_3"},      {0x07, "iconst_4"}, 
    {0x08, "iconst_5"},        {0x09, "lconst_0"},        {0x0A, "lconst_1"},      {0x0B, "fconst_0"},
    {0x0C, "fconst_1"},        {0x0D, "fconst_2"},        {0x0E, "dconst_0"},      {0x0F, "dconst_1"},
    {0x10, "bipush"},          {0x11, "sipush"} ,         {0x12, "ldc"},           {0x13, "ldc_w"},
    {0x14, "ldc2_w"},          {0x15, "iload"},           {0x16, "lload"},         {0x17, "fload"},
    {0x18, "dload"},           {0x19, "aload"},           {0x1A, "iload_0"},       {0x1B, "iload_1"}, 
    {0x1C, "iload_2"},         {0x1D, "iload_3"},         {0x1E, "lload_0"},       {0x1F, "lload_1"},    
    {0x20, "lload_2"},         {0x21, "lload_3"},         {0x22, "fload_0"},       {0x23, "fload_1"},              
    {0x24, "fload_2"},         {0x25, "fload_3"},         {0x26, "dload_0"},       {0x27, "dload_1"},    
    {0x28, "dload_2"},         {0x29, "dload_3"},         {0x2A, "aload_0"},       {0x2B, "aload_1"},
    {0x2C, "aload_2"},         {0x2D, "aload_3"},         {0x2E, "iaload"},        {0x2F, "laload"},
    {0x30, "faload"},          {0x31, "daload"},          {0x32, "aaload"},        {0x33, "baload"},   
    {0x34, "caload"},          {0x35, "saload"},          {0x36, "istore"},        {0x37, "lstore"},   
    {0x38, "fstore"},          {0x39, "dstore"},          {0x3A, "astore"},        {0x3B, "istore_0"},
    {0x3C, "istore_1"},        {0x3D, "istore_2"},        {0x3E, "istore_3"},      {0x3F, "lstore_0"},
    {0x40, "lstore_1"},        {0x41, "lstore_2"},        {0x42, "lstore_3"},      {0x43, "fstore_0"},
    {0x44, "fstore_1"},        {0x45, "fstore_2"},        {0x46, "fstore_3"},      {0x47, "dstore_0"},
    {0x48, "dstore_1"},        {0x49, "dstore_2"},        {0x4A, "dstore_3"},      {0x4B, "astore_0"}, 
    {0x4C, "astore_1"},        {0x4D, "astore_2"},        {0x4E, "astore_3"},      {0x4F, "iastore"},
    {0x50, "lastore"},         {0x51, "fastore"},         {0x52, "dastore"},       {0x53, "aastore"},
    {0x54, "bastore"},         {0x55, "castore"},         {0x56, "sastore"},       {0x57, "pop"},
    {0x58, "pop2"},            {0x59, "dup"},             {0x5A, "dup_x1"},        {0x5B, "dup_x2"},
    {0x5C, "dup2"},            {0x5D, "dup2_x1"},         {0x5E, "dup2_x2"},       {0x5F, "swap"},
    {0x60, "iadd"},            {0x61, "ladd"},            {0x62, "fadd"},          {0x63, "dadd"},
    {0x64, "isub"},            {0x65, "lsub"},            {0x66, "fsub"},          {0x67, "dsub"},              
    {0x68, "imul"},            {0x69, "lmul"},            {0x6A, "fmul"},          {0x6B, "dmul"},
    {0x6C, "idiv"},            {0x6D, "ldiv"},            {0x6E, "fdiv"},          {0x6F, "ddiv"},
    {0x70, "irem"},            {0x71, "lrem"},            {0x72, "frem"},          {0x73, "drem"},
    {0x74, "ineg"},            {0x75, "lneg"},            {0x76, "fneg"},          {0x77, "dneg"},
    {0x78, "ishl"},            {0x79, "lshl"},            {0x7A, "ishr"},          {0x7B, "lshr"},
    {0x7C, "iushr"},           {0x7D, "lushr"},           {0x7E, "iand"},          {0x7F, "land"},          
    {0x80, "ior"},             {0x81, "lor"},             {0x82, "ixor"},          {0x83, "lxor"},          
    {0x84, "iinc"},            {0x85, "i2l"},             {0x86, "i2f"},           {0x87, "i2d"},           
    {0x88, "l2i"},             {0x89, "l2f"},             {0x8A, "l2d"},           {0x8B, "f2i"},           
    {0x8C, "f2l"},             {0x8D, "f2d"},             {0x8E, "d2i"},           {0x8F, "d2l"},           
    {0x90, "d2f"},             {0x91, "i2b"},             {0x92, "i2c"},           {0x93, "i2s"},           
    {0x94, "lcmp"},            {0x95, "fcmpl"},           {0x96, "fcmpg"},         {0x97, "dcmpl"},         
    {0x98, "dcmpg"},           {0x99, "ifeq"},            {0x9A, "ifne"},          {0x9B, "iflt"},          
    {0x9C, "ifge"},            {0x9D, "ifgt"},            {0x9E, "ifle"},          {0x9F, "if_icmpeq"},     
    {0xA0, "if_icmpne"},       {0xA1, "if_icmplt"},       {0xA2, "if_icmpge"},     {0xA3, "if_icmpgt"},     
    {0xA4, "if_icmple"},       {0xA5, "if_acmpeq"},       {0xA6, "if_acmpne"},     {0xA7, "goto"},         
    {0xA8, "jsr"},             {0xA9, "ret"},             {0xAA, "tableswitch"},   {0xAB, "lookupswitch"},  
    {0xAC, "ireturn"},         {0xAD, "lreturn"},         {0xAE, "freturn"},       {0xAF, "dreturn"},       
    {0xB0, "areturn"},         {0xB1, "return"},          {0xB2, "getstatic"},     {0xB3, "putstatic"},     
    {0xB4, "getfield"},        {0xB5, "putfield"},        {0xB6, "invokevirtual"}, {0xB7, "invokespecial"}, 
    {0xB8, "invokestatic"},    {0xB9, "invokeinterface"}, {0xBA, "invokedynamic"}, {0xBB, "new"},          
    {0xBC, "newarray"},        {0xBD, "anewarray"},       {0xBE, "arraylength"},   {0xBF, "athrow"},        
    {0xC0, "checkcast"},       {0xC1, "instanceof"},      {0xC2, "monitorenter"},  {0xC3, "monitorexit"},   
    {0xC4, "wide"},            {0xC5, "multianewarray"},  {0xC6, "ifnull"},        {0xC7, "ifnonnull"},     
    {0xC8, "goto_w"},          {0xC9, "jsr_w"},
    // reserved
    {0xCA, "break_point"},      
    {0xFE, "impdep_1"},
    {0xFF, "impdep_2"}
};

typedef map<u1, function<void(int&, cp_info_vector&, bytestream&)>> bytecode_map;

const bytecode_map debug = {
    {0x18, index_debug},           // dload
    {0x19, index_debug},           // aload
    {0x3A, index_debug},           // astore
    {0x10, bipush_debug},          // bipush
    {0x17, index_debug},           // fload
    {0x39, index_debug},           // dstore
    {0xA9, index_debug},           // ret
    {0xBC, newarray_debug},        // new_array
    {0x38, index_debug},           // fstore
    {0x12, reference_debug},       // ldc
    {0x15, index_debug},           // iload
    {0x16, index_debug},           // lload
    {0x36, index_debug},           // istore
    {0x37, index_debug},           // lstore
    {0xA7, jump_debug},            // goto
    {0xA8, jump_debug},            // jsr
    {0xB2, reference_wide_debug},  // getstatic
    {0xB3, reference_wide_debug},  // putstatic
    {0xB4, reference_wide_debug},  // getfield
    {0xB5, reference_wide_debug},  // putfield
    {0xB6, reference_wide_debug},  // invokevirtual
    {0xB7, reference_wide_debug},  // invokespecial
    {0xB8, reference_wide_debug},  // invokestatic
    {0xBB, reference_wide_debug},  // new
    {0xBD, reference_wide_debug},  // anewarray
    {0xC0, reference_wide_debug},  // checkcast
    {0xC1, reference_wide_debug},  // instanceof
    {0xC6, jump_debug},            // ifnull
    {0xC7, jump_debug},            // ifnonnull
    {0x99, jump_debug},            // ifeq
    {0x9A, jump_debug},            // ifne
    {0x9B, jump_debug},            // iflt
    {0x9C, jump_debug},            // ifge
    {0x9D, jump_debug},            // ifgt
    {0x9E, jump_debug},            // ifle
    {0x9F, jump_debug},            // if_icmpeq
    {0xA0, jump_debug},            // if_icmpne
    {0xA1, jump_debug},            // if_icmplt
    {0xA2, jump_debug},            // if_icmpge
    {0xA3, jump_debug},            // if_icmpgt
    {0xA4, jump_debug},            // if_icmple
    {0xA5, jump_debug},            // if_acmpeq
    {0xA6, jump_debug},            // if_acmpne
    {0x84, iinc_debug},            // iinc
    {0x11, sipush_debug},          // sipush
    {0x13, reference_wide_debug},  // ldc_w
    {0x14, reference_wide_debug},  // ldc2_w
    {0xC5, multianewarray_debug},  // miltianewarray
    {0xB9, invoke_debug},          // invokeinterface
    {0xBA, invoke_debug},          // invokedynamic
    {0xC8, jump_wide_debug},       // goto_w
    {0xC9, jump_wide_debug},       // jsr_w
    {0xAA, tableswitch_debug},     // tableswitch
    {0xAB, lookupswitch_debug},    // lookupswitch
    {0xC4, wide_debug}             // wide
};

typedef map<u1, function<void(cp_info_vector&, bytestream&, stack<frame_t>*)>> bytecode_instr;

// TODO: fix swap and ldiv
const bytecode_instr bytecodes = {
    {0x00, nop},             {0x01, aconst_null},     {0x02, iconst_m1},     {0x03, iconst_0},
    {0x04, iconst_1},        {0x05, iconst_2},        {0x06, iconst_3},      {0x07, iconst_4}, 
    {0x08, iconst_5},        {0x09, lconst_0},        {0x0A, lconst_1},      {0x0B, fconst_0},
    {0x0C, fconst_1},        {0x0D, fconst_2},        {0x0E, dconst_0},      {0x0F, dconst_1},
    {0x10, bipush},          {0x11, sipush} ,         {0x12, ldc},           {0x13, ldc_w},
    {0x14, ldc2_w},          {0x15, iload},           {0x16, lload},         {0x17, fload},
    {0x18, dload},           {0x19, aload},           {0x1A, iload_0},       {0x1B, iload_1}, 
    {0x1C, iload_2},         {0x1D, iload_3},         {0x1E, lload_0},       {0x1F, lload_1},    
    {0x20, lload_2},         {0x21, lload_3},         {0x22, fload_0},       {0x23, fload_1},              
    {0x24, fload_2},         {0x25, fload_3},         {0x26, dload_0},       {0x27, dload_1},    
    {0x28, dload_2},         {0x29, dload_3},         {0x2A, aload_0},       {0x2B, aload_1},
    {0x2C, aload_2},         {0x2D, aload_3},         {0x2E, iaload},        {0x2F, laload},
    {0x30, faload},          {0x31, daload},          {0x32, aaload},        {0x33, baload},   
    {0x34, caload},          {0x35, saload},          {0x36, istore},        {0x37, lstore},   
    {0x38, fstore},          {0x39, dstore},          {0x3A, astore},        {0x3B, istore_0},
    {0x3C, istore_1},        {0x3D, istore_2},        {0x3E, istore_3},      {0x3F, lstore_0},
    {0x40, lstore_1},        {0x41, lstore_2},        {0x42, lstore_3},      {0x43, fstore_0},
    {0x44, fstore_1},        {0x45, fstore_2},        {0x46, fstore_3},      {0x47, dstore_0},
    {0x48, dstore_1},        {0x49, dstore_2},        {0x4A, dstore_3},      {0x4B, astore_0}, 
    {0x4C, astore_1},        {0x4D, astore_2},        {0x4E, astore_3},      {0x4F, iastore},
    {0x50, lastore},         {0x51, fastore},         {0x52, dastore},       {0x53, aastore},
    {0x54, bastore},         {0x55, castore},         {0x56, sastore},       {0x57, pop},
    {0x58, pop2},            {0x59, dup},             {0x5A, dup_x1},        {0x5B, dup_x2},
    {0x5C, dup2},            {0x5D, dup2_x1},         {0x5E, dup2_x2},       /*{0x5F, swap},*/
    {0x60, iadd},            {0x61, ladd},            {0x62, fadd},          {0x63, dadd},
    {0x64, isub},            {0x65, lsub},            {0x66, fsub},          {0x67, dsub},              
    {0x68, imul},            {0x69, lmul},            {0x6A, fmul},          {0x6B, dmul},
    {0x6C, idiv},            /*{0x6D, ldiv},*/            {0x6E, fdiv},          {0x6F, ddiv},
    {0x70, irem},            {0x71, lrem},            {0x72, frem},          {0x73, drem},
    {0x74, ineg},            {0x75, lneg},            {0x76, fneg},          {0x77, dneg},
    {0x78, ishl},            {0x79, lshl},            {0x7A, ishr},          {0x7B, lshr},
    {0x7C, iushr},           {0x7D, lushr},           {0x7E, iand},          {0x7F, land},          
    {0x80, ior},             {0x81, lor},             {0x82, ixor},          {0x83, lxor},          
    {0x84, iinc},            {0x85, i2l},             {0x86, i2f},           {0x87, i2d},           
    {0x88, l2i},             {0x89, l2f},             {0x8A, l2d},           {0x8B, f2i},           
    {0x8C, f2l},             {0x8D, f2d},             {0x8E, d2i},           {0x8F, d2l},           
    {0x90, d2f},             {0x91, i2b},             {0x92, i2c},           {0x93, i2s},           
    {0x94, lcmp},            {0x95, fcmpl},           {0x96, fcmpg},         {0x97, dcmpl},         
    {0x98, dcmpg},           {0x99, ifeq},            {0x9A, ifne},          {0x9B, iflt},          
    {0x9C, ifge},            {0x9D, ifgt},            {0x9E, ifle},          {0x9F, if_icmpeq},     
    {0xA0, if_icmpne},       {0xA1, if_icmplt},       {0xA2, if_icmpge},     {0xA3, if_icmpgt},     
    {0xA4, if_icmple},       {0xA5, if_acmpeq},       {0xA6, if_acmpne},     {0xA7, _goto},         
    {0xA8, jsr},             {0xA9, ret},             {0xAA, tableswitch},   {0xAB, lookupswitch},  
    {0xAC, ireturn},         {0xAD, lreturn},         {0xAE, freturn},       {0xAF, dreturn},       
    {0xB0, areturn},         {0xB1, _return},          {0xB2, getstatic},     {0xB3, putstatic},     
    {0xB4, getfield},        {0xB5, putfield},        {0xB6, invokevirtual}, {0xB7, invokespecial}, 
    {0xB8, invokestatic},    {0xB9, invokeinterface}, {0xBA, invokedynamic}, {0xBB, _new},          
    {0xBC, newarray},        {0xBD, anewarray},       {0xBE, arraylength},   {0xBF, athrow},        
    {0xC0, checkcast},       {0xC1, instanceof},      {0xC2, monitorenter},  {0xC3, monitorexit},   
    {0xC4, wide},            {0xC5, multianewarray},  {0xC6, ifnull},        {0xC7, ifnonnull},     
    {0xC8, goto_w},          {0xC9, jsr_w},
    // reserved
    {0xCA, break_point},      
    {0xFE, impdep_1},
    {0xFF, impdep_2}
};

#endif // _BYTECODE_HPP