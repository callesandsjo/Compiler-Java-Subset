#include "Boolean.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock* Boolean::genIR(BBlock *currblock, std::string &ret_name)
{
        ret_name = value;
        return currblock;
}
