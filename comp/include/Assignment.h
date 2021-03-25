#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Tac.h"

class Assignment : public Tac
{
public:
    Assignment(std::string _op, std::string _lns, std::string _rns, std::string _result) : Tac(_op, _lns, _rns, _result) {}
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        if (getOp() == "System.print")
        {
            *outStream << instructionCounter++ << " iload " << getLns() << std::endl;
            *outStream << instructionCounter++ << getInstruction(getOp()) << std::endl;
            return;
        }
        if (isNumber(getLns()))
        {
            *outStream << instructionCounter++ << " iconst " << getLns() << std::endl;
        }
        else
        {
            *outStream << instructionCounter++ << " iload " << getLns() << std::endl;
        }
        if (isNumber(getRns()))
        {
            *outStream << instructionCounter++ << " iconst " << getRns() << std::endl;
        }
        else
        {
            *outStream << instructionCounter++ << " iload " << getRns() << std::endl;
        }
        *outStream << instructionCounter++ << getInstruction(getOp()) << std::endl;
        *outStream << instructionCounter++ << " istore " << getResult() << std::endl;
    }
    std::string getInstruction(std::string op)
    {
        if (op == "+")
        {
            return " iadd ";
        }
        if (op == "-")
        {
            return " isub ";
        }
        if (op == "*")
        {
            return " imul ";
        }
        if (op == "LessThan")
        {
            return " ilt ";
        }
        if (op == "System.print")
        {
            return " print ";
        }
         if (op == "AND")
        {
            return " iand ";
        }
        return "";
    }
};
#endif