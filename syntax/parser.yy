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