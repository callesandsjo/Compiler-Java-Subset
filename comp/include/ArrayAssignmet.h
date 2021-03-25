#ifndef ARRAYASSIGNMENT_H
#define ARRAYASSIGNMENT_H

#include "Tac.h"

class ArrayAssignment : public Tac
{
public:
    ArrayAssignment(std::string _x, std::string _i, std::string _y) : Tac("Array assignment", _x, _i, _y) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        // it will not be used due to we disregard identifier and array types (assig3)
    }
};
#endif