%option noyywrap
blank [ \t]

%{
    #include "parser.hpp"    
%}

%%

{blank}+   {}
"true"     return tapl::simple::parser::token::TOK_TRUE;
"false"    return tapl::simple::parser::token::TOK_FALSE;
"0"        return tapl::simple::parser::token::TOK_ZERO;
"iszero"   return tapl::simple::parser::token::TOK_ISZERO;
"succ"     return tapl::simple::parser::token::TOK_SUCC;
"pred"     return tapl::simple::parser::token::TOK_PRED;
"if"       return tapl::simple::parser::token::TOK_IF;
"then"     return tapl::simple::parser::token::TOK_THEN;
"else"     return tapl::simple::parser::token::TOK_ELSE;
<<eof>>    return tapl::simple::parser::token::TOK_EOF;
. {
    std::cerr << "Unexpected lexer error: " << yytext << "\n";
}
%%