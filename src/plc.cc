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
  //If incorrect arguments are specified:
  if (argc != 2)
  {
    cout << "Please use the following format: " << argv[0] << " <input-file>" << endl;
  }

  //Open input and output files
  ifstream inputFile(argv[1]);
  if (!inputFile)
  {
    cerr << "Input file " << argv[1] << " could not be opened." << endl;
    return 1;
  }

  SymbolTable symbolTable;

  Scanner scanner(inputFile, symbolTable);
  Administration administration(inputFile, scanner);
  Parser parser(administration);
  int status = parser.parse();
  if (status == 0)
  {
    cout << "Parsing completed successfully." << endl;
  }
  else
  {
    cerr << "Compiler encountered " << administration.getErrorCount() << " error(s)" << endl;
  }


  // //-----------------Block Table Testing---------------------
  // BlockTable blockTable;
  //
  // cout << "table created. size is: " << blockTable.tableSize() << endl;
  // (void)blockTable.newBlock();
  // cout << "new block created. table size: " << blockTable.tableSize() << endl
  //      << endl;
  // cout << "Inserting (1, 1, 1, mKind::VARKIND, mType::INT)" << endl;
  // (void)blockTable.insert(1, 1, 1, mKind::VARKIND, mType::INT);
  // cout << "current block size: " << blockTable.blockSize() << endl
  //      << endl;
  // cout << "Inserting (2, 2, 1, mKind::VARKIND, mType::INT)" << endl;
  // (void)blockTable.insert(2, 2, 1, mKind::VARKIND, mType::INT);
  // cout << "current block size: " << blockTable.blockSize() << endl
  //      << endl;
  // cout << "Block Level: " << blockTable.currentBlockLevel() << endl
  //      << endl;
  //
  // cout << "--Block: --";
  // blockTable.printBlock();
  // cout << endl;
  //
  // //for testing searchBlock
  // bool tru, fals;
  // tru = blockTable.searchBlock(2);
  // cout << "true or false: " << tru << endl;
  // fals = blockTable.searchBlock(3);
  // cout << "true or false: " << fals << endl <<endl;
  //
  // //for testing searchTable
  // bool tru2, fals2;
  // tru2 = blockTable.searchTable(2, 1);
  // cout << "true or false: " << tru2 << endl;
  // fals2 = blockTable.searchTable(3, 0);
  // cout << "true or false: " << fals2 << endl <<endl;
  //
  // (void)blockTable.newBlock();
  // cout << "new block created. table size: " << blockTable.tableSize() << endl
  //      << endl;
  // cout << "Inserting (1, 1, 1, mKind::VARKIND, mType::INT)" << endl;
  // (void)blockTable.insert(1, 1, 1, mKind::VARKIND, mType::INT);
  // cout << "current block size: " << blockTable.blockSize() << endl
  //      << endl;
  // cout << "Block Level: " << blockTable.currentBlockLevel() << endl
  //      << endl;
  //
  // (void)blockTable.newBlock();
  // cout << "new block created. table size: " << blockTable.tableSize() << endl
  //      << endl;
  // cout << "Inserting (2, 2, 1, mKind::VARKIND, mType::INT)" << endl;
  // (void)blockTable.insert(2, 2, 1, mKind::VARKIND, mType::INT);
  // cout << "current block size: " << blockTable.blockSize() << endl
  //      << endl;
  // cout << "Block Level: " << blockTable.currentBlockLevel() << endl
  //      << endl;
  //
  // cout << "---Table: ---" ;
  // blockTable.printTable();
  // cout << endl << endl;
  //
  // (void)blockTable.endBlock();
  // cout << "block popped. table size: " << blockTable.tableSize() << endl
  //      << endl;
  // (void)blockTable.endBlock();
  // cout << "block popped. table size: " << blockTable.tableSize() << endl
  //      << endl;
  //
  // cout << "---Table: ---";
  // blockTable.printTable();
  // cout << endl << endl;

  return 0;
}
