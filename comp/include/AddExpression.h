#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class AddExpression : public Node
{
    public:
    AddExpression(std::string v): Node("AddExpression",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif