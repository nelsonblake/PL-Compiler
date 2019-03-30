//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Driver Program
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include <iostream>
#include <fstream>
#include "./administration.h"
#include "./parser.h"

int main(int argc, char *argv[])
{
  // If incorrect arguments are specified:
  if (argc != 3)
  {
    cout << "Please use the following format: " << argv[0] << " <input-file> <output-file>" << endl;
  }

  // Open input and output files
  ifstream inputFile(argv[1]);
  if (!inputFile)
  {
    cerr << "Input file " << argv[1] << " could not be opened." << endl;
    return 1;
  }

  ofstream outputFile(argv[2]);
  if (!outputFile)
  {
    cerr << "Output file" << argv[2] << " could not be opened." << endl;
    return 1;
  }

  SymbolTable symbolTable;

  Scanner scanner(inputFile, symbolTable);
  Administration administration(inputFile, outputFile, scanner);
  Parser parser(administration);
  int status = parser.parse();
  if (status == 0)
  {
    cout << "Scanning, parsing, and type/scope checking successfully completed" << endl;
  }
  else
  {
    cerr << "Compiler encountered " << administration.getErrorCount() << " error(s)" << endl;
    cout << endl
         << "Note: scanning and parsing errors are muted for clarity," << endl;
    cout << "although they will still show in the error count" << endl;
  }

  return 0;
}
