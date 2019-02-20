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
  while (!admin.getInputFilePtr()->eof() && admin.getErrorCount() < MAX_ERRORS)
  {
    laToken = admin.getScanner().getToken();
    if (laToken.getSname() == INVALID_CHAR || laToken.getSname() == INVALID_ID || laToken.getSname() == INVALID_NUM)
    {
      handleScanError(laToken);
    }
    if (admin.getErrorCount() == MAX_ERRORS)
    {
      cout << "Maximum error count reached (" << MAX_ERRORS << ") - Compiler is stopping." << endl;
      return 1;
    }
  }
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