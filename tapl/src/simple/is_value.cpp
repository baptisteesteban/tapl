#include <tapl/simple/is_value.hpp>

namespace tapl::simple
{
  void IsValueVisitor::accept(True* t)
  {
    m_res = true;
  }
  void IsValueVisitor::accept(False* t)
  {
    m_res = true;
  }

  bool is_value(const term_ptr_t& t)
  {
    IsValueVisitor viz;
    t->visit(viz);
    return viz.result();
  }
} // namespace tapl::simple