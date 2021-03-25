#include "Expressions.h"
#include "Tac.h"
#include "BBlock.h"
#include "Parameter.h"
#include <string>

BBlock *Expressions::genIR(BBlock *currblock, std::string &ret_name)
{
    int count = 0;
    for (auto i = children.rbegin(); i != children.rend(); i++)
    {
        count++;
        std::string p;
        (*i)->genIR(currblock, p);
        Tac *param = new Parameter(p);
        currblock->tacinstructions.push_back(param);
    }
    // returning amount of params to methodcall
    ret_name = std::to_string(count);
    return currblock;
}