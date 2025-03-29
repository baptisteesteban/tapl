#include <tapl/simple/eval.hpp>
#include <tapl/simple/parse.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <sstream>
#include <string>

int main(void)
{
  std::string        ref = "true";
  auto               t   = tapl::simple::parse("if true then true else false");
  auto               tp  = tapl::simple::eval(t);
  std::ostringstream os;
  tapl::simple::pretty_print(tp, os);
  if (ref == os.str())
    return 0;
  return 1;
}