//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Driver Program
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************
#include "./symbolTable.h"

int main()
{
  SymbolTable s = SymbolTable();
  s.init();
  s.printTable();

  return 0;
}