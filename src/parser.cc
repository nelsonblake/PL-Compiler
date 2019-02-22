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
  laToken = admin.getScanner().getToken();
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
void Parser::match(const Symbol &s, const StopSet &sts)
{
  Symbol laSymbol = laToken.getSname();
  if (laSymbol == s)
  {
    laToken = admin.getScanner().getToken();
    handleScanError(laToken);
  }
  else
  {
    syntaxError(sts);
  }
  syntaxCheck(sts);
}

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

void Parser::syntaxError(const StopSet &sts)
{
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

// Non-Terminal Parsing Functions
void Parser::program(const StopSet &sts)
{
  block(sts);
  match(Symbol::PERIOD, sts);
}

void Parser::block(const StopSet &sts)
{
  match(Symbol::BEGIN, stsUnion(stsUnion(stsUnion(sts, firstDefinitionPart), firstStatementPart), stsTerminal(Symbol::END)));
  definitionPart(stsUnion(stsUnion(sts, firstStatementPart), stsTerminal(Symbol::END)));
  statementPart(stsUnion(sts, stsTerminal(Symbol::END)));
  match(Symbol::END, sts);
}

void Parser::definitionPart(const StopSet &sts)
{
}
void Parser::definition(const StopSet &sts)
{
}
void Parser::constantDefinition(const StopSet &sts)
{
}
void Parser::variableDefinition(const StopSet &sts)
{
}
void Parser::typeSymbol(const StopSet &sts)
{
}
void Parser::variableList(const StopSet &sts)
{
}
void Parser::procedureDefinition(const StopSet &sts)
{
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
}
void Parser::booleanSymbol(const StopSet &sts)
{
}