//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, ofstream &outputFile, Scanner &s) : scanner(s)
{
  inputFilePtr = &inputFile;
  outputFilePtr = &outputFile;
  currentLine = 1;
  errorCount = 0;
}

// Destructor
Administration::~Administration()
{
  outputFilePtr = nullptr;
}

// Public Methods
Scanner Administration::getScanner()
{
  return scanner;
}

ifstream *Administration::getInputFilePtr()
{
  return inputFilePtr;
}

int Administration::getCurrentLine()
{
  return currentLine;
}

int Administration::getErrorCount()
{
  return errorCount;
}

void Administration::incrementCurrentLine()
{
  currentLine++;
}

void Administration::error(const ErrorTypes &eType, const string &s, const Token &t)
{
  string errorType(s);
  Token temp(t);
  if (eType == ErrorTypes::ScanError)
  {
    cout << "Scanner encountered an error at line " << currentLine << ": " << s << ": " << temp.getSval().getLexeme() << endl;
  }

  else if (eType == ErrorTypes::ParseError)
  {
    cout << "Parser encountered an error at line " << currentLine << endl;
  }

  errorCount++;
}
