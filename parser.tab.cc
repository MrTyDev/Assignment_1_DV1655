// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 19 "parser.yy"

  // The lexer function declaration. It must return a token.
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  // Global pointer to the root AST node.
  Node* root;
  // External variable for tracking current line number.
  extern int yylineno;

#line 57 "parser.tab.cc"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 130 "parser.tab.cc"

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

  /*---------.
  | symbol.  |
  `---------*/



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

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_pre_return_statements: // pre_return_statements
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
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
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_pre_return_statements: // pre_return_statements
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression_list: // expression_list
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_pre_return_statements: // pre_return_statements
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression_list: // expression_list
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
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
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_pre_return_statements: // pre_return_statements
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression_list: // expression_list
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
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
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_pre_return_statements: // pre_return_statements
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
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
  case 2: // goal: main_class class_declaration_list
#line 69 "parser.yy"
                                        { 
    yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Add the main class.
    if(yystack_[0].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // Optionally add class declarations.
    root = yylhs.value.as < Node * > (); // Set the global AST root.
}
#line 831 "parser.tab.cc"
    break;

  case 3: // expression: expression AND expression
#line 79 "parser.yy"
                                      {
        yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 841 "parser.tab.cc"
    break;

  case 4: // expression: expression OR expression
#line 84 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 851 "parser.tab.cc"
    break;

  case 5: // expression: expression LT expression
#line 89 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("LessThanExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 861 "parser.tab.cc"
    break;

  case 6: // expression: expression GT expression
#line 94 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("GreaterThanExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 871 "parser.tab.cc"
    break;

  case 7: // expression: expression EQ expression
#line 99 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("EqualExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 881 "parser.tab.cc"
    break;

  case 8: // expression: expression PLUS expression
#line 104 "parser.yy"
                                 {
        yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 891 "parser.tab.cc"
    break;

  case 9: // expression: expression MINUS expression
#line 109 "parser.yy"
                                  {
        yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 901 "parser.tab.cc"
    break;

  case 10: // expression: expression MULT expression
#line 114 "parser.yy"
                                 {
        yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 911 "parser.tab.cc"
    break;

  case 11: // expression: factor
#line 119 "parser.yy"
             { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 917 "parser.tab.cc"
    break;

  case 12: // expression: expression LBRACKET expression RBRACKET
#line 120 "parser.yy"
                                              { 
        // Represents an array access: array[expression]
        yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // Array operand.
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Index expression.
    }
#line 928 "parser.tab.cc"
    break;

  case 13: // expression: expression DOT LENGTH
#line 126 "parser.yy"
                            {
        // Get the length of an array.
        yylhs.value.as < Node * > () = new Node("Length", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 938 "parser.tab.cc"
    break;

  case 14: // expression: expression DOT IDENTIFIER LPAREN expression_list RPAREN
#line 131 "parser.yy"
                                                              {
        // Method call on an object with parameters.
        yylhs.value.as < Node * > () = new Node("MethodCall", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); // The caller object.
        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Optional argument list.
    }
#line 949 "parser.tab.cc"
    break;

  case 15: // expression: NEW INT_TYPE LBRACKET expression RBRACKET
#line 137 "parser.yy"
                                                {
        // Create a new array.
        yylhs.value.as < Node * > () = new Node("NewArray", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // The size of the array.
    }
#line 959 "parser.tab.cc"
    break;

  case 16: // expression: NEW IDENTIFIER LPAREN RPAREN
#line 142 "parser.yy"
                                   {
        // Create a new object.
        yylhs.value.as < Node * > () = new Node("NewObject", yystack_[2].value.as < std::string > (), yylineno);
    }
#line 968 "parser.tab.cc"
    break;

  case 17: // expression: NOT expression
#line 146 "parser.yy"
                     {
        // Logical NOT expression.
        yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 978 "parser.tab.cc"
    break;

  case 18: // expression: expression DOT IDENTIFIER
#line 151 "parser.yy"
                                {
        // Field access: object.field
        yylhs.value.as < Node * > () = new Node("FieldAccess", yystack_[0].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 988 "parser.tab.cc"
    break;

  case 19: // factor: INTEGER_LITERAL
#line 159 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); }
#line 994 "parser.tab.cc"
    break;

  case 20: // factor: LPAREN expression RPAREN
#line 160 "parser.yy"
                                 { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1000 "parser.tab.cc"
    break;

  case 21: // factor: IDENTIFIER
#line 161 "parser.yy"
                   { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); }
#line 1006 "parser.tab.cc"
    break;

  case 22: // factor: TRUE
#line 162 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("Boolean", "true", yylineno); }
#line 1012 "parser.tab.cc"
    break;

  case 23: // factor: FALSE
#line 163 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "false", yylineno); }
#line 1018 "parser.tab.cc"
    break;

  case 24: // factor: THIS
#line 164 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1024 "parser.tab.cc"
    break;

  case 25: // main_class: PUBLIC CLASS IDENTIFIER LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET IDENTIFIER RPAREN LBRACE statement_list RBRACE RBRACE
#line 170 "parser.yy"
                                                {
                yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
                // Create a 'MainMethod' node containing the statements.
                Node* mainMethod = new Node("MainMethod", "", yylineno);
                mainMethod->children.push_back(yystack_[2].value.as < Node * > ()); // Statements block inside main.
                yylhs.value.as < Node * > ()->children.push_back(mainMethod);
            }
#line 1036 "parser.tab.cc"
    break;

  case 26: // main_class: CLASS IDENTIFIER LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET IDENTIFIER RPAREN LBRACE statement RBRACE RBRACE
#line 179 "parser.yy"
                                           {
                // Alternate syntax for the main class.
                yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
                Node* mainMethod = new Node("MainMethod", "", yylineno);
                mainMethod->children.push_back(yystack_[2].value.as < Node * > ()); // Single statement.
                yylhs.value.as < Node * > ()->children.push_back(mainMethod);
            }
#line 1048 "parser.tab.cc"
    break;

  case 27: // statement: LBRACE statement_list RBRACE
#line 189 "parser.yy"
                                        { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1054 "parser.tab.cc"
    break;

  case 28: // statement: IF LPAREN expression RPAREN statement ELSE statement
#line 190 "parser.yy"
                                                                {
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // Condition.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // 'Then' branch.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // 'Else' branch.
         }
#line 1065 "parser.tab.cc"
    break;

  case 29: // statement: WHILE LPAREN expression RPAREN statement
#line 196 "parser.yy"
                                                    {
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Loop condition.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // Loop body.
         }
#line 1075 "parser.tab.cc"
    break;

  case 30: // statement: PRINTLN LPAREN expression RPAREN SEMICOLON
#line 201 "parser.yy"
                                                      {
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Expression to print.
         }
#line 1084 "parser.tab.cc"
    break;

  case 31: // statement: IDENTIFIER ASSIGN expression SEMICOLON
#line 205 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("AssignStatement", yystack_[3].value.as < std::string > (), yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Right-hand side value.
         }
#line 1093 "parser.tab.cc"
    break;

  case 32: // statement: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 209 "parser.yy"
                                                                               {
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", yystack_[6].value.as < std::string > (), yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // Array index.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Value assigned.
         }
#line 1103 "parser.tab.cc"
    break;

  case 33: // statement_list: %empty
#line 217 "parser.yy"
                            { 
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno); 
    }
#line 1111 "parser.tab.cc"
    break;

  case 34: // statement_list: statement_list statement
#line 220 "parser.yy"
                               {
        if(yystack_[0].value.as < Node * > ()) yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 1120 "parser.tab.cc"
    break;

  case 35: // return_statement: RETURN expression SEMICOLON
#line 225 "parser.yy"
                                              {
    yylhs.value.as < Node * > () = new Node("ReturnStatement", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // The expression to return.
    }
#line 1129 "parser.tab.cc"
    break;

  case 36: // pre_return_statements: %empty
#line 233 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno); }
#line 1135 "parser.tab.cc"
    break;

  case 37: // pre_return_statements: pre_return_statements statement
#line 234 "parser.yy"
                                      {
        if(yystack_[0].value.as < Node * > ()) yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 1144 "parser.tab.cc"
    break;

  case 38: // class_declaration_list: %empty
#line 241 "parser.yy"
                                    { yylhs.value.as < Node * > () = nullptr; }
#line 1150 "parser.tab.cc"
    break;

  case 39: // class_declaration_list: class_declaration_list class_declaration
#line 242 "parser.yy"
                                               {
        if(yystack_[1].value.as < Node * > () == nullptr) {
            yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
        } else {
            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        }
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1163 "parser.tab.cc"
    break;

  case 40: // class_declaration: CLASS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE
#line 253 "parser.yy"
                                                                                               {
    yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < std::string > (), yylineno);
    if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Variables.
    if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Methods.
}
#line 1173 "parser.tab.cc"
    break;

  case 41: // class_declaration: CLASS IDENTIFIER EXTENDS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE
#line 258 "parser.yy"
                                                                                                 {
    yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[6].value.as < std::string > (), yylineno);
    // Build an "Extends" node for the parent class.
    Node* extends = new Node("Extends", yystack_[4].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(extends);
    if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1186 "parser.tab.cc"
    break;

  case 42: // type: INT_TYPE LBRACKET RBRACKET
#line 269 "parser.yy"
                                 { yylhs.value.as < Node * > () = new Node("ArrayType", "int[]", yylineno); }
#line 1192 "parser.tab.cc"
    break;

  case 43: // type: BOOLEAN
#line 270 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Type", "boolean", yylineno); }
#line 1198 "parser.tab.cc"
    break;

  case 44: // type: INT_TYPE
#line 271 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("Type", "int", yylineno); }
#line 1204 "parser.tab.cc"
    break;

  case 45: // var_declaration: type IDENTIFIER SEMICOLON
#line 275 "parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node("VarDeclaration", yystack_[1].value.as < std::string > (), yylineno);
    }
#line 1212 "parser.tab.cc"
    break;

  case 46: // var_declaration_list: %empty
#line 281 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("VarDeclarationList", "", yylineno); }
#line 1218 "parser.tab.cc"
    break;

  case 47: // var_declaration_list: var_declaration_list var_declaration
#line 282 "parser.yy"
                                           {
          yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 1227 "parser.tab.cc"
    break;

  case 48: // method_declaration_list: %empty
#line 290 "parser.yy"
                                     { yylhs.value.as < Node * > () = nullptr; }
#line 1233 "parser.tab.cc"
    break;

  case 49: // method_declaration_list: method_declaration_list method_declaration
#line 291 "parser.yy"
                                                 {
        if(yystack_[1].value.as < Node * > () == nullptr) {
            yylhs.value.as < Node * > () = new Node("MethodDeclarationList", "", yylineno);
        } else {
            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        }
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1246 "parser.tab.cc"
    break;

  case 50: // method_declaration: PUBLIC type IDENTIFIER LPAREN parameter_list RPAREN LBRACE var_declaration_list pre_return_statements return_statement RBRACE
#line 304 "parser.yy"
                                                                              {
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[8].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ()); // Return type.
        if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); // Parameters.
        if(yystack_[3].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // Method body statements.
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // 'RETURN' token (for AST purposes).
    }
#line 1258 "parser.tab.cc"
    break;

  case 51: // method_declaration: PUBLIC STATIC VOID IDENTIFIER LPAREN parameter_list RPAREN LBRACE var_declaration_list statement_list RBRACE
#line 312 "parser.yy"
                                                      {
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[7].value.as < std::string > (), yylineno);
        // Create a void type node.
        Node* voidType = new Node("Type", "void", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(voidType);
        if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); // Parameters.
        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Body statements.
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Closing brace included.
    }
#line 1272 "parser.tab.cc"
    break;

  case 52: // method_declaration: PUBLIC VOID IDENTIFIER LPAREN parameter_list RPAREN LBRACE var_declaration_list statement_list RBRACE
#line 322 "parser.yy"
                                                      {
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[7].value.as < std::string > (), yylineno);
        Node* voidType = new Node("Type", "void", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(voidType);
        if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
        if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1285 "parser.tab.cc"
    break;

  case 53: // parameter_list: %empty
#line 334 "parser.yy"
                { yylhs.value.as < Node * > () = nullptr; }
#line 1291 "parser.tab.cc"
    break;

  case 54: // parameter_list: type IDENTIFIER
#line 335 "parser.yy"
                      { 
        yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
        Node* param = new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno);
        param->children.push_back(yystack_[1].value.as < Node * > ()); // Parameter type.
        yylhs.value.as < Node * > ()->children.push_back(param);
    }
#line 1302 "parser.tab.cc"
    break;

  case 55: // parameter_list: parameter_list COMMA type IDENTIFIER
#line 341 "parser.yy"
                                           {
        Node* param = new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno);
        param->children.push_back(yystack_[1].value.as < Node * > ());
        yystack_[3].value.as < Node * > ()->children.push_back(param);
        yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();
    }
#line 1313 "parser.tab.cc"
    break;

  case 56: // expression_list: %empty
#line 350 "parser.yy"
                             { yylhs.value.as < Node * > () = nullptr; }
#line 1319 "parser.tab.cc"
    break;

  case 57: // expression_list: expression
#line 351 "parser.yy"
                 { 
        yylhs.value.as < Node * > () = new Node("ExpressionList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1328 "parser.tab.cc"
    break;

  case 58: // expression_list: expression_list COMMA expression
#line 355 "parser.yy"
                                       {
        if (yystack_[2].value.as < Node * > () == nullptr) {
            yylhs.value.as < Node * > () = new Node("ExpressionList", "", yylineno);
        } else {
            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
        }
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1341 "parser.tab.cc"
    break;


#line 1345 "parser.tab.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;


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
    YY_STACK_PRINT ();
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -92;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      62,    -4,   -27,    28,   -92,    19,    49,   -92,    90,    84,
      87,    76,   -92,    99,    98,     8,   100,    89,   -92,    85,
     104,   105,    82,   114,   106,   133,   115,   -92,   109,   -92,
      -1,   -92,   147,   135,   127,   144,   -92,   119,   -92,    82,
     138,   148,   -92,   -92,   142,   137,   140,    35,   151,   161,
     141,   170,   171,   -92,   178,   145,   184,    82,    82,   158,
     187,    82,   159,    60,    72,   188,   198,    77,   -92,   199,
      82,   201,   202,    92,   204,   -92,   177,   -92,   -92,   -92,
     217,   218,   221,     0,   219,   -92,    82,   -92,    82,    29,
      57,    -6,    -6,    -6,    -6,    -6,   231,    82,    63,    73,
     232,   -92,   -92,    -6,    -6,   -92,   -92,   -92,   -19,   -92,
     -92,   237,   -92,   253,   269,   132,   186,   -92,    86,   -92,
      -6,   -92,   234,   -92,    64,   285,   216,   223,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,   -15,    92,    -6,    92,
     233,   -92,   243,   -92,   150,   -92,   -92,    -6,   249,     4,
       4,    64,   323,   312,    65,    65,   334,   -92,   251,   235,
     203,   -92,   -92,    -6,   -92,   220,   -92,    -6,    92,   -92,
     168,   -92,   301,    95,   -92,   -92,   -92,    -6,   301
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    38,     0,     0,     1,     2,     0,
       0,     0,    39,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    48,     0,     0,     0,    44,    43,     0,    47,
       0,    46,     0,     0,     0,     0,    40,     0,    49,    48,
       0,     0,    42,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    53,    53,     0,
       0,    53,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,    46,     0,    46,    33,    33,
       0,     0,     0,     0,     0,    46,    33,    55,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    34,    27,     0,     0,    22,    23,    24,     0,    19,
      21,     0,    11,     0,     0,     0,     0,    26,     0,    52,
       0,    37,     0,    25,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,    51,     0,    50,    20,     0,     0,     8,
       9,    10,     3,     4,     5,     6,     7,    13,    18,     0,
       0,    29,    30,     0,    35,     0,    16,    56,     0,    12,
       0,    15,    57,     0,    28,    32,    14,     0,    58
  };

  const short
  parser::yypgoto_[] =
  {
     -92,   -92,   -91,   -92,   -92,   -73,   -72,   -92,   -92,   -92,
     -92,    -3,   -92,   -26,   230,   -92,    -8,   -92
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     3,   111,   112,     4,   101,    89,   122,    99,     8,
      12,    28,    29,    22,    30,    38,    63,   173
  };

  const unsigned char
  parser::yytable_[] =
  {
      84,   113,   114,   115,   116,    39,   103,    90,   104,   130,
     126,    94,   124,   125,    98,     6,    36,   136,    95,     5,
     157,    37,   138,   127,    18,   118,   121,   158,     7,   144,
     105,   106,   107,   108,    46,   109,   110,   149,   150,   151,
     152,   153,   154,   155,   156,    79,   100,   160,    19,    86,
      64,    88,    53,    67,    62,    62,   165,    37,    62,    97,
      80,     9,    81,    82,   159,    10,   161,    76,   128,   129,
     130,    83,   170,    79,   102,    69,   172,   136,   136,    79,
     119,    70,   138,   138,     1,     2,   178,    71,    80,    79,
      81,    82,    74,    70,    80,   174,    81,    82,    70,    83,
      13,   120,    79,   143,    80,    83,    81,    82,    79,    14,
     176,    26,    27,    11,    21,    83,   177,    80,    15,    81,
      82,    16,    17,    80,    20,    81,    82,    23,    83,    24,
      31,    25,    32,    34,    83,   128,   129,   130,   131,   132,
     133,   134,   135,    44,    45,   136,    42,    33,    26,    27,
     138,    35,   141,   128,   129,   130,   131,   132,   133,   134,
     135,    40,    41,   136,    43,    48,    49,    50,   138,    54,
     164,   128,   129,   130,   131,   132,   133,   134,   135,    51,
      55,   136,    52,    56,    57,    58,   138,    60,   175,   128,
     129,   130,   131,   132,   133,   134,   135,    59,    61,   136,
      65,    68,    66,    72,   138,   142,   128,   129,   130,   131,
     132,   133,   134,   135,    73,    75,   136,    77,    78,    87,
      85,   138,   169,   128,   129,   130,   131,   132,   133,   134,
     135,    91,    92,   136,   147,    93,    96,   148,   138,   171,
     128,   129,   130,   131,   132,   133,   134,   135,   117,   123,
     136,   145,   137,   162,   163,   138,   128,   129,   130,   131,
     132,   133,   134,   135,   166,   167,   136,   168,   139,    47,
       0,   138,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   136,     0,   140,     0,     0,   138,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   136,     0,
     146,     0,     0,   138,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   136,   128,   129,   130,   131,   138,
     133,   134,   135,     0,     0,   136,   128,   129,   130,     0,
     138,   133,   134,   135,     0,     0,   136,   128,   129,   130,
       0,   138,   133,   134,     0,     0,     0,   136,     0,     0,
       0,     0,   138
  };

  const short
  parser::yycheck_[] =
  {
      73,    92,    93,    94,    95,    31,    12,    79,    14,     5,
      29,    11,   103,   104,    86,    42,    17,    13,    18,    23,
      35,    22,    18,    42,    16,    97,    99,    42,     0,   120,
      36,    37,    38,    39,    37,    41,    42,   128,   129,   130,
     131,   132,   133,   134,   135,    16,    17,   138,    40,    75,
      58,    77,    17,    61,    57,    58,   147,    22,    61,    85,
      31,    42,    33,    34,   137,    16,   139,    70,     3,     4,
       5,    42,   163,    16,    17,    15,   167,    13,    13,    16,
      17,    21,    18,    18,    22,    23,   177,    15,    31,    16,
      33,    34,    15,    21,    31,   168,    33,    34,    21,    42,
      16,    28,    16,    17,    31,    42,    33,    34,    16,    22,
      15,    29,    30,    23,    25,    42,    21,    31,    42,    33,
      34,    22,    24,    31,    24,    33,    34,    42,    42,    25,
      16,    26,    26,    18,    42,     3,     4,     5,     6,     7,
       8,     9,    10,    24,    25,    13,    19,    14,    29,    30,
      18,    42,    20,     3,     4,     5,     6,     7,     8,     9,
      10,    14,    27,    13,    20,    27,    18,    25,    18,    18,
      20,     3,     4,     5,     6,     7,     8,     9,    10,    42,
      19,    13,    42,    42,    14,    14,    18,    42,    20,     3,
       4,     5,     6,     7,     8,     9,    10,    19,    14,    13,
      42,    42,    15,    15,    18,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    16,    16,    13,    16,    16,    42,
      16,    18,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    14,    14,    13,    18,    14,    17,    14,    18,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    17,    17,
      13,    17,    15,    20,    11,    18,     3,     4,     5,     6,
       7,     8,     9,    10,    15,    14,    13,    32,    15,    39,
      -1,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    -1,    15,    -1,    -1,    18,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      15,    -1,    -1,    18,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,     3,     4,     5,     6,    18,
       8,     9,    10,    -1,    -1,    13,     3,     4,     5,    -1,
      18,     8,     9,    10,    -1,    -1,    13,     3,     4,     5,
      -1,    18,     8,     9,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    18
  };

  const signed char
  parser::yystos_[] =
  {
       0,    22,    23,    44,    47,    23,    42,     0,    52,    42,
      16,    23,    53,    16,    22,    42,    22,    24,    16,    40,
      24,    25,    56,    42,    25,    26,    29,    30,    54,    55,
      57,    16,    26,    14,    18,    42,    17,    22,    58,    56,
      14,    27,    19,    20,    24,    25,    54,    57,    27,    18,
      25,    42,    42,    17,    18,    19,    42,    14,    14,    19,
      42,    14,    54,    59,    59,    42,    15,    59,    42,    15,
      21,    15,    15,    16,    15,    16,    54,    16,    16,    16,
      31,    33,    34,    42,    48,    16,    56,    42,    56,    49,
      49,    14,    14,    14,    11,    18,    17,    56,    49,    51,
      17,    48,    17,    12,    14,    36,    37,    38,    39,    41,
      42,    45,    46,    45,    45,    45,    45,    17,    49,    17,
      28,    48,    50,    17,    45,    45,    29,    42,     3,     4,
       5,     6,     7,     8,     9,    10,    13,    15,    18,    15,
      15,    20,    19,    17,    45,    17,    15,    18,    14,    45,
      45,    45,    45,    45,    45,    45,    45,    35,    42,    48,
      45,    48,    20,    11,    20,    45,    15,    14,    32,    19,
      45,    19,    45,    60,    48,    20,    15,    21,    45
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    56,    56,    57,    57,
      58,    58,    58,    59,    59,    59,    60,    60,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     3,     6,     5,     4,     2,     3,     1,
       3,     1,     1,     1,     1,    18,    17,     3,     7,     5,
       5,     4,     7,     0,     2,     3,     0,     2,     0,     2,
       6,     8,     3,     1,     1,     3,     0,     2,     0,     2,
      11,    11,    10,     0,     2,     4,     0,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULT", "AND", "OR", "LT", "GT", "EQ", "ASSIGN", "NOT", "DOT", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON",
  "COMMA", "PUBLIC", "CLASS", "STATIC", "VOID", "MAIN", "STRING", "RETURN",
  "INT_TYPE", "BOOLEAN", "IF", "ELSE", "WHILE", "PRINTLN", "LENGTH",
  "TRUE", "FALSE", "THIS", "NEW", "EXTENDS", "INTEGER_LITERAL",
  "IDENTIFIER", "$accept", "goal", "expression", "factor", "main_class",
  "statement", "statement_list", "return_statement",
  "pre_return_statements", "class_declaration_list", "class_declaration",
  "type", "var_declaration", "var_declaration_list",
  "method_declaration_list", "method_declaration", "parameter_list",
  "expression_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    69,    69,    79,    84,    89,    94,    99,   104,   109,
     114,   119,   120,   126,   131,   137,   142,   146,   151,   159,
     160,   161,   162,   163,   164,   168,   177,   189,   190,   196,
     201,   205,   209,   217,   220,   225,   233,   234,   241,   242,
     253,   258,   269,   270,   271,   275,   281,   282,   290,   291,
     303,   311,   321,   334,   335,   341,   350,   351,   355
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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
#line 1948 "parser.tab.cc"

#line 364 "parser.yy"
