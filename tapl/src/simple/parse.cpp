#include <tapl/simple/parse.hpp>

#include <parser.hpp>

#include <cassert>

namespace tapl::simple
{
  namespace details
  {
    int Driver::parse(const char* src)
    {
      scan_begin(src);
      parser parser_instance(*this);
      int    status = parser_instance();
      scan_end();
      return status;
    }

    typename Driver::value_t&& Driver::deliver()
    {
      assert(m_has_ast);
      m_has_ast = false;
      return std::move(m_ast);
    }
    void Driver::receive(typename Driver::value_t&& v)
    {
      assert(!m_has_ast);
      m_ast     = std::forward<value_t>(v);
      m_has_ast = true;
    }
  } // namespace details

  std::unique_ptr<Term> parse(const char* source)
  {
    details::Driver drv;
    int             status = drv.parse(source);
    if (!status)
      return std::forward<std::unique_ptr<Term>>(drv.deliver());
    return nullptr;
  }

  std::unique_ptr<Term> parse(const std::string& source)
  {
    return parse(source.c_str());
  }
} // namespace tapl::simple