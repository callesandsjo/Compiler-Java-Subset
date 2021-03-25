#ifndef STOPTAC_H
#define STOPTAC_H

#include "Tac.h"

class StopTac : public Tac
{
public:
    StopTac() : Tac("Stop", "", "", "") {}
    void dump() { printf("Stop %s\n", getLns().c_str()); }
    void generateCode(std::ofstream *outStream, int &instructionCounter)
    {
        *outStream << instructionCounter++ << " stop " << std::endl;
    }
};
#endif