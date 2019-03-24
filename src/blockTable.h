//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef BLOCKTABLE_H
#define BLOCKTABLE_H

#include <vector>
#include <stack>
#include <iostream>
#include "./tableEntry.h"

using namespace std;

const int MAXBLOCK = 20;

class BlockTable
{
public:
  // Constructors
  BlockTable();

  // Public Methods
  bool searchBlock(const int &);
  TableEntry searchTable(const int &);
  bool insert(const int &, const int &, const int &, const mKind &, const mType &);
  int getConstantValue(const int &);
  bool newBlock();
  void endBlock();
  int currentBlockLevel();
  void printBlock();
  void printTable();
  int tableSize();
  int blockSize();

private:
  // Private Data Members
  vector<vector<TableEntry>> table;
  int blockLevel;
};

#endif
