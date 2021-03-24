#include "Return.h"

#include "Tac.h"
#include "ReturnTac.h"
#include "BBlock.h"

BBlock *Return::genIR(BBlock *currblock, std::string &ret_name)
{
        std::string name = genName();
        ret_name = name;
        std::list<Node *>::iterator it = children.begin();
        std::advance(it, 0);
        std::string identifier;
        (*it)->genIR(currblock, identifier);

        Tac in = ReturnTac(identifier);
        currblock->tacinstructions.push_back(in);
        return currblock;
}
