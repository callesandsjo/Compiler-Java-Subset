#ifndef STATEMENT_H
#define STATEMENT_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class Statement : public Node
{
    public:
        Statement(std::string v): Node("Statement",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif