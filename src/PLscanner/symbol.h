//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Terminal Symbols for PL Language
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef SYMBOL_H
#define SYMBOL_H

enum Symbol
{
  BEGIN = 'begin',
  END = 'end',
  CONST = 'const',
  ARRAY = 'array',
  INTEGER = 'integer',
  BOOLEAN = 'boolean',
  PROC = 'proc',
  SKIP = 'skip',
  READ = 'read',
  WRITE = 'write',
  CALL = 'call',
  IF = 'if',
  FI = 'fi',
  DO = 'do',
  OD = 'od',
  FALSE = 'false',
  TRUE = 'true',
  ID,
  NUM,
  DECIMAL = '.',
  COMMA = ',',
  OPEN_SQUARE_BRACKET = '[',
  CLOSE_SQUARE_BRACKET = ']',
  OPEN_PARENTHESIS = '\(',
  CLOSE_PARENTHESIS = ')',
  GUARDED_COMMAND = '[]',
  COMMENT = '$',
  AND_OPERATOR = '&',
  OR_OPERATOR = '|',
  NOT_OPERATOR = '~',
  LESS_THAN_OPERATOR = '<',
  GREATER_THAN_OPERATOR = '>',
  EQUAL_OPERATOR = '=',
  ADDITION_OPERATOR = '=',
  SUBTRACTION_OPERATOR = '-',
  MULTIPLICATION_OPERATOR = '*',
  DIVISION_OPERATOR = '/',
  MODULUS_OPERATOR = '\\',
  ASSIGNMENT_OPERATOR = ':=',
  ARROW_OPERATOR = '->'
};
#endif