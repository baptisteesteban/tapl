%option noyywrap
blank [ \t]

%{
    #include "parser.hpp"    
%}

%%

{blank}+   {}
"true"     return tapl::simple::parser::make_TRUE();
"false"    return tapl::simple::parser::make_FALSE();
"0"        return tapl::simple::parser::make_ZERO();
"iszero"   return tapl::simple::parser::make_ISZERO();
"succ"     return tapl::simple::parser::make_SUCC();
"pred"     return tapl::simple::parser::make_PRED();
"if"       return tapl::simple::parser::make_IF();
"then"     return tapl::simple::parser::make_THEN();
"else"     return tapl::simple::parser::make_ELSE();
<<eof>>    return tapl::simple::parser::make_EOF();
. {
    std::cerr << "Unexpected lexer error: " << yytext << "\n";
}
%%