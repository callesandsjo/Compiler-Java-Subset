#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include "Program.h"
#include "Method.h"
#include <stack>
class Interpreter
{
public:
    Program *program;
    Method *main;
    std::stack<int> data_stack;
    bool debug;

    Interpreter(Program *p,bool d) {program = p; debug=d; main = program->getMethod(program->getMainMethod());}
    void print() {  }
    void execute();
    int data_pop() {int t = data_stack.top(); data_stack.pop(); return t;}
};
#endif