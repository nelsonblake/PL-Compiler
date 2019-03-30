//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Entry Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./tableEntry.h"

// Constructors
TableEntry::TableEntry()
{
  index = -1;
  arrSize = 0;
  constVal = 0;
  depth = 0;
  kind = VARKIND;
  type = UNIV;
  displacement = 0;
  startLabel = 0;
}

TableEntry::TableEntry(const int &i, const int &a, const int &c, const int &d, const int &disp, const int &sL, const mKind &k, const mType &t)
{
  index = i;
  arrSize = a;
  constVal = c;
  depth = d;
  kind = k;
  type = t;
  displacement = disp;
  startLabel = sL;
}

// Public Methods
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

int TableEntry::getDisplacement()
{
  return displacement;
}

int TableEntry::getStartLabel()
{
  return startLabel;
}

void TableEntry::setDisplacement(const int &d)
{
  displacement = d;
}

void TableEntry::setStartLabel(const int &s)
{
  startLabel = s;
}

void TableEntry::printEntry()
{
  cout << "Index: " << index << endl
       << "Array Size: " << arrSize << endl
       << "Constant Value: " << constVal << endl
       << "Block level: " << depth << endl
       << "Kind: " << kind << endl
       << "Type: " << type << endl
       << "Displacement: " << displacement << endl
       << "Start Label: " << startLabel << endl
       << endl;
}
