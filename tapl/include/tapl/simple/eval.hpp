#pragma once

#include <tapl/simple/ast.hpp>

namespace tapl::simple
{
  term_ptr_t eval(const term_ptr_t& t);
} // namespace tapl::simple