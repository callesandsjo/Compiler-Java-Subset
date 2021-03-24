#include "ClassDeclaration.h"
#include "../tac/Tac.h"
#include "../tac/Assignment.h"
#include "../BBlock.h"
 std::string ClassDeclaration::genIR(BBlock *currblock) {
        std::string name = genName();
        std::list<Node*>::iterator it = children.begin();
        std::advance(it, 0);
        std::string lns_name = (*it)->genIR(currblock);

        std::advance(it,1);
        std::string rns_name = (*it)->genIR(currblock);

        Tac in = Assignment("+", lns_name, rns_name, name);
        currblock->tacinstructions.push_back(in);
        return name;
    }