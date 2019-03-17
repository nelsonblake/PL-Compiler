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
  BlockTable(); //initialize empty blockTable;

  bool searchBlock(const int &);
  TableEntry searchTable(const int &);                                              //check if index is in current Block
  bool insert(const int &, const int &, const int &, const mKind &, const mType &); //insert an entry into table, return true if index does not exist
  int getConstantValue(const int &);
  bool newBlock();
  void endBlock();
  int currentBlockLevel();
  void printBlock();
  void printTable();
  int tableSize();
  int blockSize();

private:
  vector<vector<TableEntry>> table; //a stack but easier to access
  int blockLevel;
};

#endif
