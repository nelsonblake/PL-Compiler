//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Driver Program
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include <iostream>
#include <fstream>
#include "./administration.h"

// int main()
// {
//   SymbolTable table = SymbolTable();
//   table.init();
//   table.printTable();
//
//   return 0;
// }

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
    cerr << "Input file " << argv[2] << " could not be opened." << endl;
    return 1;
  }

  ofstream outputFile(argv[2]);
  if (!outputFile)
  {
    cerr << "Output file" << argv[2] << " could not be opened." << endl;
    return 1;
  }
  SymbolTable table;
  Scanner scanner(inputFile, table);
  Administration compiler(inputFile, outputFile, scanner);
  int status = compiler.scan();
  if (status == 0)
  {
    cout << "Scanning completed successfully." << endl;
  }
  else
  {
    cerr << "Scanner encountered error(s)" << endl;
  }
  // table.printTable();

  return 0;
}
