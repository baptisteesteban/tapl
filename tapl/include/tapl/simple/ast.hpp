#pragma once

#include <memory>

namespace tapl::simple
{
  class Visitor;

  class Term
  {
  public:
    virtual void visit(Visitor* viz) = 0;
  };

  class True : public Term
  {
  public:
    void visit(Visitor* viz) override;
  };

  class False : public Term
  {
  public:
    void visit(Visitor* viz) override;
  };

  class Zero : public Term
  {
  public:
    void visit(Visitor* viz) override;
  };

  class Succ : public Term
  {
  public:
    Succ(Term* t);
    Term* term() { return m_term; }

    void visit(Visitor* viz) override;

  private:
    Term* m_term;
  };

  class Pred : public Term
  {
  public:
    Pred(Term* t);
    Term* term() { return m_term; }

    void visit(Visitor* viz) override;

  private:
    Term* m_term;
  };

  class IsZero : public Term
  {
  public:
    IsZero(Term* t);
    Term* term() { return m_term; }

    void visit(Visitor* viz) override;

  private:
    Term* m_term;
  };

  class IfThenElse : public Term
  {
  public:
    IfThenElse(Term* tif, Term* tthen, Term* telse);

    Term* tif() { return m_if; }
    Term* tthen() { return m_then; }
    Term* telse() { return m_else; }

    void visit(Visitor* viz) override;

  private:
    Term* m_if;
    Term* m_then;
    Term* m_else;
  };
} // namespace tapl::simple