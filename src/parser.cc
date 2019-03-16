//************************************************************************************
// CPSC 4600
// PL Language Parser
// Parser Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./parser.h"

// Constructors
Parser::Parser(Administration &a) : admin(a)
{
  laToken = getValidToken();
}

// Public Methods
int Parser::parse()
{
  StopSet initialSts = {Symbol::PERIOD};
  program(initialSts);

  if (admin.getErrorCount() > 0)
  {
    return 1;
  }
  return 0;
}

// Private Methods
Token Parser::getValidToken()
{
  Token t = admin.getScanner().getToken();

  while (t.getSname() == Symbol::NEWLINE || t.getSname() == Symbol::NONAME)
  {
    if (t.getSname() == Symbol::NEWLINE)
    {
      admin.incrementCurrentLine();
    }
    if (admin.getInputFilePtr()->eof())
    {
      return Token(Symbol::END_OF_INPUT, Attribute());
    }
    t = admin.getScanner().getToken();
  }
  if (t.getSname() == ID)
  {
    admin.getScanner().getSymbolTablePtr()->insert(t);
  }
  return t;
}

void Parser::syntaxError(const StopSet &sts)
{
  Symbol laSymbol = laToken.getSname();
  if (laSymbol == INVALID_CHAR)
  {
    admin.error(ErrorTypes::ScanError, "Invalid character", laToken);
  }
  else if (laSymbol == INVALID_ID)
  {
    admin.error(ErrorTypes::ScanError, "Invalid identifier", laToken);
  }
  else if (laSymbol == INVALID_NUM)
  {
    admin.error(ErrorTypes::ScanError, "Invalid number", laToken);
  }
  else
  {
    admin.error(ErrorTypes::ParseError, "", Token());
  }
  while (!member(laSymbol, sts))
  {
    laToken = admin.getScanner().getToken();
    laSymbol = laToken.getSname();
  }
}

void Parser::syntaxCheck(const StopSet &sts)
{
  Symbol laSymbol = laToken.getSname();
  if (laSymbol == Symbol::END_OF_INPUT)
  {
    return;
  }
  if (!member(laSymbol, sts))
  {
    syntaxError(sts);
  }
}

bool Parser::member(const Symbol &s, StopSet sts)
{
  StopSet::iterator it;
  it = find(sts.begin(), sts.end(), s);
  if (it != sts.end())
  {
    return true;
  }
  return false;
}

StopSet Parser::stsUnion(const StopSet &sts1, const StopSet &sts2)
{
  StopSet newSts;
  newSts.reserve(sts1.size() + sts2.size());
  newSts.insert(newSts.end(), sts1.begin(), sts1.end());
  newSts.insert(newSts.end(), sts2.begin(), sts2.end());
  return newSts;
}

StopSet Parser::stsTerminal(const Symbol &s)
{
  StopSet newSts;
  newSts.push_back(s);
  return newSts;
}

void Parser::printNT(const string &s)
{
  cout << "Parsing: " << s << endl;
}

void Parser::printSts(const StopSet &sts)
{
  for (auto i = sts.begin(); i != sts.end(); ++i)
  {
    cout << *i << ' ' << endl;
  }
  cout << endl;
}

void Parser::match(const Symbol &s, const StopSet &sts)
{
  string lexeme = laToken.getSval().getLexeme();
  int value = laToken.getSval().getValue();
  if (lexeme == "")
  {
    cout << "Matching Terminal: " << value << endl;
  }
  else
  {
    cout << "Matching Terminal: " << lexeme << endl;
  }

  Symbol laSymbol = laToken.getSname();
  if (laSymbol == s)
  {
    laToken = getValidToken();
  }
  else
  {
    syntaxError(sts);
  }
  syntaxCheck(sts);
}

void Parser::matchName(const Symbol &s, const StopSet &sts, int &index)
{
  index = admin.getScanner().getSymbolTablePtr()->search(laToken.getSval().getLexeme());
  cout << "Matching Terminal: " << laToken.getSval().getLexeme() << " at index: " << index << endl;

  Symbol laSymbol = laToken.getSname();
  if (laSymbol == s)
  {
    laToken = getValidToken();
  }
  else
  {
    syntaxError(sts);
  }
  syntaxCheck(sts);
}

