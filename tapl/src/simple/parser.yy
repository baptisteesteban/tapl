%language "C++"
%require "3.2"
%define api.value.type variant
%define api.token.constructor
%define api.token.prefix {TOK_}
%define api.namespace {tapl::simple}

%code provides
{
#define YY_DECL \
    tapl::simple::parser::symbol_type yylex(tapl::simple::details::Driver& drv)

YY_DECL;
}

%code requires
{
    #include <tapl/simple/ast.hpp>
    #include <tapl/simple/parse.hpp>

    #include <memory>
    #include <utility>
}

%param { tapl::simple::details::Driver& drv }

%type<std::unique_ptr<tapl::simple::Term>> term

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

file: term EOF { drv.receive(std::move($1)); }

term: TRUE { $$ = std::make_unique<True>(); }
    | FALSE { $$ = std::make_unique<False>(); }
    | ZERO { $$ = std::make_unique<Zero>(); }
    | PRED term { $$ = std::make_unique<Pred>(std::move($2)); }
    | SUCC term { $$ = std::make_unique<Succ>(std::move($2)); }
    | ISZERO term { $$ = std::make_unique<IsZero>(std::move($2)); }
    | IF term THEN term ELSE term { $$ = std::make_unique<IfThenElse>(std::move($2), std::move($4), std::move($6)); }

%%

void tapl::simple::parser::error(const std::string& s)
{
    std::cerr << "Unexpected parser error: " << s << "\n";
}