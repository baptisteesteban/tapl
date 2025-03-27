%option noyywrap c++
%option outfile="lexer.cpp"

%{
    #include <memory>
%}

%%

true printf("TRUE");
false printf("FALSE");
zero printf("ZERO");
succ printf("SUCC");
pred printf("PRED");
iszero printf("ISZERO");
if printf("IF");
then printf("THEN");
else printf("ELSE");

%%

int main(void)
{
    auto lexer = std::make_unique<yyFlexLexer>();
    while (lexer->yylex() > 0) continue;
    return 0;
}