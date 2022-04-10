#include "../../include/instructions/references.hpp"
#include "../../include/utils.hpp"
#include <iostream>
#include <string.h>

/// TODO: finish getstatic
void getstatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    // auto top_frame = stack_f->top();
    // u1 indexbyte1 = code[++top_frame.pc];
    // u1 indexbyte2 = code[++top_frame.pc];
    // u2 index = ((u2)indexbyte1 << 8) | indexbyte2;

    // auto reference = to_cp_info(constant_pool[index - 1]);
    // string class_name = reference->get_content(constant_pool);

    // cout << "[GETSTATIC] Class name: " << class_name << endl;

    // top_frame.pc++;
    // stack_f->pop();
    // stack_f->push(top_frame);

    // // se for a classe default do Java: System -> nao empilhar
    // if (class_name == "java/lang/System"){
    //     top_frame.pc++;
    //     return;
    // }

    auto top_frame = stack_f->top();
    u1 indexbyte1 = code[++top_frame.pc];
    u1 indexbyte2 = code[++top_frame.pc];
    u2 index = ((u2)indexbyte1 << 8) | indexbyte2;

    auto reference = to_cp_info(constant_pool[index-1]);

    if (!reference)
    {
        cout << "Doesn't exist data in index: " << endl;
        return;
    }

    if (reference->tag != 9) // TAG_REF_CMP
    {
        cout << "It's not possible access a static field with wrong reference" << endl;
        return;
    }

    string class_name = reference->get_content(constant_pool);

    cout << "[GETSTATIC] Class name: " << class_name << endl;

    if(class_name != "java/lang/System")
    {
        cout << "As 'java/lang/System', doesn't need" << endl;
        top_frame.pc++;
        stack_f->pop();
        stack_f->push(top_frame);
        return;
    }
    top_frame.pc++;
    stack_f->pop();
    stack_f->push(top_frame);
}

void putstatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void getfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void putfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

//! TODO: finish invokevirtual
void invokevirtual(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    auto methodref = to_cp_info(constant_pool[index - 1]);

    top_frame.pc++;

    if (!methodref)
    {
        cout << "Doesn't exist data in index: " << endl;
        return;
    }

    if (methodref->tag != 10)
    {
        cout << "It's not possible access a static field with wrong reference" << endl;
        return;
    }

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
            }
        }
    }

    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[INVOKE_VIRTUAL] index: " << (u4) index << endl;
}

//! TODO: finish
void invokespecial(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
	auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

	auto method_ref = constant_pool[index];
	auto name_and_type = constant_pool[to_cp_info(method_ref)->_methodref->name_and_type_idx - 1];

    string class_name = to_cp_info(method_ref)->_methodref->get_class_name(constant_pool);
    string method_name = to_cp_info(name_and_type)->_name_and_type->get_name(constant_pool);
    string method_desc = to_cp_info(name_and_type)->_name_and_type->get_descriptor(constant_pool);
}

//! TODO: finish invokestatic
void invokestatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();
    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    top_frame.pc++;
    
    stack_f->pop();
    stack_f->push(top_frame);

    cout << "[INVOKESTATIC] index: " << (u4) index << endl;
    exit(1);
}

void invokeinterface(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void invokedynamic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

//! TODO: fix new
void _new(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    cout << "_NEW: instructions/references/_new" << endl;
    exit(1);
    auto top_frame = stack_f->top();

    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    auto class_info = constant_pool[index];
    string class_name = to_cp_info(class_info)->_class->get_content(constant_pool);

    operand_t objectref;

    if (class_name == "java/lang/StringBuilder")
        objectref._string = new string("");
    else
        objectref._string = new string("L" + class_name);

    top_frame.operand_stack.push(objectref);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
}

void newarray(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void anewarray(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void arraylength(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void athrow(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void checkcast(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void instanceof(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void monitorenter(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}

void monitorexit(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    exit(1);
}