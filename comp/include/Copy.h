#ifndef COPY_H
#define COPY_H

#include "Tac.h"

class Copy : public Tac
{
    public:
	Copy(std::string _lns, std::string _result) : Tac("Copy", _lns, "", _result) {}
};
#endif