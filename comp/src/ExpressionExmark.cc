#include "ExpressionExmark.h"
#include "Tac.h"
#include "BBlock.h"
#include "Parameter.h"
#include "Uassignment.h"
BBlock* ExpressionExmark::genIR(BBlock *currblock, std::string &ret_name)
{    
    std::string tmp = genTmpName();
    ret_name = tmp;
    std::list<Node*>::iterator it = children.begin();
    std::string exp;
    (*it)->genIR(currblock, exp);
    
    Tac *in = new Uassignment("!", exp, tmp);
    currblock->tacinstructions.push_back(in);
    return currblock;
}