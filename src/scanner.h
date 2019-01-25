//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Scanner Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include "./token.h"
#include "./symbolTable.h"

using namespace std;

class Scanner
{
public:
  // Constructors
  Scanner(ifstream &, SymbolTable &);

  // Assignment operator
  Scanner operator=(const Scanner &);

  // Destructor
  ~Scanner();

  // Public Methods
  Token getToken();
  SymbolTable *getSymbolTablePtr();

private:
  // Data Members
  ifstream *inputFilePtr;
  SymbolTable *symbolTablePtr;
  char nextChar;

  // Private Methods
  bool isWhitespace(const char &);
  bool isAlpha(const char &);
  bool isDigit(const char &);
  bool isSpecial(const char &);
  Token recognizeId();
  Token recognizeSpecial();
  Token recognizeDigit();
  Token recognizeComment();
};

#endif
