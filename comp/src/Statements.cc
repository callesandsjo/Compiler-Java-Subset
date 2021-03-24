#include "Statements.h"
#include "Tac.h"
#include "BBlock.h"
#include "Copy.h"
BBlock *Statements::genIR(BBlock *currblock, std::string &ret_name)
{
    std::string name = genName();
    ret_name = name;
    std::string tmp;
    for (auto i = children.begin(); i != children.end(); i++)
    {
        currblock = (*i)->genIR(currblock, tmp);
    }

    return currblock;
}
