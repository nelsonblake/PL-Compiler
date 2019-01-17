//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Token Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef TOKEN_H
#define TOKEN_H

#include "./symbol.h"
#include <string>

using namespace std;

class Token
{
public:
  // Constructors
  Token();
  Token(const Symbol &, const string &);

  // Public Methods
  Symbol getSname();
  void setSname(const Symbol &);
  string getSval();
  void setSval(const string &);

private:
  // Data Members
  Symbol sname;
  string sval;
};

#endif
