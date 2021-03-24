compiler: lex.yy.c parser.tab.o main.cc ST.o TypeChecker.o AssignmentChecker.o NodeFact.o
		g++ -g -ocompiler TypeChecker.o AssignmentChecker.o ST.o parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -c parser.tab.cc -std=c++14
AssignmentChecker.o: AssignmentChecker.cc AssignmentChecker.h
		g++ -g -c AssignmentChecker.cc -std=c++14
ST.o: ST.cc Visitor.h ST.h
		g++ -g -c ST.cc -std=c++14
NodeFact.o: NodeFact.cc NodeFact.h
		g++ -g -c NodeFact.cc -std=c++14
TypeChecker.o: TypeChecker.cc TypeChecker.h
		g++ -g -c TypeChecker.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex

CC=g++
CFLAGS=-std=c++14
DEPS = node/AddExpression.h ST.h
OBJ = node/AddExpression.o ST.cc

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf ST.o AssignmentChecker.o TypeChecker.o
		#rm -R compiler.dSYM