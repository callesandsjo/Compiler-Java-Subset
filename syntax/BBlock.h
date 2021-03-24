#ifndef BBLOCK_H
#define BBLOCK_H

#include "tac/Tac.h"
#include <list>


class BBlock
{
    public:
        std::string name;
        Tac condition;
        BBlock *trueEdge, *falseEdge;
        std::list<Tac> tacinstructions;

	    BBlock() : trueEdge(nullptr), falseEdge(nullptr) {}

};
#endif