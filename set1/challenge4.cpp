// Matasano Crypto Challenge 4 - Set 1
// g++ -o challenge4 challenge4.cpp convertHexStringToAscii.cpp findSingleByteXORCipher.cpp freqScore.cpp hexmanip.cpp xorHexStrings.cpp
#include <iostream>
#include <fstream>
#include "findSingleByteXORCipher.h"
#include "freqScore.h"
using namespace std;
const int INPUT_SIZE = 80;
const int MESSAGE_SIZE = 60;

int main()
{
  char datafile[] = "fourData.txt"; 
  char input[] = "0e3647e8592d35514a081243582536ed3de6734059001e3f535ce6271032";
  char *message;
  message = new char[INPUT_SIZE];
  char *bestMessageSoFar;
  bestMessageSoFar = new char[INPUT_SIZE];
  int counter = 0;
  int score = 0;
  int indexOfBestMessage = -1;
  int lowestScore = 111000;

  ifstream inputfile;

  inputfile.open(datafile);

  while(inputfile >> input)
  {
    cout << "Input string " << counter + 1 << " is: " << input << endl;
    cout << "FindSingleByteXORCipher(input) is: " << findSingleByteXORCipher(input);
    message = findSingleByteXORCipher(input);
//    cout << "Message " << counter + 1;
//    cout << " is: " << message << "." << endl;
    score = getFreqScore(message);
    cout << "Score " << counter + 1 << " for message " << message << " is: " << score << endl;
    if(score < lowestScore)
    {
      lowestScore = score;
      indexOfBestMessage = counter;
      bestMessageSoFar = message;
    }
    counter++;
  }

  inputfile.close();

  cout << "Decoded message is: " << bestMessageSoFar << endl;
  cout << " from string number: " << indexOfBestMessage + 1 << endl;

  return(0);
}
