#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class IfStatement : public Node
{
public:
    IfStatement(std::string v) : Node("IfStatement", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif