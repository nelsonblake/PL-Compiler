//************************************************************************************
// CPSC 4600
// PL Language Parser
// First Sets for Parser
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef FIRSTSETS_H
//************************************************************************************
// CPSC 4600
// PL Language Compiler
// First Sets of PL Grammar
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#define FIRSTSETS_H

#include <vector>
#include "./token.h"

using namespace std;

typedef vector<Symbol> StopSet;

static const StopSet firstBooleanSymbol = {Symbol::FALSE, Symbol::TRUE};
static const StopSet firstConstant = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID};
static const StopSet firstIndexedSelector = {Symbol::OPEN_SQUARE_BRACKET};
static const StopSet firstVariableAccess = {Symbol::ID};
static const StopSet firstFactor = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstMultiplyingOperator = {Symbol::MULTIPLICATION_OPERATOR, Symbol::MODULUS_OPERATOR, Symbol::DIVISION_OPERATOR};
static const StopSet firstTerm = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstAddingOperator = {Symbol::ADDITION_OPERATOR, Symbol::SUBTRACTION_OPERATOR};
static const StopSet firstSimpleExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstRelationalOperator = {Symbol::LESS_THAN_OPERATOR, Symbol::EQUAL_OPERATOR, Symbol::GREATER_THAN_OPERATOR};
static const StopSet firstPrimaryExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstPrimaryOperator = {Symbol::AND_OPERATOR, Symbol::OR_OPERATOR};
static const StopSet firstExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstGuardedCommand = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstGuardedCommandList = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstDoStatement = {Symbol::DO};
static const StopSet firstIfStatement = {Symbol::IF};
static const StopSet firstProcedureStatement = {Symbol::CALL};
static const StopSet firstAssignmentStatement = {Symbol::ID};
static const StopSet firstExpressionList = {Symbol::SUBTRACTION_OPERATOR, Symbol::NUM, Symbol::BOOLEAN, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
static const StopSet firstWriteStatement = {Symbol::WRITE};
static const StopSet firstVariableAccessList = {Symbol::ID};
static const StopSet firstReadStatement = {Symbol::READ};
static const StopSet firstEmptyStatement = {Symbol::SKIP};
static const StopSet firstStatement = {Symbol::SKIP, Symbol::READ, Symbol::WRITE, Symbol::ID, Symbol::CALL, Symbol::IF, Symbol::DO};
static const StopSet firstStatementPart = {Symbol::SKIP, Symbol::READ, Symbol::WRITE, Symbol::ID, Symbol::CALL, Symbol::IF, Symbol::DO, Symbol::EPSILON};
static const StopSet firstProcedureDefinition = {Symbol::PROC};
static const StopSet firstVariableList = {Symbol::ID};
static const StopSet firstTypeSymbol = {Symbol::INTEGER, Symbol::BOOLEAN};
static const StopSet firstVariableDefinition = {Symbol::INTEGER, Symbol::BOOLEAN};
static const StopSet firstArrayOrVariableListDefinition = {Symbol::ID, Symbol::ARRAY};
static const StopSet firstConstantDefinition = {Symbol::CONST};
static const StopSet firstDefinition = {Symbol::CONST, Symbol::INTEGER, Symbol::BOOLEAN, Symbol::PROC};
static const StopSet firstDefinitionPart = {Symbol::CONST, Symbol::INTEGER, Symbol::BOOLEAN, Symbol::PROC, Symbol::EPSILON};
static const StopSet firstBlock = {Symbol::BEGIN};
static const StopSet firstProgram = {Symbol::BEGIN};

#endif