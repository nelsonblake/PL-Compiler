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

class Parser
{
public:
  // Constructors
  Parser(Administration &);

  // Public Methods
  int parse();

private:
  // Private Methods
  bool member(const Symbol &, const vector<Symbol> &);
  void match(const Symbol &, const vector<Symbol> &);
  void syntaxError(const vector<Symbol> &);
  void syntaxCheck(const vector<Symbol> &);
  void handleScanError(Token &);

  // Data Members
  Token laToken;
  Administration &admin;
};

#endif