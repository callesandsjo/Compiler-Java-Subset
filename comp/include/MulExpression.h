#ifndef MULEXPRESSION_H
#define MULEXPRESSION_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class MulExpression : public Node
{
    public:
    MulExpression(std::string v): Node("MulExpression",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif