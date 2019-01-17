//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Attribute Interface
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
// TODO: Expand
//************************************************************************************

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "../PLScanner/token.h"

using namespace std;

class Attribute
{
public:
  // Constructors
  Attribute(const Token&);

private:
  // Data Members
  Token token;
};

#endif
