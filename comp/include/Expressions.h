#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class Expressions : public Node
{
public:
    Expressions(std::string v) : Node("Expressions", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif