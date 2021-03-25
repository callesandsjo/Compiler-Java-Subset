%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #include "NodeFact.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;

  extern int node_id;
  
}
%token <std::string> PLUS MULT LESSTHAN MIN AND LP RP LB RB LM RM COMMA SEMICOLON DOT IF ELSE WHILE CLASS EXTENDS PUBLIC STATIC VOID BOOL INT STRING TRUE FALSE THIS NEW SYSTEMOUTPRINT RETURN LENGTH MAIN ID NUM EQ EXMARK
%token END 0 "end of file"
%type <Node *> Goal  MainClass ClassDeclarations ClassDeclaration VarDeclarations VarDeclaration MethodDeclarations MethodDeclaration Arguments Type Statements Statement Expressions Expression Identifier MultFactor SubTerm

%%
Goal: MainClass ClassDeclarations END
                      {
                        $$=NodeFact::newNode("Goal", "");
                        $$->add_child($1);
                        $$->add_child($2);
                        root = $$;
                      }
;

MainClass: CLASS Identifier LM PUBLIC STATIC VOID MAIN LP STRING LB RB Identifier RP LM Statements RM RM
                      {
                        $$ =NodeFact::newNode("MainClass", "");
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                        $$->add_child(NodeFact::newNode("Identifier", $12->value));
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
                        $$ = NodeFact::newNode("ClassDeclarations", "");
                      }
;

ClassDeclaration: CLASS Identifier EXTENDS Identifier LM VarDeclarations MethodDeclarations RM 
                      {                 
                        $$ = NodeFact::newNode("ClassDeclaration", "EXTENDED");
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                        $$->add_child(NodeFact::newNode("Identifier", $4->value));
                        $$->add_child($6);
                        $$->add_child($7);
                      }
                  | CLASS Identifier LM VarDeclarations MethodDeclarations RM                    
                      {                 
                        $$ = NodeFact::newNode("ClassDeclaration", $2->value); 
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                        $$->add_child($4);
                        $$->add_child($5);
                      }
                  | CLASS Identifier LM MethodDeclarations RM
                      {
                        $$ = NodeFact::newNode("ClassDeclaration", $2->value); 
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                        $$->add_child($4);
                      }
                  | CLASS Identifier EXTENDS Identifier LM MethodDeclarations RM
                      {
                        $$ = NodeFact::newNode("ClassDeclaration", "EXTENDED"); 
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                        $$->add_child(NodeFact::newNode("Identifier", $4->value));
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
                        $$ = NodeFact::newNode("VarDeclarations", "");
                      }
;

VarDeclaration: Type Identifier SEMICOLON
                      {
                        $$ = NodeFact::newNode("VarDeclaration", "TYPE");
                        $$->add_child($1);
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                      }
;

MethodDeclarations: 
                      {
                        $$ = NodeFact::newNode("MethodDeclarations", "");
                      }
                      | MethodDeclaration MethodDeclarations
                      {
                        $$ = $2;
                        $$->add_child($1);
                      }
;

MethodDeclaration: PUBLIC Type Identifier LP Arguments RP LM VarDeclarations Statements RETURN Expression SEMICOLON RM
                      {
                        $$ = NodeFact::newNode("MethodDeclaration", $3->value);
                        $$->add_child(NodeFact::newNode("Type", $2->value));
                        $$->add_child(NodeFact::newNode("Identifier", $3->value));
                        $$->add_child($5);
                        $$->add_child($8);
                        $$->add_child($9);
                        $$->add_child(NodeFact::newNode("Return", "RETURN")->add_child($11));
                      }
                  | PUBLIC Type Identifier LP Arguments RP LM Statements RETURN Expression SEMICOLON RM
                      {
                        $$ = NodeFact::newNode("MethodDeclaration", $3->value);
                        $$->add_child($2);
                        $$->add_child(NodeFact::newNode("Identifier", $3->value));
                        $$->add_child($5);
                        $$->add_child($8);
                        $$->add_child(NodeFact::newNode("Return", "RETURN")->add_child($10));
                      }
;

Arguments: Type Identifier 
                      {
                        $$ = NodeFact::newNode("Arguments", "");
                        $$->add_child($1);
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                      }
           | Type Identifier COMMA Arguments
                      {
                        $$ = $4;
                        $$->add_child($1);
                        $$->add_child(NodeFact::newNode("Identifier", $2->value));
                      }
           |
                      {
                        $$ = NodeFact::newNode("Arguments", "");
                      }
;

Type: INT LB RB
      {
        $$ = NodeFact::newNode("Type", "INT bracket"+$1);
      }
      | BOOL
      {
        $$ = NodeFact::newNode("Integer", $1);
      } 
      | INT 
      {
        $$ = NodeFact::newNode("Integer", $1);
      }
      | Identifier
      {
        $$ = NodeFact::newNode("Identifier", $1->value);
        $$->add_child($1);
      }
;

Statements: Statement Statements
{
              $$ = $2;
              $$->prepend_child($1);
              //$$->add_child($1);
}
            |
{
              $$ = NodeFact::newNode("Statements", "");
}
;

