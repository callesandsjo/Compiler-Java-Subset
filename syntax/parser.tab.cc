// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 11 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;

  extern int node_id;
  

#line 56 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 128 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 41: // Goal
      case 42: // MainClass
      case 43: // ClassDeclarations
      case 44: // ClassDeclaration
      case 45: // VarDeclarations
      case 46: // VarDeclaration
      case 47: // MethodDeclarations
      case 48: // MethodDeclaration
      case 49: // Arguments
      case 50: // Type
      case 51: // Statements
      case 52: // Statement
      case 53: // Expression
      case 54: // Expressions
      case 55: // Operations
      case 56: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUS
      case 4: // MULT
      case 5: // LESSTHAN
      case 6: // MIN
      case 7: // AND
      case 8: // LP
      case 9: // RP
      case 10: // LB
      case 11: // RB
      case 12: // LM
      case 13: // RM
      case 14: // COMMA
      case 15: // SEMICOLON
      case 16: // DOT
      case 17: // IF
      case 18: // ELSE
      case 19: // WHILE
      case 20: // CLASS
      case 21: // EXTENDS
      case 22: // PUBLIC
      case 23: // STATIC
      case 24: // VOID
      case 25: // BOOL
      case 26: // INT
      case 27: // STRING
      case 28: // TRUE
      case 29: // FALSE
      case 30: // THIS
      case 31: // NEW
      case 32: // SYSTEMOUTPRINT
      case 33: // RETURN
      case 34: // LENGTH
      case 35: // MAIN
      case 36: // ID
      case 37: // NUM
      case 38: // EQ
      case 39: // EXMARK
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 41: // Goal
      case 42: // MainClass
      case 43: // ClassDeclarations
      case 44: // ClassDeclaration
      case 45: // VarDeclarations
      case 46: // VarDeclaration
      case 47: // MethodDeclarations
      case 48: // MethodDeclaration
      case 49: // Arguments
      case 50: // Type
      case 51: // Statements
      case 52: // Statement
      case 53: // Expression
      case 54: // Expressions
      case 55: // Operations
      case 56: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUS
      case 4: // MULT
      case 5: // LESSTHAN
      case 6: // MIN
      case 7: // AND
      case 8: // LP
      case 9: // RP
      case 10: // LB
      case 11: // RB
      case 12: // LM
      case 13: // RM
      case 14: // COMMA
      case 15: // SEMICOLON
      case 16: // DOT
      case 17: // IF
      case 18: // ELSE
      case 19: // WHILE
      case 20: // CLASS
      case 21: // EXTENDS
      case 22: // PUBLIC
      case 23: // STATIC
      case 24: // VOID
      case 25: // BOOL
      case 26: // INT
      case 27: // STRING
      case 28: // TRUE
      case 29: // FALSE
      case 30: // THIS
      case 31: // NEW
      case 32: // SYSTEMOUTPRINT
      case 33: // RETURN
      case 34: // LENGTH
      case 35: // MAIN
      case 36: // ID
      case 37: // NUM
      case 38: // EQ
      case 39: // EXMARK
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 41: // Goal
      case 42: // MainClass
      case 43: // ClassDeclarations
      case 44: // ClassDeclaration
      case 45: // VarDeclarations
      case 46: // VarDeclaration
      case 47: // MethodDeclarations
      case 48: // MethodDeclaration
      case 49: // Arguments
      case 50: // Type
      case 51: // Statements
      case 52: // Statement
      case 53: // Expression
      case 54: // Expressions
      case 55: // Operations
      case 56: // Identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // PLUS
      case 4: // MULT
      case 5: // LESSTHAN
      case 6: // MIN
      case 7: // AND
      case 8: // LP
      case 9: // RP
      case 10: // LB
      case 11: // RB
      case 12: // LM
      case 13: // RM
      case 14: // COMMA
      case 15: // SEMICOLON
      case 16: // DOT
      case 17: // IF
      case 18: // ELSE
      case 19: // WHILE
      case 20: // CLASS
      case 21: // EXTENDS
      case 22: // PUBLIC
      case 23: // STATIC
      case 24: // VOID
      case 25: // BOOL
      case 26: // INT
      case 27: // STRING
      case 28: // TRUE
      case 29: // FALSE
      case 30: // THIS
      case 31: // NEW
      case 32: // SYSTEMOUTPRINT
      case 33: // RETURN
      case 34: // LENGTH
      case 35: // MAIN
      case 36: // ID
      case 37: // NUM
      case 38: // EQ
      case 39: // EXMARK
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 41: // Goal
      case 42: // MainClass
      case 43: // ClassDeclarations
      case 44: // ClassDeclaration
      case 45: // VarDeclarations
      case 46: // VarDeclaration
      case 47: // MethodDeclarations
      case 48: // MethodDeclaration
      case 49: // Arguments
      case 50: // Type
      case 51: // Statements
      case 52: // Statement
      case 53: // Expression
      case 54: // Expressions
      case 55: // Operations
      case 56: // Identifier
        value.move< Node * > (that.value);
        break;

      case 3: // PLUS
      case 4: // MULT
      case 5: // LESSTHAN
      case 6: // MIN
      case 7: // AND
      case 8: // LP
      case 9: // RP
      case 10: // LB
      case 11: // RB
      case 12: // LM
      case 13: // RM
      case 14: // COMMA
      case 15: // SEMICOLON
      case 16: // DOT
      case 17: // IF
      case 18: // ELSE
      case 19: // WHILE
      case 20: // CLASS
      case 21: // EXTENDS
      case 22: // PUBLIC
      case 23: // STATIC
      case 24: // VOID
      case 25: // BOOL
      case 26: // INT
      case 27: // STRING
      case 28: // TRUE
      case 29: // FALSE
      case 30: // THIS
      case 31: // NEW
      case 32: // SYSTEMOUTPRINT
      case 33: // RETURN
      case 34: // LENGTH
      case 35: // MAIN
      case 36: // ID
      case 37: // NUM
      case 38: // EQ
      case 39: // EXMARK
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 41: // Goal
      case 42: // MainClass
      case 43: // ClassDeclarations
      case 44: // ClassDeclaration
      case 45: // VarDeclarations
      case 46: // VarDeclaration
      case 47: // MethodDeclarations
      case 48: // MethodDeclaration
      case 49: // Arguments
      case 50: // Type
      case 51: // Statements
      case 52: // Statement
      case 53: // Expression
      case 54: // Expressions
      case 55: // Operations
      case 56: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // PLUS
      case 4: // MULT
      case 5: // LESSTHAN
      case 6: // MIN
      case 7: // AND
      case 8: // LP
      case 9: // RP
      case 10: // LB
      case 11: // RB
      case 12: // LM
      case 13: // RM
      case 14: // COMMA
      case 15: // SEMICOLON
      case 16: // DOT
      case 17: // IF
      case 18: // ELSE
      case 19: // WHILE
      case 20: // CLASS
      case 21: // EXTENDS
      case 22: // PUBLIC
      case 23: // STATIC
      case 24: // VOID
      case 25: // BOOL
      case 26: // INT
      case 27: // STRING
      case 28: // TRUE
      case 29: // FALSE
      case 30: // THIS
      case 31: // NEW
      case 32: // SYSTEMOUTPRINT
      case 33: // RETURN
      case 34: // LENGTH
      case 35: // MAIN
      case 36: // ID
      case 37: // NUM
      case 38: // EQ
      case 39: // EXMARK
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 27 "parser.yy"
{
  yylhs.value.as < Node * > ()=new Node("Goal", "");
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  root = yylhs.value.as < Node * > ();
}
#line 841 "parser.tab.cc"
    break;

  case 3:
