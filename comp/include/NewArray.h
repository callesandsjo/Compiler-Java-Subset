#ifndef NEWARRAY_H
#define NEWARRAY_H

#include "Tac.h"

class NewArray : public Tac
{
    public:
	NewArray(std::string _N, std::string _type, std::string _result) : Tac("NEW ARRAY", _N, _type, _result) {}
    void dump() {printf("%s := %s %s, %s\n", getResult().c_str(), getOp().c_str(), getRns().c_str(), getLns().c_str());}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        // generating fake address, it will not be used due to we disregard identifier types (assig3)
        *outStream << instructionCounter++ << " iconst " << 50000 + instructionCounter << std::endl;
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
};
#endif