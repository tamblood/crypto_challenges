#ifndef FINDSINGLEBYTEXORCIPHER_H
#define FINDSINGLEBYTEXORCIPHER_H

  const int BYTE_SIZE = 8;
  const int POSSIBLE_MASKS = 256;
  char *findSingleByteXORCipher(char input[]);
  void generateOneByteXorMask(int maskInDecimal, int oneByteXORMask[]);
  void generateXorHexStringMask(int oneByteXORMask[], char xorHexStringMask[], int inputSize);
  int convertFourBitIntToHexInt(int fourBitInt[]);
  char convertBitIntToHexChar(int oneByteXORMask[], int startAt);

#endif
