#ifndef STATEMENTS_H
#define STATEMENTS_H

#include "Node.h"
#include "BBlock.h"

class Statements : public Node
{
    public:
    Statements(std::string v): Node("Statements",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif