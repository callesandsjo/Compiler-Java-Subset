#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Tac.h"

class Assignment : public Tac
{
    public:
	Assignment(std::string _op, std::string _lns, std::string _rns, std::string _result) : Tac(_op, _lns, _rns, _result) {}
};
#endif