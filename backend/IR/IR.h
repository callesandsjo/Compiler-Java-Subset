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
                TAC *newArrayAccessExp = new Assignment(genName(), genExpTAC((*it)) + "[" + genExpTAC((*++it)) + "]");
                currentBlock->addTAC(newArrayAccessExp);
                return newArrayAccessExp->result;
            }
            else if(node->value == "New")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new Assignment(genName(), genExpTAC((*it)));
                currentBlock->addTAC(newArrayNewExp);
                return newArrayNewExp->result;
            }
            else if(node->value == "New int")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new Assignment(genName(), genExpTAC((*it)));
                currentBlock->addTAC(newArrayNewExp);
                return newArrayNewExp->result;
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
                currentBlock->addTAC(newExp);
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
        if(node->type == "Expression")
        {
            
            if(node->value == "index")
            {
                
                auto it = node->children.begin();
                TAC *newArrayAccessExp = new Assignment(genName(), genExpTAC((*it)) + "[" + genExpTAC((*++it)) + "]");
                currentBlock->addTAC(newArrayAccessExp);
            }
            else if(node->value == "New")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new Assignment(genName(), genExpTAC((*it)));
                currentBlock->addTAC(newArrayNewExp);
            }
            else if(node->value == "New int")
            {
                
                auto it = node->children.begin();
                TAC *newArrayNewExp = new Assignment(genName(), genExpTAC((*it)));
                currentBlock->addTAC(newArrayNewExp);
            }
            else if(node->value == "!")
            {
                
                //Unary expression
                auto it = node->children.begin();
                TAC *newUnaryExp = new UnaryExpression(genName(), "!", genExpTAC((*it))); //result, lhs, operation, rhs
                this->currentBlock->addTAC(newUnaryExp);
            }
            else if(node->value == "operation")
            {
                
                auto it = node->children.begin();
                TAC *newExp = new Expression(genName(), genExpTAC((*it)), genExpTAC((*++it)), genExpTAC((*++it)));
                currentBlock->addTAC(newExp);
            }

    
        }
            
        
        else if(node->type == "Statement")
        {
            if(node->value == "Assigning" || node->value == "ELSE Assigning")
            {
                auto it = node->children.begin();
                TAC *newAssignment = new Assignment((*it)->value, genExpTAC((*++it)));
            }
            else if (node->value == "List Assigning")
            {
                auto it = node->children.begin();
                TAC *newAssignment = new Assignment((*it)->value + "[" + genExpTAC((*++it)) + "]", genExpTAC((*++it)));
            }
            

        }
        return;
    }
};

#endif