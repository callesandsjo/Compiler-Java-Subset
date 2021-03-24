#ifndef RETURNTAC_H
#define RETURNTAC_H

#include "Tac.h"

class ReturnTac : public Tac
{
    public:
	ReturnTac(std::string _result) : Tac("Return", "", "", _result) {}
};
#endif