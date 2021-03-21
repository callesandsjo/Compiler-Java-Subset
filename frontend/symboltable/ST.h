#ifndef ST_H
#define ST_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "../Node.h"
#include "../Visitor.h"
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
  bool findInScope(string name, string inScope)
  {

    if (scope == inScope)
    {
        string name_to_find=inScope + "__Id__" + name;
        //cout << "CHECKING ST: " << name_to_find << ":" << inScope << endl;
        if(identif_map.find(name_to_find) == identif_map.end()){
        return false;
        } else {
        return true;
        }
    }
    else
    {
      for (auto const &elem : method_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return true;
        }
      }
      for (auto const &elem : class_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return true;
        }
      }
    }
    return false;
  }
  string getType(string name, string inScope)
  {

    if (scope == inScope)
    {
        string name_to_find=inScope + "__Id__" + name;
        //cout << "CHECKING ST: " << name_to_find << ":" << inScope << endl;
        if(identif_map.find(name_to_find) == identif_map.end()){
        return "NONE";
        } else {
        return identif_map[name_to_find];
        }
    }
    else
    {
      for (auto const &elem : method_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return elem.second->getType( name,  inScope);
        }
      }
      for (auto const &elem : class_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return elem.second->getType( name,  inScope);
        }
      }
    }
    return "NONE";
  }
  void visit(Node *n) override
  {
    Visitor *s = check_node(n);
    for (auto i = n->children.begin(); i != n->children.end(); i++)
    {
      (*i)->accept(s);
    }
    //cout << "ADD ST: " << n->value << ":" << n->type << endl;
  }
  ST *check_node(Node *n)
  {
    std::list<std::string>::iterator it = std::find(listOfStrs.begin(), listOfStrs.end(), n->type);
    if (it != listOfStrs.end())
    {
      cout << "ADD ST: " << n->value << ":" << n->type << endl;
      if (n->type == "Identifier")
      {
        if (n->parent->type == "VarDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
          return this;
        }
        else if (n->parent->type == "MethodDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
          return this;
        }
        else if (n->parent->type == "ClassDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, this->scope + "__Id__" + n->value});
          return this;
        }
        else if (n->parent->type == "MainClass")
        {
          if (n->parent->children.front()->value == n->value)
          {
            identif_map.insert({this->scope + "__Id__" + n->value, this->scope + "__Id__" + n->value});
          }
          else
          {
            identif_map.insert({this->scope + "__Id__" + n->value, "String[]"});
          }
          return this;
        }
        else if (n->parent->type == "Arguments")
        {
          std::string my_type = "";
          for (auto i = n->parent->children.begin(); i != n->parent->children.end(); i++)
          {
            if ((*i)->value == n->value)
            {
              break;
            }
            my_type = (*i)->value;
          }
          identif_map.insert({this->scope + "__Id__" + n->value, my_type});
          return this;
        }

        //identif_map.insert({this->scope+"__Id__"+n->value, n->type});
        return this;
      }
      else if (n->type == "MainClass")
      {
        ST *s = new ST(this->scope + "__Main__" + n->value, this);
        class_map.insert({n->value, s});
        return s;
      }
      else if (n->type == "ClassDeclaration")
      {
        ST *s = new ST(this->scope + "__Class__" + n->value, this);
        class_map.insert({n->value, s});
        return s;
      }
      else if (n->type == "MethodDeclaration")
      {
        ST *s = new ST(this->scope + "__Method__" + n->value, this);
        method_map.insert({n->value, s});
        return s;
      }
      else
      {
        cout << "Not supposed to be here!" << endl;
        return this;
      }
    }
    return this;
  }

  void print()
  {

    for (auto const &elem : identif_map)
    {
      cout << elem.first << ":" << elem.second << endl;
    }
    for (auto const &elem : method_map)
    {
      elem.second->print();
    }
    for (auto const &elem : class_map)
    {
      elem.second->print();
    }
  }
};

#endif