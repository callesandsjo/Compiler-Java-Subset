#include<iostream>
#include "parser.tab.hh"
#include <memory>
extern std::shared_ptr<Node> root;

void yy::parser::error(std::string const&err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

int main(int argc, char **argv)
{
  std::ofstream outStream;
  outStream.open("tree.dot");

  yy::parser parser;
  
  if(!parser.parse()) {
    std::cout << "Built a parse-tree:" << std::endl;
    root->print_tree();
    int count = 0;
    outStream << "digraph {" << std::endl;
    root->generate_tree(count, &outStream);
    outStream << "}" << std::endl;
    outStream.close();

    //Build symbol table
    //ST st;
    //root->buildST(st);

    //Semantic analysis
    //root->checkSemantics(st);
  }
  return 0;
}