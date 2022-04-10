#include "../../include/instructions/references.hpp"
#include "../../include/utils.hpp"
#include <iostream>
#include <string.h>

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

void putstatic(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void getfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void putfield(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
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

    // string object_class = "java/lang/Object";
    // string string_class = "java/lang/String";
    // string string_class_builder = "java/lang/StringBuilder";
    // string init_method = "<init>";

    // if (((class_name == object_class || class_name == string_class) && method_name == init_method) || 
    // (class_name == string_class_builder && method_name == init_method))
    // {
    //     if (class_name == string_class || class_name == string_class_builder)
    //         top_frame.operand_stack.pop();
    //     else if (method_name == init_method) {
    //         operand_t variable_class = top_frame.local_variables_array.at(0);
    //         load_class_variables(variable_class->class_container);
    //     }
    //     return;
    // }
    // else
    // {
    //     string invoke_type = "special";
    //     class_not_default_java(curr_frame, class_name, method_name, method_desc, invoke_type);
    // }

    // if (class_name.find("java/") != string::npos)
    // {
    //     cout << "Java Class not implemented - Aborting" << endl;
    //     exit(1);
    // }
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

void _new(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{
    auto top_frame = stack_f->top();

    auto indexbyte1 = code[++top_frame.pc];
    auto indexbyte2 = code[++top_frame.pc];
    auto index = (indexbyte1 << 8) | indexbyte2;

    auto class_info = constant_pool[index];
    string class_name = to_cp_info(class_info)->_class->get_content(constant_pool);

    operand_t objectref;

    if (class_name == "java/lang/StringBuilder")
        objectref._string = new string("");
    else //
        objectref._string = new string("L" + class_name);

    top_frame.operand_stack.push(objectref);
    top_frame.pc++;

    stack_f->pop();
    stack_f->push(top_frame);
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

void athrow(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void checkcast(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void instanceof(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void monitorenter(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}

void monitorexit(cp_info_vector &constant_pool, bytestream &code, stack<frame_t> *stack_f)
{

}