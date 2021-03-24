#ifndef TYPE_H
#define TYPE_H

#include "Node.h"
#include "BBlock.h"

class Type : public Node
{
    public:
    Type(std::string v): Node("Type",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif