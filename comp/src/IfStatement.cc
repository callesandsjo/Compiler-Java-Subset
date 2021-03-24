#include "IfStatement.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"
#include "CondJump.h"
#include "Jump.h"

BBlock* IfStatement::genIR(BBlock *currblock, std::string &ret_name)
{
        std::list<Node*>::iterator it = children.begin();
        std::advance(it, 0);
        std::string operation;
        (*it)->genIR(currblock, operation);

        //true block
        BBlock* tBlock=new BBlock();
        std::advance(it,1);
        std::string t;
        BBlock* tb = (*it)->genIR(tBlock, t);

        //false block
        BBlock* fBlock=new BBlock();
        std::advance(it,1);
        std::string f;
        BBlock* fb = (*it)->genIR(fBlock, f);

        //jump block
        BBlock* jBlock=new BBlock();
        jBlock->name = genName();
        //currblock->generate_tree();

        Tac in = CondJump("iffalse", operation, fBlock->name);
        currblock->tacinstructions.push_back(in);

        Tac un = Jump(tBlock->name);
        currblock->tacinstructions.push_back(un);

        Tac un2 = Jump(jBlock->name);
        tb->tacinstructions.push_back(un2);
        fb->tacinstructions.push_back(un2);

        //link together
        tb->trueEdge=jBlock;
        fb->trueEdge=jBlock;
        currblock->trueEdge=tBlock;
        currblock->falseEdge=fBlock;

        ret_name = jBlock->name;
        return jBlock;
}
