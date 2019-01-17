//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Attribute Implementation
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
// TODO: Expand
//************************************************************************************

#include "./attribute.h"

using namespace std;

// Constructor
Attribute::Attribute(const Token& t)
{
  token = t;
}
