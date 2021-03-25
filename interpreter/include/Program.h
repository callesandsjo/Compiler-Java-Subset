#ifndef PROGRAM_H
#define PROGRAM_H

#include "Method.h"
#include <map>
class Program
{
public:
    std::map<std::string, Method*> methods;
    std::string startName;
    bool debug;
    Program() {}
    void print() {  }
    Method *getMethod(std::string s) {return methods[s];}
    std::string getMainMethod() {return startName;}

};
#endif