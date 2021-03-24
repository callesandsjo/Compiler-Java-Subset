#ifndef NODE_H
#define NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "Visitor.h"
#include "BBlock.h"
#include <cstdio>
#include <map>

using namespace std;

class Node
{
public:
	int id;
	Node *parent;
	string type, value;
	list<Node *> children;
	static map<std::string, BBlock *> *entry_blocks;
	Node(string t, string v) : type(t), value(v) { cout << "creating node " << t << " " << v << endl; }
	Node()
	{
		type = "uninitialised";
		value = "uninitialised";
	} // Bison needs this.

	void print_tree(int depth = 0)
	{
		for (int i = 0; i < depth; i++)
			cout << "  ";
		cout << type << ":" << value << endl;
		//cout << "children=" << children.size() << endl;
		for (auto i = children.begin(); i != children.end(); i++)
		{
			(*i)->print_tree(depth + 1);
		}
	}

	Node *add_child(Node *n)
	{
		cout << "adding child: " << n->type << endl;
		n->parent = this;
		children.push_back(n);
		return this;
	}

	Node *prepend_child(Node *n)
	{
		cout << "adding child: " << n->type << endl;
		n->parent = this;
		children.push_front(n);
		return this;
	}

	void generate_tree(int &count, ofstream *outStream)
	{
		id = count++;
		*outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

		for (auto i = children.begin(); i != children.end(); i++)
		{
			(*i)->generate_tree(count, outStream);
			*outStream << "n" << id << " -> n" << (*i)->id << endl;
		}
	}

	void accept(Visitor *st)
	{
		//cout<< "Node "<<this<<" visitor "<<st<< endl;
		st->visit(this);
	}

	std::string getClassName()
	{
		Node *p = this;
		while (p != nullptr)
		{
			if (p->type == "ClassDeclaration" || p->type == "MainClass")
			{
				return p->value;
			}
			else
			{
				p = p->parent;
			}
		}
		return "MainClass";
	}

	std::string genName()
	{
		char buffer[100];
		static int counter = 0;
		counter++;
		std::sprintf(buffer, "block_%d", counter);
		return buffer;
	}

	std::string genTmpName()
	{
		char buffer[100];
		static int counter = 0;
		counter++;
		std::sprintf(buffer, "_t%d", counter);
		return buffer;
	}

	virtual BBlock *genIR(BBlock *currblock, std::string &ret_name) { return currblock; }
};

#endif