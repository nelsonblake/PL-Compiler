//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include "./mKind.h"
#include "./mType.h"
#include <iostream>

using namespace std;

const int MAXDEPTH = 20;

class TableEntry
{
public:
  // Constructors
  TableEntry();
  TableEntry(const int &, const int &, const int &, const int &, const mKind &, const mType &);
  TableEntry(const int &, const int &, const mKind &, const mType &);

  // Public Methods
  int getIndex();
  int getArrSize();
  int getConstVal();
  int getDepth();
  mKind getKind();
  mType getType();
  void printEntry();

private:
  // Private Data Members
  int index;
  int arrSize;
  int constVal;
  int depth;
  mKind kind;
  mType type;
};

#endif
