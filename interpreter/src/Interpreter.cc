#include "Interpreter.h"
#include "Activation.h"
#include <stack>
#include "Instruction.h"
#include <iostream>

void Interpreter::execute()
{
    Method *m = main;
    Activation *current_activation = new Activation(0, m);
    current_activation->debug=debug;
    int instruction_id = -1;
    std::stack<Activation*> activations_stack;

    Instruction *instruction;
    Activation * tmpAct;
    Method* tMethod;
    int val;
    int val2;
    while (instruction_id != STOP)
    {
        instruction = current_activation->getNextInstruction();
         if (debug)
         {
            std::cout<<"Executing   --> "; instruction->print();
            }
        switch (instruction->getInstructionId())
        {
        case GOTO :
            current_activation->pc = atoi(instruction->argument.c_str());
            break;
        case IADD :
            data_stack.push(data_pop() + data_pop());
            break;
        case IAND :
            data_stack.push(data_pop() * data_pop() == 0 ? 0 : 1); 
            break;
        case ICONST :
            data_stack.push(atoi(instruction->argument.c_str()));
            break;
        case IFFALSEGOTO :
            if (data_pop() == 0) 
            {
                current_activation->pc = atoi(instruction->argument.c_str()); 
            }
            break;
        case ILOAD :
            val=current_activation->getValue(instruction->argument);
            if (debug)
                std::cout<<"ILOAD   --> "<< val << std::endl;
            data_stack.push(current_activation->getValue(instruction->argument));
            break;
        
        case ILT :
            data_stack.push(data_pop() > data_pop() ? 1 : 0); 
            break;
        
        case IMUL :
            data_stack.push(data_pop() * data_pop());
            break;
        
        case INOT :
            data_stack.push(data_pop() == 0 ? 1 : 0); 
            break;
        
        case INVOKEVIRTUAL :
            activations_stack.push(current_activation);
            tMethod = program->getMethod(instruction->argument);
            current_activation = new Activation(0, tMethod);
            current_activation->debug=debug;
            break;
        
        case IRETURN :
            tmpAct = activations_stack.top();
            activations_stack.pop();
            delete current_activation;
            current_activation=tmpAct;
            break;
        
        case ISTORE :
            current_activation->storeValue(instruction->argument, data_pop());
            break;
        
        case ISUB :
            val=data_pop();
            val2=data_pop();
            data_stack.push( val2 - val);
            break;
        
        case PRINT :
            std::cout << data_pop() << std::endl;
            break;
        case STOP :
            return;
            break;
        
        default:
            break;
        }
    }
    
}