// Non-Terminal Parsing Functions
void Parser::program(const StopSet &sts)
{
  printNT("Program");

  if(table.newBlock() == false)
    admin.fatal("Exceeded Block Limit");

  block(sts);

  table.endBlock();

  match(Symbol::PERIOD, sts);
}

void Parser::block(const StopSet &sts)
{
  printNT("Block");
  match(Symbol::BEGIN, stsUnion(stsUnion(stsUnion(sts, firstDefinitionPart), firstStatementPart), stsTerminal(Symbol::END)));
  definitionPart(stsUnion(stsUnion(sts, firstStatementPart), stsTerminal(Symbol::END)));
  statementPart(stsUnion(sts, stsTerminal(Symbol::END)));
  match(Symbol::END, sts);
}

void Parser::definitionPart(const StopSet &sts)
{
  printNT("Definition Part");
  syntaxCheck(stsUnion(sts, firstDefinition));
  while (member(laToken.getSname(), firstDefinition))
  {
    definition(stsUnion(stsTerminal(Symbol::SEMICOLON), sts));
    match(Symbol::SEMICOLON, stsUnion(firstDefinition, sts));
  }
}

void Parser::definition(const StopSet &sts)
{
  printNT("Definition");
  bool parseError = false;
  if (member(laToken.getSname(), firstConstantDefinition))
  {
    constantDefinition(sts);
  }
  else if (member(laToken.getSname(), firstVariableDefinition))
  {
    variableDefinition(sts);
  }
  else if (member(laToken.getSname(), firstProcedureDefinition))
  {
    procedureDefinition(sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsUnion(firstConstantDefinition, firstVariableDefinition), firstProcedureDefinition))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::constantDefinition(const StopSet &sts)
{
  int tempVal;
  int index;

  printNT("Constant Definition");
  match(Symbol::CONST, stsUnion(stsUnion(stsUnion(sts, stsTerminal(Symbol::ID)), stsTerminal(Symbol::EQUAL_OPERATOR)), firstConstant));

  Token tempTok = laToken;
  matchName(Symbol::ID, stsUnion(stsUnion(sts, stsTerminal(Symbol::EQUAL_OPERATOR)), firstConstant), index);

  //match(Symbol::ID, stsUnion(stsUnion(sts, stsTerminal(Symbol::EQUAL_OPERATOR)), firstConstant));
  match(Symbol::EQUAL_OPERATOR, stsUnion(sts, firstConstant));
  tempVal = laToken.getSval().getValue();
  if(!table.insert(index, 0, tempVal, mKind::CONSTKIND, mType::INT)) //this constant value is wrong, it should be n=10, but not sure how to get to the 10 first
    {
        admin.error(ErrorTypes::ScopeError, "Ambiguous definition of constant", tempTok);
    }
  table.printTable(); //just to check the constant value
  constant(sts);

}

void Parser::variableDefinition(const StopSet &sts)
{
  printNT("Variable Definition");
  typeSymbol(stsUnion(sts, firstArrayOrVariableListDefinition));
  arrayOrVariableListDefinition(sts);
}

void Parser::arrayOrVariableListDefinition(const StopSet &sts)
{
  printNT("Array or Variable List Definition");
  bool parseError = false;
  if (member(laToken.getSname(), firstVariableList))
  {
    variableList(sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::ARRAY)))
  {
    match(Symbol::ARRAY, stsUnion(stsTerminal(Symbol::CLOSE_SQUARE_BRACKET), stsUnion(firstConstant, stsUnion(stsTerminal(Symbol::OPEN_SQUARE_BRACKET), stsUnion(firstVariableList, sts)))));
    variableList(stsUnion(stsTerminal(Symbol::CLOSE_SQUARE_BRACKET), stsUnion(firstConstant, stsUnion(stsTerminal(Symbol::OPEN_SQUARE_BRACKET), sts))));
    match(Symbol::OPEN_SQUARE_BRACKET, stsUnion(stsTerminal(Symbol::CLOSE_SQUARE_BRACKET), stsUnion(firstConstant, sts)));
    constant(stsUnion(stsTerminal(Symbol::CLOSE_SQUARE_BRACKET), sts));
    match(Symbol::CLOSE_SQUARE_BRACKET, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(firstVariableList, stsTerminal(Symbol::ARRAY)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::typeSymbol(const StopSet &sts)
{
  printNT("Type Symbol");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::INTEGER)))
  {
    match(Symbol::INTEGER, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::BOOLEAN)))
  {
    match(Symbol::BOOLEAN, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsTerminal(Symbol::INTEGER), stsTerminal(Symbol::BOOLEAN)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::variableList(const StopSet &sts)
{
  printNT("Variable List");
  match(Symbol::ID, stsUnion(stsTerminal(Symbol::COMMA), sts));
  while (member(laToken.getSname(), stsTerminal(Symbol::COMMA)))
  {
    match(Symbol::COMMA, stsUnion(stsTerminal(Symbol::ID), sts));
    match(Symbol::ID, sts);
  }
}

void Parser::procedureDefinition(const StopSet &sts)
{
  printNT("Procedure Definition");
  match(Symbol::PROC, stsUnion(stsUnion(stsTerminal(Symbol::ID), firstBlock), sts));
  match(Symbol::ID, stsUnion(sts, firstBlock));
  block(sts);
}

void Parser::statementPart(const StopSet &sts)
{
  printNT("Statement Part");
  syntaxCheck(stsUnion(sts, firstStatement));
  while (member(laToken.getSname(), firstStatement))
  {
    statement(stsUnion(stsTerminal(Symbol::SEMICOLON), sts));
    match(Symbol::SEMICOLON, stsUnion(firstStatement, sts));
  }
}

void Parser::statement(const StopSet &sts)
{
  printNT("Statement");
  bool parseError = false;
  if (member(laToken.getSname(), firstEmptyStatement))
  {
    emptyStatement(sts);
  }
  else if (member(laToken.getSname(), firstReadStatement))
  {
    readStatement(sts);
  }
  else if (member(laToken.getSname(), firstWriteStatement))
  {
    writeStatement(sts);
  }
  else if (member(laToken.getSname(), firstAssignmentStatement))
  {
    assignmentStatement(sts);
  }
  else if (member(laToken.getSname(), firstProcedureStatement))
  {
    procedureStatement(sts);
  }
  else if (member(laToken.getSname(), firstIfStatement))
  {
    ifStatement(sts);
  }
  else if (member(laToken.getSname(), firstDoStatement))
  {
    doStatement(sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON,
               stsUnion(
                   stsUnion(
                       stsUnion(
                           stsUnion(
                               stsUnion(
                                   stsUnion(firstEmptyStatement, firstReadStatement),
                                   firstWriteStatement),
                               firstAssignmentStatement),
                           firstProcedureStatement),
                       firstIfStatement),
                   firstDoStatement)) &&
       parseError))
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::emptyStatement(const StopSet &sts)
{
  printNT("Empty Statement");
  match(Symbol::SKIP, sts);
}

void Parser::readStatement(const StopSet &sts)
{
  printNT("Read Statement");
  match(Symbol::READ, stsUnion(firstVariableAccessList, sts));
  variableAccessList(sts);
}

void Parser::variableAccessList(const StopSet &sts)
{
  printNT("Variable Access List");
  variableAccess(stsUnion(stsTerminal(Symbol::COMMA), sts));
  while (member(laToken.getSname(), stsTerminal(Symbol::COMMA)))
  {
    match(Symbol::COMMA, stsUnion(firstVariableAccess, sts));
    variableAccess(sts);
  }
}

void Parser::writeStatement(const StopSet &sts)
{
  printNT("Write Statement");
  match(Symbol::WRITE, stsUnion(firstExpressionList, sts));
  expressionList(sts);
}

void Parser::expressionList(const StopSet &sts)
{
  printNT("Expression List");
  expression(stsUnion(stsTerminal(Symbol::COMMA), sts));
  while (member(laToken.getSname(), stsTerminal(Symbol::COMMA)))
  {
    match(Symbol::COMMA, stsUnion(firstExpression, sts));
    expression(sts);
  }
}

void Parser::assignmentStatement(const StopSet &sts)
{
  printNT("Assignment Statement");
  variableAccessList(stsUnion(stsUnion(stsTerminal(Symbol::ASSIGNMENT_OPERATOR), firstExpressionList), sts));
  match(Symbol::ASSIGNMENT_OPERATOR, stsUnion(firstExpressionList, sts));
  expressionList(sts);
}

void Parser::procedureStatement(const StopSet &sts)
{
  printNT("Proc Statement");
  match(Symbol::CALL, stsUnion(stsTerminal(Symbol::ID), sts));
  match(Symbol::ID, sts);
}

void Parser::ifStatement(const StopSet &sts)
{
  printNT("If Statement");
  match(Symbol::IF, stsUnion(stsTerminal(Symbol::FI), stsUnion(firstGuardedCommandList, sts)));
  guardedCommandList(stsUnion(stsTerminal(Symbol::FI), sts));
  match(Symbol::FI, sts);
}

void Parser::doStatement(const StopSet &sts)
{
  printNT("Do Statement");
  match(Symbol::DO, stsUnion(stsTerminal(Symbol::OD), stsUnion(firstGuardedCommandList, sts)));
  guardedCommandList(stsUnion(stsTerminal(Symbol::OD), sts));
  match(Symbol::OD, sts);
}

void Parser::guardedCommandList(const StopSet &sts)
{
  printNT("Guarded Command List");
  guardedCommand(stsUnion(stsTerminal(Symbol::GUARDED_COMMAND), sts));
  while (member(laToken.getSname(), stsTerminal(Symbol::GUARDED_COMMAND)))
  {
    match(Symbol::GUARDED_COMMAND, stsUnion(firstGuardedCommand, sts));
    guardedCommand(sts);
  }
}

void Parser::guardedCommand(const StopSet &sts)
{
  printNT("Guarded Command");
  expression(stsUnion(stsUnion(stsTerminal(Symbol::ARROW), firstStatementPart), sts));
  match(Symbol::ARROW, stsUnion(firstStatementPart, sts));
  statementPart(sts);
}

void Parser::expression(const StopSet &sts)
{
  printNT("Expression");
  primaryExpression(stsUnion(firstPrimaryOperator, sts));
  while (member(laToken.getSname(), firstPrimaryOperator))
  {
    primaryOperator(stsUnion(firstPrimaryExpression, sts));
    primaryExpression(sts);
  }
}

void Parser::primaryOperator(const StopSet &sts)
{
  printNT("Primary Operator");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::AND_OPERATOR)))
  {
    match(Symbol::AND_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::OR_OPERATOR)))
  {
    match(Symbol::OR_OPERATOR, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsTerminal(Symbol::AND_OPERATOR), stsTerminal(Symbol::OR_OPERATOR)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::primaryExpression(const StopSet &sts)
{
  printNT("Primary Expression");
  simpleExpression(stsUnion(firstRelationalOperator, sts));
  if (member(laToken.getSname(), firstRelationalOperator))
  {
    relationalOperator(stsUnion(firstSimpleExpression, sts));
    simpleExpression(sts);
  }
}

void Parser::relationalOperator(const StopSet &sts)
{
  printNT("Relational Operator");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::LESS_THAN_OPERATOR)))
  {
    match(Symbol::LESS_THAN_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::EQUAL_OPERATOR)))
  {
    match(Symbol::EQUAL_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::GREATER_THAN_OPERATOR)))
  {
    match(Symbol::GREATER_THAN_OPERATOR, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsUnion(stsTerminal(Symbol::LESS_THAN_OPERATOR), stsTerminal(Symbol::EQUAL_OPERATOR)), stsTerminal(Symbol::GREATER_THAN_OPERATOR)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::simpleExpression(const StopSet &sts)
{
  printNT("Simple Expression");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::SUBTRACTION_OPERATOR)))
  {
    match(Symbol::SUBTRACTION_OPERATOR, stsUnion(stsUnion(firstTerm, sts), firstAddingOperator));
    term(stsUnion(firstAddingOperator, sts));
    while (member(laToken.getSname(), firstAddingOperator))
    {
      addingOperator(stsUnion(firstTerm, sts));
      term(sts);
    }
  }
  else if (member(laToken.getSname(), firstTerm))
  {
    term(stsUnion(firstAddingOperator, sts));
    while (member(laToken.getSname(), firstAddingOperator))
    {
      addingOperator(stsUnion(firstTerm, sts));
      term(sts);
    }
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsTerminal(Symbol::SUBTRACTION_OPERATOR), firstTerm))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::addingOperator(const StopSet &sts)
{
  printNT("Adding Operator");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::ADDITION_OPERATOR)))
  {
    match(Symbol::ADDITION_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::SUBTRACTION_OPERATOR)))
  {
    match(Symbol::SUBTRACTION_OPERATOR, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsTerminal(Symbol::ADDITION_OPERATOR), stsTerminal(Symbol::SUBTRACTION_OPERATOR)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::term(const StopSet &sts)
{
  printNT("Term");
  factor(stsUnion(firstMultiplyingOperator, sts));
  while (member(laToken.getSname(), firstMultiplyingOperator))
  {
    multiplyingOperator(stsUnion(firstFactor, sts));
    factor(sts);
  }
}

void Parser::multiplyingOperator(const StopSet &sts)
{
  printNT("Multiplying Operator");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::MULTIPLICATION_OPERATOR)))
  {
    match(Symbol::MULTIPLICATION_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::DIVISION_OPERATOR)))
  {
    match(Symbol::DIVISION_OPERATOR, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::MODULUS_OPERATOR)))
  {
    match(Symbol::MODULUS_OPERATOR, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON,
               stsUnion(
                   stsUnion(
                       stsTerminal(Symbol::MULTIPLICATION_OPERATOR),
                       stsTerminal(Symbol::DIVISION_OPERATOR)),
                   stsTerminal(Symbol::MODULUS_OPERATOR)))) &&
      parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::factor(const StopSet &sts)
{
  printNT("Factor");
  bool parseError = false;
  if (member(laToken.getSname(), firstVariableAccess))
  {
    variableAccess(sts);
  }
  else if (member(laToken.getSname(), firstConstant))
  {
    constant(sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::OPEN_PARENTHESIS)))
  {
    match(Symbol::OPEN_PARENTHESIS, stsUnion(stsUnion(firstExpression, sts), stsTerminal(Symbol::CLOSE_PARENTHESIS)));
    expression(stsUnion(stsTerminal(Symbol::CLOSE_PARENTHESIS), sts));
    match(Symbol::CLOSE_PARENTHESIS, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::NOT_OPERATOR)))
  {
    match(Symbol::NOT_OPERATOR, stsUnion(firstFactor, sts));
    factor(sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON,
               stsUnion(
                   stsUnion(
                       stsUnion(
                           firstConstant,
                           firstVariableAccess),
                       stsTerminal(Symbol::OPEN_PARENTHESIS)),
                   stsTerminal(Symbol::NOT_OPERATOR)))) &&
      parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::variableAccess(const StopSet &sts)
{
  printNT("Variable Access");
  match(Symbol::ID, stsUnion(stsTerminal(Symbol::OPEN_SQUARE_BRACKET), sts));
  if (member(laToken.getSname(), firstIndexedSelector))
  {
    indexedSelector(sts);
  }
}

