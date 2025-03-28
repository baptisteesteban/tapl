#pragma once

#include <tapl/simple/ast.hpp>


namespace tapl::simple
{
  namespace details
  {
    class Driver
    {
    public:
      using value_t = std::shared_ptr<Term>;

    public:
      Driver() = default;

      value_t&& deliver();
      void      receive(value_t&& v);

      int parse(const char* src);

    private:
      void scan_begin(const char* source);
      void scan_end();

    private:
      value_t m_ast     = nullptr;
      bool    m_has_ast = false;
    };
  } // namespace details

  std::shared_ptr<Term> parse(const char* source);
  std::shared_ptr<Term> parse(const std::string& source);
} // namespace tapl::simple