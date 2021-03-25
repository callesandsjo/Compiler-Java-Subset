#Makefile
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/compiler
SRC := $(wildcard $(SRC_DIR)/*.cc)
OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -I.
CFLAGS   := -g -std=c++14
LDFLAGS  := -Llib
LDLIBS   := -lm
CC		:= g++
.PHONY: all clean

all: $(EXE) lex.yy.o  parser.tab.o

parser.tab.cc: parser.yy
	bison parser.yy

lex.yy.c: lexer.flex parser.tab.cc
	flex lexer.flex

parser.tab.o: parser.tab.cc
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

tree:
	dot -Tpdf tree.dot -otree.pdf
	dot -Tpdf IRtree.dot -oirtree.pdf

$(EXE): parser.tab.o lex.yy.o $(OBJ) | $(BIN_DIR)
	@echo
	@echo Create $@
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	@echo
	@echo Compile $<
	$(CC) $(CPPFLAGS) $(CFLAGS) -MD -c $< -o $@

	@sed -e 's/\#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d>> obj/$*.d

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)  parser.tab.cc parser.tab.hh lex.yy.c lex.yy.o parser.tab.o IRtree.dot irtree.pdf tree.dot tree.pdf stack.hh

-include $(OBJ:.o=.d)