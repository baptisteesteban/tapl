#include <tapl/simple/ast.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <iostream>

int main(void)
{
  using namespace tapl::simple;

  std::unique_ptr<Term> ast =
      std::make_unique<IfThenElse>(std::make_unique<True>(), std::make_unique<True>(), std::make_unique<False>());
  pretty_print(ast, std::cout);
  std::cout << "\n";
  return 0;
}