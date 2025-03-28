#pragma once

#include <tapl/simple/is_numerical.hpp>

namespace tapl::simple
{
  class IsValueVisitor : public IsNumericalVisitor
  {
  public:
    void accept(True* t) override;
    void accept(False* t) override;
  };

  bool is_value(const term_ptr_t& t);
} // namespace tapl::simple