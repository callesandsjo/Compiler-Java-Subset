#include "WhileStatement.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"
#include "Jump.h"
#include "CondJump.h"

BBlock *WhileStatement::genIR(BBlock *currblock, std::string &ret_name)
{
        std::string name = genName();
        std::list<Node *>::iterator it = children.begin();
        std::advance(it, 0);
        //Block for loop header
        BBlock *headerblock = new BBlock();
        std::string ht;
        (*it)->genIR(headerblock, ht);

        //Block for loop body
        std::advance(it, 1);
        BBlock *loopblock = new BBlock();
        std::string lt;
        BBlock* b = (*it)->genIR(loopblock, lt);



        BBlock *jBlock = new BBlock();
        jBlock->name = genName();

        //link blocks
        headerblock->trueEdge = loopblock;
        headerblock->falseEdge = jBlock;

        Tac headblockToJoinBlock = CondJump("iffalse", ht, jBlock->name);
        headerblock->tacinstructions.push_back(headblockToJoinBlock);

        Tac headblockToLoopblock = Jump(loopblock->name);
        headerblock->tacinstructions.push_back(headblockToLoopblock);

        Tac loopblockToHeadbock = Jump(headerblock->name);
        b->tacinstructions.push_back(loopblockToHeadbock);

        currblock->trueEdge = headerblock;

        ret_name = jBlock->name;
        return jBlock;
}
