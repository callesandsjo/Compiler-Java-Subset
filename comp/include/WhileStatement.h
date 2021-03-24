#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class WhileStatement : public Node
{
    public:
        WhileStatement(std::string v): Node("WhileStatement",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif