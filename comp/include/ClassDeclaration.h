#ifndef CLASSDECLARATION_H
#define CLASSDECLARATION_H

#include "Node.h"
#include "BBlock.h"

class ClassDeclaration : public Node
{
public:
    ClassDeclaration(std::string v) : Node("ClassDeclaration", v) {}
    //MethodCall(std::string _f, std::string _N, std::string _result) : Tac("Call", _f, _N, _result) {}
    BBlock *genIR(BBlock *currblock, std::string &ret_name);
};
#endif