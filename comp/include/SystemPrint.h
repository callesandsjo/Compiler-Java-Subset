#ifndef SYSTEMPRINT_H
#define SYSTEMPRINT_H

#include "Node.h"
#include "BBlock.h"

class SystemPrint : public Node
{
    public:
    SystemPrint(std::string v): Node("SystemPrint",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif