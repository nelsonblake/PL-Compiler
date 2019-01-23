//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Administration Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <string>
#include <iostream>
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

  // Public Methods
  void newLine();
  void error(const string &);
  int scan();

private:
  // Data Members
  ofstream outputFile;
  Scanner scanner;
  int currentLine;
  bool correctLine;
  int errorCount;
};

#endif
