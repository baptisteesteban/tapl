#include <tapl/simple/pretty_print.hpp>

namespace tapl::simple
{
  PrettyPrintVisitor::PrettyPrintVisitor(std::ostream& out)
    : m_out(out)
  {
  }

  void PrettyPrintVisitor::accept(True* t)
  {
    m_out << "true";
  }

  void PrettyPrintVisitor::accept(False* t)
  {
    m_out << "false";
  }

  void PrettyPrintVisitor::accept(Zero* t)
  {
    m_out << "0";
  }

  void PrettyPrintVisitor::accept(Succ* t)
  {
    m_out << "succ ";
    t->term()->visit(*this);
  }

  void PrettyPrintVisitor::accept(Pred* t)
  {
    m_out << "pred ";
    t->term()->visit(*this);
  }

  void PrettyPrintVisitor::accept(IsZero* t)
  {
    m_out << "iszero ";
    t->term()->visit(*this);
  }

  void PrettyPrintVisitor::accept(IfThenElse* t)
  {
    m_out << "if ";
    t->tif()->visit(*this);
    m_out << " then ";
    t->tthen()->visit(*this);
    m_out << " else ";
    t->telse()->visit(*this);
  }

  void pretty_print(const std::unique_ptr<Term>& ast, std::ostream& out)
  {
    auto viz = PrettyPrintVisitor(out);
    ast->visit(viz);
  }
} // namespace tapl::simple