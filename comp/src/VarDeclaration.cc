#include "VarDeclaration.h"
#include "Tac.h"
#include "BBlock.h"
#include "Copy.h"
BBlock *VarDeclaration::genIR(BBlock *currblock, std::string &ret_name)
{
    // name of block is name of method
    currblock->name = currblock->name;
    ret_name = currblock->name;

    for (auto i = children.begin(); i != children.end(); i++)
    {
        // leaf nodes returns value = var, skipping "Integer" node with i++
        i++;
        std::string var;
        (*i)->genIR(currblock, var);
        Tac *in = new Copy("0", var);
        currblock->tacinstructions.push_back(in);
    }
    return currblock;
}