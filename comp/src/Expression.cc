#include "Expression.h"
#include "Tac.h"
#include "BBlock.h"
#include "Parameter.h"
#include <string>

BBlock *Expression::genIR(BBlock *currblock, std::string &ret_name)
{
    // When Expression has a expression inside, ex ( exp )  
    if (value == "ExpressionWKid")
    {
        std::list<Node *>::iterator it = children.begin();
        return (*it)->genIR(currblock, ret_name);
    }
    ret_name = value;
    return currblock;
}