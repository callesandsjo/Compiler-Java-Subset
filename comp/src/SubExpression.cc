#include "SubExpression.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock* SubExpression::genIR(BBlock *currblock, std::string &ret_name)
{
        std::string name = genName();
        std::list<Node *>::iterator it = children.begin();
        std::advance(it, 0);
        std::string lns_name;
        (*it)->genIR(currblock, lns_name);

        std::advance(it, 1);
        std::string rns_name;
        (*it)->genIR(currblock, rns_name);

        std::string genTmp = genTmpName();
        Tac *in = new Assignment("-", lns_name, rns_name, genTmp);
        currblock->tacinstructions.push_back(in);
        ret_name = genTmp;
        return currblock;
}
