//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Implementation File
// Written By: Eric Den Haan and Blake Nelson
// Inspired By: https://gist.github.com/ducngtuan/4332979
//************************************************************************************

#include "./symbolTable.h"
#include <string>
#include <array>

using namespace std;

// Constructors
SymbolTable::SymbolTable()
{
  table = vector<Token>(TABLE_SIZE);
  occupiedCells = 0;
}

// Destructor
SymbolTable::~SymbolTable()
{
}

// init Method
// Initialize the Symbol Table with all reserved words
// Fill remaining space with NONAME Empty Token
void SymbolTable::init()
{
  string reservedWords[17] =
      {
          "BEGIN",
          "END",
          "CONST",
          "ARRAY",
          "INTEGER",
          "BOOLEAN",
          "PROC",
          "SKIP",
          "READ",
          "WRITE",
          "CALL",
          "IF",
          "FI",
          "DO",
          "OD",
          "FALSE",
          "TRUE",
      };
  for (unsigned int i = 0; i < table.size(); i++)
  {
    table[i] = Token();
  }
  for (unsigned int i = BEGIN; i < TRUE; i++)
  {
    Attribute a = Attribute(-1, reservedWords[i - BEGIN]);
    Token t = Token(static_cast<Symbol>(i), a);
    (void)insert(t);
  }
}

// search Method
// Given a lexeme, return the position in the table
// Or, if not found, return -1
int SymbolTable::search(const string &lexeme)
{
  int index = findIndex(lexeme);
  if (index != -1)
  {
    if (table[index].getSname() != NONAME)
    {
      return index;
    }
  }
  return -1;
}

// insert Method
// Given a lexeme, create the appropriate Token and insert into Symbol Table
// If the lexeme already exists, return the position in the table
int SymbolTable::insert(const Token &t)
{
  Token temp(t);
  int location = search(temp.getSval().getLexeme());

  if (location != -1)
  {
    return location;
  }
  if (occupiedCells < TABLE_SIZE)
  {
    // Insert the token in the Table
    table[location] = temp;

    // If the Attribute's value is -1, we must update it to the index in the Table
    // If it is not -1, then the Token is a NUM or similar type
    if (temp.getSval().getValue() == -1)
    {
      table[location].setSval(Attribute(location, temp.getSval().getLexeme()));
    }

    occupiedCells++;
  }
  // If the table is full, return -1 for now, possibly implement extendible hashing in future
  else
  {
    return -1;
  }
  return location;
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

// hash Method
// The hash function for the Symbol Table
int SymbolTable::hash(const string &lexeme)
{
  int value = 0;
  for (unsigned int i = 0; i < lexeme.length(); i++)
  {
    value = 37 * value + lexeme[i];
  }
  return value;
}

// findIndex Method
// Use the hash function to find the index of the new table entry
int SymbolTable::findIndex(const string &lexeme)
{
  int h = hash(lexeme) % TABLE_SIZE, offset = 0, index;

  while (offset < TABLE_SIZE)
  {
    index = (h + offset) % TABLE_SIZE;

    if (table[index].getSname() == NONAME || table[index].getSval().getLexeme() == lexeme)
    {
      return index;
    }

    offset++;
  }
  return -1;
}