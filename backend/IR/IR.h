#ifndef IR_H
#define IR_H

#include <list>
#include <iostream>
#include "../Node.h"
#include "../Visitor.h"
#include <map>
#include "BasicBlock.h"


struct IR : public Visitor{
    std::list<BasicBlock*> CFGs;
    BasicBlock *currentBlock; //helper for knowing which block should be modified
    void visit(Node *node) override { //Visiting in postorder
        if (node == nullptr)
            return;
        
        for(auto children = node->children.begin(); children != node->children.end(); children++)
            visit(*children);
        
        parseNode(node);
    }

    void parseNode(Node *node) {
        return;
    }
};

#endif