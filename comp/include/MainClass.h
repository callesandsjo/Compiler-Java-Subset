#ifndef MAINCLASS_H
#define MAINCLASS_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class MainClass : public Node
{
public:
    MainClass(std::string v) : Node("MainClass", v) {}

    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif