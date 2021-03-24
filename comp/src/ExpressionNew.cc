#include "ExpressionNew.h"
#include "Tac.h"
#include "BBlock.h"
#include "New.h"

BBlock* ExpressionNew::genIR(BBlock *currblock, std::string &ret_name)
{    
    std::string tmp = genTmpName();

    std::list<Node*>::iterator it = children.begin();
    std::string identifier;
    (*it)->genIR(currblock, identifier);
    
    Tac in = New(identifier, tmp);
    currblock->tacinstructions.push_back(in);
    ret_name = tmp;
    return currblock;
}