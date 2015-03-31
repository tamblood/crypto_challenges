#include <iostream>
#include <cmath>
#include "hexmanip.h"
using namespace std;

void displayBitInt(int bitInt[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << bitInt[i];
  }
  cout << endl;
}

int convertHexCharToHexInt(char hexChar)
{
  int hexInt;
  char hexCharArray[1];

  hexCharArray[0] = hexChar;

  switch (hexChar)
  {
    case 'a': 
    case 'A': hexInt = 10;
              break;
    case 'b': hexInt = 11;
    case 'B': hexInt = 11;
              break;
    case 'c': hexInt = 12;
    case 'C': hexInt = 12;
              break;
    case 'd': hexInt = 13;
    case 'D': hexInt = 13;
              break;
    case 'e': hexInt = 14;
    case 'E': hexInt = 14;
              break;
    case 'f': hexInt = 15;
    case 'F': hexInt = 15;
              break;
    default:  hexInt = atoi(hexCharArray);
              break;
  }
  return hexInt;
}

void convertHexIntToFourBitInt(int hexInt, int fourBitInt[])
{
  // set divider to break integer into powers of 2 pieces
  int divider = pow(2, FOUR_BIT_INT_SIZE - 1); 

  for (int i = 0; i < FOUR_BIT_INT_SIZE; i++)
  {
    fourBitInt[i] = hexInt / divider;
    hexInt = hexInt % divider;
    divider /= 2;
  }
}

void convertHexCharToFourBitInt(char hexChar, int fourBitInt[])
{
  int hexInt;
  hexInt = convertHexCharToHexInt(hexChar);
  cout << "hexChar is: " << hexChar << ", "  << "HexInt is: " << hexInt << endl;
  convertHexIntToFourBitInt(hexInt, fourBitInt);
  cout << "four bit int is: " << endl;
  displayBitInt(fourBitInt, FOUR_BIT_INT_SIZE);
  
}

int convertHexCharToInt(char hexChar)
{
  int hexInt;
  char hexCharStr[1];
  switch (hexChar)
  {
    case 'a':
    case 'A': hexInt = 10;
              break;
    case 'b':
    case 'B': hexInt = 11;
              break;
    case 'c':
    case 'C': hexInt = 12;
              break;
    case 'd':
    case 'D': hexInt = 13;
              break;
    case 'e':
    case 'E': hexInt = 14;
              break;
    case 'f':
    case 'F': hexInt = 15;
              break;
    default:  hexCharStr[0] = hexChar;
              hexInt = atoi(hexCharStr);
              break;
  }
  return hexInt;
}

