

compiler: lex.yy.c parser.tab.o main.cc TypeChecker.o AssignmentChecker.o
		g++ -g -o bin/compiler build/TypeChecker.o build/AssignmentChecker.o build/parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -c parser.tab.cc -o build/parser.tab.o -std=c++14
AssignmentChecker.o: frontend/semantics/AssignmentChecker.cc frontend/semantics/AssignmentChecker.h
		g++ -g -c frontend/semantics/AssignmentChecker.cc -o build/AssignmentChecker.o -std=c++14
TypeChecker.o: frontend/semantics/TypeChecker.cc frontend/semantics/TypeChecker.h
		g++ -g -c frontend/semantics/TypeChecker.cc -o build/TypeChecker.o -std=c++14
parser.tab.cc: frontend/syntax/parser.yy
		bison frontend/syntax/parser.yy
lex.yy.c: frontend/syntax/lexer.flex parser.tab.cc dirs
		flex frontend/syntax/lexer.flex
tree: 
		 dot -Tpdf tree.dot -otree.pdf
dirs:
	mkdir -p build/ && mkdir -p bin/
clean:
		rm -f parser.tab.* lex.yy.c* bin/compiler stack.hh tree.dot tree.pdf build/*
		#rm -R compiler.dSYM