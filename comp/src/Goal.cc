#include "Goal.h"
#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock* Goal::genIR(BBlock *currblock, std::string &ret_name)
{
        std::string name = genName();
        ret_name = name;
        std::list<Node*>::iterator it = children.begin();
        
        //First child in goal
        BBlock* first_child = new BBlock();
        std::advance(it, 0);
        std::string c;
        (*it)->genIR(first_child, c);
        
        //Call genIR for all classes in classdeclarations
        std::advance(it, 1);
        std::string t;
        (*it)->genIR(currblock, t);

        currblock->trueEdge = first_child;
        //Tac in = Assignment("-", lns_name, rns_name, name);
        //currblock->tacinstructions.push_back(in);
        return currblock;
}