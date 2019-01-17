//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Interface File
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
//************************************************************************************

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include './attribute.h'
#include './symbolTableEntry.h'

using namespace std;

const int TABLE_SIZE = 997;

class SymbolTable
{
public:
  // Constructors
  SymbolTable();

  // Public Methods
  int get(const int&);
  void put(const int&, const Attribute&);

private:
  // Data Members
  **SymbolTableEntry table;
};

#endif
