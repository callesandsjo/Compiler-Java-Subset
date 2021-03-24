#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class Boolean : public Node
{
    public:
        Boolean(std::string v): Node("Boolean",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif