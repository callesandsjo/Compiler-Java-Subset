#ifndef PARAMETER_H
#define PARAMETER_H

#include "Tac.h"

class Parameter : public Tac
{
    public:
	Parameter(std::string _y) : Tac("Parameter", "", "",_y) {}
    void dump() {printf("Param %s\n", getResult().c_str());}

};
#endif