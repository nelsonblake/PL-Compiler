//************************************************************************************
// CPSC 4600
// PL Language Parser
// First Sets for Parser
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include <vector>
#include "./token.h"

using namespace std;

typedef vector<Symbol> StopSet;

StopSet firstBooleanSymbol = {Symbol::FALSE, Symbol::TRUE};
StopSet firstConstant = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID};
StopSet firstIndexedSelector = {Symbol::OPEN_SQUARE_BRACKET};
StopSet firstVariableAccess = {Symbol::ID};
StopSet firstFactor = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
StopSet firstMultiplyingOperator = {Symbol::MULTIPLICATION_OPERATOR, Symbol::MODULUS_OPERATOR, Symbol::DIVISION_OPERATOR};
StopSet firstTerm = {Symbol::NUM, Symbol::FALSE, Symbol::TRUE, Symbol::ID, Symbol::OPEN_PARENTHESIS, Symbol::NOT_OPERATOR};
StopSet firstAddingOperator = {Symbol::ADDITION_OPERATOR, Symbol::SUBTRACTION_OPERATOR};
StopSet firstSimpleExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstRelationalOperator = {Symbol::LESS_THAN_OPERATOR, Symbol::EQUAL_OPERATOR, Symbol::GREATER_THAN_OPERATOR};
StopSet firstPrimaryExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstPrimaryOperator = {Symbol::AND_OPERATOR, Symbol::OR_OPERATOR};
StopSet firstExpression = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstGuardedCommand = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstGuardedCommandList = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstDoStatement = {Symbol::DO};
StopSet firstIfStatement = {Symbol::IF};
StopSet firstProcedureStatement = {Symbol::CALL};
StopSet firstAssignmentStatement = {Symbol::ID};
StopSet firstExpressionList = {Symbol::SUBTRACTION_OPERATOR, Symbol::EPSILON};
StopSet firstWriteStatement = {Symbol::WRITE};
StopSet firstVariableAccessList = {Symbol::ID};
StopSet firstReadStatement = {Symbol::READ};
StopSet firstEmptyStatement = {Symbol::SKIP};
StopSet firstStatement = {Symbol::SKIP, Symbol::READ, Symbol::WRITE, Symbol::ID, Symbol::CALL, Symbol::IF, Symbol::DO};
StopSet firstStatementPart = {Symbol::SKIP, Symbol::READ, Symbol::WRITE, Symbol::ID, Symbol::CALL, Symbol::IF, Symbol::DO, Symbol::EPSILON};
StopSet firstProcedureDefinition = {Symbol::PROC};
StopSet firstVariableList = {Symbol::ID};
StopSet firstTypeSymbol = {Symbol::INTEGER, Symbol::BOOLEAN};
StopSet firstVariableDefinition = {Symbol::INTEGER, Symbol::BOOLEAN};
StopSet firstConstantDefinition = {Symbol::CONST};
StopSet firstDefinition = {Symbol::CONST, Symbol::INTEGER, Symbol::BOOLEAN, Symbol::PROC};
StopSet firstDefinitionPart = {Symbol::CONST, Symbol::INTEGER, Symbol::BOOLEAN, Symbol::PROC, Symbol::EPSILON};
StopSet firstBlock = {Symbol::BEGIN};
StopSet firstProgram = {Symbol::BEGIN};