#ifndef BBLOCK_H
#define BBLOCK_H

#include "Tac.h"
#include <list>
#include <iostream>
#include <fstream>
#include <cstdio>

class BBlock
{
public:
    std::string name;
    Tac condition;
    BBlock *trueEdge, *falseEdge;
    std::list<Tac> tacinstructions;

    BBlock() : trueEdge(nullptr), falseEdge(nullptr) { name = genName(); }

    std::string genName()
    {
        char buffer[100];
        static int counter = 0;
        counter++;
        std::sprintf(buffer, "Bblock_%d", counter);
        return buffer;
    }
    void generate_tree(std::ofstream *outStream)
    {
        *outStream << name << " [label=\"" << name << "\\n";
        if (condition.getOp() != "")
        {
            condition.dump(outStream);
        }
        for (auto i = tacinstructions.begin(); i != tacinstructions.end(); i++)
        {
            (*i).dump(outStream);
        }
        *outStream << "\"];" << std::endl;
        if (trueEdge != 0)
        {
            *outStream << name << " -> " << trueEdge->name << " [xlabel=\"true\"] " << std::endl;
            trueEdge->generate_tree(outStream);
        }
        if (falseEdge != 0)
        {
            *outStream << name << " -> " << falseEdge->name << " [xlabel=\"false\"] " << std::endl;
            falseEdge->generate_tree(outStream);
        }
    }
};
#endif