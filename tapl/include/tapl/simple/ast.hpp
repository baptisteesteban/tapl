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
    Succ(std::unique_ptr<Term>&& t);
    std::unique_ptr<Term>& term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::unique_ptr<Term> m_term;
  };

  class Pred : public Term
  {
  public:
    Pred(std::unique_ptr<Term>&& t);
    std::unique_ptr<Term>& term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::unique_ptr<Term> m_term;
  };

  class IsZero : public Term
  {
  public:
    IsZero(std::unique_ptr<Term>&& t);
    std::unique_ptr<Term>& term() { return m_term; }

    void visit(Visitor& viz) override;

  private:
    std::unique_ptr<Term> m_term;
  };

  class IfThenElse : public Term
  {
  public:
    IfThenElse(std::unique_ptr<Term>&& tif, std::unique_ptr<Term>&& tthen, std::unique_ptr<Term>&& telse);

    std::unique_ptr<Term>& tif() { return m_if; }
    std::unique_ptr<Term>& tthen() { return m_then; }
    std::unique_ptr<Term>& telse() { return m_else; }

    void visit(Visitor& viz) override;

  private:
    std::unique_ptr<Term> m_if;
    std::unique_ptr<Term> m_then;
    std::unique_ptr<Term> m_else;
  };

  using term_ptr_t = std::unique_ptr<Term>;
} // namespace tapl::simple