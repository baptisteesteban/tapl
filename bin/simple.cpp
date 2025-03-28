#include <tapl/simple/ast.hpp>
#include <tapl/simple/parse.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <iostream>

int main(void)
{
  using namespace tapl::simple;

  std::unique_ptr<Term> ast = parse("if true then true else false");
  pretty_print(ast, std::cout);
  std::cout << "\n";
  return 0;
}