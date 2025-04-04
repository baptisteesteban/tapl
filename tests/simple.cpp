#include <tapl/simple/ast.hpp>
#include <tapl/simple/eval.hpp>
#include <tapl/simple/is_numerical.hpp>
#include <tapl/simple/is_value.hpp>
#include <tapl/simple/parse.hpp>
#include <tapl/simple/pretty_print.hpp>

#include <gtest/gtest.h>

#include <sstream>
#include <string_view>

using namespace tapl::simple;

TEST(Simple, PrettyPrint)
{
  std::string_view      expected = "if true then true else false";
  std::ostringstream    out;
  std::shared_ptr<Term> ast =
      std::make_shared<IfThenElse>(std::make_shared<True>(), std::make_shared<True>(), std::make_shared<False>());
  pretty_print(ast, out);
  ASSERT_EQ(out.str(), expected);
}

TEST(Simple, Parser)
{
  {
    const char* ref[] = {
        "true",                                                 //
        "false",                                                //
        "0",                                                    //
        "pred 0",                                               //
        "succ 0",                                               //
        "pred succ succ 0",                                     //
        "if true then true else false",                         //
        "if pred succ 0 then succ succ 0 else pred pred succ 0" //
    };

    for (const char* e : ref)
    {
      std::ostringstream os;
      auto               t = parse(e);
      pretty_print(t, os);
      ASSERT_EQ(e, os.str());
    }
  }

  {
    const char*        in  = "\tif true  then \ttrue        else iszero succ     0";
    const char*        ref = "if true then true else iszero succ 0";
    auto               t   = parse(in);
    std::ostringstream os;
    pretty_print(t, os);
    ASSERT_EQ(ref, os.str());
  }
}

TEST(Simple, IsNumerical)
{
  const std::pair<const char*, bool> ref[] = {
      {"0", true},                             //
      {"if true then true else false", false}, //
      {"succ 0", true},                        //
      {"succ succ 0", true}                    //
  };

  for (auto e : ref)
  {
    auto t = parse(e.first);
    ASSERT_EQ(is_numerical(t), e.second);
  }
}

TEST(Simple, IsValue)
{
  const std::pair<const char*, bool> ref[] = {
      {"0", true},                             //
      {"if true then true else false", false}, //
      {"succ 0", true},                        //
      {"succ succ 0", true},                   //
      {"true", true},                          //
      {"false", true}                          //
  };

  for (auto e : ref)
  {
    auto t = parse(e.first);
    ASSERT_EQ(is_value(t), e.second);
  }
}

TEST(Simple, Eval)
{
  const std::pair<const char*, const char*> ref[] = {
      {"0", "0"},                                                       //
      {"pred 0", "0"},                                                  //
      {"pred succ 0", "0"},                                             //
      {"if true then true else false", "true"},                         //
      {"if false then true else false", "false"},                       //
      {"iszero 0", "true"},                                             //
      {"iszero succ 0", "false"},                                       //
      {"iszero pred 0", "true"},                                        //
      {"if iszero 0 then true else false", "true"},                     //
      {"if if true then false else true then true else false", "false"} //
  };
  for (auto e : ref)
  {
    auto               t  = parse(e.first);
    auto               tp = eval(t);
    std::ostringstream os;
    pretty_print(tp, os);
    ASSERT_EQ(os.str(), e.second);
  }
}