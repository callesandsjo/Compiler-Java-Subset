#ifndef CONDJUMP_H
#define CONDJUMP_H

#include "Tac.h"

class CondJump : public Tac
{
    public:
	CondJump(std::string _op, std::string _x, std::string _label) : Tac(_op, _x, "",_label) {}
    void dump() {printf("%s %s goto %s\n", getOp().c_str(), getLns().c_str(), getResult().c_str());}
};
#endif