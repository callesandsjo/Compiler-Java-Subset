#ifndef PARAMETER_H
#define PARAMETER_H

#include "Tac.h"

class Parameter : public Tac
{
public:
    Parameter(std::string _y) : Tac("Parameter", _y, "", "") {}
    void dump() { printf("Param %s\n", getLns().c_str()); }
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        if (isNumber(getLns()))
        {
            *outStream << instructionCounter++ << " iconst " << getLns() << std::endl;
        }
        else
        {
            *outStream << instructionCounter++ << " iload " << getLns() << std::endl;
        }
    }
};
#endif