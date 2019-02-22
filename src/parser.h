//************************************************************************************
// CPSC 4600
// PL Language Parser
// Parser Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include <vector>
#include "./administration.h"
#include "./token.h"
#include "./firstSets.h"

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
  bool member(const Symbol &, StopSet);
  void match(const Symbol &, const StopSet &);
  void syntaxError(const StopSet &);
  void syntaxCheck(const StopSet &);
  void handleScanError(Token &);
  Token getValidToken();
  StopSet stsUnion(const StopSet &, const StopSet &);
  StopSet stsTerminal(const Symbol &);
  void printNT(const string &);

  // Non-Terminal Parsing Functions
  void program(const StopSet &);
  void block(const StopSet &);
  void definitionPart(const StopSet &);
  void definition(const StopSet &);
  void constantDefinition(const StopSet &);
  void variableDefinition(const StopSet &);
  void typeSymbol(const StopSet &);
  void variableList(const StopSet &);
  void procedureDefinition(const StopSet &);
  void statementPart(const StopSet &);
  void statement(const StopSet &);
  void emptyStatement(const StopSet &);
  void readStatement(const StopSet &);
  void variableAccessList(const StopSet &);
  void writeStatement(const StopSet &);
  void expressionList(const StopSet &);
  void assignmentStatement(const StopSet &);
  void procedureStatement(const StopSet &);
  void ifStatement(const StopSet &);
  void doStatement(const StopSet &);
  void guardedCommandList(const StopSet &);
  void guardedCommand(const StopSet &);
  void expression(const StopSet &);
  void primaryOperator(const StopSet &);
  void primaryExpression(const StopSet &);
  void relationalOperator(const StopSet &);
  void simpleExpression(const StopSet &);
  void addingOperator(const StopSet &);
  void term(const StopSet &);
  void multiplyingOperator(const StopSet &);
  void factor(const StopSet &);
  void variableAccess(const StopSet &);
  void indexedSelector(const StopSet &);
  void constant(const StopSet &);
  void booleanSymbol(const StopSet &);

  // Data Members
  Token laToken;
  Administration &admin;
};

#endif