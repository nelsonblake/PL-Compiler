//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Scanner Implementation File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#include "./scanner.h"

// Constructors
Scanner::Scanner(ifstream &inputFile, SymbolTable &table)
{
  SymbolTable t = table;
  inputFilePtr = &inputFile;
  symbolTablePtr = &table;
  symbolTablePtr->init();
}

// Assignment Operator
Scanner Scanner::operator=(const Scanner &s)
{
  this->inputFilePtr = s.inputFilePtr;
  this->symbolTablePtr = s.symbolTablePtr;
  this->nextChar = s.nextChar;

  return *this;
}

// Destructor
Scanner::~Scanner()
{
  inputFilePtr = nullptr;
  symbolTablePtr = nullptr;
}

// getSymbolTablePtr Method
SymbolTable *Scanner::getSymbolTablePtr()
{
  return symbolTablePtr;
}

// isWhitespace Method
bool Scanner::isWhitespace(const char &c)
{
  if (isspace(c))
  {
    return true;
  }
  return false;
}

// isAlpha Method
bool Scanner::isAlpha(const char &c)
{
  if (isalpha(c))
  {
    return true;
  }
  return false;
}

// isDigit Method
bool Scanner::isDigit(const char &c)
{
  if (isdigit(c))
  {
    return true;
  }
  return false;
}

// isSpecial Method
bool Scanner::isSpecial(const char &c)
{
  char specials[19] = {
      '.',
      ',',
      ';',
      '~',
      '<',
      '>',
      '=',
      '[',
      ']',
      '&',
      '|',
      '+',
      '-',
      '*',
      '\\',
      '/',
      '(',
      ')',
      ':',
  };
  if (find(begin(specials), end(specials), c) != end(specials))
  {
    return true;
  }
  return false;
}

//getToken Method
Token Scanner::getToken()
{
  nextChar = inputFilePtr->get();
  Token t;

  if (isWhitespace(nextChar))
  {
    //
  }

  else if (isAlpha(nextChar))
  {
    t = recognizeId();
  }

  else if (isDigit(nextChar))
  {
    t = recognizeDigit();
  }

  else if (isSpecial(nextChar))
  {
    t = recognizeSpecial();
  }

  else
  {
    t = Token();
  }

  return t;
}

// recognizeId Method
Token Scanner::recognizeId()
{
  string lexeme(1, nextChar);
  do
  {
    nextChar = nextChar = inputFilePtr->get();
    {
      string nextPart(1, nextChar);
      lexeme += nextPart;
    }
  } while (!isWhitespace(nextChar) && (nextChar == '_' || isAlpha(nextChar) || isDigit(nextChar)));

  cout << lexeme << endl;

  // int index = symbolTablePtr->search(lexeme);
  // if (index == -1)
  // {
  //   Token t = Token(ID, Attribute(lexeme));
  //   return t;
  // }
  return Token();
}

// recognizeDigit Method
Token Scanner::recognizeDigit()
{
  return Token();
}

// recognizeSpecial Method
Token Scanner::recognizeSpecial()
{
  return Token();
}
