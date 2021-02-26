#ifndef VISITOR_H
#define	VISITOR_H

class Node;

class Visitor {
public:
    Visitor() {std::cout << "SKAPADE Visitor" << std::endl;}
    virtual void visit(Node *n) = 0;
    virtual ~Visitor(){};
};

#endif