#include<iostream>
#include "parser.tab.hh"
#include <memory>
#include "ST.h"
extern std::shared_ptr<Node> root;
extern FILE* yyin;

void yy::parser::error(std::string const&err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

int main(int argc, char **argv)
{
  if(argc > 1) {
    if(!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
    else{
      yyin = fopen(argv[1], "r"); 
    }
      
  }

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
    ST st;
    root->buildST(&st);
    st.print();

    //Semantic analysis
    //root->checkSemantics(st);
  }
  return 0;
}