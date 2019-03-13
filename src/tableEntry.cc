#include "./tableEntry.h"

TableEntry::TableEntry()
{
  index = 0;
  arrSize = 0;
  constVal = 0;
  depth = 0;
  kind = VAR;
  type = UNIV;
}

TableEntry::TableEntry(const int &i, const int &a, const int &c, const int &d, const mKind &k, const mType &t)
{
  index = i;
  arrSize = a;
  constVal = c;
  depth = d;
  kind = k;
  type = t;
}

TableEntry::TableEntry(const int &i, const int &d, const mKind &k, const mType &t)
{
  index = i;
  depth = d;
  kind = k;
  type = t;
}

int TableEntry::getIndex()
{
  return index;
}

int TableEntry::getArrSize()
{
  return arrSize;
}

int TableEntry::getConstVal()
{
  return constVal;
}

int TableEntry::getDepth()
{
  return depth;
}

mKind TableEntry::getKind()
{
  return kind;
}

mType TableEntry::getType()
{
  return type;
}
