#ifndef CONVERTHEXSTRINGTOASCII_H
#define CONVERTHEXSTRINGTOASCII_H

char *convertHexStringToAscii(char *hexString);
int getNextChars(char hexString[], char hexChar[], int indexStartAt, int numCharsToGet);
int convertHexByteToInt(char hexByte[]);
char convertResultIntToResultChar(int resultInt);

#endif
