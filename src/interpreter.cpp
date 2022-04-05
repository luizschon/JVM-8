#include "../include/interpreter.hpp"
#include "../include/class_file.hpp"
#include "../include/bytecode.hpp"
#include "../include/method_area.hpp"
#include "../include/types.hpp"
#include "../include/utils.hpp"
#include "../include/frame.hpp"
#include "../include/dump_class_file.hpp"
#include "../include/class_loader.hpp"
#include <iostream>
#include <assert.h>

void JVMInterpreter::run(class_file *class_f)
{
    stack_frame stck_frame;

    // Method_Area * method_area = new Method_Area();
    // method_area = load_class_memory(class_file);
    // Frame::set_instructions_functions();

    // Frame* frame = new Frame(find_main(method_area), class_file);
    // frame_stack.push(frame);

    // while (!(frame_stack.empty())) {
    //     frame_stack.top()->execute_frame(); // executa stack frame do topo para baixo
    // }

    // delete(method_area);

    // carrega o method area
    method_area mthd_area = this->load_class(class_f);

    // for (auto i : mthd_area.loaded_classes)
    // {
    //     cout << "M_AREA: " << i.first << endl;
    //     cout << "CONTAINER: " << i.second << endl;
    //     assert(i.second->class_fields != nullptr);
    //     // for (auto j : *i.second->class_fields)
    //     // {
    //     //     // cout << "C_FIELD: " << j.first << endl;
    //     // }
    // }
    
    // for (auto i : mthd_area.static_classes)
    // {
    //     cout << "M_AREA: " << i.first << endl;
    //     cout << "CONTAINER: " << i.second << endl;
    //     for (auto j : *i.second->class_fields)
    //     {
    //         cout << "C_FIELD: " << j.first << endl;
    //     }
    // }

    method_info *m_info = find_main(&mthd_area);

    cout << "NAME INDEX " << hex << m_info->name_idx << endl;
    cout << "DESCRIPTOR INDEX " << m_info->descriptor_idx << endl;
    cout << "ACCESS FLAGS " << m_info->access_flags << endl;
    cout << "ATTRIBUTE COUNT " << m_info->attr_count << endl;

    // itera sobre os metodos do class file ate encontrar a main
    // frame_t frame = frame_t(test, class_f);
    // stck_frame.push(frame);

    // cria um frame com o metodo main

    // da um push no stack frame

    // faz o loop
    // do {
    //     atomically calculate pc and fetch opcode at pc;
    //     if (operands) fetch operands;
    //     execute the action for the opcode;
    // } while (there is more to do);
    // while (!stck_frame.empty())
    // {
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
    // }
}

method_area JVMInterpreter::load_class(class_file *class_f)
{
    cout << "STRING: " << get_name(class_f->constant_pool, class_f->this_class) << endl;
    // cria um novo container para a classe
    class_container* cls_container = new class_container(class_f);
    cls_container->class_fields = NULL;

    // talvez precise converter o nome de u2 para string 
    string cls_name = get_name(class_f->constant_pool, class_f->this_class);
    
    // inicializa o method area
    method_area mthd_area;
    load_class_variables(*cls_container);
    mthd_area.loaded_classes.insert(pair<string, class_container*>(cls_name, cls_container));
    mthd_area.static_classes.insert(pair<string, class_container*>(cls_name, cls_container));

    cout << "END OF LOAD CLASS" << endl;
    return mthd_area;
}

void JVMInterpreter::load_class_variables(class_container &cls_container)
{
    class_file current_class = *cls_container.class_f;
    string super_class_name;

    // fica no loop ate encontrar java/lang/Object
    do {
        auto super_class = to_cp_info(current_class.constant_pool[current_class.super_class - 1])->_class;
        super_class_name = get_name(current_class.constant_pool, current_class.super_class);

        for (int i = 0; i < current_class.fields_count; i++)
        {
            auto field = current_class.fields[i];
            string field_name = get_utf8_content(*to_cp_info(cls_container.class_f->constant_pool[field.name_idx])->_utf8);
            string var_type = get_utf8_content(*to_cp_info(cls_container.class_f->constant_pool[field.descriptor_idx])->_utf8);

            (*cls_container.class_fields)[field_name] = check_string_create_type(var_type);
        }

        if (super_class_name != "java/lang/Object" && super_class_name != "")
            current_class = load_parent_classes(super_class_name);
        cout << "Whiling" << endl;
    } while (super_class_name != "java/lang/Object");
}


