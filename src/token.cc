//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Token Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./token.h"

using namespace std;

// Constructors
Token::Token()
{
  sname = NONAME;
  sval = Attribute();
}

Token::Token(const Symbol &symbol, const Attribute &sv)
{
  sname = symbol;
  sval = sv;
}

Token::Token(const Token &t)
{
  sname = t.sname;
  sval = t.sval;
}

// Getters and Setters
Symbol Token::getSname()
{
  return sname;
}

void Token::setSname(const Symbol &symbol)
{
  sname = symbol;
}

Attribute Token::getSval()
{
  return sval;
}

void Token::setSval(const Attribute &sv)
{
  sval = sv;
}
