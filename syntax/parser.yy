%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;

  extern int node_id;
  
}
%token <std::string> PLUS MULT LESSTHAN MIN AND LP RP LB RB LM RM COMMA SEMICOLON DOT IF ELSE WHILE CLASS EXTENDS PUBLIC STATIC VOID BOOL INT STRING TRUE FALSE THIS NEW SYSTEMOUTPRINT RETURN LENGTH MAIN ID NUM EQ EXMARK
%token END 0 "end of file"
%type <Node *> Goal  MainClass ClassDeclarations ClassDeclaration VarDeclarations VarDeclaration MethodDeclarations MethodDeclaration Arguments Type Statements Statement Expressions Expression Operations Identifier

%%
Goal: MainClass ClassDeclarations END
{
  $$=new Node("Goal", "");
  $$->children.push_back($1);
  root = $$;
};

MainClass: CLASS Identifier LM PUBLIC STATIC VOID MAIN LP STRING LB RB Identifier RP LM Statement RM RM
{

};

ClassDeclarations: ClassDeclaration ClassDeclarations |
{

};

ClassDeclaration: CLASS Identifier EXTENDS Identifier LM VarDeclarations MethodDeclarations RM
                | CLASS Identifier LM VarDeclarations MethodDeclarations RM
{

};

VarDeclarations: VarDeclaration VarDeclarations |
{

};

VarDeclaration: Type Identifier SEMICOLON
{

};

MethodDeclarations: MethodDeclaration MethodDeclarations |
{

};

MethodDeclaration: PUBLIC Type Identifier LP Arguments RP LM VarDeclarations Statements RETURN Expression SEMICOLON RM
{

};

Arguments: Type Identifier | Type Identifier COMMA Arguments |
{

};

Type: INT LB RB | BOOL | INT | Identifier
{

};

Statements: Statement Statements |
{

};

Statement: LM Statements RM 
         | IF LP Expression RP Statement ELSE Statement
         | WHILE LP Expression RP Statement
         | SYSTEMOUTPRINT LP Expression RP SEMICOLON
         | Identifier EQ Expression SEMICOLON
         | Identifier LB Expression RB EQ Expression SEMICOLON
{

};

Expression: Expression Operations Expression
          | Expression LB Expression RB
          | Expression DOT LENGTH
          | Expression DOT Identifier LP Expressions RP
          | NUM
          | TRUE
          | FALSE
          | Identifier
          | THIS
          | NEW INT LB Expression RB
          | NEW Identifier LP RP
          | EXMARK Expression
          | LP Expression RP
{

};

Expressions: Expression | Expression COMMA Expressions |
{

};

Operations: PLUS | MIN | LESSTHAN | MULT | AND
{

};

Identifier: ID
{

};
