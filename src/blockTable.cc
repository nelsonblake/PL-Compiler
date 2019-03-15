//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./blockTable.h"

BlockTable::BlockTable()
{
  table.clear();
  blockLevel = 0;
}

bool BlockTable::search(const int &index)
{
  for (auto i = table.back().begin(); i != table.back().end(); i++)
  {
    if (index == i->getIndex())
    {
      return true;
    }
  }
  return false;
}

bool BlockTable::insert(const int &index, const int &arrSize, const int &constVal, const mKind &kind, const mType &type)
{
  bool found = false;
  if (table.back().empty())
  {
    cout << "empty block" << endl;
    TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, kind, type);
    table.back().push_back(entry);
    found = true;
  }
  else
  {
    for (unsigned int i = 0; i != table.back().size(); i++)
    {
      if (index == table.back()[i].getIndex())
      {
        cout << "Previously defined ID" << endl; //already have this entry
        break;
      }
      else
      {
        cout << "valid entry" << endl;
        TableEntry entry = TableEntry(index, arrSize, constVal, blockLevel, kind, type);
        table.back().push_back(entry);
        found = true;
      }
    }
  }
  return found;
}

bool BlockTable::find(const int &index, const bool &error)
{
  bool found = false;
  for (unsigned int i = 0; i != table.size(); i++)
  {
    for (unsigned int j = 0; j != table[i].size(); j++)
    {
      if (index == table[i][j].getIndex())
      {
        //return *j;
        found = true;
        break;
      }
    }
  }
  return found;
}

bool BlockTable::newBlock()
{
  if (table.size() >= MAXBLOCK)
  {
    return false;
  }
  else
  {
    blockLevel++;
    vector<TableEntry> vec;
    vec.clear();
    table.push_back(vec);
    return true;
  }
}

void BlockTable::endBlock()
{
  table.pop_back();
  blockLevel--;
}

int BlockTable::currentBlockLevel()
{
  return blockLevel;
}

void BlockTable::printBlock()
{
  for (unsigned int i = 0; i < table.back().size(); i++)
  {
    table.back()[i].printEntry();
  }
}

void BlockTable::printTable()
{
  for (unsigned int i = 0; i < table.size(); i++)
  {
    for (unsigned int j = 0; j < table[i].size(); j++)
    {
      table[i][j].printEntry();
    }
  }
}

int BlockTable::tableSize()
{
  return table.size();
}

int BlockTable::blockSize()
{
  return table.back().size();
}
