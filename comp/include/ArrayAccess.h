#ifndef ARRAYACCESS_H
#define ARRAYACCESS_H

#include "Tac.h"

class ArrayAccess : public Tac
{
    public:
	ArrayAccess(std::string _y, std::string _i, std::string _x) : Tac("Array access", _y, _i,_x) {}
};
#endif