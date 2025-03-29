#include <tapl/simple/eval.hpp>
#include <tapl/simple/parse.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
  using namespace tapl::simple;

  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " \"term\"\n";
    return 1;
  }
  auto t = parse(argv[1]);
  std::cout << "Input term: ";
  pretty_print(t, std::cout);
  std::cout << "\n";
  auto t_eval = eval(t);
  std::cout << "Evaluated term: ";
  pretty_print(t_eval, std::cout);
  std::cout << "\n";

  return 0;
}