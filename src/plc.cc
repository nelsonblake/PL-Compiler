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
#include "./Assembler.h"
#include "./interp.h"

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
    cout << endl;
    return 0;
  }

  // Run the assembler
  //ifstream assemblerInputFile("../test-output/docsExample.txt");
  ifstream assemblerInputFile(argv[2]);
  ofstream assemblerOutputFile("../test-output/assemblyCode.txt");
  Assembler assembler(assemblerInputFile, assemblerOutputFile);
  assembler.firstPass();
  assembler.secondPass();

  // Run the compiled program
  //Interpreter interpreter("../test-output/executableExample.txt", false);
  Interpreter interpreter("../test-output/assemblyCode.txt", false);
  return 0;
}
