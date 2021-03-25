#ifndef COPY_H
#define COPY_H

#include "Tac.h"

#include <cctype>
#include <iostream>
#include <cstring>

class Copy : public Tac
{
public:
    Copy(std::string _lns, std::string _result) : Tac("Copy", _lns, "", _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        if (isNumber(getLns()))
        {
            *outStream << instructionCounter++ << " iconst " << getLns() << std::endl;
        }
        else if (isBoolString(getLns()))
        {
            *outStream << instructionCounter++ << " iconst " << (getLns() == "false" ? 0 : 1)<< std::endl;
        }
        else
        {
            *outStream << instructionCounter++ << " iload " << getLns() << std::endl;
        }
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
};
#endif