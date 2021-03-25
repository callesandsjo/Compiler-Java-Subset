#ifndef LESSTHANOPERATION_H
#define LESSTHANOPERATION_H

#include "Node.h"
#include "BBlock.h"

class LessThanOperation : public Node
{
public:
    LessThanOperation(std::string v) : Node("LessThanOperation", v) {}
    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif