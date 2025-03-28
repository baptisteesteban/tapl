#include <tapl/simple/is_numerical.hpp>

namespace tapl::simple
{
  namespace
  {
    class IsNumericalVisitor : public Visitor
    {
    public:
      IsNumericalVisitor() = default;

      void accept(True* t) override { m_res = false; }
      void accept(False* t) override { m_res = false; }
      void accept(Zero* t) override { m_res = true; }
      void accept(Succ* t) override { t->term()->visit(*this); }
      void accept(Pred* t) override { m_res = false; }
      void accept(IsZero* t) override { m_res = false; }
      void accept(IfThenElse* t) override { m_res = false; }
      bool result() const noexcept { return m_res; }

    protected:
      bool m_res = true;
    };
  } // namespace

  bool is_numerical(const term_ptr_t& t)
  {
    IsNumericalVisitor viz;
    t->visit(viz);
    return viz.result();
  }
} // namespace tapl::simple