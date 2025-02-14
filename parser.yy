/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
// Makes error messages more detailed.
%define parse.error verbose
// Use variant to handle different semantic types.
%define api.value.type variant
// Enables token constructor syntax.
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h" // Used to build AST nodes.
  #define USE_LEX_ONLY false // Set to true if you want separate lexer testing.
}

/* Code included in the parser implementation file */
%code{
  // The lexer function declaration. It must return a token.
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  // Global pointer to the root AST node.
  Node* root;
  // External variable for tracking current line number.
  extern int yylineno;
}

/* Token definitions */
// Define tokens for operators, parenthesis, punctuation, and reserved keywords.
%token <std::string> PLUS MINUS MULT AND OR LT GT EQ ASSIGN NOT DOT
%token <std::string> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token <std::string> SEMICOLON COMMA
%token <std::string> PUBLIC CLASS STATIC VOID MAIN STRING RETURN
%token <std::string> INT_TYPE BOOLEAN IF ELSE WHILE PRINTLN LENGTH
%token <std::string> TRUE FALSE THIS NEW EXTENDS
%token <std::string> INTEGER_LITERAL IDENTIFIER
%token END 0 "end of file"

/* Operator precedence and associativity */
// Establish operator precedence to control rule evaluation.
%left OR
%left AND
%left EQ
%left LT GT
%left PLUS MINUS
%left MULT
%right NOT
%left DOT
%left LBRACKET

/* Non-terminal types */
// Specify that non-terminals return a pointer to a Node (AST node).
// Add this to your %type declarations at the top
%type <Node *> pre_return_statements
%type <Node *> expression factor
%type <Node *> statement statement_list main_class return_statement
%type <Node *> goal class_declaration_list class_declaration
%type <Node *> var_declaration method_declaration type
%type <Node *> parameter_list expression_list
%type <Node *> var_declaration_list method_declaration_list

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%

// The start symbol of the grammar builds the complete AST.
goal: main_class class_declaration_list { 
    $$ = new Node("Goal", "", yylineno);
    $$->children.push_back($1); // Add the main class.
    if($2) $$->children.push_back($2); // Optionally add class declarations.
    root = $$; // Set the global AST root.
};


