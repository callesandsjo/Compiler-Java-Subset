#ifndef CLASSDECLARATIONS_H
#define CLASSDECLARATIONS_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class ClassDeclarations : public Node
{
    public:
    ClassDeclarations(std::string v): Node("ClassDeclarations",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif