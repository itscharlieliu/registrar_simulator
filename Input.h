/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/



#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <fstream>

using namespace std;

class UserInput
{
private:
  int lines;

protected:
  string userInput;
  string fileName;
  void setString();
  ifstream myFile;

public:
  UserInput();
  UserInput(string fileName);
  ~UserInput();


  void addFile(string fileName);
  string getString();
  int getLines();

};


#endif
