#pragma once

#include <tapl/simple/ast.hpp>

#include <ostream>

namespace tapl::simple
{
  void pretty_print(const std::shared_ptr<Term>& ast, std::ostream& out);
} // namespace tapl::simple