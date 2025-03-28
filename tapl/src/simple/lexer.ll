%option noyywrap
blank [ \t]

%{
    #include "parser.hpp"    
%}

%%

{blank}+   {}
"true"     return yy::parser::make_TRUE();
"false"    return yy::parser::make_FALSE();
"0"        return yy::parser::make_ZERO();
"iszero"   return yy::parser::make_ISZERO();
"succ"     return yy::parser::make_SUCC();
"pred"     return yy::parser::make_PRED();
"if"       return yy::parser::make_IF();
"then"     return yy::parser::make_THEN();
"else"     return yy::parser::make_ELSE();
<<eof>>    return yy::parser::make_EOF();
. {
    std::cerr << "Unexpected lexer error: " << yytext << "\n";
}
%%