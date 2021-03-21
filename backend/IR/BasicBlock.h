#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include "ThreeAddressCodes.h"
#include <list>

class BasicBlock {
    std::string name;
    std::list<TAC> tacs;

    TAC *cond;

    BasicBlock *trueBlock, *falseBlock;
    BasicBlock()
        : trueBlock(nullptr), falseBlock(nullptr) {}
    
};

//CFG : rootblock?, IR : list of CFG?

#endif