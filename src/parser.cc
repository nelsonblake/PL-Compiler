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
  StopSet initialSts;
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
    cout << "Error" << endl;
  }
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

StopSet stsUnion(const StopSet &sts, const Symbol &s)
{
  StopSet newSts = sts;
  newSts.push_back(s);
  return newSts;
}

// Non-Terminal Parsing Functions
void Parser::program(const StopSet &sts)
{
  block(stsUnion(sts, Symbol::PERIOD));
  match(Symbol::PERIOD, sts);
}

void Parser::block(const StopSet &sts)
{
  match(Symbol::BEGIN, sts);
  //DefinitionPart
  //StatementPart
  match(Symbol::END, sts);
}