//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Attribute Interface
// Written By: Eric Den Haan and Blake Nelson
// TODO: Expand
//************************************************************************************

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "./token.h"

using namespace std;

class Attribute
{
public:
  // Constructors
  Attribute();
  Attribute(const Token &);

private:
  // Data Members
  Token token;
};

#endif
