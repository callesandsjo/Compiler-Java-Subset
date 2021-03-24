#ifndef TypeChecker_H
#define TypeChecker_H
#include <algorithm>
#include <unordered_map>
#include "Node.h"
#include "Visitor.h"
#include "ST.h"
class TypeChecker : public Visitor
{
    public:
    ST* st;
    string scope;
    TypeChecker *parent;
    std::list<std::string> listOfStrs = {"Identifier", "MainClass", "MethodDeclaration", "ClassDeclaration"};
    std::map<std::string, string> identif_map;
    std::map<std::string, TypeChecker*> method_map;
    std::map<std::string, TypeChecker*> class_map;
	list<Node*> children;
	TypeChecker(ST* s) : scope(""), parent(0) ,st(s){cout << "SKAPADE TypeChecker" << endl;}
    TypeChecker(string n, TypeChecker *p) : scope(n), parent(p) ,st(p->st){} 
    ~TypeChecker() override {cout << "Destructor TypeChecker" << this << endl;}
       
        void visit(Node* n) override;
        Visitor* check_node(Node* n);
    private:
        std::unordered_map<std::string, int> type_system_;
        int type_count_;

        ST* tree_;
};
#endif