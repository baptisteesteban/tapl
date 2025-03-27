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

  Succ::Succ(std::unique_ptr<Term>&& t)
    : m_term(std::forward<std::unique_ptr<Term>>(t))
  {
  }

  void Succ::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  Pred::Pred(std::unique_ptr<Term>&& t)
    : m_term(std::forward<std::unique_ptr<Term>>(t))
  {
  }

  void Pred::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  IsZero::IsZero(std::unique_ptr<Term>&& t)
    : m_term(std::forward<std::unique_ptr<Term>>(t))
  {
  }

  void IsZero::visit(Visitor& viz)
  {
    viz.accept(this);
  }

  IfThenElse::IfThenElse(std::unique_ptr<Term>&& tif, std::unique_ptr<Term>&& tthen, std::unique_ptr<Term>&& telse)
    : m_if(std::forward<std::unique_ptr<Term>>(tif))
    , m_then(std::forward<std::unique_ptr<Term>>(tthen))
    , m_else(std::forward<std::unique_ptr<Term>>(telse))
  {
  }

  void IfThenElse::visit(Visitor& viz)
  {
    viz.accept(this);
  }
} // namespace tapl::simple