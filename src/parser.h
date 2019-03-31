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

#define MAXLABELCOUNT 256

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
  void block(const StopSet &, const int &, const int &);
  int definitionPart(const StopSet &);
  int definition(const StopSet &, int &);
  void constantDefinition(const StopSet &);
  int variableDefinition(const StopSet &, int &);
  int arrayOrVariableListDefinition(const StopSet &, const mType &, int &);
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
  void guardedCommandList(const StopSet &, int &, const int &);
  void guardedCommand(const StopSet &, int &, const int &);
  mType expression(const StopSet &);
  Symbol primaryOperator(const StopSet &);
  mType primaryExpression(const StopSet &);
  Symbol relationalOperator(const StopSet &);
  mType simpleExpression(const StopSet &);
  Symbol addingOperator(const StopSet &);
  mType term(const StopSet &);
  Symbol multiplyingOperator(const StopSet &);
  mType factor(const StopSet &);
  mType variableAccess(const StopSet &);
  mType indexedSelector(const StopSet &);
  void constant(const StopSet &, int &, mType &);
  int booleanSymbol(const StopSet &);
  int newLabel();

  // Data Members
  Token laToken;
  Administration &admin;
  BlockTable table;
  int currentLabel;
};

#endif