#line 34 "parser.yy"
{

}
#line 849 "parser.tab.cc"
    break;

  case 4:
#line 38 "parser.yy"
                   { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 855 "parser.tab.cc"
    break;

  case 5:
#line 39 "parser.yy"
{

}
#line 863 "parser.tab.cc"
    break;

  case 7:
#line 45 "parser.yy"
{

}
#line 871 "parser.tab.cc"
    break;

  case 8:
#line 49 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 877 "parser.tab.cc"
    break;

  case 9:
#line 50 "parser.yy"
{

}
#line 885 "parser.tab.cc"
    break;

  case 10:
#line 55 "parser.yy"
{

}
#line 893 "parser.tab.cc"
    break;

  case 11:
#line 59 "parser.yy"
                    { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 899 "parser.tab.cc"
    break;

  case 12:
#line 60 "parser.yy"
{

}
#line 907 "parser.tab.cc"
    break;

  case 13:
#line 65 "parser.yy"
{

}
#line 915 "parser.tab.cc"
    break;

  case 14:
#line 69 "parser.yy"
           { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 921 "parser.tab.cc"
    break;

  case 15:
#line 69 "parser.yy"
                             { yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); }
#line 927 "parser.tab.cc"
    break;

  case 16:
#line 70 "parser.yy"
{

}
#line 935 "parser.tab.cc"
    break;

  case 20:
#line 75 "parser.yy"
{

}
#line 943 "parser.tab.cc"
    break;

  case 21:
#line 79 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 949 "parser.tab.cc"
    break;

  case 22:
#line 80 "parser.yy"
{

}
#line 957 "parser.tab.cc"
    break;

  case 27:
#line 88 "parser.yy"
           { yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); }
#line 963 "parser.tab.cc"
    break;

  case 28:
#line 90 "parser.yy"
{

}
#line 971 "parser.tab.cc"
    break;

  case 29:
#line 94 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 977 "parser.tab.cc"
    break;

  case 30:
#line 95 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); }
#line 983 "parser.tab.cc"
    break;

  case 31:
#line 96 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 989 "parser.tab.cc"
    break;

  case 32:
#line 97 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[5].value.as < Node * > (); }
#line 995 "parser.tab.cc"
    break;

  case 36:
#line 101 "parser.yy"
            { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1001 "parser.tab.cc"
    break;

  case 41:
#line 107 "parser.yy"
{

}
#line 1009 "parser.tab.cc"
    break;

  case 42:
#line 111 "parser.yy"
             { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1015 "parser.tab.cc"
    break;

  case 43:
#line 111 "parser.yy"
                          { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); }
#line 1021 "parser.tab.cc"
    break;

  case 44:
#line 112 "parser.yy"
{

}
#line 1029 "parser.tab.cc"
    break;

  case 49:
#line 117 "parser.yy"
{

}
#line 1037 "parser.tab.cc"
    break;

  case 50:
#line 122 "parser.yy"
{

}
#line 1045 "parser.tab.cc"
    break;


#line 1049 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -15,   -14,    24,    19,   -57,    30,   -57,   -14,    59,    19,
      38,    -5,   -57,   -57,    39,    -8,   -14,    40,   -57,    55,
      44,    -8,   -14,   -57,    58,    32,    61,    -8,    60,    44,
     -57,    64,    -8,    73,   -57,   -14,   -57,   -57,   -57,    44,
      57,    78,    74,    79,    -8,   -57,    84,    89,   -14,   -14,
      98,    85,    92,    -8,    -8,   109,    -9,   -57,    -9,    -9,
     114,   116,   117,    99,    -9,    -6,   120,   122,    46,    46,
      46,    46,   -57,    46,    46,   123,   -57,    46,   -57,   -57,
     -57,   -17,   -57,    46,    87,   -57,   102,   110,   124,   138,
     152,   -57,   166,   127,   130,   230,   -57,   -57,   -57,   -57,
     -57,    -9,    46,   -23,    46,    -9,   131,   134,   112,   -57,
     -57,    46,   142,   135,   174,   -57,   144,   230,   -57,   -57,
     -57,    46,   188,   -57,    -9,   -57,    46,   202,   -57,   -57,
     216,   151,   -57,    46,   -57,   -57
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     5,    50,     0,     1,     0,     0,     5,
       0,     0,     2,     4,     0,     9,     0,     0,    18,    19,
      12,     9,     0,    20,     0,     0,     0,     0,     0,    12,
       8,     0,     9,     0,    17,     0,     7,    11,    10,    12,
       0,     0,     0,     0,    16,     6,     0,     0,     0,     0,
       0,    14,     0,     9,    16,     0,    22,    15,     0,    22,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    23,     0,    34,    35,
      37,     0,    33,     0,     0,    36,     0,     0,     0,     0,
       0,     3,     0,     0,     0,    40,    45,    48,    47,    46,
      49,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      41,     0,     0,     0,     0,    31,     0,    29,    25,    26,
      13,     0,     0,    39,     0,    30,    44,     0,    38,    24,
      42,     0,    28,    44,    32,    43
  };

  const short
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,   154,   -57,   -20,   -57,    22,   -57,   107,
       2,   -34,   -56,   -33,    31,   -57,    -1
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     9,    20,    21,    28,    29,    47,
      22,    63,    64,   130,   131,   104,    85
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    30,    66,    59,    73,     1,    11,    15,    60,    93,
      61,   115,    39,     4,    23,    24,    16,    18,    19,     4,
      23,    31,     4,    62,     6,    67,    23,     4,     4,    35,
      72,    23,    74,    56,    41,    84,    86,    87,    88,     7,
      89,    90,    10,    23,    92,   113,    48,    51,    52,   118,
      95,    37,    23,    23,    77,    65,    48,    65,    65,    12,
      14,    42,    17,    65,    25,    26,    27,    33,   129,   114,
      32,   117,    34,    36,    78,    79,    80,    81,   122,    38,
      94,    40,     4,    82,    43,    83,    44,    45,   127,    46,
      96,    97,    98,    99,   100,    49,   101,   102,    50,    54,
      65,    55,   116,   103,    65,    96,    97,    98,    99,   100,
      53,   105,   102,    96,    97,    98,    99,   100,   103,   106,
     102,    58,    68,    65,    69,    70,   103,    96,    97,    98,
      99,   100,    71,    75,   102,    76,    91,   111,   112,   107,
     103,    96,    97,    98,    99,   100,   119,   120,   102,   108,
     121,   123,   126,   124,   103,    96,    97,    98,    99,   100,
     134,    57,   102,    13,   135,     0,     0,   109,   103,    96,
      97,    98,    99,   100,     0,   110,   102,    96,    97,    98,
      99,   100,   103,     0,   102,   125,     0,     0,     0,     0,
     103,    96,    97,    98,    99,   100,     0,     0,   102,   128,
       0,     0,     0,     0,   103,    96,    97,    98,    99,   100,
       0,     0,   102,     0,     0,     0,     0,   132,   103,    96,
      97,    98,    99,   100,     0,     0,   102,     0,     0,     0,
     133,     0,   103,    96,    97,    98,    99,   100,     0,     0,
     102,     0,     0,     0,     0,     0,   103
  };

  const short
  parser::yycheck_[] =
  {
       1,    21,    58,    12,    10,    20,     7,    12,    17,    26,
      19,    34,    32,    36,    15,    16,    21,    25,    26,    36,
      21,    22,    36,    32,     0,    59,    27,    36,    36,    27,
      64,    32,    38,    53,    35,    68,    69,    70,    71,    20,
      73,    74,    12,    44,    77,   101,    44,    48,    49,   105,
      83,    29,    53,    54,     8,    56,    54,    58,    59,     0,
      22,    39,    23,    64,    24,    10,    22,    35,   124,   102,
      12,   104,    11,    13,    28,    29,    30,    31,   111,    15,
      81,     8,    36,    37,    27,    39,     8,    13,   121,    10,
       3,     4,     5,     6,     7,    11,     9,    10,     9,    14,
     101,     9,   103,    16,   105,     3,     4,     5,     6,     7,
      12,     9,    10,     3,     4,     5,     6,     7,    16,     9,
      10,    12,     8,   124,     8,     8,    16,     3,     4,     5,
       6,     7,    33,    13,    10,    13,    13,    10,     8,    15,
      16,     3,     4,     5,     6,     7,    15,    13,    10,    11,
      38,     9,     8,    18,    16,     3,     4,     5,     6,     7,
       9,    54,    10,     9,   133,    -1,    -1,    15,    16,     3,
       4,     5,     6,     7,    -1,     9,    10,     3,     4,     5,
       6,     7,    16,    -1,    10,    11,    -1,    -1,    -1,    -1,
      16,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    16,     3,     4,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    -1,    16,     3,     4,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    16
  };

  const signed char
  parser::yystos_[] =
  {
       0,    20,    41,    42,    36,    56,     0,    20,    43,    44,
      12,    56,     0,    43,    22,    12,    21,    23,    25,    26,
      45,    46,    50,    56,    56,    24,    10,    22,    47,    48,
      45,    56,    12,    35,    11,    50,    13,    47,    15,    45,
       8,    56,    47,    27,     8,    13,    10,    49,    50,    11,
       9,    56,    56,    12,    14,     9,    45,    49,    12,    12,
      17,    19,    32,    51,    52,    56,    52,    51,     8,     8,
       8,    33,    51,    10,    38,    13,    13,     8,    28,    29,
      30,    31,    37,    39,    53,    56,    53,    53,    53,    53,
      53,    13,    53,    26,    56,    53,     3,     4,     5,     6,
       7,     9,    10,    16,    55,     9,     9,    15,    11,    15,
       9,    10,     8,    52,    53,    34,    56,    53,    52,    15,
      13,    38,    53,     9,    18,    11,     8,    53,    11,    52,
      53,    54,    15,    14,     9,    54
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    40,    41,    42,    43,    43,    44,    44,    45,    45,
      46,    47,    47,    48,    49,    49,    49,    50,    50,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     2,     0,     8,     6,     2,     0,
       3,     2,     0,    13,     2,     4,     0,     3,     1,     1,
       1,     2,     0,     3,     7,     5,     5,     4,     7,     3,
       4,     3,     6,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     1,     3,     0,     1,     1,     1,     1,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUS", "MULT", "LESSTHAN",
  "MIN", "AND", "LP", "RP", "LB", "RB", "LM", "RM", "COMMA", "SEMICOLON",
  "DOT", "IF", "ELSE", "WHILE", "CLASS", "EXTENDS", "PUBLIC", "STATIC",
  "VOID", "BOOL", "INT", "STRING", "TRUE", "FALSE", "THIS", "NEW",
  "SYSTEMOUTPRINT", "RETURN", "LENGTH", "MAIN", "ID", "NUM", "EQ",
  "EXMARK", "$accept", "Goal", "MainClass", "ClassDeclarations",
  "ClassDeclaration", "VarDeclarations", "VarDeclaration",
  "MethodDeclarations", "MethodDeclaration", "Arguments", "Type",
  "Statements", "Statement", "Expression", "Expressions", "Operations",
  "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    26,    26,    33,    38,    39,    43,    44,    49,    50,
      54,    59,    60,    64,    69,    69,    70,    74,    74,    74,
      74,    79,    80,    84,    85,    86,    87,    88,    89,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   111,   111,   112,   116,   116,   116,   116,   116,
     121
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1535 "parser.tab.cc"

