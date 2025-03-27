#include <tapl/simple/ast.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <gtest/gtest.h>

#include <sstream>
#include <string_view>

using namespace tapl::simple;

TEST(Simple, PrettyPrint)
{
  std::string_view      expected = "if true then true else false";
  std::ostringstream    out;
  std::unique_ptr<Term> ast =
      std::make_unique<IfThenElse>(std::make_unique<True>(), std::make_unique<True>(), std::make_unique<False>());
  pretty_print(ast, out);
  ASSERT_EQ(out.str(), expected);
}