Statement: LM Statements RM 
            {
              $$ = NodeFact::newNode("Statement", ""); 
              $$->add_child($2);
            }
         | IF LP Expression RP Statement ELSE Statement 
            {
              $$ = NodeFact::newNode("IfStatement", "IF");
              $$->add_child($3);
              $$->add_child($5);
              $7->value = "ELSE " + $7->value;
              $$->add_child($7);
            }
         | WHILE LP Expression RP Statement
            {
              $$ = NodeFact::newNode("WhileStatement", "WHILE");
              $$->add_child($3);
              $$->add_child($5); 
            }
         | SYSTEMOUTPRINT LP Expression RP SEMICOLON
            {
              $$ = NodeFact::newNode("SystemPrint", "Syst print ");
              $$->add_child($3); 
            }
         | Identifier EQ Expression SEMICOLON
            {
              $$ = NodeFact::newNode("StatementAssigning", "Assigning");
              $$->add_child($1);
              $$->add_child($3); 
            }
         | Identifier LB Expression RB EQ Expression SEMICOLON
            {
              $$ = NodeFact::newNode("StatementListAssigning", "List Assigning");
              $$->add_child($1);
              $$->add_child($3);
              $$->add_child($6);
            }
;

Expressions: Expression
{
              $$ = NodeFact::newNode("Expressions", "");
              $$->add_child($1);
} 
            | Expression COMMA Expressions
{
              $$ = $3;
              $$->add_child($1);
}
            |
{
              $$ = NodeFact::newNode("Expressions", "");
}
;

Expression: Expression AND Expression 
              { 
                $$ = NodeFact::newNode("AndOperation", $2);
                $$->add_child($1); 
                $$->add_child($3); 
              }
          |
          Expression LESSTHAN Expression 
              { 
                $$ = NodeFact::newNode("LessThanOperation", $2); 
                $$->add_child($1); 
                $$->add_child($3); 
              }
          |
          Expression PLUS Expression   
              { 
                $$ = NodeFact::newNode("AddExpression", $2);
                $$->add_child($1); 
                $$->add_child($3); 
              }
          |
          SubTerm MIN SubTerm   
              { 
                $$ = NodeFact::newNode("SubExpression", $2);
                $$->add_child($1); 
                $$->add_child($3); 
              }
          |  MultFactor MULT MultFactor 
              { 
                $$ = NodeFact::newNode("MulExpression", $2);
                $$->add_child($1); 
                $$->add_child($3); 
              }
          | 
          
          Expression LB Expression RB 
              { 
                $$ = NodeFact::newNode("Expression", "index"); 
                $$->add_child($1); 
                $$->add_child($3); 
              }
          | Expression DOT LENGTH 
              { 
                $$ = NodeFact::newNode("Expression", "list length"); 
                $$->add_child($1);
              }
          | Expression DOT Identifier LP Expressions RP 
              { 
                $$ = NodeFact::newNode("MethodCall", "method call");
                $$->add_child($1); 
                $$->add_child(NodeFact::newNode("Identifier", $3->value));
                $$->add_child($5);
              }
          | NUM 
              { 
                $$ = NodeFact::newNode("Expression", $1);
              }
          | TRUE 
              { 
                $$ = NodeFact::newNode("Expression", $1);
              }
          | FALSE 
              { 
                $$ = NodeFact::newNode("Expression", $1);
              }
          | Identifier 
              { 
                $$ = NodeFact::newNode("Identifier", $1->value);
              }
          | THIS 
              { 
                $$ = NodeFact::newNode("Expression", $1);
              }
          | NEW INT LB Expression RB 
              { 
                $$ = NodeFact::newNode("ExpressionNewArray", "int"); 
                $$->add_child($4);
              }
          | NEW Identifier LP RP 
              { 
                $$ = NodeFact::newNode("ExpressionNew", "New"); 
                $$->add_child($2);
              }
          | EXMARK Expression 
              { 
                $$ = NodeFact::newNode("ExpressionExmark", "!"); 
                $$->add_child($2);
              }
          | LP Expression RP 
              { 
                $$ = NodeFact::newNode("Expression", "ExpressionWKid"); 
                $$->add_child($2);
              }
;


MultFactor: ID
              {
                $$ = NodeFact::newNode("Identifier", $1);
              }
        |
        NUM
              {
                $$ = NodeFact::newNode("Expression", $1);
              }
        | LP Expression RP 
              { 
                $$ = NodeFact::newNode("Expression", "ExpressionWKid"); 
                $$->add_child($2);
              }
;

SubTerm: MultFactor MULT MultFactor
              {
                $$ = NodeFact::newNode("MulExpression", $2);
                $$->add_child($1); 
                $$->add_child($3); 
              }
        | ID
              {
                $$ = NodeFact::newNode("Identifier", $1);
              }
        |
        NUM
              {
                $$ = NodeFact::newNode("Expression", $1);
              }
        | LP Expression RP 
              { 
                $$ = NodeFact::newNode("Expression", "ExpressionWKid"); 
                $$->add_child($2);
              }
;

Identifier: ID
              {
                $$ = NodeFact::newNode("Identifier", $1);
              }
;
