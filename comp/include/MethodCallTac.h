#ifndef METHODCALLTAC_H
#define METHODCALLTAC_H

#include "Tac.h"

class MethodCallTac : public Tac
{
public:
    MethodCallTac(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    void dump() { printf("%s := call %s %s\n", getResult().c_str(), getLns().c_str(), getRns().c_str()); }
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " invokevirtual " << getLns() << std::endl;
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
};
#endif