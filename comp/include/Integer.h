#ifndef INTEGER_H
#define INTEGER_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class Integer : public Node
{
public:
    Integer(std::string v) : Node("Integer", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif