//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Attribute Implementation File
// Written By: Eric Den Haan and Blake Nelson
// TODO: Expand
//************************************************************************************

#include "./attribute.h"

using namespace std;

// Constructors
Attribute::Attribute()
{
  value = -1;
  lexeme = "";
}

Attribute::Attribute(const string &l)
{
  value = -1;
  lexeme = l;
}

Attribute::Attribute(const int &v)
{
  value = v;
  lexeme = "";
}

Attribute::Attribute(const int &v, const string &l = "")
{
  value = v;
  lexeme = l;
}

// Getters
int Attribute::getValue()
{
  return value;
}

string Attribute::getLexeme()
{
  return lexeme;
}
