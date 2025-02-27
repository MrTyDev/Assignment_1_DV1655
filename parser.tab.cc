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
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_type: // type
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_expression_list_nonempty: // expression_list_nonempty
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
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_type: // type
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_expression_list_nonempty: // expression_list_nonempty
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
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_type: // type
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_expression_list_nonempty: // expression_list_nonempty
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
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_type: // type
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_expression_list_nonempty: // expression_list_nonempty
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
      case symbol_kind::S_main_class: // main_class
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_declaration_list: // class_declaration_list
      case symbol_kind::S_type: // type
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_var_declaration: // var_declaration
      case symbol_kind::S_var_declaration_list: // var_declaration_list
      case symbol_kind::S_method_declaration: // method_declaration
      case symbol_kind::S_method_declaration_list: // method_declaration_list
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_expression_list_nonempty: // expression_list_nonempty
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
  case 2: // goal: main_class class_declaration_list "end of file"
#line 67 "parser.yy"
                                            { 
    yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    root = yylhs.value.as < Node * > ();
}
#line 826 "parser.tab.cc"
    break;

  case 3: // main_class: PUBLIC CLASS IDENTIFIER LBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LBRACKET RBRACKET IDENTIFIER RPAREN LBRACE statement_list RBRACE RBRACE
#line 77 "parser.yy"
                                                {
                yylhs.value.as < Node * > () = new Node("MainClass", yystack_[15].value.as < std::string > (), yylineno);
                // Create a 'MainMethod' node containing the statements.
                Node* mainMethod = new Node("MainMethod", "", yylineno);
                mainMethod->children.push_back(yystack_[2].value.as < Node * > ()); // Statements block inside main.
                yylhs.value.as < Node * > ()->children.push_back(mainMethod);
            }
#line 838 "parser.tab.cc"
    break;

  case 4: // class_declaration: CLASS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE
#line 87 "parser.yy"
                                                                                               {
    yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < std::string > (), yylineno);
    if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Variables.
    if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Methods.
    }
#line 848 "parser.tab.cc"
    break;

  case 5: // class_declaration: CLASS IDENTIFIER EXTENDS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE
