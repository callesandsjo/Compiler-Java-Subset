#include "AssignmentChecker.h"

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

void AssignmentChecker::visit(Node* n){

    Visitor *s = check_node(n);
    for(auto i=n->children.begin(); i!=n->children.end(); i++)
		{
            (*i)->accept(s);

		}
  }
Visitor* AssignmentChecker::check_node(Node *n)
  {
    std::list<std::string>::iterator it = std::find(listOfStrs.begin(), listOfStrs.end(), n->type);
    if (it != listOfStrs.end())
    {
        if (n->type == "Identifier")
        {
            cout << "----- " << n->parent->type << endl;
            //if (n->parent->type == "Statement" && (n->parent->value =="Assigning" ||  n->parent->value =="ELSE Assigning"))
            if (n->parent->type == "Statement" && n->parent->value.find("Assigning")!=std::string::npos)
            {
                cout << ">>>>>>>>>> ASSIGNMENT ADD ST: " << n->value << ":" << n->type << endl;
            
                cout << "########    Statement value  " << n->parent->value << endl;
                cout << "########    Checking  id   " << n->value <<" in scope "<<this->scope << endl;
                string lType =st->getType(n->value,this->scope);
                string rightSideType="NONE";
                //cout << "########    Id "<<n->value<< " Found in scope   " << this->scope <<" type ="<<lType<<endl;
                //cout << "########    Expression  type  " << n->parent->children.back()->type << endl;
                //cout << "########    Expression  value  " << n->parent->children.back()->value << endl;
                if (n->parent->children.back()->value == "method call"){
                    Node *n1= n->parent->children.back()->children.front();
                    
                    std::list<Node*>::iterator it=n->parent->children.back()->children.begin();
                    std::advance(it,1);
                    Node *n2= (*it);
                  
                    if (n1->value == "New"){
                        string classname=n1->children.front()->value;
                        string methodName= n2->value;
                        string mscope = "__Class__"+classname+"__Method__"+methodName;
                        rightSideType=st->getType(methodName, mscope);

                    } 

                } 
                if (n->parent->children.back()->type == "Expression") {
                    std::string nr=n->parent->children.back()->value;

                    bool is_int = std::all_of(nr.begin(), nr.end(), ::isdigit);
                    if (is_int){
                        rightSideType="int";
                    } 
                } 
                if (lType == rightSideType ){
                    cout << "########    Method  Type  MATCHES " << rightSideType<< endl;

                } else{
                    cout << "ERROR ########    Method  Type  NOT MATCHES " << rightSideType<< endl;
                    throw std::runtime_error("Type missmatch " + lType + "  !=   " + rightSideType);


                } 
                //identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
                return this;
            }
            
            return this;
        }
        else if (n->type == "MainClass")
        {
            AssignmentChecker *s = new AssignmentChecker(this->scope + "__Main__" + n->value, this);
            class_map.insert({n->value, s});
            return s;
        }
        else if (n->type == "ClassDeclaration")
        {
            AssignmentChecker *s = new AssignmentChecker(this->scope + "__Class__" + n->value, this);
            class_map.insert({n->value, s});
            return s;
        }
        else if (n->type == "MethodDeclaration")
        {
            AssignmentChecker *s = new AssignmentChecker(this->scope + "__Method__" + n->value, this);
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