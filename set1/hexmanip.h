#ifndef HEXMANIP_H
#define HEXMANIP_H

  const int SIZE = 120;
  const int FOUR_BIT_INT_SIZE = 4;

  void convertHexCharToFourBitInt(char hexChar, int fourBitInt[]);
  int convertHexCharToHexInt(char hexChar);
  void convertHexIntToFourBitInt(int hexInt, int fourBitInt[]);
  void displayBitInt(int bitInt[], int size);
  int convertHexCharToInt(char hexChar);

#endif

