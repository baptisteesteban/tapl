#pragma once

#include <tapl/simple/ast.hpp>

namespace tapl::simple
{
  std::unique_ptr<Term> parse(const char* source);
} // namespace tapl::simple