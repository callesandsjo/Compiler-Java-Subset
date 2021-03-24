#include "ClassDeclaration.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"
BBlock* ClassDeclaration::genIR(BBlock *currblock, std::string &ret_name)
{
    // Block name is set to class name
    std::list<Node *>::iterator it = children.begin();
    BBlock *class_block = new BBlock();
    std::advance(it, 0);
    std::string name;
    (*it)->genIR(class_block, name);

    // Set block name 
    class_block->name = name;
    ret_name = name;

    // variable declaration is simplified in this assignment
    // call genIR methodeclarations with classblock
    std::advance(it, 1);
    std::string tmp;
    (*it)->genIR(class_block, tmp);

    return currblock;
}