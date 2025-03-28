#include <tapl/simple/parse.hpp>

namespace tapl::simple
{
  std::unique_ptr<Term> parse(const char* source)
  {
    return std::make_unique<True>(); // TODO: implement
  }
} // namespace tapl::simple