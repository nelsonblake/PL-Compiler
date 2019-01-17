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
  // Constructors
  Token(const Symbol&);
  Token(const Symbol&, const string&);

  // Public Methods
  void getSname();
  void setSname();
  void getSval();
  void setSval();

  // Data Members
  Symbol sname;
  string sval;
};

#endif
