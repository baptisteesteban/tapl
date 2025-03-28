#include <tapl/simple/ast.hpp>
#include <tapl/simple/visitor.hpp>

namespace tapl::simple
{
  void True::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  void False::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  void Zero::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  Succ::Succ(std::shared_ptr<Term> t)
    : m_term(t)
  {
  }

  void Succ::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  Pred::Pred(std::shared_ptr<Term> t)
    : m_term(t)
  {
  }

  void Pred::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  IsZero::IsZero(std::shared_ptr<Term> t)
    : m_term(t)
  {
  }

  void IsZero::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  IfThenElse::IfThenElse(std::shared_ptr<Term> tif, std::shared_ptr<Term> tthen, std::shared_ptr<Term> telse)
    : m_if(tif)
    , m_then(tthen)
    , m_else(telse)
  {
  }

  void IfThenElse::visit(Visitor& viz)
  {
    viz.accept(this);
  }
} // namespace tapl::simple