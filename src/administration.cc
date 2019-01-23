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
  //open the files
  inputFile.open("./data.txt");
  outputFile.open("./output.txt");
  currentLine = 0;
  errorCount = 0;
}

// Destructor
Administration::~Administration()
{
  scanner = nullptr;
  outputFilePtr = nullptr;
}

void Administration::newLine()
{
  //encounter a line error
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
  int indexOfToken = -1;
  string line;
  //Giving error on inputFile not being declared, but there is no ifstream data member
  //getline(inputFile, line, '\n');
  return indexOfToken;
}
