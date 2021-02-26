compiler: lex.yy.c parser.tab.o main.cc ST.o
		g++ -g -ocompiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -c parser.tab.cc -std=c++14
ST.o: ST.cc Visitor.h ST.h
		g++ -g -c ST.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf ST.o
		#rm -R compiler.dSYM