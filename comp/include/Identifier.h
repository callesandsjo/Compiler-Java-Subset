#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class Identifier : public Node
{
    public:
        Identifier(std::string v): Node("Identifier",v){}

	//MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock* genIR(BBlock *currblock, std::string &ret_name);
};
#endif