// Expression productions build nodes for arithmetic, logical, and other operations.
expression: expression AND expression {
        $$ = new Node("AndExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression OR expression {
        $$ = new Node("OrExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression LT expression {
        $$ = new Node("LessThanExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression GT expression {
        $$ = new Node("GreaterThanExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression EQ expression {
        $$ = new Node("EqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression PLUS expression {
        $$ = new Node("AddExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression MINUS expression {
        $$ = new Node("SubExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression MULT expression {
        $$ = new Node("MultExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | factor { $$ = $1; } // Base case: a factor.
    | expression LBRACKET expression RBRACKET { 
        // Represents an array access: array[expression]
        $$ = new Node("ArrayAccess", "", yylineno);
        $$->children.push_back($1); // Array operand.
        $$->children.push_back($3); // Index expression.
    }
    | expression DOT LENGTH {
        // Get the length of an array.
        $$ = new Node("Length", "", yylineno);
        $$->children.push_back($1);
    }
    | expression DOT IDENTIFIER LPAREN expression_list RPAREN {
        // Method call on an object with parameters.
        $$ = new Node("MethodCall", $3, yylineno);
        $$->children.push_back($1); // The caller object.
        if($5) $$->children.push_back($5); // Optional argument list.
    }
    | NEW INT_TYPE LBRACKET expression RBRACKET {
        // Create a new array.
        $$ = new Node("NewArray", "", yylineno);
        $$->children.push_back($4); // The size of the array.
    }
    | NEW IDENTIFIER LPAREN RPAREN {
        // Create a new object.
        $$ = new Node("NewObject", $2, yylineno);
    }
    | NOT expression {
        // Logical NOT expression.
        $$ = new Node("NotExpression", "", yylineno);
        $$->children.push_back($2);
    }
    | expression DOT IDENTIFIER {
        // Field access: object.field
        $$ = new Node("FieldAccess", $3, yylineno);
        $$->children.push_back($1);
    }
    ;

// Basic expressions (literals, identifiers, etc.)
factor: INTEGER_LITERAL  { $$ = new Node("Int", $1, yylineno); }
      | LPAREN expression RPAREN { $$ = $2; }
      | IDENTIFIER { $$ = new Node("Identifier", $1, yylineno); }
      | TRUE { $$ = new Node("Boolean", "true", yylineno); }
      | FALSE { $$ = new Node("Boolean", "false", yylineno); }
      | THIS { $$ = new Node("This", "", yylineno); }
      ;

// Defines the main class which contains the main method.
main_class: PUBLIC CLASS IDENTIFIER LBRACE PUBLIC STATIC VOID MAIN 
            LPAREN STRING LBRACKET RBRACKET IDENTIFIER RPAREN 
            LBRACE statement_list RBRACE RBRACE {
                $$ = new Node("MainClass", $3, yylineno);
                // Create a 'MainMethod' node containing the statements.
                Node* mainMethod = new Node("MainMethod", "", yylineno);
                mainMethod->children.push_back($16); // Statements block inside main.
                $$->children.push_back(mainMethod);
            }
            | CLASS IDENTIFIER LBRACE PUBLIC STATIC VOID MAIN 
            LPAREN STRING LBRACKET RBRACKET IDENTIFIER RPAREN 
            LBRACE statement RBRACE RBRACE {
                // Alternate syntax for the main class.
                $$ = new Node("MainClass", $2, yylineno);
                Node* mainMethod = new Node("MainMethod", "", yylineno);
                mainMethod->children.push_back($15); // Single statement.
                $$->children.push_back(mainMethod);
            }
            ;

// Various statement kinds are defined here.
statement: LBRACE statement_list RBRACE { $$ = $2; }
         | IF LPAREN expression RPAREN statement ELSE statement {
                $$ = new Node("IfStatement", "", yylineno);
                $$->children.push_back($3); // Condition.
                $$->children.push_back($5); // 'Then' branch.
                $$->children.push_back($7); // 'Else' branch.
         }
         | WHILE LPAREN expression RPAREN statement {
                $$ = new Node("WhileStatement", "", yylineno);
                $$->children.push_back($3); // Loop condition.
                $$->children.push_back($5); // Loop body.
         }
         | PRINTLN LPAREN expression RPAREN SEMICOLON {
                $$ = new Node("PrintStatement", "", yylineno);
                $$->children.push_back($3); // Expression to print.
         }
         | IDENTIFIER ASSIGN expression SEMICOLON {
                $$ = new Node("AssignStatement", $1, yylineno);
                $$->children.push_back($3); // Right-hand side value.
         }
         | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON {
                $$ = new Node("ArrayAssignStatement", $1, yylineno);
                $$->children.push_back($3); // Array index.
                $$->children.push_back($6); // Value assigned.
         }
         ;

// A list of statements.
statement_list: /* empty */ { 
        $$ = new Node("StatementList", "", yylineno); 
    }
    | statement_list statement {
        if($2) $1->children.push_back($2);
        $$ = $1;
    }
    ;
return_statement: RETURN expression SEMICOLON {
    $$ = new Node("ReturnStatement", "", yylineno);
    $$->children.push_back($2); // The expression to return.
    }
    ;


pre_return_statements: 
    /* empty */ { $$ = new Node("StatementList", "", yylineno); }
    | pre_return_statements statement {
        if($2) $1->children.push_back($2);
        $$ = $1;
    }
    ;

// A potentially empty list of class declarations.
class_declaration_list: /* empty */ { $$ = nullptr; }
    | class_declaration_list class_declaration {
        if($1 == nullptr) {
            $$ = new Node("ClassDeclarationList", "", yylineno);
        } else {
            $$ = $1;
        }
        $$->children.push_back($2);
    }
    ;

// Declares a class with its variables and methods. Two forms for with/without inheritance.
class_declaration: CLASS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE {
    $$ = new Node("ClassDeclaration", $2, yylineno);
    if($4) $$->children.push_back($4); // Variables.
    if($5) $$->children.push_back($5); // Methods.
}
| CLASS IDENTIFIER EXTENDS IDENTIFIER LBRACE var_declaration_list method_declaration_list RBRACE {
    $$ = new Node("ClassDeclaration", $2, yylineno);
    // Build an "Extends" node for the parent class.
    Node* extends = new Node("Extends", $4, yylineno);
    $$->children.push_back(extends);
    if($6) $$->children.push_back($6);
    if($7) $$->children.push_back($7);
}
;

// The type productions handle array types, primitive types, and identifiers as types.
type: INT_TYPE LBRACKET RBRACKET { $$ = new Node("ArrayType", "int[]", yylineno); }
    | BOOLEAN { $$ = new Node("Type", "boolean", yylineno); }
    | INT_TYPE { $$ = new Node("Type", "int", yylineno); }
    ;


var_declaration: type IDENTIFIER SEMICOLON {
    $$ = new Node("VarDeclaration", $2, yylineno);
    }
    ;

var_declaration_list: 
      /* empty */ { $$ = new Node("VarDeclarationList", "", yylineno); }
    | var_declaration_list var_declaration {
          $1->children.push_back($2);
          $$ = $1;
    }
    ;


// List of method declarations.
method_declaration_list: /* empty */ { $$ = nullptr; }
    | method_declaration_list method_declaration {
        if($1 == nullptr) {
            $$ = new Node("MethodDeclarationList", "", yylineno);
        } else {
            $$ = $1;
        }
        $$->children.push_back($2);
    }
    ;

// Three forms of method declarations.
method_declaration: 
    PUBLIC type IDENTIFIER LPAREN parameter_list RPAREN 
    LBRACE var_declaration_list pre_return_statements return_statement RBRACE {
        $$ = new Node("MethodDeclaration", $3, yylineno);
        $$->children.push_back($2); // Return type.
        if($5) $$->children.push_back($5); // Parameters.
        if($8) $$->children.push_back($8); // Method body statements.
        $$->children.push_back($9); // 'RETURN' token (for AST purposes).
    }
    | PUBLIC STATIC VOID IDENTIFIER LPAREN parameter_list RPAREN 
    LBRACE var_declaration_list statement_list RBRACE {
        $$ = new Node("MethodDeclaration", $4, yylineno);
        // Create a void type node.
        Node* voidType = new Node("Type", "void", yylineno);
        $$->children.push_back(voidType);
        if($6) $$->children.push_back($6); // Parameters.
        if($9) $$->children.push_back($9); // Body statements.
        $$->children.push_back($10); // Closing brace included.
    }
    | PUBLIC VOID IDENTIFIER LPAREN parameter_list RPAREN 
    LBRACE var_declaration_list statement_list RBRACE {
        $$ = new Node("MethodDeclaration", $3, yylineno);
        Node* voidType = new Node("Type", "void", yylineno);
        $$->children.push_back(voidType);
        if($5) $$->children.push_back($5);
        if($8) $$->children.push_back($8);
        $$->children.push_back($9);
    }
    ;

// Parameter list for a method: can be empty or multiple parameters.
parameter_list: 
    /* empty */ { $$ = nullptr; }
    | type IDENTIFIER { 
        $$ = new Node("ParameterList", "", yylineno);
        Node* param = new Node("Parameter", $2, yylineno);
        param->children.push_back($1); // Parameter type.
        $$->children.push_back(param);
    }
    | parameter_list COMMA type IDENTIFIER {
        Node* param = new Node("Parameter", $4, yylineno);
        param->children.push_back($3);
        $1->children.push_back(param);
        $$ = $1;
    }
    ;

// Expression list used for method arguments.
expression_list: /* empty */ { $$ = nullptr; }
    | expression { 
        $$ = new Node("ExpressionList", "", yylineno);
        $$->children.push_back($1);
    }
    | expression_list COMMA expression {
        $1->children.push_back($3);
        $$ = $1;
    }
    ;
%%