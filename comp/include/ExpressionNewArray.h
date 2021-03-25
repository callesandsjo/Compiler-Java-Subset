#ifndef EXPRESSIONNEWARRAY_H
#define EXPRESSIONNEWARRAY_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class ExpressionNewArray : public Node
{
public:
    ExpressionNewArray(std::string v) : Node("ExpressionNewArray", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif