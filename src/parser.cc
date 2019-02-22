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
void Parser::handleScanError(Token &t)
{
  if (t.getSname() == INVALID_CHAR)
  {
    admin.error(ErrorTypes::ScanError, "Invalid character", t);
  }
  else if (t.getSname() == INVALID_ID)
  {
    admin.error(ErrorTypes::ScanError, "Invalid identifier", t);
  }
  else if (t.getSname() == INVALID_NUM)
  {
    admin.error(ErrorTypes::ScanError, "Invalid number", t);
  }
}

Token Parser::getValidToken()
{
  Token t = admin.getScanner().getToken();
  while (t.getSname() == Symbol::NEWLINE || t.getSname() == Symbol::NONAME)
  {
    t = admin.getScanner().getToken();
  }
  return t;
}

void Parser::syntaxError(const StopSet &sts)
{
  cout << "Error: " << laToken.getSname() << endl;
  exit(1);
}

void Parser::syntaxCheck(const StopSet &sts)
{
  Symbol laSymbol = laToken.getSname();
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

void Parser::match(const Symbol &s, const StopSet &sts)
{
  cout << "Terminal: " << laToken.getSval().getLexeme() << " " << laToken.getSval().getValue() << endl;
  Symbol laSymbol = laToken.getSname();
  if (laSymbol == s)
  {
    laToken = getValidToken();
    handleScanError(laToken);
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
  block(sts);
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
  StopSet newSts = stsUnion(sts, firstDefinition);
  syntaxCheck(newSts);
  while (member(laToken.getSname(), firstDefinition))
  {
    definition(newSts);
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
  printNT("Constant Definition");
  match(Symbol::CONST, stsUnion(stsUnion(stsUnion(sts, stsTerminal(Symbol::ID)), stsTerminal(Symbol::EQUAL_OPERATOR)), firstConstant));
  match(Symbol::ID, stsUnion(stsUnion(sts, stsTerminal(Symbol::EQUAL_OPERATOR)), firstConstant));
  match(Symbol::EQUAL_OPERATOR, stsUnion(sts, firstConstant));
  constant(sts);
}
void Parser::variableDefinition(const StopSet &sts)
{
  printNT("Variable Definition");
}
void Parser::typeSymbol(const StopSet &sts)
{
}
void Parser::variableList(const StopSet &sts)
{
}
void Parser::procedureDefinition(const StopSet &sts)
{
  printNT("Procedure Definition");
}
void Parser::statementPart(const StopSet &sts)
{
}
void Parser::statement(const StopSet &sts)
{
}
void Parser::emptyStatement(const StopSet &sts)
{
}
void Parser::readStatement(const StopSet &sts)
{
}
void Parser::variableAccessList(const StopSet &sts)
{
}
void Parser::writeStatement(const StopSet &sts)
{
}
void Parser::expressionList(const StopSet &sts)
{
}
void Parser::assignmentStatement(const StopSet &sts)
{
}
void Parser::procedureStatement(const StopSet &sts)
{
}
void Parser::ifStatement(const StopSet &sts)
{
}
void Parser::doStatement(const StopSet &sts)
{
}
void Parser::guardedCommandList(const StopSet &sts)
{
}
void Parser::guardedCommand(const StopSet &sts)
{
}
void Parser::expression(const StopSet &sts)
{
}
void Parser::primaryOperator(const StopSet &sts)
{
}
void Parser::primaryExpression(const StopSet &sts)
{
}
void Parser::relationalOperator(const StopSet &sts)
{
}
void Parser::simpleExpression(const StopSet &sts)
{
}
void Parser::addingOperator(const StopSet &sts)
{
}
void Parser::term(const StopSet &sts)
{
}
void Parser::multiplyingOperator(const StopSet &sts)
{
}
void Parser::factor(const StopSet &sts)
{
}
void Parser::variableAccess(const StopSet &sts)
{
}
void Parser::indexedSelector(const StopSet &sts)
{
}
void Parser::constant(const StopSet &sts)
{
  printNT("Constant");
}
void Parser::booleanSymbol(const StopSet &sts)
{
}