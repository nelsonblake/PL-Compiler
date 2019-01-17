//************************************************************************************
// CPSC 4600
// PL Language Scanner
// Scanner Interface File
// Written By: Eric Den Haan and Blake Nelson
//************************************************************************************

#ifndef SCANNER_H
#define SCANNER_H

#include "./token.h"

using namespace std;

class Scanner
{
  // Constructors
  Scanner();

  // Public Methods
  Token getToken();

  // Data Members
};

#endif
