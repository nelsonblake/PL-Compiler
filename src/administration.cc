//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, ofstream &outputFile, Scanner &s) : scanner(s)
{
  inputFilePtr = &inputFile;
  outputFilePtr = &outputFile;
  currentLine = 0;
  errorCount = 0;
  correctLine = true;
}

// Destructor
Administration::~Administration()
{
  outputFilePtr = nullptr;
}

void Administration::newLine()
{
  if (correctLine == false)
  {
    errorCount++;
    if (errorCount == MAX_ERRORS)
    {
      cerr << "Maximum error count exceeded -- stopping scanner." << endl;
      exit(-1);
    }
    currentLine++;
  }
  correctLine = true;
}

void Administration::error(const string &s)
{
  cout << currentLine << " " << s << endl;
}

int Administration::scan()
{
  while (!inputFilePtr->eof())
  {
    Token t = scanner.getToken();
    if (t.getSname() != NONAME)
    {
      (void)scanner.getSymbolTablePtr()->insert(t);
    }
  }

  return 0;
}
