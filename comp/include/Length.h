#ifndef LENGTH_H
#define LENGTH_H

#include "Tac.h"

class Length : public Tac
{
public:
    Length(std::string _y, std::string _result) : Tac("Length", "", _y, _result) {}
    void dump() { printf("%s := length %s\n", getResult().c_str(), getRns().c_str()); }
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        // it will not be used due to we disregard identifier and array types (assig3)
    }
};
#endif