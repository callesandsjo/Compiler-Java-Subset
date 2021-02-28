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
                        $$->add_child($1);
                        $$->add_child($2);
                        root = $$;
                      }
;

MainClass: CLASS Identifier LM PUBLIC STATIC VOID MAIN LP STRING LB RB Identifier RP LM Statements RM RM
                      {
                        $$ = new Node("MainClass", "");
                        $$->add_child($2);
                        $$->add_child($12);
                        $$->add_child($15);
                      }
;

ClassDeclarations: ClassDeclaration ClassDeclarations
                      {
                        $$ = $2;
                        $$->add_child($1);
                      }
                    |
                      {
                        $$ = new Node("ClassDeclarations", "");
                      }
;

ClassDeclaration: CLASS Identifier EXTENDS Identifier LM VarDeclarations MethodDeclarations RM 
                      {                 
                        $$ = new Node("ClassDeclaration", "EXTENDED"); 
                        $$->add_child($2);
                        $$->add_child($4);
                        $$->add_child($6);
                        $$->add_child($7);
                      }
                  | CLASS Identifier LM VarDeclarations MethodDeclarations RM                    
                      {                 
                        $$ = new Node("ClassDeclaration", $2->value); 
                        $$->add_child($2);
                        $$->add_child($4);
                        $$->add_child($5);
                      }
                  | CLASS Identifier LM MethodDeclarations RM
                      {
                        $$ = new Node("ClassDeclaration", $2->value); 
                        $$->add_child($2);
                        $$->add_child($4);
                      }
                  | CLASS Identifier EXTENDS Identifier LM MethodDeclarations RM
                      {
                        $$ = new Node("ClassDeclaration", "EXTENDED"); 
                        $$->add_child($2);
                        $$->add_child($4);
                        $$->add_child($6);
                      }
;

VarDeclarations: VarDeclarations VarDeclaration 
                      {
                        //VarDeclarations: | VarDeclaration VarDeclarations 
                        $$ = $1;
                        $$->children.push_back($2);
                      }
                 |
                      {
                        $$ = new Node("VarDeclarations", "");
                      }
;

VarDeclaration: Type Identifier SEMICOLON
                      {
                        $$ = new Node("VarDeclaration", "TYPE");
                        $$->add_child($1);
                        $$->add_child($2);
                      }
;

MethodDeclarations: 
                      {
                        $$ = new Node("MethodDeclarations", "");
                      }
                      | MethodDeclaration MethodDeclarations
                      {
                        $$ = $2;
                        $$->add_child($1);
                      }
;

MethodDeclaration: PUBLIC Type Identifier LP Arguments RP LM VarDeclarations Statements RETURN Expression SEMICOLON RM
                      {
                        $$ = new Node("MethodDeclaration", $3->value);
                        $$->add_child($2);
                        $$->add_child($3);
                        $$->add_child($5);
                        $$->add_child($8);
                        $$->add_child($9);
                        $11->value = "RETURN";
                        $$->add_child($11);
                      }
                  | PUBLIC Type Identifier LP Arguments RP LM Statements RETURN Expression SEMICOLON RM
                      {
                        $$ = new Node("MethodDeclaration", $3->value);
                        $$->add_child($2);
                        $$->add_child($3);
                        $$->add_child($5);
                        $$->add_child($8);
                        $10->value = "RETURN";
                        $$->add_child($10);
                      }
;

Arguments: Type Identifier 
                      {
                        $$ = new Node("Arguments", "");
                        $$->add_child($1);
                        $$->add_child($2);
                      }
           | Type Identifier COMMA Arguments
                      {
                        $$ = $4;
                        $$->add_child($1);
                        $$->add_child($2);
                      }
           |
                      {
                        $$ = new Node("Arguments", "");
                      }
;

