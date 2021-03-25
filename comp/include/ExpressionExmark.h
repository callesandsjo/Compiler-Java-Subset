#ifndef EXPRESSIONEXMARK_H
#define EXPRESSIONEXMARK_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class ExpressionExmark : public Node
{
public:
    ExpressionExmark(std::string v) : Node("ExpressionExmark", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif