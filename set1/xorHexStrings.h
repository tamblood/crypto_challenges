#ifndef XORHEXSTRINGS_H
#define XORHEXSTRINGS_H

#include <iostream>
using namespace std;
  extern const int FOUR_BIT_INT_SIZE;
  extern const int SIZE;

  char *xorTwoHexStrings(char string1[], char string2[]);
  void displayFourBitInt(int fourBitInt[]);
  void xorFourBit(int fourBitInt[], int fourBitInt2[], int xorResult4BitInt[]);
  int convertFourBitToHexInt(int xorResult4BitInt[]);
  char convertHexIntToHexChar(int hexInt);

#endif

