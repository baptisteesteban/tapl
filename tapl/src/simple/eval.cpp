#include <tapl/simple/eval.hpp>
#include <tapl/simple/is_numerical.hpp>
#include <tapl/simple/visitor.hpp>

namespace tapl::simple
{
  namespace
  {
    class NoRuleApplies : public std::exception
    {
    };

    term_ptr_t eval1(term_ptr_t t)
    {
      if (auto tp = std::dynamic_pointer_cast<IfThenElse>(t); tp != nullptr)
      {
        auto cond = tp->tif();
        if (auto condp = std::dynamic_pointer_cast<True>(cond); condp != nullptr)
          return tp->tthen();
        else if (auto condp = std::dynamic_pointer_cast<False>(cond); condp != nullptr)
          return tp->telse();
        else
        {
          auto t1p = eval1(cond);
          return std::make_shared<IfThenElse>(t1p, tp->tthen(), tp->telse());
        }
      }
      else if (auto tp = std::dynamic_pointer_cast<Succ>(t); tp != nullptr)
      {
        auto t1p = eval1(t);
        return std::make_shared<Succ>(t1p);
      }
      else if (auto tp = std::dynamic_pointer_cast<Pred>(t); tp != nullptr)
      {
        auto t1 = tp->term();
        if (auto t1c = std::dynamic_pointer_cast<Zero>(t1); t1c != nullptr)
          return std::make_shared<Zero>();
        else if (auto t1c = std::dynamic_pointer_cast<Succ>(t1); t1c != nullptr && is_numerical(t1c->term()))
          return t1c->term();
        else
        {
          auto t1p = eval1(t1);
          return std::make_shared<Pred>(t1p);
        }
      }
      else if (auto tp = std::dynamic_pointer_cast<IsZero>(t); tp != nullptr)
      {
        auto t1 = tp->term();
        if (auto t1c = std::dynamic_pointer_cast<Zero>(t1); t1c != nullptr)
          return std::make_shared<True>();
        else if (auto t1c = std::dynamic_pointer_cast<Succ>(t1); t1c != nullptr && is_numerical(t1c->term()))
          return std::make_shared<False>();
        else
        {
          auto t1p = eval1(t1);
          return std::make_shared<IsZero>(t1p);
        }
      }
      else
        throw NoRuleApplies();
    }
  } // namespace
  term_ptr_t eval(term_ptr_t t)
  {
    try
    {
      auto tp = eval1(t);
      return eval(tp);
    }
    catch (NoRuleApplies)
    {
      return t;
    }
  }
} // namespace tapl::simple