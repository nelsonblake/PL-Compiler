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
#include "./blockTable.h"

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
  int matchName(const Symbol &, const StopSet &);
  void syntaxError(const StopSet &);
  void syntaxCheck(const StopSet &);
  Token getValidToken();
  StopSet stsUnion(const StopSet &, const StopSet &);
  StopSet stsTerminal(const Symbol &);
  void printNT(const string &);
  void printSts(const StopSet &);

  // Non-Terminal Parsing Functions
  void program(const StopSet &);
  void block(const StopSet &);
  void definitionPart(const StopSet &);
  void definition(const StopSet &);
  void constantDefinition(const StopSet &);
  void variableDefinition(const StopSet &);
  void arrayOrVariableListDefinition(const StopSet &, const mType &);
  mType typeSymbol(const StopSet &);
  vector<int> variableList(const StopSet &);
  void procedureDefinition(const StopSet &);
  void statementPart(const StopSet &);
  void statement(const StopSet &);
  void emptyStatement(const StopSet &);
  void readStatement(const StopSet &);
  vector<mType> variableAccessList(const StopSet &);
  void writeStatement(const StopSet &);
  vector<mType> expressionList(const StopSet &);
  void assignmentStatement(const StopSet &);
  void procedureStatement(const StopSet &);
  void ifStatement(const StopSet &);
  void doStatement(const StopSet &);
  void guardedCommandList(const StopSet &);
  void guardedCommand(const StopSet &);
  mType expression(const StopSet &);
  void primaryOperator(const StopSet &);
  mType primaryExpression(const StopSet &);
  void relationalOperator(const StopSet &);
  mType simpleExpression(const StopSet &);
  void addingOperator(const StopSet &);
  mType term(const StopSet &);
  void multiplyingOperator(const StopSet &);
  mType factor(const StopSet &);
  mType variableAccess(const StopSet &);
  mType indexedSelector(const StopSet &);
  void constant(const StopSet &, int &, mType &);
  int booleanSymbol(const StopSet &);

  // Data Members
  Token laToken;
  Administration &admin;
  BlockTable table;
};

#endif
