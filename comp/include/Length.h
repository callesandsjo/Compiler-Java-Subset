#ifndef LENGTH_H
#define LENGTH_H

#include "Tac.h"

class Length : public Tac
{
    public:
	Length(std::string _y, std::string _result) : Tac("Length", "", _y, _result) {}
    void dump() {printf("%s := length %s\n", getResult().c_str(), getRns().c_str());}

};
#endif