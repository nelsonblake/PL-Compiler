//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Implementation File
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
//************************************************************************************

#include "./symbolTableEntry.h"

using namespace std;

// Constructors
SymbolTableEntry(const int& k, const Attribute& attr)
{
  key = k;
  attributes = attr;
}

// Getters
int getKey()
{
  return key;
}

int getAttributes()
{
  return attributes;
}