#line 92 "parser.yy"
                                                                                                     {
    yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[6].value.as < std::string > (), yylineno);
    // Build an "Extends" node for the parent class.
    Node* extends = new Node("Extends", yystack_[4].value.as < std::string > (), yylineno);
    yylhs.value.as < Node * > ()->children.push_back(extends);
    if(yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 861 "parser.tab.cc"
    break;

  case 6: // class_declaration_list: %empty
#line 105 "parser.yy"
                                    { yylhs.value.as < Node * > () = nullptr; }
#line 867 "parser.tab.cc"
    break;

  case 7: // class_declaration_list: class_declaration_list class_declaration
#line 106 "parser.yy"
                                               {
        if(yystack_[1].value.as < Node * > () == nullptr) {
            yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
        } else {
            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        }
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 880 "parser.tab.cc"
    break;

  case 8: // type: INT_TYPE LBRACKET RBRACKET
#line 118 "parser.yy"
                                 { yylhs.value.as < Node * > () = new Node("ArrayType", "int[]", yylineno); }
#line 886 "parser.tab.cc"
    break;

  case 9: // type: BOOLEAN
#line 119 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Type", "boolean", yylineno); }
#line 892 "parser.tab.cc"
    break;

  case 10: // type: INT_TYPE
#line 120 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("Type", "int", yylineno); }
#line 898 "parser.tab.cc"
    break;

  case 11: // type: IDENTIFIER
#line 121 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno); }
#line 904 "parser.tab.cc"
    break;

  case 12: // factor: INTEGER_LITERAL
#line 125 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); }
#line 910 "parser.tab.cc"
    break;

  case 13: // factor: LPAREN expression RPAREN
#line 126 "parser.yy"
                                 { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 916 "parser.tab.cc"
    break;

  case 14: // factor: IDENTIFIER
#line 127 "parser.yy"
                   { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); }
#line 922 "parser.tab.cc"
    break;

  case 15: // factor: TRUE
#line 128 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("Boolean", "true", yylineno); }
#line 928 "parser.tab.cc"
    break;

  case 16: // factor: FALSE
#line 129 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "false", yylineno); }
#line 934 "parser.tab.cc"
    break;

  case 17: // factor: THIS
#line 130 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 940 "parser.tab.cc"
    break;

  case 18: // statement: LBRACE statement_list RBRACE
#line 135 "parser.yy"
                                        { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 946 "parser.tab.cc"
    break;

  case 19: // statement: IF LPAREN expression RPAREN statement ELSE statement
#line 136 "parser.yy"
                                                                {
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // Condition.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // 'Then' branch.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // 'Else' branch.
         }
#line 957 "parser.tab.cc"
    break;

  case 20: // statement: IF LPAREN expression RPAREN statement
#line 142 "parser.yy"
                                                 {
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Condition.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // 'Then' branch.
         }
#line 967 "parser.tab.cc"
    break;

  case 21: // statement: WHILE LPAREN expression RPAREN statement
#line 147 "parser.yy"
                                                    {
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Loop condition.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // Loop body.
         }
#line 977 "parser.tab.cc"
    break;

  case 22: // statement: PRINTLN LPAREN expression RPAREN SEMICOLON
#line 152 "parser.yy"
                                                      {
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Expression to print.
         }
#line 986 "parser.tab.cc"
    break;

  case 23: // statement: IDENTIFIER ASSIGN expression SEMICOLON
#line 156 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("AssignStatement", yystack_[3].value.as < std::string > (), yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Right-hand side value.
         }
#line 995 "parser.tab.cc"
    break;

  case 24: // statement: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 160 "parser.yy"
                                                                               {
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", yystack_[6].value.as < std::string > (), yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // Array index.
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Value assigned.
         }
#line 1005 "parser.tab.cc"
    break;

  case 25: // statement: var_declaration
#line 165 "parser.yy"
                           { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1011 "parser.tab.cc"
    break;

  case 26: // statement_list: statement
#line 170 "parser.yy"
                          { 
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1020 "parser.tab.cc"
    break;

  case 27: // statement_list: statement_list statement
#line 174 "parser.yy"
                               {
        yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 1029 "parser.tab.cc"
    break;

  case 28: // var_declaration: type IDENTIFIER SEMICOLON
#line 182 "parser.yy"
                              {
        yylhs.value.as < Node * > () = new Node("VarDeclaration", yystack_[1].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Variable type.
    }
#line 1038 "parser.tab.cc"
    break;

  case 29: // var_declaration: type IDENTIFIER LBRACKET RBRACKET SEMICOLON
#line 186 "parser.yy"
                                                  { 
        yylhs.value.as < Node * > () = new Node("ArrayDeclaration", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // Variable type.
    }
#line 1047 "parser.tab.cc"
    break;

  case 30: // var_declaration_list: %empty
#line 195 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("VarDeclarationList", "", yylineno); }
#line 1053 "parser.tab.cc"
    break;

  case 31: // var_declaration_list: var_declaration_list var_declaration
#line 196 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = new Node("VarDeclarationList", "", yylineno);
          yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();

    }
#line 1064 "parser.tab.cc"
    break;

  case 32: // method_declaration: PUBLIC type IDENTIFIER LPAREN parameter_list RPAREN LBRACE var_declaration_list statement_list RETURN expression SEMICOLON RBRACE
#line 208 "parser.yy"
                                                                                  {
        // First, create the method node.
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[10].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());        // Return type
        if(yystack_[8].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());   // Parameters
        if(yystack_[5].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());   // Variable declarations
        if(yystack_[4].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());   // Statements
        
        // Enforce a return statement for non-void methods.
        if (yystack_[11].value.as < Node * > ()->value != "void") {
            Node* returnNode = new Node("Return", "", yylineno);
            returnNode->children.push_back(yystack_[2].value.as < Node * > ()); // Return expression
            yylhs.value.as < Node * > ()->children.push_back(returnNode);
        }
    }
#line 1084 "parser.tab.cc"
    break;

  case 33: // method_declaration: PUBLIC type IDENTIFIER LPAREN parameter_list RPAREN LBRACE RETURN expression SEMICOLON RBRACE
#line 224 "parser.yy"
                                                {
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[8].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());        // Return type
        if(yystack_[6].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());   // Parameters
        
        Node* returnNode = new Node("Return", "", yylineno);
        returnNode->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(returnNode);
    }
#line 1098 "parser.tab.cc"
    break;

  case 34: // method_declaration_list: %empty
#line 237 "parser.yy"
                                     { yylhs.value.as < Node * > () = nullptr; }
#line 1104 "parser.tab.cc"
    break;

  case 35: // method_declaration_list: method_declaration_list method_declaration
#line 238 "parser.yy"
                                                 {
        if(yystack_[1].value.as < Node * > () == nullptr) {
            yylhs.value.as < Node * > () = new Node("MethodDeclarationList", "", yylineno);
        } else {
            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        }
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1117 "parser.tab.cc"
    break;

  case 36: // parameter_list: %empty
#line 250 "parser.yy"
                { yylhs.value.as < Node * > () = nullptr; }
#line 1123 "parser.tab.cc"
    break;

  case 37: // parameter_list: type IDENTIFIER
#line 251 "parser.yy"
                      { 
        yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
        Node* param = new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno);
        param->children.push_back(yystack_[1].value.as < Node * > ()); // Parameter type.
        yylhs.value.as < Node * > ()->children.push_back(param);
    }
#line 1134 "parser.tab.cc"
    break;

  case 38: // parameter_list: parameter_list COMMA type IDENTIFIER
#line 257 "parser.yy"
                                           {
        Node* param = new Node("Parameter", yystack_[0].value.as < std::string > (), yylineno);
        param->children.push_back(yystack_[1].value.as < Node * > ());
        yystack_[3].value.as < Node * > ()->children.push_back(param);
        yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();
    }
#line 1145 "parser.tab.cc"
    break;

  case 39: // expression: expression AND expression
#line 266 "parser.yy"
                                      {
        yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1155 "parser.tab.cc"
    break;

  case 40: // expression: expression OR expression
#line 271 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1165 "parser.tab.cc"
    break;

  case 41: // expression: expression LT expression
#line 276 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("LessThanExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1175 "parser.tab.cc"
    break;

  case 42: // expression: expression EQ expression
#line 281 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("EqualExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1185 "parser.tab.cc"
    break;

  case 43: // expression: expression PLUS expression
#line 286 "parser.yy"
                                 {
        yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1195 "parser.tab.cc"
    break;

  case 44: // expression: expression MINUS expression
#line 291 "parser.yy"
                                  {
        yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1205 "parser.tab.cc"
    break;

  case 45: // expression: expression MULT expression
#line 296 "parser.yy"
                                 {
        yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1215 "parser.tab.cc"
    break;

  case 46: // expression: factor
#line 301 "parser.yy"
             { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1221 "parser.tab.cc"
    break;

  case 47: // expression: expression LBRACKET expression RBRACKET
#line 302 "parser.yy"
                                              { 
        // Represents an array access: array[expression]
        yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // Array operand.
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Index expression.
    }
#line 1232 "parser.tab.cc"
    break;

  case 48: // expression: expression DOT LENGTH
#line 308 "parser.yy"
                            {
        // Get the length of an array.
        yylhs.value.as < Node * > () = new Node("Length", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 1242 "parser.tab.cc"
    break;

  case 49: // expression: expression DOT IDENTIFIER LPAREN expression_list RPAREN
#line 313 "parser.yy"
                                                              {
        // Method call on an object with parameters.
        yylhs.value.as < Node * > () = new Node("MethodCall", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); // The caller object.
        if(yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Optional argument list.
    }
#line 1253 "parser.tab.cc"
    break;

  case 50: // expression: NEW INT_TYPE LBRACKET expression RBRACKET
#line 319 "parser.yy"
                                                {
        // Create a new array.
        yylhs.value.as < Node * > () = new Node("NewArray", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // The size of the array.
    }
#line 1263 "parser.tab.cc"
    break;

  case 51: // expression: NEW IDENTIFIER LPAREN RPAREN
#line 324 "parser.yy"
                                   {
        // Create a new object.
        yylhs.value.as < Node * > () = new Node("NewObject", yystack_[2].value.as < std::string > (), yylineno);
    }
#line 1272 "parser.tab.cc"
    break;

  case 52: // expression: NOT expression
#line 328 "parser.yy"
                     {
        // Logical NOT expression.
        yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1282 "parser.tab.cc"
    break;

  case 53: // expression_list: %empty
#line 339 "parser.yy"
                { yylhs.value.as < Node * > () = nullptr; }
#line 1288 "parser.tab.cc"
    break;

  case 54: // expression_list: expression_list_nonempty
#line 340 "parser.yy"
                             { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1294 "parser.tab.cc"
    break;

  case 55: // expression_list_nonempty: expression
#line 344 "parser.yy"
               { 
        yylhs.value.as < Node * > () = new Node("ExpressionList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1303 "parser.tab.cc"
    break;

  case 56: // expression_list_nonempty: expression_list_nonempty COMMA expression
#line 348 "parser.yy"
                                              {
        yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1312 "parser.tab.cc"
    break;


#line 1316 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -70;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -18,     0,    50,   -70,    20,   -70,    21,    55,   -70,    30,
     -70,    58,    -5,    53,   -70,    49,    78,   -20,    88,    81,
      87,   -70,   -70,    64,   -70,    25,   -70,    97,    95,    80,
     -70,   -20,   -70,   -20,    91,   -70,   111,   -70,    89,    29,
     115,   114,   121,   -70,   117,   -70,   -20,    96,   104,   -13,
     133,   -70,   135,   -20,   136,   125,   107,    86,    19,    86,
     -70,    86,   140,   142,   150,    -6,   -70,    52,   -70,    19,
      19,   -70,   -70,   -70,    34,   -70,   -70,   -70,   119,    59,
     -70,    79,    19,    19,    19,    19,    19,   149,   -70,    60,
     242,   151,   153,    19,    19,    19,    19,    19,    19,    19,
      32,    19,   154,    19,   -70,   258,   274,   290,   137,   191,
     -70,   -70,    19,   157,    36,    36,    60,   328,   317,    35,
     339,   -70,   156,   208,   -70,   155,    86,    86,   162,   -70,
     163,   225,   -70,    19,   -70,   167,   158,   -70,   -70,    19,
     -70,   306,   170,   166,   -70,    86,   173,   -70,    19,   -70,
     -70,   306
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     6,     0,     1,     0,     0,     2,     0,
       7,     0,     0,     0,    30,     0,     0,    34,     0,     0,
      10,     9,    11,     0,    31,     0,    30,     0,     0,     0,
       4,     0,    35,    34,     0,     8,     0,    28,     0,     0,
       0,     0,     0,     5,     0,    29,    36,     0,     0,     0,
       0,    37,     0,     0,     0,    30,     0,     0,     0,     0,
      38,     0,     0,     0,     0,    11,    26,     0,    25,     0,
       0,    15,    16,    17,     0,    12,    14,    46,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    27,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
       3,    13,     0,     0,    43,    44,    45,    39,    40,    41,
      42,    48,     0,     0,    33,     0,     0,     0,     0,    23,
       0,     0,    51,    53,    47,     0,    20,    21,    22,     0,
      50,    55,     0,    54,    32,     0,     0,    49,     0,    19,
      24,    56
  };

  const short
  parser::yypgoto_[] =
  {
     -70,   -70,   -70,   -70,   -70,     6,   -70,   -61,    38,   -14,
     -19,   -70,   159,   -70,   -69,   -70,   -70
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    10,     6,    23,    77,    66,    67,    68,
      17,    32,    25,    49,    78,   142,   143
  };

  const unsigned char
  parser::yytable_[] =
  {
      89,    90,    52,    24,     1,    85,    88,    33,    53,    20,
      21,    14,    86,   105,   106,   107,   108,   109,    88,    24,
      88,     8,    22,     4,   114,   115,   116,   117,   118,   119,
     120,    69,   123,    70,   125,    15,    59,    38,    93,    94,
      95,    95,    30,   131,     9,    80,    43,    31,   100,   100,
       5,    31,    48,   101,   101,    71,    72,    73,    74,    56,
      75,    76,     7,    91,   141,   136,   137,   121,    61,    87,
     146,    11,    12,   100,   122,    61,    92,    16,   101,   151,
      13,    20,    21,    62,   149,    63,    64,   103,    20,    21,
      62,    18,    63,    64,    65,    61,   104,    79,    36,    81,
      37,    65,    61,    19,    26,    28,    29,    27,    20,    21,
      62,    34,    63,    64,    35,    20,    21,    62,    40,    63,
      64,    65,    93,    94,    95,    96,    97,    98,    65,    99,
      41,    42,   100,    44,    45,    46,    47,   101,    50,   102,
      93,    94,    95,    96,    97,    98,    51,    99,    54,    60,
     100,    55,    57,    58,    82,   101,    83,   129,    93,    94,
      95,    96,    97,    98,    84,    99,   110,   113,   100,   112,
     133,   124,   132,   101,   139,   135,    93,    94,    95,    96,
      97,    98,   138,    99,   144,   147,   100,   148,     0,     0,
     145,   101,    39,   150,    93,    94,    95,    96,    97,    98,
       0,    99,     0,     0,   100,     0,     0,     0,     0,   101,
     130,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,   100,     0,     0,     0,     0,   101,   134,    93,    94,
      95,    96,    97,    98,     0,    99,     0,     0,   100,     0,
       0,     0,     0,   101,   140,    93,    94,    95,    96,    97,
      98,     0,    99,     0,     0,   100,     0,   111,     0,     0,
     101,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,   100,     0,   126,     0,     0,   101,    93,    94,    95,
      96,    97,    98,     0,    99,     0,     0,   100,     0,   127,
       0,     0,   101,    93,    94,    95,    96,    97,    98,     0,
      99,     0,     0,   100,     0,   128,     0,     0,   101,    93,
      94,    95,    96,    97,    98,     0,    99,     0,     0,   100,
      93,    94,    95,    96,   101,    98,     0,    99,     0,     0,
     100,    93,    94,    95,     0,   101,    98,     0,    99,     0,
       0,   100,    93,    94,    95,     0,   101,    98,     0,     0,
       0,     0,   100,     0,     0,     0,     0,   101
  };

  const short
  parser::yycheck_[] =
  {
      69,    70,    15,    17,    22,    11,    67,    26,    21,    29,
      30,    16,    18,    82,    83,    84,    85,    86,    79,    33,
      81,     0,    42,    23,    93,    94,    95,    96,    97,    98,
      99,    12,   101,    14,   103,    40,    55,    31,     3,     4,
       5,     5,    17,   112,    23,    59,    17,    22,    13,    13,
       0,    22,    46,    18,    18,    36,    37,    38,    39,    53,
      41,    42,    42,    29,   133,   126,   127,    35,    16,    17,
     139,    16,    42,    13,    42,    16,    42,    24,    18,   148,
      22,    29,    30,    31,   145,    33,    34,    28,    29,    30,
      31,    42,    33,    34,    42,    16,    17,    59,    18,    61,
      20,    42,    16,    25,    16,    18,    42,    26,    29,    30,
      31,    14,    33,    34,    19,    29,    30,    31,    27,    33,
      34,    42,     3,     4,     5,     6,     7,     8,    42,    10,
      19,    42,    13,    18,    20,    14,    19,    18,    42,    20,
       3,     4,     5,     6,     7,     8,    42,    10,    15,    42,
      13,    16,    16,    28,    14,    18,    14,    20,     3,     4,
       5,     6,     7,     8,    14,    10,    17,    14,    13,    18,
      14,    17,    15,    18,    11,    20,     3,     4,     5,     6,
       7,     8,    20,    10,    17,    15,    13,    21,    -1,    -1,
      32,    18,    33,    20,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,
      19,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    18,    19,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    18,    19,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    13,    -1,    15,    -1,    -1,
      18,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    13,    -1,    15,    -1,    -1,    18,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    15,
      -1,    -1,    18,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    13,    -1,    15,    -1,    -1,    18,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    13,
       3,     4,     5,     6,    18,     8,    -1,    10,    -1,    -1,
      13,     3,     4,     5,    -1,    18,     8,    -1,    10,    -1,
      -1,    13,     3,     4,     5,    -1,    18,     8,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    18
  };

  const signed char
  parser::yystos_[] =
  {
       0,    22,    44,    45,    23,     0,    47,    42,     0,    23,
      46,    16,    42,    22,    16,    40,    24,    53,    42,    25,
      29,    30,    42,    48,    52,    55,    16,    26,    18,    42,
      17,    22,    54,    53,    14,    19,    18,    20,    48,    55,
      27,    19,    42,    17,    18,    20,    14,    19,    48,    56,
      42,    42,    15,    21,    15,    16,    48,    16,    28,    53,
      42,    16,    31,    33,    34,    42,    50,    51,    52,    12,
      14,    36,    37,    38,    39,    41,    42,    49,    57,    51,
      52,    51,    14,    14,    14,    11,    18,    17,    50,    57,
      57,    29,    42,     3,     4,     5,     6,     7,     8,    10,
      13,    18,    20,    28,    17,    57,    57,    57,    57,    57,
      17,    15,    18,    14,    57,    57,    57,    57,    57,    57,
      57,    35,    42,    57,    17,    57,    15,    15,    15,    20,
      19,    57,    15,    14,    19,    20,    50,    50,    20,    11,
      19,    57,    58,    59,    17,    32,    57,    15,    21,    50,
      20,    57
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    18,     6,     8,     0,     2,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     7,
       5,     5,     5,     4,     7,     1,     1,     2,     3,     5,
       0,     2,    13,    11,     0,     2,     0,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     1,     4,     3,     6,
       5,     4,     2,     0,     1,     1,     3
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
  "IDENTIFIER", "$accept", "goal", "main_class", "class_declaration",
  "class_declaration_list", "type", "factor", "statement",
  "statement_list", "var_declaration", "var_declaration_list",
  "method_declaration", "method_declaration_list", "parameter_list",
  "expression", "expression_list", "expression_list_nonempty", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    67,    67,    75,    87,    92,   105,   106,   118,   119,
     120,   121,   125,   126,   127,   128,   129,   130,   135,   136,
     142,   147,   152,   156,   160,   165,   170,   174,   182,   186,
     195,   196,   207,   223,   237,   238,   250,   251,   257,   266,
     271,   276,   281,   286,   291,   296,   301,   302,   308,   313,
     319,   324,   328,   339,   340,   344,   348
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
#line 1912 "parser.tab.cc"

#line 353 "parser.yy"
