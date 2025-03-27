#pragma once

#include <tapl/simple/visitor.hpp>

#include <ostream>

namespace tapl::simple
{
  class PrettyPrintVisitor : public Visitor
  {
  public:
    PrettyPrintVisitor(std::ostream& out);

    void accept(True* t) override;
    void accept(False* t) override;
    void accept(Zero* t) override;
    void accept(Succ* t) override;
    void accept(Pred* t) override;
    void accept(IsZero* t) override;
    void accept(IfThenElse* t) override;

  private:
    std::ostream& m_out;
  };

  void pretty_print(const std::unique_ptr<Term>& ast, std::ostream& out);
} // namespace tapl::simple