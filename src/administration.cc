//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Administration Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./administration.h"

// Constructors
Administration::Administration(ifstream &inputFile, ofstream &outputFile, Scanner &s) : scanner(s)
{
  inputFilePtr = &inputFile;
  outputFilePtr = &outputFile;
  currentLine = 1;
  errorCount = 0;
  correctLine = true;
}

// Destructor
Administration::~Administration()
{
  outputFilePtr = nullptr;
}

void Administration::error(const string &s, const Token &t)
{
  string errorType(s);
  Token temp(t);
  cout << "Scanner encountered an error at line " << currentLine << ": " << s << ": " << temp.getSval().getLexeme() << endl;

  // Ignore the rest of the line
  inputFilePtr->ignore(256, '\n');
  currentLine++;
  errorCount++;
}

int Administration::scan()
{
  while (!inputFilePtr->eof() && errorCount < MAX_ERRORS)
  {
    Token t = scanner.getToken();
    if (t.getSname() == ID)
    {
      int idIndex = scanner.getSymbolTablePtr()->insert(t);
      (*outputFilePtr) << "TOKEN TYPE: ID  - "
                       << "TOKEN ATTRIBUTES - "
                       << "INDEX: " << setw(5);
      (*outputFilePtr) << idIndex << setw(10);
      (*outputFilePtr) << " - LEXEME: " << t.getSval().getLexeme() << endl;
    }
    else if (t.getSname() == NUM)
    {
      (*outputFilePtr) << "TOKEN TYPE: NUM - "
                       << "TOKEN ATTRIBUTES - "
                       << "VALUE: " << setw(5);
      (*outputFilePtr) << t.getSval().getValue() << endl;
    }
    else if (
        t.getSname() == AND_OPERATOR ||
        t.getSname() == OR_OPERATOR ||
        t.getSname() == NOT_OPERATOR ||
        t.getSname() == LESS_THAN_OPERATOR ||
        t.getSname() == GREATER_THAN_OPERATOR ||
        t.getSname() == EQUAL_OPERATOR ||
        t.getSname() == ADDITION_OPERATOR ||
        t.getSname() == SUBTRACTION_OPERATOR ||
        t.getSname() == MULTIPLICATION_OPERATOR ||
        t.getSname() == DIVISION_OPERATOR ||
        t.getSname() == MODULUS_OPERATOR ||
        t.getSname() == ASSIGNMENT_OPERATOR ||
        t.getSname() == ARROW ||
        t.getSname() == PERIOD ||
        t.getSname() == COMMA ||
        t.getSname() == SEMICOLON ||
        t.getSname() == OPEN_SQUARE_BRACKET ||
        t.getSname() == CLOSE_SQUARE_BRACKET ||
        t.getSname() == OPEN_PARENTHESIS ||
        t.getSname() == CLOSE_PARENTHESIS ||
        t.getSname() == GUARDED_COMMAND)
    {
      (*outputFilePtr) << "TOKEN TYPE: OPERATOR " << t.getSval().getLexeme() << endl;
    }
    else if (
        t.getSname() == BEGIN ||
        t.getSname() == END ||
        t.getSname() == CONST ||
        t.getSname() == ARRAY ||
        t.getSname() == INTEGER ||
        t.getSname() == BOOLEAN ||
        t.getSname() == PROC ||
        t.getSname() == SKIP ||
        t.getSname() == READ ||
        t.getSname() == WRITE ||
        t.getSname() == CALL ||
        t.getSname() == IF ||
        t.getSname() == FI ||
        t.getSname() == DO ||
        t.getSname() == OD ||
        t.getSname() == FALSE ||
        t.getSname() == TRUE)
    {
      (*outputFilePtr) << "TOKEN TYPE: RESERVED WORD " << t.getSval().getLexeme() << endl;
    }
    else if (t.getSname() == NEWLINE)
    {
      currentLine++;
    }
    else if (t.getSname() == INVALID_CHAR)
    {
      error("Invalid character", t);
    }
    else if (t.getSname() == INVALID_ID)
    {
      error("Invalid identifier", t);
    }
    else if (t.getSname() == INVALID_NUM)
    {
      error("Invalid number", t);
    }
  }
  if (errorCount == MAX_ERRORS)
  {
    cout << "Maximum error count reached (" << MAX_ERRORS << ") - Scanner is stopping." << endl;
    return 1;
  }
  if (errorCount > 0)
  {
    return 1;
  }
  return 0;
}
