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
                    $$ = new Node("MainClass", "");
                    $$->children.push_back($2);
                    $$->children.push_back($12);
                    $$->children.push_back($15);
                    root = $$;
};

ClassDeclarations: | ClassDeclaration ClassDeclarations
{
                    //$$ = $2;
                    $$ = new Node("ClassDeclarations", "");
                    $$->children.push_back($1);

};

ClassDeclaration: CLASS Identifier EXTENDS Identifier LM VarDeclarations MethodDeclarations RM 
{                 $$ = new Node("ClassDeclaration", ""); 
                  $$->children.push_back($2);
                  $$->children.push_back($4);
                  $$->children.push_back($6);
                  $$->children.push_back($7);
}
                  | CLASS Identifier LM VarDeclarations MethodDeclarations RM                    
{                 $$->children.push_back($2);
                  $$->children.push_back($4);
                  $$->children.push_back($5);}
;

VarDeclarations: | VarDeclaration VarDeclarations {
                  $$ = new Node("VarDeclarations", "");
                  $$->children.push_back($1);

};

VarDeclaration: Type Identifier SEMICOLON
{
                  $$ = new Node("ClassDeclaration", "");
                  $$->children.push_back($2);

};

MethodDeclarations: | MethodDeclaration MethodDeclarations
{
                  $$ = new Node("MethodDeclarations", "");
                  $$->children.push_back($1);
};

MethodDeclaration: PUBLIC Type Identifier LP Arguments RP LM VarDeclarations Statements RETURN Expression SEMICOLON RM
{
                  $$ = new Node("MethodDeclaration", "");
                  $$->children.push_back($3);
                  $$->children.push_back($5);
                  $$->children.push_back($8);
                  $$->children.push_back($9);
                  $$->children.push_back($11);
};


Arguments: | Type Identifier 
{
                  $$ = new Node("Arguments", "");
                  $$->children.push_back($2);
}
           | Type Identifier COMMA Arguments
{
                  $$ = new Node("Arguments", "");
                  $$->children.push_back($2);     
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
