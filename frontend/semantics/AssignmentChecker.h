#ifndef AssignmentChecker_H
#define AssignmentChecker_H
#include <algorithm>
#include <unordered_map>
#include "../Node.h"
#include "../Visitor.h"
#include "../symboltable/ST.h"
using namespace std;
class AssignmentChecker : public Visitor
{
    public:
    ST* st;
    string scope;
    AssignmentChecker *parent;
    std::list<std::string> listOfStrs = {"Identifier", "MainClass", "MethodDeclaration", "ClassDeclaration"};
    std::map<std::string, string> identif_map;
    std::map<std::string, AssignmentChecker*> method_map;
    std::map<std::string, AssignmentChecker*> class_map;
	AssignmentChecker(ST* s) : scope(""), parent(0) ,st(s){cout << "SKAPADE AssignmentChecker" << endl;}
    AssignmentChecker(string n, AssignmentChecker *p) : scope(n), parent(p) ,st(p->st){} 
       
        void visit(Node* n) override;
        Visitor* check_node(Node* n);
    private:
        std::unordered_map<std::string, int> type_system_;
        int type_count_;

        ST* tree_;
};
#endif