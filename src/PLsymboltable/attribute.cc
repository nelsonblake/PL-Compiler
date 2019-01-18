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
Attribute::Attribute(const int &v, const string &l = "")
{
  value = v;
  lexeme = l;
}

// Getters and Setters
int Attribute::getValue()
{
  return value;
}

void Attribute::setValue(const int &v)
{
  value = v;
}

string Attribute::getLexeme()
{
  return lexeme;
}

void Attribute::setLexeme(const string &l)
{
  lexeme = l;
}