#ifndef NODEFACT_H
#define	NODEFACT_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "Visitor.h"
#include "Node.h"
#include <cstdio>


using namespace std;


class NodeFact {
public:
	Node * newNode(string t, string v);
};

#endif