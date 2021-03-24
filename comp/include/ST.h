#ifndef ST_H
#define ST_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "Node.h"
#include "Visitor.h"
#include <algorithm>
#include <map>

using namespace std;

class ST : public Visitor
{
public:
  string scope;
  ST *parent;
  std::list<std::string> listOfStrs = {"Identifier", "MainClass", "MethodDeclaration", "ClassDeclaration"};
  std::map<std::string, string> identif_map;
  std::map<std::string, ST *> method_map;
  std::map<std::string, ST *> class_map;

  list<Node *> children;
  ST() : scope(""), parent(0) {  }
  ST(string n, ST *p) : scope(n), parent(p) {}
  ~ST() override {  }
  bool findInScope(string name, string inScope);
  string getType(string name, string inScope);

  void visit(Node *n) override
  {
    Visitor *s = check_node(n);
    for (auto i = n->children.begin(); i != n->children.end(); i++)
    {
      (*i)->accept(s);
    }
    //cout << "ADD ST: " << n->value << ":" << n->type << endl;
  }
  ST *check_node(Node *n);
  void print();
};

#endif