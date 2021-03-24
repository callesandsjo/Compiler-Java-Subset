#ifndef NEW_H
#define NEW_H

#include "Tac.h"

class New : public Tac
{
    public:
	New(std::string _type, std::string _result) : Tac("NEW", "", _type, _result) {}
    void dump() {printf("%s := %s %s\n", getResult().c_str(), getOp().c_str(), getRns().c_str());}

};
#endif