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
  Parser();

  // Public Methods
  void match(const Symbol &, const vector<Symbol> &);
  void syntaxError(const vector<Symbol> &);
  void syntaxCheck(const vector<Symbol> &);

private:
  // Private Methods
  bool member(const Symbol &, const vector<Symbol> &);

  // Data Members
  Token lookAhead;
  Administration &admin;
};

#endif;