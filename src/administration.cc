//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, Scanner &s) : scanner(s)
{
  inputFilePtr = &inputFile;
  currentLine = 1;
  errorCount = 0;
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

void Administration::error(const ErrorTypes &eType, const string &s, Token t)
{
  string errorType(s);
  Token temp(t);
  if (eType == ErrorTypes::ScanError)
  {
    cout << endl
         << "Scanner encountered an error at line " << currentLine << ": " << s << ": " << temp.getSval().getLexeme() << endl
         << endl;
  }

  else if (eType == ErrorTypes::ParseError)
  {
    cout << endl
         << "Syntax error from parser at line " << currentLine << endl
         << endl;
  }
  else if (eType == ErrorTypes::ScopeError)
  {
    cout << endl
         << "Scope error at line " << currentLine << ": " + s + " " << endl
         << endl;
  }
  else if (eType == ErrorTypes::TypeError)
  {
    cout << endl
         << "Type error at line " << currentLine << ": " + s + " " << endl
         << endl;
  }

  errorCount++;
}

void Administration::fatal(const string &s)
{
  cout << s << endl;
  exit(1);
}
