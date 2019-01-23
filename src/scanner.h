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
#include "./token.h"
#include "./symbolTable.h"

using namespace std;

class Scanner
{
public:
  // Constructors
  Scanner();
  Scanner(ifstream &inputStream, SymbolTable &symbolTable);

  // Public Methods
  Token getToken();

private:
  // Data Members
  ifstream inputFile;
  SymbolTable symbolTable;
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
