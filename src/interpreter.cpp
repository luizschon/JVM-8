#include "../include/interpreter.hpp"

void execute(class_file &class_f, bytestream &code)
{
    stack_frame stack_frame;
    u8 pc = 0;
    while (!stack_frame.empty())
    {
        // executes instructions starting from 0 
        u1 opcode = code[pc];
        if (bytecodes.count(opcode))
        {
            auto execute_instr = bytecodes.at(opcode);
            execute_instr(pc, class_f.constant_pool, code, stack_frame);
        }
        else 
            cout << "Instruction Not Found" << endl;
    }

    cout << "Iniciando Execucao" << endl;
}