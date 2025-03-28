#include <tapl/simple/pretty_print.hpp>
#include <tapl/simple/visitor.hpp>

namespace tapl::simple
{
  namespace
  {
    class PrettyPrintVisitor : public Visitor
    {
    public:
      PrettyPrintVisitor(std::ostream& out)
        : m_out(out)
      {
      }

      void accept(True* t) override { m_out << "true"; }
      void accept(False* t) override { m_out << "false"; }
      void accept(Zero* t) override { m_out << "0"; }
      void accept(Succ* t) override
      {
        m_out << "succ ";
        t->term()->visit(*this);
      }
      void accept(Pred* t) override
      {
        m_out << "pred ";
        t->term()->visit(*this);
      }
      void accept(IsZero* t) override
      {
        m_out << "iszero ";
        t->term()->visit(*this);
      }
      void accept(IfThenElse* t) override
      {
        m_out << "if ";
        t->tif()->visit(*this);
        m_out << " then ";
        t->tthen()->visit(*this);
        m_out << " else ";
        t->telse()->visit(*this);
      }

    private:
      std::ostream& m_out;
    };
  } // namespace

  void pretty_print(const std::shared_ptr<Term>& ast, std::ostream& out)
  {
    auto viz = PrettyPrintVisitor(out);
    ast->visit(viz);
  }
} // namespace tapl::simple