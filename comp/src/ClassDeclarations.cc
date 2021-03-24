#include "ClassDeclarations.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock* ClassDeclarations::genIR(BBlock *currblock, std::string &ret_name)
{
    std::string name = genName();
    ret_name = name;
    for (auto i = children.begin(); i != children.end(); i++)
    {
        std::string tmp;
        (*i)->genIR(currblock, tmp);
    }

    return currblock;
}