void Parser::indexedSelector(const StopSet &sts)
{
  printNT("Indexed Selector");
  match(Symbol::OPEN_SQUARE_BRACKET, stsUnion(stsUnion(firstExpression, sts), stsTerminal(Symbol::CLOSE_SQUARE_BRACKET)));
  expression(stsUnion(stsTerminal(Symbol::CLOSE_SQUARE_BRACKET), sts));
  match(Symbol::CLOSE_SQUARE_BRACKET, sts);
}

void Parser::constant(const StopSet &sts)
{
  printNT("Constant");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::NUM)))
  {
    match(Symbol::NUM, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::BOOLEAN)))
  {
    match(Symbol::BOOLEAN, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::ID)))
  {
    match(Symbol::ID, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsUnion(stsTerminal(Symbol::NUM), stsTerminal(Symbol::BOOLEAN)), stsTerminal(Symbol::ID)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}

void Parser::booleanSymbol(const StopSet &sts)
{
  printNT("Boolean Symbol");
  bool parseError = false;
  if (member(laToken.getSname(), stsTerminal(Symbol::FALSE)))
  {
    match(Symbol::FALSE, sts);
  }
  else if (member(laToken.getSname(), stsTerminal(Symbol::TRUE)))
  {
    match(Symbol::TRUE, sts);
  }
  else
  {
    parseError = true;
  }
  if ((!member(Symbol::EPSILON, stsUnion(stsTerminal(Symbol::TRUE), stsTerminal(Symbol::FALSE)))) && parseError)
  {
    syntaxError(sts);
  }
  else
  {
    syntaxCheck(sts);
  }
}
