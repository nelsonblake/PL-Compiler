#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include "./mKind.h"
#include "./mType.h"

using namespace std;

#define MAXDEPTH 20;

class TableEntry
{
public:
  TableEntry();
  TableEntry(const int &, const int &, const int &, const int &, const mKind &, const mType &); //specified version for Arr and Const
  TableEntry(const int &, const int &, const mKind &, const mType &); //index + depth

  int getIndex();
  int getArrSize();
  int getConstVal();
  int getDepth();
  mKind getKind();
  mType getType();

private:

  int index; //symbolTable index
  int arrSize; //only used for arrays
  int constVal; //only used for const
  int depth;
  mKind kind;
  mType type;

};

#endif
