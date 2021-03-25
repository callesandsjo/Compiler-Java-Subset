#ifndef RETURNTAC_H
#define RETURNTAC_H

#include "Tac.h"

class ReturnTac : public Tac
{
    public:
	ReturnTac(std::string _result) : Tac("Return", "", "", _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        if(isNumber(getResult()) || isBoolString(getResult())) {
             *outStream << instructionCounter++ << " iconst " << getResult() << std::endl;
        }
        else if(isBoolString(getResult())) {
                 *outStream << instructionCounter++ << " iconst " << (getResult()=="true"? 1 : 0) << std::endl;
        } else {
            *outStream << instructionCounter++ << " iload " << getResult() << std::endl;
        }
        *outStream << instructionCounter++ << " ireturn " << std::endl;
    }
};
#endif