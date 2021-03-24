#include "Type.h"
#include "Tac.h"
#include "BBlock.h"
BBlock *Type::genIR(BBlock *currblock, std::string &ret_name)
{
    ret_name = value;
    return currblock;
}