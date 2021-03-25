#include "SystemPrint.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock *SystemPrint::genIR(BBlock *currblock, std::string &ret_name)
{
        std::string name = genName();
        ret_name = name;
        std::list<Node *>::iterator it = children.begin();
        std::advance(it, 0);
        std::string lns_name;
        (*it)->genIR(currblock, lns_name);
        Tac *in = new Assignment("System.print", lns_name, "", "");
        currblock->tacinstructions.push_back(in);
        return currblock;
}
