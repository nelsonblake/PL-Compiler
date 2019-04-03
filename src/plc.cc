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
#include "./assembler.h"
#include "./interp.h"

int main(int argc, char *argv[])
{
  // If incorrect arguments are specified:
  if (argc < 3 || argc > 4)
  {
    cout << "Please use the following format: " << argv[0] << " <input-file> <output-file> <-s>" << endl;
    cout << "Add option -s for stepping" << endl;
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
  ifstream assemblerInputFile(argv[2]);
  ofstream assemblerOutputFile("../test-output/assemblyCode.txt");
  Assembler assembler(assemblerInputFile, assemblerOutputFile);

  // Carry out the first pass
  assembler.firstPass();

  // We must close the file after the first pass and re-open it to do the second pass
  assemblerInputFile.close();
  assemblerInputFile.open(argv[2]);
  assembler.secondPass();

  // Run the compiled program
  if (argc == 4 && string(argv[3]) == "-s")
  {
    Interpreter interpreter("../test-output/assemblyCode.txt", true);
  }
  else
  {
    Interpreter interpreter("../test-output/assemblyCode.txt", false);
  }

  return 0;
}
