#ifndef VARDECLARATIONS_H
#define VARDECLARATIONS_H

#include "Node.h"
#include "BBlock.h"

class VarDeclarations : public Node
{
    public:
    VarDeclarations(std::string v): Node("VarDeclarations",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif