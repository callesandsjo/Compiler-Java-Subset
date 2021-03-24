#ifndef VARDECLARATION_H
#define VARDECLARATION_H

#include "Node.h"
#include "BBlock.h"

class VarDeclaration : public Node
{
    public:
    VarDeclaration(std::string v): Node("Arguments",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif