#ifndef GOAL_H
#define GOAL_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class Goal : public Node
{
    public:
    Goal(std::string v): Node("Goal",v){}
	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif