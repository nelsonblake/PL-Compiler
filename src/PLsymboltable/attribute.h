//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Attribute Interface File
// Written By: Eric Den Haan and Blake Nelson
// TODO: Expand
//************************************************************************************

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "./token.h"
#include <string>

using namespace std;

class Attribute
{
public:
  // Constructors
  Attribute();
  Attribute(const string &);
  Attribute(const int &, const string &);

  // Public Methods
  // Getters and Setters
  int getValue();
  void setValue(const int &);
  string getLexeme();
  void setLexeme(const string &);

private:
  // Data Members
  // for NUM, value is the numerical value of the decimal string
  // for ID/Keywords, value is the location of the token in the Symbol Table
  int value;
  // for ID/Keywords, unused otherwise
  string lexeme;
};

#endif
