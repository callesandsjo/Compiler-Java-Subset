#include <iostream>
#include "parser.tab.hh"
#include <memory>
#include "ST.h"
#include "TypeChecker.h"
#include "AssignmentChecker.h"
extern std::shared_ptr<Node> root;
extern FILE *yyin;
extern int yylineno;

void yy::parser::error(std::string const &err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << " on line:" << yylineno << std::endl;
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    if (!(yyin = fopen(argv[1], "r")))
    {
      perror(argv[1]);
      return 1;
    }
    else
    {
      yyin = fopen(argv[1], "r");
    }
  }

  std::ofstream outStream;
  outStream.open("out/tree.dot");

  yy::parser parser;

  if (!parser.parse())
  {
    std::cout << "Built a parse-tree:" << std::endl;
    root->print_tree();
    int count = 0;
    outStream << "digraph {" << std::endl;
    root->generate_tree(count, &outStream);
    outStream << "}" << std::endl;
    outStream.close();

    //Build symbol table
    ST st;
    root->accept(&st);
    st.print();

    //Semantic analysis

    TypeChecker tc(&st);
    root->accept(&tc);
    AssignmentChecker ac(&st);
    root->accept(&ac);

    //root->checkSemantics(st);

    BBlock *b = new BBlock();
    b->name = "start";
    Node::entry_blocks->insert(std::pair<std::string, BBlock *>(b->name, b));
    std::string ret;
    root->genIR(b, ret);
    std::ofstream outIrStream;
    outIrStream.open("out/IRtree.dot");
    outIrStream << "digraph {" << std::endl;
    outIrStream << "graph [splines=ortho]" << std::endl;
    outIrStream << "node [shape=box];" << std::endl;
    for (auto const &elem : (*Node::entry_blocks))
    {
      elem.second->generate_tree(&outIrStream);
    }
    outIrStream << "}" << std::endl;
    outIrStream.close();

    // Basically BBlock generateByteCode
    for (auto const &elem : (*Node::entry_blocks))
    {
      int instructionCounter = 0;
      std::ofstream outByteStream;
      outByteStream.open("out/"+elem.first+".byteCode");
      elem.second->generateCode(&outByteStream, instructionCounter);
      outByteStream.flush();
      outByteStream.close();
    }

  }
  return 0;
}