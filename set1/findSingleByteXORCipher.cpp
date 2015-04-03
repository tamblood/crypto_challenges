#include<iostream>
#include<cmath>     // for pow function
#include "hexmanip.h"  
#include "xorHexStrings.h"  
#include "convertHexStringToAscii.h"
#include "freqScore.h"
#include "findSingleByteXORCipher.h"
using namespace std;

//int main()
//{
//  char input[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
//
//  cout << findSingleByteXORCipher(input) << endl;
//
//}

void generateOneByteXorMask(int maskInDecimal, int oneByteXORMask[])
{
  int divider = pow(2, BYTE_SIZE - 1); // divider starts at 128

  for(int i = 0; i < BYTE_SIZE; i++)
  {
    oneByteXORMask[i] = maskInDecimal / divider;
    maskInDecimal = maskInDecimal % divider;
    divider /= 2;
  }
}

int convertFourBitIntToHexInt(int fourBitInt[])
{
  int hexInt = 0;
  int multiplier = pow(2, FOUR_BIT_INT_SIZE - 1);
  
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
  {
    hexInt += fourBitInt[i] * multiplier;
    multiplier /= 2;
  }
  return hexInt;
}

char convertBitIntToHexChar(int oneByteXORMask[], int startAt)
{
  char hexChar;
  int hexInt;
  int fourBitInt[FOUR_BIT_INT_SIZE];

  //  load fourBitInt
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
    fourBitInt[i] = oneByteXORMask[startAt + i];

  // convert 4 bit int to hex int
  hexInt = convertFourBitIntToHexInt(fourBitInt);

  // convert hex int to hexchar
  hexChar = convertHexIntToHexChar(hexInt);
  
  return hexChar;

}

void generateXorHexStringMask(int oneByteXORMask[], char xorHexStringMask[], int inputSize)
{
  char hexCharFirst;
  char hexCharSecond;
  int startAt = 0;

  // get two hex string equivalent for oneByteXORMask 8 bit int
  hexCharFirst = convertBitIntToHexChar(oneByteXORMask, startAt);
  startAt += FOUR_BIT_INT_SIZE;
  hexCharSecond = convertBitIntToHexChar(oneByteXORMask, startAt);

  // repeat two hex string to make mask of length inputsize
  for(int i = 0; i < inputSize; i++)
  {
    if(i % 2 == 0)
      xorHexStringMask[i] = hexCharFirst;
    else
      xorHexStringMask[i] = hexCharSecond;
  }
  
  // add null character at end of c string
  xorHexStringMask[inputSize] = '\0';
}

char *findSingleByteXORCipher(char input[]) 
{

  int inputSize = strlen(input);
  char *decodedMessage;
  decodedMessage = new char[inputSize + 1];
  char *xorResult;
  xorResult = new char[inputSize + 1];
  char *asciiResult;
  asciiResult = new char[inputSize + 1];

  int oneByteXORMask[BYTE_SIZE];
  char xorHexStringMask[inputSize + 1];

  int freqScore = -1;
  int lowestScore = 1111110;
  char *bestMessageSoFar;
  bestMessageSoFar = new char[inputSize + 1];

  // for each possible mask
  //   generate an xor mask
  //   apply xor mask to input to get result
  //   convert result to ascii
  for (int i = 0; i < POSSIBLE_MASKS; i++)
  {
    generateOneByteXorMask(i, oneByteXORMask);
    cout << "One byte xor mask is: " << endl;
    displayBitInt(oneByteXORMask, BYTE_SIZE);
    generateXorHexStringMask(oneByteXORMask, xorHexStringMask, inputSize);
    xorResult = xorTwoHexStrings(input, xorHexStringMask);
    asciiResult = convertHexStringToAscii(xorResult);
    
    cout << "Input is: " << endl;
    cout << input << endl;
    cout << "Xor hex string mask is: " << endl;
    cout << xorHexStringMask << endl;
    cout << "Xor in hex of input and mask is: ";
    cout << xorResult << endl;
    cout << "Ascii conversion of xorResult is: ";
    cout << asciiResult << endl;

    freqScore = getFreqScore(asciiResult);
    if (freqScore < lowestScore)
    {
      lowestScore = freqScore;
      bestMessageSoFar = asciiResult;
    }
    cout << "Frequency score is: " << endl;
    cout << freqScore << endl;
  }

  decodedMessage = bestMessageSoFar;

  delete [] xorResult;
  delete [] asciiResult;

  cout << "lowest score: " << lowestScore << endl;
  cout << "bestMessageSoFar: " << bestMessageSoFar << endl;
  return decodedMessage;
}
