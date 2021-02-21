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
%token <std::string> PLUSOP MULTOP INT LP RP
%token END 0 "end of file"
%type <Node *> expression  addExpression multExpression factor

%%
Goal: MainClass ClassDeclarations EOF
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

Arguments: Type Identifier | Type Identifier COLON Arguments |
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
          | Expression DOT LENTH
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

Expressions: Expression | Expression COLON Expressions |
{

};

Operations: PLUS | MIN | LESSTHAN | MULT | AND
{

};

Identifier: ID
{

};


expression: addExpression 
                          {
                            $$ = new Node("Expression", "");
                            $$->children.push_back($1);
                            root = $$;
                          };

addExpression: multExpression { $$ = $1; }
      | addExpression PLUSOP multExpression { 
                            $$ = new Node("AddExpression", "");
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
      ;

multExpression: factor  { $$ = $1; }
        | multExpression MULTOP factor        { 
                        $$ = new Node("MultExpression", ""); 
                        $$->children.push_back($1);
                        $$->children.push_back($3);
                      }
        ;

factor: INT  {  $$ = new Node("Int", $1); }
    | LP expression RP { $$ = $2; }
    ;