operand_t* JVMInterpreter::check_string_create_type(string type_string)
{
    operand_t* new_type = (operand_t* )malloc(sizeof(operand_t));

    switch (type_string.c_str()[0])
    {
    case 'I':
        new_type->tag = CONSTANT_INT; //3
        new_type->int_type = 0;
        break;

    case 'F':
        new_type->tag = CONSTANT_FLOAT; //4
        new_type->float_type = 0;
        break;

    case 'J':
        new_type->tag = CONSTANT_LONG;  //5
        new_type->long_type = 0;
        break;

    case 'D':
        new_type->tag = CONSTANT_DOUBLE;    //6
        new_type->double_type = 0;
        break;

    case 'Z':
        new_type->tag = CONSTANT_BOOL;  //90
        new_type->bool_type = 0;
        break;

    case 'B':
        new_type->tag = CONSTANT_BYTE;  //91
        new_type->byte_type = 0;
        break;

    case 'C':
        new_type->tag = CONSTANT_CHAR;  //92
        new_type->char_type = 0;
        break;

    case 'S':
        new_type->tag = CONSTANT_SHORT; //93
        new_type->short_type = 0;
        break;

    case '[':
        new_type->tag = CONSTANT_ARRAY; //94
        new_type->array_type = new Array_type();
        new_type->array_type->array = {};
        break;

    case 'P':
        new_type->tag = CONSTANT_EMPTY; //0
        break;

        case CONSTANT_STRING:
        new_type->tag = CONSTANT_STRING;    //8
        new_type->string_type = new string("");
        break;

    case 'L': // Tipo Classe
        if (type_string == "Ljava/lang/Integer;")
        {
            new_type->tag = CONSTANT_INT;   //3
            new_type->int_type = 0;
        }
        if (type_string == "Ljava/lang/String;")
        {
            new_type->tag = CONSTANT_STRING;    //8
            new_type->string_type = new string("");
        }
        else 
        {
            new_type->tag = CONSTANT_CLASS; //7
            new_type->class_type = (class_container*) malloc(sizeof(class_container));

            string class_realname = type_string.substr(1, type_string.size());

            class_file class_info = load_parent_classes(class_realname);
            *(new_type->class_type->class_f) = class_info;

            load_class_variables(*new_type->class_type);
        }
        break;
    }
    cout << "Pizza" << endl;
    return new_type; 
}

class_file JVMInterpreter::load_parent_classes(string class_path)
{
    cout << "class_path (load_parent_classes) = " << class_path << endl;

    // verifica se a classe esta no mesmo diretorio atual
    string current_path_folder_inter = "examples/";

    string filepath = current_path_folder_inter + class_path + ".class";
    ClassLoader loader;
    class_file class_f = *loader.load(filepath);
    string class_name = get_name(class_f.constant_pool, class_f.this_class);

    // ??????????????????????????????/ global
    methodArea = load_class(&class_f);
    cout << "This is the end" << endl;
    return class_f;
}

method_info *find_main(method_area *mthd_area)
{ 
    class_file *class_f = mthd_area->loaded_classes.begin()->second->class_f;
    for (int i = 0; i < class_f->methods_count; i++)
    // for (auto method : class_f->methods)
    {
        auto method = class_f->methods[i];
        // method_info *mthd_info;
        string method_name = to_cp_info(class_f->constant_pool[method.name_idx - 1])->_utf8->get_content();
        method_info* temp = &method;
        cout << "method_info: " << method_name << endl;
        if (method_name == "main")
        {
            string method_descriptor = to_cp_info(class_f->constant_pool[method.descriptor_idx - 1])->_utf8->get_content();
            if (method_descriptor == "([Ljava/lang/String;)V")
                return temp;
        }
    }
    return NULL;
}