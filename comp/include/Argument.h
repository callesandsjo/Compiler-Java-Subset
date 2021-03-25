#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "Tac.h"

class Argument : public Tac
{
    public:
	Argument(std::string _result) : Tac("Arg", "", "", _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
};
#endif