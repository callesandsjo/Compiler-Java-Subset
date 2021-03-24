#ifndef ANDOPERATION_H
#define ANDOPERATION_H

#include "Node.h"
#include "BBlock.h"

class AndOperation : public Node
{
    public:
    AndOperation(std::string v): Node("AndOperation",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif