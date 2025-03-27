#include <tapl/simple/ast.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <iostream>

int main(void)
{
  using namespace tapl::simple;
  auto CTrue       = new True;
  auto CFalse      = new False;
  auto Cifthenelse = new IfThenElse(CTrue, CTrue, CFalse);
  pretty_print(Cifthenelse, std::cout);
  std::cout << "\n";
  delete CTrue;
  delete CFalse;
  delete Cifthenelse;
  return 0;
}