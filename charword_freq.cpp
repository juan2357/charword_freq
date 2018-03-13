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
using namespace std;

//function prototypes
string readFile();

//main function
int main() {

  readFile();

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

  return sentence;

}
