#include <tapl/simple/is_value.hpp>

namespace tapl::simple
{
  namespace
  {
    class IsValueVisitor : public Visitor
    {
    public:
      IsValueVisitor() = default;

      void accept(True* t) override { m_res = true; }
      void accept(False* t) override { m_res = true; }
      void accept(Zero* t) override { m_res = true; }
      void accept(Succ* t) override { t->term()->visit(*this); }
      void accept(Pred* t) override { m_res = false; }
      void accept(IsZero* t) override { m_res = false; }
      void accept(IfThenElse* t) override { m_res = false; }
      bool result() const noexcept { return m_res; }

    protected:
      bool m_res = false;
    };
  } // namespace

  bool is_value(const term_ptr_t& t)
  {
    IsValueVisitor viz;
    t->visit(viz);
    return viz.result();
  }
} // namespace tapl::simple