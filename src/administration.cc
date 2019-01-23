//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, ofstream &outputFile, Scanner &s)
{
  scanner = &s;
  outputFilePtr = &outputFile;
  currentLine = 0;
  errorCount = 0;
}

// Destructor
Administration::~Administration()
{
  scanner = nullptr;
  outputFilePtr = nullptr;
}