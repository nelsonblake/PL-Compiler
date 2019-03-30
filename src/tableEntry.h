//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Block Table Entry Interface File
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
  TableEntry(const int &, const int &, const int &, const int &, const int &, const int &, const mKind &, const mType &);

  // Public Methods
  int getIndex();
  int getArrSize();
  int getConstVal();
  int getDepth();
  mKind getKind();
  mType getType();
  int getDisplacement();
  int getStartLabel();
  void setDisplacement(const int &);
  void setStartLabel(const int &);
  void printEntry();

private:
  // Private Data Members
  int displacement;
  int startLabel;
  int index;
  int arrSize;
  int constVal;
  int depth;
  mKind kind;
  mType type;
};

#endif
