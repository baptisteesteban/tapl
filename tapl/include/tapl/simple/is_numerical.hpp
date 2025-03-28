#pragma once

#include <tapl/simple/visitor.hpp>

namespace tapl::simple
{
  class IsNumericalVisitor : public Visitor
  {
  public:
    IsNumericalVisitor() = default;

    void accept(True* t);
    void accept(False* t);
    void accept(Zero* t);
    void accept(Succ* t);
    void accept(Pred* t);
    void accept(IsZero* t);
    void accept(IfThenElse* t);
    bool result() const noexcept;

  protected:
    bool m_res = true;
  };

  inline bool IsNumericalVisitor::result() const noexcept
  {
    return m_res;
  }

  bool is_numerical(const term_ptr_t& t);
} // namespace tapl::simple