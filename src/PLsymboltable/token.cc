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
  sname = INVALID;
  sval = "";
}

Token::Token(const Symbol &symbol, const string &sv)
{
  sname = symbol;
  sval = sv;
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

string Token::getSval()
{
  return sval;
}

void Token::setSval(const string &sv)
{
  sval = sv;
}
