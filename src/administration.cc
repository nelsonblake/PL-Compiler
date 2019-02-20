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
  if (eType == ErrorTypes::ScanError)
  {
    string errorType(s);
    Token temp(t);
    cout << "Scanner encountered an error at line " << currentLine << ": " << s << ": " << temp.getSval().getLexeme() << endl;
  }

  // Ignore the rest of the line
  inputFilePtr->ignore(256, '\n');
  currentLine++;
  errorCount++;
}

// int Administration::scan()
// {
//   while (!inputFilePtr->eof() && errorCount < MAX_ERRORS)
//   {
//     Token t = scanner.getToken();
//     if (t.getSname() == ID)
//     {
//       (void)scanner.getSymbolTablePtr()->insert(t);
//     }
//     else if (t.getSname() == NEWLINE)
//     {
//       currentLine++;
//     }
//     else if (t.getSname() == INVALID_CHAR)
//     {
//       error(ErrorTypes::ScanError, "Invalid character", t);
//     }
//     else if (t.getSname() == INVALID_ID)
//     {
//       error(ErrorTypes::ScanError, "Invalid identifier", t);
//     }
//     else if (t.getSname() == INVALID_NUM)
//     {
//       error(ErrorTypes::ScanError, "Invalid number", t);
//     }
//   }
//   if (errorCount == MAX_ERRORS)
//   {
//     cout << "Maximum error count reached (" << MAX_ERRORS << ") - Compiler is stopping." << endl;
//     return 1;
//   }
//   if (errorCount > 0)
//   {
//     return 1;
//   }
//   return 0;
// }
