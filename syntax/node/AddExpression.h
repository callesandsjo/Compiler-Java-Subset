#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "../Node.h"
#include "../tac/Tac.h"
#include "../tac/Assignment.h"
#include "../BBlock.h"

class AddExpression : public Node
{
    public:
    AddExpression(std::string v): Node("AddExpression",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    std::string genIR(BBlock *currblock);
};
#endif