#ifndef RETURNTAC_H
#define RETURNTAC_H

#include "Tac.h"

class ReturnTac : public Tac
{
    public:
	ReturnTac(std::string _result) : Tac("Return", "", "", _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " iload " << getResult() << std::endl;
        *outStream << instructionCounter++ << " ireturn " << std::endl;
    }
};
#endif