#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class Expression : public Node
{
public:
    Expression(std::string v) : Node("Expression", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif