#ifndef BLOCKTABLE_H
#define BLOCKTABLE_H

#include <vector>
#include <stack>
#include <iostream>
#include "./tableEntry.h"

using namespace std;

class BlockTable
{
public:
  BlockTable(); //initialize empty blockTable;

  bool search(const int &index); //check if index is in current Block
  bool insert(TableEntry &entry); //isert an entry into table, return true if index does not exist
  TableEntry find(const int &index, const bool &error);
  bool newBlock();
  bool endBlock();
  int currentDepth();

private:
  stack<vector<TableEntry>> table;
  vector<TableEntry> block;
  int depth;
};

#endif
