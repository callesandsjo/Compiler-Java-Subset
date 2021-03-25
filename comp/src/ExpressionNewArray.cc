#include "ExpressionNewArray.h"
#include "Tac.h"
#include "BBlock.h"
#include "NewArray.h"

BBlock* ExpressionNewArray::genIR(BBlock *currblock, std::string &ret_name)
{    
    std::string tmp = genTmpName();
    ret_name = tmp;
    std::list<Node*>::iterator it = children.begin();
    std::string amount_elem;
    (*it)->genIR(currblock, amount_elem);
    
    Tac *in = new NewArray(amount_elem, value, tmp);
    currblock->tacinstructions.push_back(in);
    return currblock;
}