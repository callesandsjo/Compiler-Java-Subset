#include "AndOperation.h"
#include "Tac.h"
#include "BBlock.h"
#include "NewArray.h"
#include "Assignment.h"

BBlock* AndOperation::genIR(BBlock *currblock, std::string &ret_name)

{    
    std::string name = genTmpName();
    ret_name = name;
    std::list<Node*>::iterator it = children.begin();
    std::advance(it, 0);
    std::string identifier; 
    (*it)->genIR(currblock, identifier);

    std::advance(it, 1);
    std::string exp;
    (*it)->genIR(currblock, exp);

    Tac in = Assignment("AND", identifier, exp, name);
    currblock->tacinstructions.push_back(in);
    return currblock;
}