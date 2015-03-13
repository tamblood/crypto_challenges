#include<iostream>
#include<cmath> // for pow function

using namespace std;
const int SIZE = 120;
const int FOUR_BIT_INT_SIZE = 4;

char *xorTwoHexStrings(char string1[], char string2[]);
void convertHexCharToFourBitInt(char hexChar, int fourBitInt[]);
void convertHexIntToFourBitInt(int hexInt, int fourBitInt[]);
void displayFourBitInt(int fourBitInt[]);
void xorFourBit(int fourBitInt[], int fourBitInt2[], int xorResult4BitInt[]);
int convertFourBitToHexInt(int xorResult4BitInt[]);
char convertHexIntToHexChar(int hexInt);

int main()
{
  char string1[SIZE] = "1c0111001f010100061a024b53535009181c";
  char string2[SIZE] = "686974207468652062756c6c277320657965";
  char xorResult[SIZE];

  strcpy(xorResult, xorTwoHexStrings(string1, string2));
  cout << "Result is: " << xorResult << endl;
}

char *xorTwoHexStrings(char string1[], char string2[])
{
  char *xorStrPtr;
  int counter = 0;
  int fourBitInt[FOUR_BIT_INT_SIZE];
  int fourBitInt2[FOUR_BIT_INT_SIZE];
  int xorResult4BitInt[FOUR_BIT_INT_SIZE];
  int hexInt;
  char hexChar;
  xorStrPtr = new char[SIZE];
  
  // for each char in string1
  //   find xor result with char in string2
  //   convert result to integer in hex
  //   convert integer in hex to char in hex
  //   store in xorResult
  while(string1[counter] != '\0')
  {
    convertHexCharToFourBitInt(string1[counter], fourBitInt);
    convertHexCharToFourBitInt(string2[counter], fourBitInt2);

    // find xor of two four Bit Int arrays, put in xorResult Bit Int array
    xorFourBit(fourBitInt, fourBitInt2, xorResult4BitInt);

    // convert result to hexInt
    hexInt = convertFourBitToHexInt(xorResult4BitInt);
    
    // convert hexInt to hexChar
    hexChar = convertHexIntToHexChar(hexInt);
    
    // store hexChar in xorResult string
    xorStrPtr[counter] = hexChar;

    counter++;
  }

  return xorStrPtr;
}

char convertHexIntToHexChar(int hexInt)
{
  char hexChar;
  switch (hexInt)
  {
    case 10: hexChar = 'a';
             break;
    case 11: hexChar = 'b';
             break;
    case 12: hexChar = 'c';
             break;
    case 13: hexChar = 'd';
             break;
    case 14: hexChar = 'e';
             break;
    case 15: hexChar = 'f';
             break;
    default: hexChar = '0' + hexInt;
             break;
  }
  return hexChar;
}

int convertFourBitToHexInt(int xorResult4BitInt[])
{
  int hexInt = 0;
  int multiplier = pow(2, FOUR_BIT_INT_SIZE - 1);

  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
  {
    hexInt += xorResult4BitInt[i] * multiplier;
    multiplier /= 2;
  }
  return hexInt;
}

void xorFourBit(int fourBitInt[], int fourBitInt2[], int xorResult4BitInt[])
{
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
  {
    if (fourBitInt[i] == 1 && fourBitInt2[i] == 0)
      xorResult4BitInt[i] = 1;
    else if (fourBitInt[i] == 0 && fourBitInt2[i] == 1)
      xorResult4BitInt[i] = 1;
    else
      xorResult4BitInt[i] = 0;
  }
}

void displayFourBitInt(int fourBitInt[])
{
  cout << "fourBitInt is: " << endl;
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
    cout << fourBitInt[i];
  cout << endl;
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

void convertHexIntToFourBitInt(int hexInt, int fourBitInt[])
{
  int divider = pow(2, FOUR_BIT_INT_SIZE - 1);

  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
  {
    fourBitInt[i] = hexInt / divider;
    hexInt = hexInt % divider;
    divider /= 2;
  } 
}

void convertHexCharToFourBitInt(char hexChar, int fourBitInt[])
{
  int hexInt;
  cout << "hexchar is: " << hexChar << endl;
   
  // convert to int
  hexInt = convertHexCharToInt(hexChar);
  cout << "hexInt is: " << hexInt << endl;

  // convert int to fourBitInt
  convertHexIntToFourBitInt(hexInt, fourBitInt);
  cout << "fourBitInt is: " << endl;
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
    cout << fourBitInt[i];
  cout << endl;
}
