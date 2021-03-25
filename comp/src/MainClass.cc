#include "MainClass.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"
#include "StopTac.h"

BBlock* MainClass::genIR(BBlock *currblock, std::string &ret_name)
{
        std::list<Node *>::iterator it = children.begin();
        std::advance(it, 0);

        //Name of the whole block is the name of the class
        std::string name;
        (*it)->genIR(currblock, name);
        currblock->name = name + "_main";
        ret_name = currblock->name;
        //skips arg in mainclass
        std::advance(it, 1);

        //call genIR statements with currblock
        std::advance(it, 1);
        std::string tmp;
        (*it)->genIR(currblock, tmp);

        // Add stop TAC
        Tac *stop = new StopTac();
        currblock->tacinstructions.push_back(stop);

        return currblock;
}
