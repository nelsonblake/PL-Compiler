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
  if (argc != 2)
  {
    cout << "Please use the following format: " << argv[0] << " <input-file>" << endl;
  }

  // Open input and output files
  ifstream inputFile(argv[1]);
  if (!inputFile)
  {
    cerr << "Input file " << argv[1] << " could not be opened." << endl;
    return 1;
  }
  //
  // SymbolTable table;
  //
  // Scanner scanner(inputFile, table);
  // Administration administration(inputFile, scanner);
  // Parser parser(administration);
  // int status = parser.parse();
  // if (status == 0)
  // {
  //   cout << "Parsing completed successfully." << endl;
  // }
  // else
  // {
  //   cerr << "Compiler encountered " << administration.getErrorCount() << " error(s)" << endl;
  // }

  BlockTable table;
  bool woah;
  woah = table.newBlock();

  cout << "table size: " << table.tableSize() << endl;

  woah = table.insert(1, 1, 1, mKind::VARKIND, mType::INT);
  woah = table.insert(1, 1, 1, mKind::VARKIND, mType::INT);
  woah = table.insert(2, 2, 1, mKind::VARKIND, mType::INT);


  cout << "current block size: " << table.blockSize() << endl;


  return 0;
}
