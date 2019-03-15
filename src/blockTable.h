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

const int MAXBLOCK = 15;

class BlockTable
{
public:
  // Constructors
  BlockTable(); //initialize empty blockTable;

  // Public Methods
  bool search(const int &index);                                                                                //check if index is in current Block
  bool insert(const int &index, const int &arrSize, const int &constVal, const mKind &kind, const mType &type); //insert an entry into table, return true if index does not exist
  bool find(const int &index, const bool &error);
  bool newBlock();
  void endBlock();
  int currentBlockLevel();
  void printBlock();
  void printTable();
  int tableSize();
  int blockSize();

private:
  // Data Members
  vector<vector<TableEntry>> table; //a stack but easier to access
  int blockLevel;
};

#endif
