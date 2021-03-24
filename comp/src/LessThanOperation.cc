#include "LessThanOperation.h"
#include "Tac.h"
#include "BBlock.h"
#include "NewArray.h"
#include "Assignment.h"

BBlock* LessThanOperation::genIR(BBlock *currblock, std::string &ret_name)
{    
    
    std::list<Node*>::iterator it = children.begin();
    std::advance(it, 0);
    std::string identifier;
    (*it)->genIR(currblock, identifier);

    std::advance(it, 1);
    std::string exp;
    (*it)->genIR(currblock, exp);

    std::string name = genTmpName();
    Tac in = Assignment("LessThan", identifier, exp, name);
    currblock->tacinstructions.push_back(in);
    std::cout<< "Added lessTan tac to "<<currblock->name<<std::endl;

    ret_name = name;
    return currblock;
}