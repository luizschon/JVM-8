#include "../include/interpreter.hpp"
#include "../include/bytecode.hpp"
#include "../include/method_area.hpp"
#include <iostream>

void JVMInterpreter::run(class_file &class_f)
{
    stack_frame stck_frame;

    // carrega o method area
    method_area mthd_area = this->load_class(class_f);

    // itera sobre os metodos do class file ate encontrar a main

    // cria um frame com o metodo main

    // da um push no stack frame

    // faz o loop
    // do {
    //     atomically calculate pc and fetch opcode at pc;
    //     if (operands) fetch operands;
    //     execute the action for the opcode;
    // } while (there is more to do);
    while (!stck_frame.empty())
    {
        // executes instructions starting from 0 
        // u1 opcode = code[this->pc];
        // if (bytecodes.count(opcode))
        // {
        //     stck_frame.top().execute_instr(class_file &, bytestream &);
        //     auto execute_opcode = bytecodes.at(opcode);
        //     execute_opcode(pc, class_f.constant_pool, code, stck_frame);
        // }
        // else 
        //     cout << "Instruction Not Found" << endl;
    }
}

method_area JVMInterpreter::load_class(class_file &class_f)
{
    // cria um novo container para a classe
    class_container* cls_container;
    cls_container->class_f = class_f;
    cls_container->class_fields = NULL;

    // talvez precise converter o nome de u2 para string 
    auto cls_name = class_f.this_class;
    
    // inicializa o method area
    method_area mthd_area;
    mthd_area.loaded_classes.insert(pair<u2, class_container*>(cls_name, cls_container));
    mthd_area.static_classes.insert(pair<u2, class_container*>(cls_name, cls_container));

    load_class_variables(*cls_container);

    return mthd_area;
}

void JVMInterpreter::load_class_variables(class_container &cls_container)
{
    class_file current_class = cls_container.class_f;
    auto super_class = current_class.constant_pool[current_class.super_class];
    auto super_class_name = current_class.super_class;

    // fica no loop ate encontrar java/lang/Object
    // do {
    //     auto super_class_name = current_class.super_class;
    //     for (auto field : current_class.fields)
    //     {
    //         auto field_name = field.name_idx;
    //         auto var_type = field.descriptor_idx;

    //         (*class_container->class_fields)[field_name] = check_string_create_type(var_type);
    //     }

    //     if (super_class_name != "java/lang/Object" && super_class_name != "") {
    //         current_class = load_parent_classes(super_class_name);
    //     }

    // } while (super_class_name != "java/lang/Object");
}