#ifndef NEWARRAY_H
#define NEWARRAY_H

#include "Tac.h"

class NewArray : public Tac
{
    public:
	NewArray(std::string _N, std::string _type, std::string _result) : Tac("NEW ARRAY", _N, _type, _result) {}
    void dump() {printf("%s := %s %s, %s\n", getResult().c_str(), getOp().c_str(), getRns().c_str(), getLns().c_str());}
};
#endif