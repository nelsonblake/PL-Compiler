//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Token Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef TOKEN_H
#define TOKEN_H

#include "./symbol.h"
#include "./attribute.h"

using namespace std;

class Token
{
public:
  // Constructors
  Token();
  Token(const Symbol &, const Attribute &);
  Token(const Token &);

  // Public Methods
  // Getters and Setters
  Symbol getSname();
  void setSname(const Symbol &);
  Attribute getSval();
  void setSval(const Attribute &);

private:
  // Data Members
  Symbol sname;
  Attribute sval;
};

#endif
