#ifndef EXPRESSIONNEW_H
#define EXPRESSIONNEW_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class ExpressionNew : public Node
{
    public:
        ExpressionNew(std::string v): Node("ExpressionNew",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif