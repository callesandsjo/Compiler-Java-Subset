#ifndef JUMP_H
#define JUMP_H

#include "Tac.h"

class Jump : public Tac
{
public:
    Jump(std::string _label) : Tac("goto", "", "", _label) {}
    void dump() { printf("goto %s\n", getResult().c_str()); }
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " goto " << getResult() << std::endl;
    }
};
#endif