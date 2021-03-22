#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

#include "ThreeAddressCodes.h"
#include <list>

class BasicBlock {
    public:
    std::string name;
    std::list<TAC> tacs;
    uint16_t tempVars;
    TAC *cond;

    BasicBlock *trueBlock, *falseBlock;
    BasicBlock()
        : trueBlock(nullptr), falseBlock(nullptr), tempVars(0) {}
    void addTAC(TAC *tac)
    {
        tacs.push_back(*tac);
    }
    
};

//CFG : rootblock?, IR : list of CFG?

#endif