//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Table Entry Interface File
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
  TableEntry(const int &, const int &, const int &, const int &, const mKind &, const mType &); //specified version for Arr and Const
  TableEntry(const int &, const int &, const mKind &, const mType &);                           //index + depth

  // Public Methods
  int getIndex();
  int getArrSize();
  int getConstVal();
  int getDepth();
  mKind getKind();
  mType getType();
  void printEntry();

private:
  // Data members
  int index;    //symbolTable index
  int arrSize;  //only used for arrays
  int constVal; //only used for const
  int depth;
  mKind kind;
  mType type;
};

#endif
