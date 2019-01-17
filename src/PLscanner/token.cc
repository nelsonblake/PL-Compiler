//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Token Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include 'token.h'

using namespace std;

// Constructors
Token::Token(const Symbol& symbol)
{
  sname = symbol;
  sval = "";
}

Token::Token(const Symbol& symbol, const string& sv)
{
  sname = symbol;
  sval = sv;
}

// Getters and Setters
Token::getSname()
{
  return sname;
}

Token::setSname(const Symbol& symbol)
{
  sname = symbol;
}

Token::getSval()
{
  return sval;
}

Token::setSval(const string& sv)
{
  sval = sv;
}
