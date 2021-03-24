#include "Identifier.h"

#include "Tac.h"
#include "Assignment.h"
#include "BBlock.h"

BBlock *Identifier::genIR(BBlock *currblock, std::string &ret_name)
{
        ret_name = value;
        return currblock;
}
