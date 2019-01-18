//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Implemenation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./symbolTable.h"

using namespace std;

// Constructors
SymbolTable::SymbolTable()
{
  table = vector<Token>(TABLE_SIZE);
}

// Destructor
SymbolTable::~SymbolTable()
{
}

// init Method
// Initialize the Symbol Table with all reserved words
void SymbolTable::init()
{
}

// search Method
// Given a lexeme, return the position in the table
// Or, if not found, return -1
int SymbolTable::search(const string &lexeme)
{
}

// insert Method
// Given a lexeme, create the appropriate Token and insert into Symbol Table
// If the lexeme already exists, return the position in the table
int SymbolTable::insert(const string &lexeme)
{
}

// isFull Method
// return true if Symbol Table is full, else false
bool SymbolTable::isFull()
{
  return occupiedCells == TABLE_SIZE;
}

// getOccupiedCells Method
int SymbolTable::getOccupiedCells()
{
  return occupiedCells;
}