Type: INT LB RB
      {
        $$ = new Node("Type", "INT bracket"+$1);
      }
      | BOOL
      {
        $$ = new Node("Type", $1);
      } 
      | INT 
      {
        $$ = new Node("Type", $1);
      }
      | Identifier
      {
        $$ = new Node("Type", $1->value);
        $$->add_child($1);
      }
;

Statements: Statement Statements
{
              $$ = $2;
              $$->add_child($1);
}
            |
{
              $$ = new Node("Statements", "");
}
;

Statement: LM Statements RM 
            {
              $$ = new Node("Statement", ""); 
              $$->add_child($2);
            }
         | IF LP Expression RP Statement ELSE Statement 
            {
              $$ = new Node("Statement", "IF"); 
              $$->add_child($3);
              $$->add_child($5);
              $7->value = "ELSE " + $7->value;
              $$->add_child($7);
            }
         | WHILE LP Expression RP Statement
            {
              $$ = new Node("Statement", "WHILE");
              $$->add_child($3);
              $$->add_child($5); 
            }
         | SYSTEMOUTPRINT LP Expression RP SEMICOLON
            {
              $$ = new Node("Statement", "Syst print ");
              $$->add_child($3); 
            }
         | Identifier EQ Expression SEMICOLON
            {
              $$ = new Node("Statement", "Assigning");
              $$->add_child($1);
              $$->add_child($3); 
            }
         | Identifier LB Expression RB EQ Expression SEMICOLON
            {
              $$ = new Node("Statement", "list assignment");
              $$->add_child($1);
              $$->add_child($3);
              $$->add_child($6);
            }
;

Expressions: Expression
{
              $$ = new Node("Expressions", "");
              $$->add_child($1);
} 
            | Expression COMMA Expressions
{
              $$ = $3;
              $$->add_child($1);
}
            |
{
              $$ = new Node("Expressions", "");
}
;

Expression: Expression Operations Expression 
              { 
                $$ = $2;
                $$->add_child($1); 
                $$->add_child($3); 
              }
          | Expression LB Expression RB 
              { 
                $$ = new Node("Expression", "index"); 
                $$->add_child($1); 
                $$->add_child($3); 
              }
          | Expression DOT LENGTH 
              { 
                $$ = new Node("Expression", "list length"); 
                $$->add_child($1);
              }
          | Expression DOT Identifier LP Expressions RP 
              { 
                $$ = new Node("Expression", "method call"); 
                $$->add_child($1); 
                $$->add_child($3); 
                $$->add_child($5);
              }
          | NUM 
              { 
                $$ = new Node("Expression", $1);
              }
          | TRUE 
              { 
                $$ = new Node("Expression", $1);
              }
          | FALSE 
              { 
                $$ = new Node("Expression", $1);
              }
          | Identifier 
              { 
                $$ = new Node("Expression", "Identifier"); 
                $$->add_child($1);
              }
          | THIS 
              { 
                $$ = new Node("Expression", $1);
              }
          | NEW INT LB Expression RB 
              { 
                $$ = new Node("Expression", "New int"); 
                $$->add_child($4);
              }
          | NEW Identifier LP RP 
              { 
                $$ = new Node("Expression", "New"); 
                $$->add_child($2);
              }
          | EXMARK Expression 
              { 
                $$ = new Node("Expression", "!"); 
                $$->add_child($2);
              }
          | LP Expression RP 
              { 
                $$ = new Node("Expression", "Expression"); 
                $$->add_child($2);
              }
;


Operations: PLUS
              {
                $$ = new Node("Operations", $1); 
              }
          | MIN 
              {
                $$ = new Node("Operations", $1); 
              }
          | LESSTHAN
              {
                $$ = new Node("Operations", $1); 
              }
          | MULT 
              {
                $$ = new Node("Operations", $1); 
              }
          | AND
              {
                $$ = new Node("Operations", $1); 
              }
;

Identifier: ID
              {
                $$ = new Node("Identifier", $1);
              }
;
