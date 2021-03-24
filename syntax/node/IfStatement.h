#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Node.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

class Ifstatement : public Node
{
    public:
    BBlock *genIR(BBlock *currblock) {
        children.front()->genIR(currblock);
        std::list<Node*>::iterator it = children.begin();
        BBlock* true_block = new BBlock();
        std::advance(it, 1);
        std::string t2 = genIR((*it), true_block);
        BBlock* false_block = new BBlock();
        std::advance(it, 2);
        std::string f2 = genIR((*it), false_block);
        BBlock* j_block = new BBlock();

        //link block together
        true_block->trueEdge = j_block;
        false_block->trueEdge = j_block;
        currblock->trueEdge = true_block;
        currblock->falseEdge = false_block;
        return j_block;
    }
};
#endif