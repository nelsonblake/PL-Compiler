#include "./blockTable.h"

BlockTable::BlockTable()
{
    table.empty();
    block.empty();
}

bool BlockTable::search(const int &index)
{
    for(auto i = block.begin(); i != block.end(); i++)
    {
      if(index == i->getIndex())
      {
        return true;
      }
    }
    return false;
}

bool BlockTable::insert(TableEntry &entry)
{
  for(auto i = block.begin(); i != block.end(); i++)
  {
    if(entry.getIndex() == i->getIndex())
    {
      return false; //already have this entry
    }
  }
  block.push_back(entry);
  return true;
}

TableEntry BlockTable::find(const int &index, const bool &error)
{
  TableEntry FUCK;
  return FUCK;
}

bool BlockTable::newBlock()
{
  return true;
}

bool BlockTable::endBlock()
{
  return true;
}

int BlockTable::currentDepth()
{
  return 0;
}
