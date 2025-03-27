#pragma once

#include <tapl/simple/ast.hpp>

#include <memory>

namespace tapl::simple
{
  class Visitor
  {
  public:
    virtual void accept(True* t)       = 0;
    virtual void accept(False* t)      = 0;
    virtual void accept(Zero* t)       = 0;
    virtual void accept(Succ* t)       = 0;
    virtual void accept(Pred* t)       = 0;
    virtual void accept(IsZero* t)     = 0;
    virtual void accept(IfThenElse* t) = 0;
  };
} // namespace tapl::simple