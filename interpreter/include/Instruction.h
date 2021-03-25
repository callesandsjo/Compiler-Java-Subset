#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <map>
#include <iostream>
#include <string>
const int ILOAD = 0;
     const int ICONST = 1;
     const int ISTORE = 2;
     const int IADD = 3;
     const int ISUB = 4;
     const int IMUL = 5;
     const int ILT = 6;
     const int IAND = 7;
     const int INOT = 9;
     const int GOTO = 10;
     const int IFFALSEGOTO = 11;
     const int INVOKEVIRTUAL = 12;
     const int IRETURN = 13;
     const int PRINT = 14;
     const int STOP = 15;
class Instruction
{
public:
/*
    static const int ILOAD ;
    static const int ICONST ;
    static const int ISTORE ;
    static const int IADD ;
    static const int ISUB ;
    static const int IMUL ;
    static const int ILT ;
    static const int IAND ;
    static const int INOT ;
    static const int GOTO ;
    static const int IFFALSEGOTO ;
    static const int INVOKEVIRTUAL ;
    static const int IRETURN ;
    static const int PRINT ;
    static const int STOP ;
*/
    std::string id;
    int pos;
    std::string argument;
    std::map<std::string, int> instructionmapping = {
        {"iload", ILOAD},
        {"iconst", ICONST},
        {"istore", ISTORE},
        {"iadd", IADD},
        {"isub", ISUB},
        {"imul", IMUL},
        {"ilt", ILT},
        {"iand", IAND},
        {"inot", INOT},
        {"goto", GOTO},
        {"iffalsegoto", IFFALSEGOTO},
        {"invokevirtual", INVOKEVIRTUAL},
        {"ireturn", IRETURN},
        {"print", PRINT},
        {"stop", STOP}
    };

    Instruction(std::string p, std::string i, std::string a) : pos(atoi(p.c_str())), id(i), argument(a) {}
    void print() { std::cout<<pos<<" "<<id<<" "<<argument<<std::endl;}
    int getInstructionId() {return instructionmapping[id];}
};

#endif