#ifndef IR_H
#define IR_H

#include <list>
#include <iostream>
#include "../../frontend/Node.h"
#include "../../frontend/Visitor.h"
#include <map>
#include "BasicBlock.h"


struct IR : public Visitor{
    std::list<BasicBlock*> CFGs;
    BasicBlock *currentBlock; //helper for knowing which block should be modified
    IR()
    {
        currentBlock = new BasicBlock();
    }
    void visit(Node *node) override { //Visiting in postorder
        if (node == nullptr)
            return;
        
        for(auto children = node->children.begin(); children != node->children.end(); children++)
            visit(*children);
        
        parseNode(node);
    }
    std::string genExpTAC(Node *node)
    {

        if(node->type == "Expression")
        {
            if(node->value == "index")
            {
                
                auto it = node->children.begin();
                TAC *newArrayAccessExp = new AssignmentList(genName(), genExpTAC((*it)), genExpTAC((*++it)));
                currentBlock->addTAC(newArrayAccessExp);
                return newArrayAccessExp->result;
            }
            else if(node->value == "New")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new NewExpression(genName(), genExpTAC((*it)));
                this->currentBlock->addTAC(newArrayNewExp);
                return newArrayNewExp->result;
            }
            else if(node->value == "New int")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new NewArrayExpression(genName(), genExpTAC((*it)));
                this->currentBlock->addTAC(newArrayNewExp);
                return newArrayNewExp->result;
            }
            else if(node->value == "!")
            {
                
                //Unary expression
                auto it = node->children.begin();
                TAC *newUnaryExp = new UnaryExpression(genName(), "!", genExpTAC((*it))); //result, lhs, operation, rhs
                this->currentBlock->addTAC(newUnaryExp);
                return newUnaryExp->result;
            }
            else if (node->value == "operation")
            {
                
                auto it = node->children.begin();
                TAC *newExp = new Expression(genName(), genExpTAC((*it)), genExpTAC((*++it)), genExpTAC((*++it)));
                this->currentBlock->addTAC(newExp);
                return newExp->result;
            }
            else if (node->value == "list length")
            {
                
                auto it = node->children.begin();
                TAC *newExp = new LengthExpression(genName(), genExpTAC((*it)));
                this->currentBlock->addTAC(newExp);
                return newExp->result;
            }
            else if (node->value == "method call")
            {
                
                auto it = node->children.begin();
                uint16_t nParams = 0;
                for(auto params = (*it)->children.begin(); params != (*it)->children.end(); params++)
                {
                    nParams++;
                    TAC *newParam = new ParameterExpression(genExpTAC(*params));
                    this->currentBlock->addTAC(newParam);
                }
                    
                TAC *newExp = new MethodCallExpression(genName(), genExpTAC((*++it)), std::to_string(nParams));
                this->currentBlock->addTAC(newExp);
                return newExp->result;
            }
            


        }

        return node->value;
    }
    std::string genName()
    {

        return "t" + to_string(currentBlock->tempVars++);

    }
    void parseNode(Node *node) {
        
        if(node->type == "Statement")
        {
            if(node->value == "Assigning" || node->value == "ELSE Assigning")
            {
                auto it = node->children.begin();
                TAC *newAssignment = new Assignment((*it)->value, genExpTAC((*++it)));
                currentBlock->addTAC(newAssignment);
            }
            else if (node->value == "List Assigning")
            {
                auto it = node->children.begin();
                TAC *newListAssignment = new ListAssignment(genExpTAC((*it)), genExpTAC((*++it)), genExpTAC((*++it)));
                currentBlock->addTAC(newListAssignment);
            }
            else if (node->value == "sys print" || node->value == "IF" || node->value == "WHILE")
            {
                auto it = node->children.begin();
                TAC *newListAssignment = new Assignment(genName(), genExpTAC((*it)));
                currentBlock->addTAC(newListAssignment);
            }
            //IF, ELSE, WHILE, FOR ... will create new blocks

        }
        else if(node->type == "MethodDeclaration")
        {
            auto it = node->children.end();
            it--;
            TAC *newReturnTAC = new ReturnExpression(genExpTAC((*it)));
            currentBlock->addTAC(newReturnTAC);

        }
        
        
        /*if(node->type == "Expression")
        {
            
            if(node->value == "index")
            {
                
                auto it = node->children.begin();
                TAC *newArrayAccessExp = new AssignmentList(genName(), genExpTAC((*it)), genExpTAC((*++it)));
                currentBlock->addTAC(newArrayAccessExp);
            }
            else if(node->value == "New")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new NewExpression(genName(), genExpTAC((*it)));
                this->currentBlock->addTAC(newArrayNewExp);
            }
            else if(node->value == "New int")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new NewArrayExpression(genName(), genExpTAC((*it)));
                this->currentBlock->addTAC(newArrayNewExp);
            }
            else if(node->value == "!")
            {
                
                //Unary expression
                auto it = node->children.begin();
                TAC *newUnaryExp = new UnaryExpression(genName(), "!", genExpTAC((*it))); //result, lhs, operation, rhs
                this->currentBlock->addTAC(newUnaryExp);
            }
            else if (node->value == "operation")
            {
                
                auto it = node->children.begin();
                TAC *newExp = new Expression(genName(), genExpTAC((*it)), genExpTAC((*++it)), genExpTAC((*++it)));
                this->currentBlock->addTAC(newExp);
            }

    
        }*/
            
        
        /*else if(node->type == "Statement")
        {
            if(node->value == "Assigning" || node->value == "ELSE Assigning")
            {
                auto it = node->children.begin();
                TAC *newAssignment = new Assignment((*it)->value, genExpTAC((*++it)));
                currentBlock->addTAC(newAssignment);
            }
            else if (node->value == "List Assigning")
            {
                auto it = node->children.begin();
                TAC *newListAssignment = new ListAssignment(genExpTAC((*it)), genExpTAC((*++it)), genExpTAC((*++it)));
                currentBlock->addTAC(newListAssignment);
            }
            //IF, ELSE, WHILE, FOR ... will create new blocks

        }*/
        //Classes to create more CFG
        return;
    }
};

#endif