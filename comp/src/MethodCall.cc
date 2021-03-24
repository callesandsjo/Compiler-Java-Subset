#include "MethodCall.h"
#include "Tac.h"
#include "BBlock.h"
#include "Copy.h"
#include "Parameter.h"
#include "MethodCallTac.h"

BBlock *MethodCall::genIR(BBlock *currblock, std::string &ret_name)
{
    std::string name = currblock->name;
    std::list<Node *>::iterator it = children.begin();
    // class name
    std::advance(it, 0);
    std::string object;
    (*it)->genIR(currblock, object);

    // Traverse to parent to get class name 
    std::string classname = getClassName();
    if (object != "this")
    {
        // last elem is expressionNewTac comming from below iterated leaf
        Tac last_elem = currblock->tacinstructions.back();
        classname = last_elem.getRns(); // Rns is basically the type in Tac New
    }

    // method name
    std::advance(it, 1);
    std::string methodname;
    (*it)->genIR(currblock, methodname);

    Tac param = Parameter(object);
    currblock->tacinstructions.push_back(param);

    std::advance(it, 1);
    std::string num_params;
    (*it)->genIR(currblock, num_params);
    int p = atoi(num_params.c_str()) + 1;

    std::string tmp = genTmpName();
    Tac mcall = MethodCallTac(classname + "." + methodname, std::to_string(p), tmp);
    currblock->tacinstructions.push_back(mcall);
    ret_name = tmp;
    return currblock;
}