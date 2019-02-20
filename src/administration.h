//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Administration Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./scanner.h"

#define MAX_ERRORS 10

enum ErrorTypes
{
  ScanError,
  ParseError,
  ScopeError,
  TypeError
};

using namespace std;

class Administration
{
public:
  // Constructors
  Administration(ifstream &, ofstream &, Scanner &);

  // Destructor
  ~Administration();

  // Public Methods
  Scanner getScanner();
  ifstream *getInputFilePtr();
  int getCurrentLine();
  int getErrorCount();
  void incrementCurrentLine();
  void error(const ErrorTypes &, const string &, const Token &);

private:
  // Data Members
  ifstream *inputFilePtr;
  ofstream *outputFilePtr;
  Scanner &scanner;
  int currentLine;
  int errorCount;
};

#endif
