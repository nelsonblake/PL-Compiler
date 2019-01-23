//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Scanner Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./scanner.h"

// Constructors
Scanner::Scanner(ifstream &inputFile, SymbolTable &table)
{
  inputFilePtr = &inputFile;
  symbolTablePtr = &table;
}

// Destructor
Scanner::~Scanner()
{
  inputFilePtr = nullptr;
  symbolTablePtr = nullptr;
}