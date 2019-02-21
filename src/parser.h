//************************************************************************************
// CPSC 4600
// PL Language Parser
// Parser Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "./administration.h"
#include "./token.h"

using namespace std;

typedef vector<Symbol> StopSet;

class Parser
{
public:
  // Constructors
  Parser(Administration &);

  // Public Methods
  int parse();

private:
  // Private Methods
  bool member(const Symbol &, const StopSet &);
  void match(const Symbol &, const StopSet &);
  void syntaxError(const StopSet &);
  void syntaxCheck(const StopSet &);
  void handleScanError(Token &);

  // Non-Terminal Parsing Functions
  void program(const StopSet &);
  void block(const StopSet &);

  // Data Members
  Token laToken;
  Administration &admin;
};

#endif