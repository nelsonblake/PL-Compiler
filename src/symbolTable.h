//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <vector>
#include <iostream>
#include "./token.h"

using namespace std;

const int TABLE_SIZE = 307;

class SymbolTable
{
public:
  // Constructors
  SymbolTable();

  // Destructor
  ~SymbolTable();

  // Public Methods
  void init();
  int search(const string &);
  int insert(const Token &);
  bool isFull();
  int getOccupiedCells();
  void printTable();

private:
  // Data Members
  vector<Token> table;
  int occupiedCells;

  // Private Methods
  int hash(const string &);
  int findIndex(const string &);
};

#endif
