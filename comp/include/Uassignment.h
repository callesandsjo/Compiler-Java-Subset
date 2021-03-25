#ifndef UASSIGNMENT_H
#define UASSIGNMENT_H

#include "Tac.h"

class Uassignment : public Tac
{
public:
    Uassignment(std::string _op, std::string _rns, std::string _result) : Tac(_op, "", _rns, _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " iload " << getLns() << std::endl;
        *outStream << instructionCounter++ << " inot " << std::endl;
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
};
#endif