//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Entry Interface File
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
//************************************************************************************

#ifndef SYMBOLTABLEENTRY_H
#define SYMBOLTABLEENTRY_H

#include "./token.h"

using namespace std;

class SymbolTableEntry
{
public:
  // Constructors
  SymbolTableEntry(const int &, const Token &);

  // Public Methods
  int getKey();
  Token getToken();

private:
  // Data Members
  int key;
  Token token;
};

#endif
