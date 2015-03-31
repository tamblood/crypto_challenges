#include<iostream>
#include<cctype>
#include "freqScore.h"
using namespace std;

//int main()
//{
//  int score = 0;
//  char testText[] = "5MjIzM7JwIfq5IDUh8vOzMKHxofXyNLJw4fIwYfFxsTI";
//
//  score = getFreqScore(testText);
//
//  return(0);
//
//}

int getFreqScore(char *testText)
{
  int freqScore = 0;
  int counter = 0;
  char current;
  

  while(testText[counter] != '\0')
  {
    current = testText[counter];

    switch(current)
    {
      case 'e': 
      case 'E':
      case 'a':
      case 'A':
      case 'i':
      case 'I':
      case 'n':
      case 'N':
      case 't':
      case 'T':
      case 'o':
      case 'O': freqScore += 1;
                break;
      case 's': 
      case 'S':
      case 'h':
      case 'H':
      case 'r':
      case 'R':
      case 'd':
      case 'D':
      case 'l':
      case 'L':
      case 'g':
      case 'G':
      case 'u':
      case 'U': freqScore += 2;
                break;
      case 'c':
      case 'C':
      case 'm':
      case 'M':
      case 'f':
      case 'F':
      case 'p':
      case 'P':
      case 'b':
      case 'B': freqScore += 5;
                break;
      case 'j':
      case 'J':
      case 'v':
      case 'V':
      case 'k':
      case 'K':
      case 'y':
      case 'Y': freqScore += 8;
                break;
      case 'q':
      case 'Q':
      case 'w':
      case 'W':
      case 'z':
      case 'Z':
      case 'x':
      case 'X': freqScore += 10;
                break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '0': freqScore += 50;
                break;
      case '!':
      case '{':
      case '}':
      case ']':
      case '[':
      case '^':
      case '|':
      case '~':
      case '%':
      case '+':
      case '-':
      case '#':
      case '*':
      case '_': freqScore += 1000;
                break;

    } 

    counter++;
  }

  cout << "Score is: ";
  cout << freqScore << " Test text is: " << testText << endl ;

  return freqScore;
}


