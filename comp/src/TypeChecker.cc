#include "TypeChecker.h"

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

void TypeChecker::visit(Node* n){

    Visitor *s = check_node(n);
    for(auto i=n->children.begin(); i!=n->children.end(); i++)
		{
            (*i)->accept(s);

		}
  }
Visitor* TypeChecker::check_node(Node *n)
  {
      //TODO: if not in current scope traverse up to class level and check for the declaration
       
    std::list<std::string>::iterator it = std::find(listOfStrs.begin(), listOfStrs.end(), n->type);
    if (it != listOfStrs.end())
    {
        if (n->type == "Identifier")
        {
            //if (n->parent->type == "Statement" && (n->parent->value =="Assigning" ||  n->parent->value =="ELSE Assigning"))
            if (n->parent->type == "Statement" && n->parent->value.find("Assigning")!=std::string::npos)
            {
                if (st->findInScope(n->value,this->scope)){
                     cout << "########    Id "<<n->value<< " Found in scope   " << this->scope << endl;
                } else {
                    cout << "#### ERROR ####    Id "<<n->value<< " Not Found in scope   " << this->scope << endl;
                    throw std::runtime_error("Id " + n->value + "  Not Found in scope   " + this->scope);

                } 
                //identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
                return this;
            }
           
            return this;
        }
        else if (n->type == "MainClass")
        {
            TypeChecker *s = new TypeChecker(this->scope + "__Main__" + n->value, this);
            class_map.insert({n->value, s});
            return s;
        }
        else if (n->type == "ClassDeclaration")
        {
            TypeChecker *s = new TypeChecker(this->scope + "__Class__" + n->value, this);
            class_map.insert({n->value, s});
            return s;
        }
        else if (n->type == "MethodDeclaration")
        {
            TypeChecker *s = new TypeChecker(this->scope + "__Method__" + n->value, this);
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