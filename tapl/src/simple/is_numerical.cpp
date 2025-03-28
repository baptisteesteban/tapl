#include <tapl/simple/is_numerical.hpp>

namespace tapl::simple
{
  void IsNumericalVisitor::accept(True* t)
  {
    m_res = false;
  }

  void IsNumericalVisitor::accept(False* t)
  {
    m_res = false;
  }

  void IsNumericalVisitor::accept(Zero* t)
  {
    m_res = true;
  }

  void IsNumericalVisitor::accept(Succ* t)
  {
    t->term()->visit(*this);
  }

  void IsNumericalVisitor::accept(Pred* t)
  {
    m_res = false;
  }

  void IsNumericalVisitor::accept(IsZero* t)
  {
    m_res = false;
  }

  void IsNumericalVisitor::accept(IfThenElse* t)
  {
    m_res = false;
  }

  bool is_numerical(const term_ptr_t& t)
  {
    IsNumericalVisitor viz;
    t->visit(viz);
    return viz.result();
  }
} // namespace tapl::simple