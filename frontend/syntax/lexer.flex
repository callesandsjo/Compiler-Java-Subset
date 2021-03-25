%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "frontend/Node.h"
}
%option noyywrap nounput batch noinput stack
%%

"*"                         {return yy::parser::make_MULT(yytext);}
"+"                         {return yy::parser::make_PLUS(yytext);}
"="                         {return yy::parser::make_EQ(yytext);}

"<"                         {return yy::parser::make_LESSTHAN(yytext);}
"-"                         {return yy::parser::make_MIN(yytext);}
"&&"                        {return yy::parser::make_AND(yytext);}

"("                         {return yy::parser::make_LP(yytext);}
")"                         {return yy::parser::make_RP(yytext);}
"["                         {return yy::parser::make_LB(yytext);}
"]"                         {return yy::parser::make_RB(yytext);}
"{"                         {return yy::parser::make_LM(yytext);}
"}"                         {return yy::parser::make_RM(yytext);}
","                         {return yy::parser::make_COMMA(yytext);}
";"                         {return yy::parser::make_SEMICOLON(yytext);}
"."                         {return yy::parser::make_DOT(yytext);}
"!"                         {return yy::parser::make_EXMARK(yytext);}

"if"                        {return yy::parser::make_IF(yytext);}
"else"                      {return yy::parser::make_ELSE(yytext);}
"while"                     {return yy::parser::make_WHILE(yytext);}
"class"                     {return yy::parser::make_CLASS(yytext);}
"extends"                   {return yy::parser::make_EXTENDS(yytext);}
"public"                    {return yy::parser::make_PUBLIC(yytext);}
"static"                    {return yy::parser::make_STATIC(yytext);}
"void"                      {return yy::parser::make_VOID(yytext);}
"boolean"                   {return yy::parser::make_BOOL(yytext);}
"int"                       {return yy::parser::make_INT(yytext);}
"String"                    {return yy::parser::make_STRING(yytext);}
"true"                      {return yy::parser::make_TRUE(yytext);}
"false"                     {return yy::parser::make_FALSE(yytext);}
"this"                      {return yy::parser::make_THIS(yytext);}
"new"                       {return yy::parser::make_NEW(yytext);}
"System.out.println"        {return yy::parser::make_SYSTEMOUTPRINT(yytext);}
"return"                    {return yy::parser::make_RETURN(yytext);}
"length"                    {return yy::parser::make_LENGTH(yytext);}
"main"                      {return yy::parser::make_MAIN(yytext);}

[a-zA-Z]([a-zA-Z0-9]|_)*    {return yy::parser::make_ID(yytext);}


(0|[1-9])?[0-9]*            {return yy::parser::make_NUM(yytext);}

"//".*"\n"                        { /* Comment */  }
"/*"(.|"\n")*"*\\"                { /* Comment */  }
\n                                {  yylineno++; }

[ \t]+                    {}

<<EOF>>                 return yy::parser::make_END();
%%