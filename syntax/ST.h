#ifndef ST_H
#define	ST_H

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


class ST : public Visitor {
public:
    string name;
    std::list<std::string> listOfStrs = {"Identifier", "MainClass", "MethodDeclaration", "ClassDeclaration"};
    std::map<std::string, string> identif_map;
    std::map<std::string, ST*> method_map;
    std::map<std::string, ST*> class_map;

	list<Node*> children;
	ST() : name("") {cout << "SKAPADE ST" << endl;}
    ST(string n) : name(n) {} 
    ~ST() override {cout << "Destructor " << this << endl;}
  
  void visit(Node *n) {
    Visitor *s = check_node(n);
    for(auto i=n->children.begin(); i!=n->children.end(); i++)
		{
            (*i)->buildST(s);

		}
        //cout << "ADD ST: " << n->value << ":" << n->type << endl;
  }
  ST* check_node(Node *n) {
      std::list<std::string>::iterator it = std::find(listOfStrs.begin(), listOfStrs.end(), n->type);
      if (it != listOfStrs.end()) {
            cout << "ADD ST: " << n->value << ":" << n->type << endl;
            if (n->type == "Identifier") {
                
                identif_map.insert({this->name+"__Id__"+n->value, n->type});
                return this;
            }
            else if (n->type == "MainClass") {
                ST *s = new ST(this->name+"__Main__"+n->value); 
                //class_map[n->value] = s;
                class_map.insert({n->value, s});
                return s;
            }
              else if (n->type == "ClassDeclaration") {
                ST *s = new ST(this->name+"__Class__"+n->value); 
                //class_map[n->value] = s;
                class_map.insert({n->value, s});
                return s;
            }
            else if (n->type == "MethodDeclaration")
            {
                ST *s = new ST(this->name+"__Method__"+n->value);
                //method_map[n->value] = s;
                method_map.insert({n->value, s});
                return s;
            }
            else {
                cout << "Not supposed to be here!" << endl;
                return this;
            }
      }
        return this;
  }
  void print() {
    
    for (auto const& elem : identif_map) {
        cout << elem.first << ":" << elem.second << endl;
    }
    for (auto const& elem : method_map) {
        elem.second->print();
    }
    for (auto const& elem : class_map) {
        elem.second->print();
    }
  }


};

#endif