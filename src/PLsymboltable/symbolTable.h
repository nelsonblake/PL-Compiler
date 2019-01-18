//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Interface File
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
//************************************************************************************

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "./token.h"
#include "./symbolTableEntry.h"

using namespace std;

const int TABLE_SIZE = 997;

class SymbolTable
{
public:
  // Constructors
  SymbolTable();

  // Destructor
  ~SymbolTable();

  // Public Methods
  Token get(const int &);
  void put(const int &, const Token &);

private:
  // Data Members
  SymbolTableEntry **table;
};

#endif
