#include<iostream>
#include "convertHexStringToAscii.h"
#include "hexmanip.h"
using namespace std;


//int main()
//{
//
//  char *result;
//  char hexString[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
//
 // result = convertHexStringToAscii(hexString);
//  cout << "Result is: " << result;
//
//  delete [] result;
//  
//  return(0);
//
//}

char *convertHexStringToAscii(char *hexString)
{
  char *asciiString = new char[strlen(hexString) / 2 + 1];
  char hexByte[2];
  int startAt = 0;
  int numCharsToGet = 2; // 2 hex chars in one byte
  int counter = 0;
  int resultInt = 0;
  char resultChar;

  while(getNextChars(hexString, hexByte, startAt, numCharsToGet) == numCharsToGet) 
  {
    cout << "hexByte is: " << hexByte[0] << hexByte[1] << endl;
    resultInt = convertHexByteToInt(hexByte);
    cout << "resultInt is: " << resultInt << endl;
    resultChar = convertResultIntToResultChar(resultInt);
    cout << "resultChar is: " << resultChar << endl;
    asciiString[counter] = resultChar;
    cout << "asciiString is: " << asciiString << endl;
    
    startAt += numCharsToGet;
    counter++;
  }
  
  return asciiString;

}

char convertResultIntToResultChar(int resultInt)
{
  char resultChar;

  // if resultInt is within ascii printable range, cast it
  if(resultInt >= 32 && resultInt <= 126)
    resultChar = (char)resultInt;
  else
    resultChar = '`';

  return resultChar;
}

int getNextChars(char hexString[], char hexChar[], int indexStartAt, int numCharsToGet)
{
  bool foundEndOfString = false;
  int counter = 0;

  for(int i = 0; i < numCharsToGet && !foundEndOfString; i++)
  {
    if (hexString[i + indexStartAt] == '\0')
    {
      foundEndOfString = true;
    }
    else
    {
      hexChar[i] = hexString[i + indexStartAt];
      counter++;
    }
  }
  return counter; // returns how many chars read
}

int convertHexByteToInt(char hexByte[])
{
  int resultInt = 0;
  char hexByteLow = hexByte[1];
  char hexByteHigh = hexByte[0];

  int multiplier = 16; // to reflect highest 4 bits of hex byte

  // convert least significant char first
  resultInt += convertHexCharToInt(hexByteLow);

  // convert most significant char
  resultInt += convertHexCharToInt(hexByteHigh) * multiplier;

  return resultInt;
  
}
