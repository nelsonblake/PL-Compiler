//************************************************************************************
// CPSC 4600
// PL Language Compiler
// Terminal Symbols for PL Language
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef SYMBOL_H
#define SYMBOL_H

enum Symbol : int
{
  // Identifier and Number
  ID = 256,
  NUM,
  // Reserved Words
  BEGIN,
  END,
  CONST,
  ARRAY,
  INTEGER,
  BOOLEAN,
  PROC,
  SKIP,
  READ,
  WRITE,
  CALL,
  IF,
  FI,
  DO,
  OD,
  FALSE,
  TRUE,
  // Operators
  AND_OPERATOR,
  OR_OPERATOR,
  NOT_OPERATOR,
  LESS_THAN_OPERATOR,
  GREATER_THAN_OPERATOR,
  EQUAL_OPERATOR,
  ADDITION_OPERATOR,
  SUBTRACTION_OPERATOR,
  MULTIPLICATION_OPERATOR,
  DIVISION_OPERATOR,
  MODULUS_OPERATOR,
  ASSIGNMENT_OPERATOR,
  // Other Symbols
  ARROW,
  PERIOD,
  COMMA,
  SEMICOLON,
  OPEN_SQUARE_BRACKET,
  CLOSE_SQUARE_BRACKET,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  GUARDED_COMMAND,
  COMMENT,
  // Utility Symbols
  NONAME,       // Empty Token
  INVALID_ID,   // ID error indicator
  INVALID_CHAR, // Char error indicator
  INVALID_NUM,  // Overflow
  NEWLINE
};
#endif
