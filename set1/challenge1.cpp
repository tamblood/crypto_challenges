// Matasano crypto challenges - Set 1 - Challenge 1

#include<iostream>
#include<cmath>     // for pow function
using namespace std;

const int SIZE = 120;
const int FOUR_BIT_INT_SIZE = 4;
const int HEX_SIX_SIZE = 6;
const int TWENTY_FOUR_BIN_SIZE = 24;

char *convertHexStringToBase64String(char hexString[]);
int getNextHexSixChar(char hexString[], char hexSixChar[], int indexStartAt, int numCharsToGet);
void convertHexSixCharToTwentyFourBin(char hexSixChar[], int twentyFourBin[]);
void convertHexCharToFourBitInt(char hexChar, int fourBitInt[]);
int convertHexCharToHexInt(char hexChar);
void convertHexIntToFourBitInt(int hexInt, int fourBitInt[]);
void displayBitInt(int bitInt[], int size);
void appendIntArray(int twentyFourBin[], int fourBitInt[], int startAt); 
void convertTwentyFourBinToFourBase64(int twentyFourBin[], char fourBase64[]);
void getNextSixBitInt(int twentyFourBin[], int sixBitInt[], int startAt);
void appendCharArray(char base64Str[], char fourBase64[], int startAppendAt, int numCharsAppend);
char convertBase64IntToBase64Char(int base64Int);
int convertSixBitIntToInt(int sixBitInt[]);

int main()
{
  char hexString[SIZE] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  char base64String[SIZE];

  cout << convertHexStringToBase64String(hexString) << endl;

  return(0);
}

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

void appendIntArray(int twentyFourBin[], int fourBitInt[], int startAt) 
{
  for(int i = 0; i < FOUR_BIT_INT_SIZE; i++)
    twentyFourBin[i + startAt] = fourBitInt[i];
}

void convertHexSixCharToTwentyFourBin(char hexSixChar[], int twentyFourBin[])
{
  int fourBitInt[FOUR_BIT_INT_SIZE];
  int twentyFourBitInt[TWENTY_FOUR_BIN_SIZE];
  int startAt = 0;

  // for each group of HexSixChar
  //   convert hex to four bit int
  //   append onto twentyfourbit int
  for (int i = 0; i < HEX_SIX_SIZE; i++)
  {
    convertHexCharToFourBitInt(hexSixChar[i], fourBitInt);
    appendIntArray(twentyFourBin, fourBitInt, startAt); 
    startAt += FOUR_BIT_INT_SIZE;
  }

  cout << "TwentyFourBin is: " << endl;
  displayBitInt(twentyFourBin, TWENTY_FOUR_BIN_SIZE);
  
}

int getNextHexSixChar(char hexString[], char hexSixChar[], int indexStartAt, int numCharsToGet)
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
      hexSixChar[i] = hexString[i + indexStartAt];
      counter++;
    }
  }
  return counter; // returns how many chars read
}

void getNextSixBitInt(int twentyFourBin[], int sixBitInt[], int startAt)
{
  for(int i = 0; i < HEX_SIX_SIZE; i++)
    sixBitInt[i] = twentyFourBin[i + startAt];
}

int convertSixBitIntToInt(int sixBitInt[])
{
  // multiplier starts at 32 for most significant six bit digit
  int multiplier = pow(2, HEX_SIX_SIZE - 1);
  int base64Int = 0;

  for(int i = 0; i < HEX_SIX_SIZE; i++)
  {
    base64Int += sixBitInt[i] * multiplier;
    multiplier /= 2;
  }
  return base64Int;
}

char convertBase64IntToBase64Char(int base64Int)
{
  char base64Char;

  if(base64Int >= 0 && base64Int < 26)
    base64Char = 'A' + base64Int;
  else if(base64Int >= 26 && base64Int < 52)
    base64Char = 'a' + base64Int - 26;
  else if(base64Int >= 52 && base64Int < 62)
    base64Char = '0' + base64Int - 52;
  else if(base64Int == 62)
    base64Char = '+';
  else if(base64Int == 63)
    base64Char = '/';
  else // error
    base64Char = '!';
    
  return base64Char;
}

void convertTwentyFourBinToFourBase64(int twentyFourBin[], char fourBase64[])
{
  int sixBitInt[HEX_SIX_SIZE];
  int startAt = 0;
  int base64Int = 0;
  char base64Char;

  // find number of six bit ints in twenty four bin
  int numSixBitInts = TWENTY_FOUR_BIN_SIZE / HEX_SIX_SIZE;

  // for each six bit int 
  for(int i = 0; i < numSixBitInts; i++)
  {
    // get six bit int
    getNextSixBitInt(twentyFourBin, sixBitInt, startAt);
    cout << "sixBitInt is: " << endl;
    displayBitInt(sixBitInt, HEX_SIX_SIZE);
    // convert six bit int to int
    base64Int = convertSixBitIntToInt(sixBitInt);
    cout << "base64Int is: " << base64Int << endl;

    // convert base64Int to base64Char
    base64Char = convertBase64IntToBase64Char(base64Int);
    cout << "base64Char is: " << base64Char << endl;

    // append to fourBase64 
    fourBase64[i] = base64Char;

    startAt += HEX_SIX_SIZE;
  }

}

void appendCharArray(char base64Str[], char fourBase64[], int startAppendAt, int numCharsAppend)
{
  for(int i = 0; i < numCharsAppend; i++)
    base64Str[i + startAppendAt] = fourBase64[i];
}

char *convertHexStringToBase64String(char hexString[])
{
  char *base64StrPtr;
  base64StrPtr = new char[SIZE];
  char hexSixChar[HEX_SIX_SIZE + 1];
  char fourBase64[FOUR_BIT_INT_SIZE];
  int indexStartAt = 0;
  int twentyFourBin[TWENTY_FOUR_BIN_SIZE];
  int startAppendAt = 0;
  int numCharsAppend = FOUR_BIT_INT_SIZE;

  while(getNextHexSixChar(hexString, hexSixChar, indexStartAt, HEX_SIX_SIZE) == HEX_SIX_SIZE)
  {
    cout << "hexSixChar is : " << hexSixChar << endl;
    convertHexSixCharToTwentyFourBin(hexSixChar, twentyFourBin);
    convertTwentyFourBinToFourBase64(twentyFourBin, fourBase64);
    appendCharArray(base64StrPtr, fourBase64, startAppendAt, numCharsAppend);
    
    startAppendAt += FOUR_BIT_INT_SIZE;
    indexStartAt += HEX_SIX_SIZE;
  }
  

  return base64StrPtr;
}
