#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <map>
#include "Program.h"
#include "Method.h"
class Activation
{
public:
    int pc; //program counter
    std::map<std::string, int> local_variable; // maps all variablename to its value
    Method *method;
    bool debug;
    Activation(int i, Method* m) {method = m; pc = i;}
    void print() {  }
    Instruction *getNextInstruction() {pc++;return method->getInstruction(pc-1);}
    void storeValue(std::string arg, int value) {local_variable[arg] = value;
    if (debug)
            std::cout<<"ISTORE   --> "<< arg <<"=" << value<<std::endl;

    }
    int getValue(std::string s) {return local_variable[s];} 
};
#endif