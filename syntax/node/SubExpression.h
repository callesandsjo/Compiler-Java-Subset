#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

#include "../Node.h"
#include "../tac/Tac.h"
#include "../tac/Assignment.h"
#include "../BBlock.h"

class SubExpression : public Node
{
    public:
        SubExpression(std::string v): Node("SubExpression",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    std::string genIR(BBlock *currblock);
};
#endif