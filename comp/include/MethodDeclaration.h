#ifndef METHODDECLARATION_H
#define METHODDECLARATION_H

#include "Node.h"
#include "BBlock.h"

class MethodDeclaration : public Node
{
    public:
    MethodDeclaration(std::string v): Node("MethodDeclaration",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif