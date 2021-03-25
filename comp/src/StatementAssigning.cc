#include "StatementAssigning.h"
#include "Tac.h"
#include "BBlock.h"
#include "Copy.h"

BBlock* StatementAssigning::genIR(BBlock *currblock, std::string &ret_name)
{
    std::string name = currblock->name;
    ret_name = name;
    std::list<Node*>::iterator it = children.begin();
    std::advance(it, 0);
    std::string identifier;
    (*it)->genIR(currblock, identifier);
    std::advance(it,1);
    std::string methodcallResult;
    (*it)->genIR(currblock, methodcallResult);

    Tac *in = new Copy(methodcallResult, identifier);
    currblock->tacinstructions.push_back(in);
    return currblock;
}


