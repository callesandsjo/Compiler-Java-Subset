#ifndef STATEMENTASSIGNING_H
#define STATEMENTASSIGNING_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class StatementAssigning : public Node
{
    public:
        StatementAssigning(std::string v): Node("StatementAssigning",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif