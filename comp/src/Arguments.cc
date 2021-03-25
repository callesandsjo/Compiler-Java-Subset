#include "Arguments.h"
#include "Tac.h"
#include "BBlock.h"
#include "Copy.h"
BBlock *Arguments::genIR(BBlock *currblock, std::string &ret_name)
{
    // name of block is name of method
    std::string name = currblock->name;

    for (auto i = children.begin(); i != children.end(); i++)
    {
        // leaf nodes returns value = arg, skipping "Interger" node with i++
        i++;
        std::string arg;
        (*i)->genIR(currblock, arg);
        Tac *in = new Copy(arg, genTmpName());
        currblock->tacinstructions.push_back(in);
    }
    return currblock;
}