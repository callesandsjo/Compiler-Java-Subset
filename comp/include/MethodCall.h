#ifndef METHODCALL_H
#define METHODCALL_H

#include "Node.h"
#include "Tac.h"
#include "BBlock.h"

class MethodCall : public Node
{
public:
    MethodCall(std::string v) : Node("MethodCall", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif