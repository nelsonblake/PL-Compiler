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
  correctLine = true;
}

// Destructor
Administration::~Administration()
{
  //not sure how to destroy this scanner
  //scanner = nullptr;
  outputFilePtr = nullptr;
}

void Administration::newLine()
{
  //encounter a line error -- HOW DO WE KNOW WHEN IT'S WRONG?
  if(correctLine == false)
  {
    //report error
    //error("meaningful error message");
    errorCount++;
    if(errorCount == MAX_ERRORS)
    {
      cout << "maximum error count exceeded" << endl;
      exit(0);
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

}
