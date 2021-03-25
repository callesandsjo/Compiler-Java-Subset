#ifndef METHOD_H
#define METHOD_H

#include "Instruction.h"
#include <list>
#include <vector>
#include <map>
class Method
{
public:
    std::vector<Instruction*> instructions;
    std::map<std::string, int> variables;
    bool isStart;
    std::string name;
    bool debug;
    Method(): isStart(false){}
    void print() {
        for (auto a : instructions)
        {
         a->print();
        }
   }
    Instruction *getInstruction(int i) {return instructions[i];}

};
#endif