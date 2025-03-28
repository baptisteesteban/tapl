#pragma once

#include <memory>

namespace tapl::simple
{
  class Visitor;

  class Term
  {
  public:
    virtual void visit(Visitor& viz) = 0;
  };

  class True : public Term
  {
  public:
    void visit(Visitor& viz) override;
  };

  class False : public Term
  {
  public:
    void visit(Visitor& viz) override;
  };

  class Zero : public Term
  {
  public:
    void visit(Visitor& viz) override;
  };

  class Succ : public Term
  {
  public:
    Succ(std::shared_ptr<Term> t);
    std::shared_ptr<Term> term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::shared_ptr<Term> m_term;
  };

  class Pred : public Term
  {
  public:
    Pred(std::shared_ptr<Term> t);
    std::shared_ptr<Term> term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::shared_ptr<Term> m_term;
  };

  class IsZero : public Term
  {
  public:
    IsZero(std::shared_ptr<Term> t);
    std::shared_ptr<Term> term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::shared_ptr<Term> m_term;
  };

  class IfThenElse : public Term
  {
  public:
    IfThenElse(std::shared_ptr<Term> tif, std::shared_ptr<Term> tthen, std::shared_ptr<Term> telse);

    std::shared_ptr<Term> tif() { return m_if; }
    std::shared_ptr<Term> tthen() { return m_then; }
    std::shared_ptr<Term> telse() { return m_else; }

    void visit(Visitor& viz) override;

  private:
    std::shared_ptr<Term> m_if;
    std::shared_ptr<Term> m_then;
    std::shared_ptr<Term> m_else;
  };

  using term_ptr_t = std::shared_ptr<Term>;
} // namespace tapl::simple