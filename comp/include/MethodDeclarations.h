#ifndef METHODDECLARATIONS_H
#define METHODDECLARATIONS_H

#include "Node.h"
#include "BBlock.h"

class MethodDeclarations : public Node
{
    public:
    MethodDeclarations(std::string v): Node("MethodDeclarations",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif