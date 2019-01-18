//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Symbol Table Implemenation File
// Written By: Eric Den Haan and Blake Nelson
// Inspired by: http://www.algolist.net/Data_structures/Hash_table/Simple_example
//************************************************************************************

#include "./symbolTable.h"

using namespace std;

// Constructors
SymbolTable::SymbolTable()
{
  table = new SymbolTableEntry *[TABLE_SIZE];

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    table[i] = NULL;
  }
}

// Destructor
SymbolTable::~SymbolTable()
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if (table[i] != NULL)
    {
      delete table[i];
    }
  }
  delete[] table;
}

// Get Method
// Given a key, return the token in the hashtable
Token SymbolTable::get(const int &key)
{
  int hash = (key % TABLE_SIZE);
  while (table[hash] != NULL && table[hash]->getKey() != key)
  {
    hash = (hash + 1) % TABLE_SIZE;
  }
  if (table[hash] == NULL)
  {
    return Token();
  }
  else
  {
    return table[hash]->getToken();
  }
}

// Put method
// Insert a Token into the Symbol Table
void SymbolTable::put(const int &key, const Token &token)
{
  int hash = (key % TABLE_SIZE);
  while (table[hash] != NULL && table[hash]->getKey() != key)
  {
    hash = (hash + 1) % TABLE_SIZE;
  }
  if (table[hash] != NULL)
  {
    delete table[hash];
  }
  table[hash] = new SymbolTableEntry(key, token);
}
