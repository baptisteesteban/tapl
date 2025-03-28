%language "C++"
%define api.value.type variant
%define api.token.constructor
%define api.token.prefix {TOK_}
%define api.namespace {tapl::simple}
%define parse.error verbose
%define parse.trace

%code provides
{
#define YY_DECL \
    tapl::simple::parser::symbol_type yylex()

YY_DECL;
}

%code requires
{
    #include <tapl/simple/ast.hpp>

    #include <iostream>
    #include <stack>
    #include <utility>
    #include <vector>
}

%token TRUE     "true"
%token FALSE    "false"
%token ZERO     "0"
%token ISZERO   "iszero"
%token SUCC     "succ"
%token PRED     "pred"
%token IF       "if"
%token THEN     "then"
%token ELSE     "else"
%token EOF 0    "end-of-file"

%%
%start file;

file: term EOF

term: TRUE {}
    | FALSE {}
    | ZERO {}
    | PRED term {}
    | SUCC term {}
    | ISZERO term {}
    | IF term THEN term ELSE term {}

%%

void tapl::simple::parser::error(const std::string& s)
{
    std::cerr << "Unexpected parser error: " << s << "\n";
}

int main(void)
{
    tapl::simple::parser parser;
    int status = parser.parse();
    std::cout << "Status: " << status << "\n";
}