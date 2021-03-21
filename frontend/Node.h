#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "Visitor.h"

using namespace std;


class Node {
public:
	int id;
	Node *parent;
	string type, value;
	list<Node*> children;
	Node(string t, string v) : type(t), value(v) {cout << "creating node " << t << " " << v <<  endl;}
	Node()
	{
		type = "uninitialised";
		value = "uninitialised"; }   // Bison needs this.
  
  void print_tree(int depth=0) {
    for(int i=0; i<depth; i++)
      cout << "  ";
    cout << type << ":" << value << endl;
	//cout << "children=" << children.size() << endl;
    for(auto i=children.begin(); i!=children.end(); i++)
		{
      		(*i)->print_tree(depth+1);
		}
  }

  void add_child(Node *n) {
	cout << "adding child: " << n->type << endl;
	n->parent = this;
	children.push_back(n);
  }

  void prepend_child(Node *n) {
	cout << "adding child: " << n->type << endl;
	n->parent = this;
	children.push_front(n);
  }

  void generate_tree(int &count, ofstream *outStream) {
	  id = count++;
	  *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

	  for (auto i = children.begin(); i != children.end(); i++)
	  {
		  (*i)->generate_tree(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << endl;
	  }
  }

  void accept(Visitor *st) {
	  //cout<< "Node "<<this<<" visitor "<<st<< endl;
		st->visit(this);
  }

};

#endif