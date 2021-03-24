#include "MethodDeclaration.h"
#include "Tac.h"
#include "BBlock.h"
BBlock *MethodDeclaration::genIR(BBlock *currblock, std::string &ret_name)
{
    // name of block is name of method
    std::string name = currblock->name + "_" + value;
    ret_name = name;

    BBlock *mBlock = new BBlock();
    mBlock->name = name;
    entry_blocks->insert(std::pair<std::string, BBlock *>(name, mBlock));

    std::list<Node *>::iterator it = children.begin();

    std::string tmp;
    BBlock *t = mBlock;

    //skipping type and identifier
    for (advance(it, 2); it != children.end(); ++it)
    {
       t = (*it)->genIR(t, tmp);
    }
    return currblock;
}