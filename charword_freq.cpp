// Name: Juan Perez   Z#:23026404
// Course: COP 3014
// Professor: Dr. Lofton Bullard
// Due Date: 3/13/18     Due Time: 11:59 pm
// Total Points: 20
// Assignment 7: charword_freq.cpp
//
// Description:
// 1. Read the contents of a data file (mytext.dat);
// 2. Process the frequency of characters (a-z) that appear in the data file 3.
// 3. Print the frequency of characters in the file to the screen;
// 4. Be able to use an ifstream object;
// *************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


//function prototypes
string readFile();
void wordCounter();
int letterCounter(char letter);

//main function
int main() {
  char letter;
  readFile();
  wordCounter();

  for (letter = 'a'; letter <= 'z'; letter++) {
    if (letterCounter(letter) != 0) {
      std::cout << std::left << setw(2)<< letterCounter(letter) << " " << letter << endl;
    }
  }


  return 0;
}
//function definitions
string readFile(){
  ifstream inFile;

  inFile.open("mytext.dat");

  string word, sentence =  " ";
  //if file not found print message and exit program
  if (inFile.fail()){
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}
  while (!inFile.eof()){
    while (getline(inFile, word)) {
      sentence = sentence + " " + word;
    }
    std::cout << "Block of text in the data file: " << sentence << '\n';
  }
  inFile.close();
  return sentence;
}

void wordCounter(){
  ifstream inFile;
  inFile.open("mytext.dat");
  int wordCount = 0;
  string word;

  while (inFile >> word) {
    wordCount++;
  }
  cout << wordCount << " words" << endl;
  return;
  inFile.close();
}

int letterCounter(char letter){
  ifstream inFile;
  char c;
  inFile.open("mytext.dat");
  inFile.get(c);

  int letterCount = 0;

  while (!inFile.eof()){
    if (tolower(c) == letter) {
      letterCount++;
    }
    inFile.get(c);
  }
  inFile.close();
  return letterCount;
}
