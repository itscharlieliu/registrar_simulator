/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#include "Simulation.h"
#include "List.h"

int main(int argc, char const *argv[]) {

  if (argc == 2)
  {
    Simulation s(argv[1]);
  }
  else
  {
    cout << "Please type a filename as a command" << endl;
  }



  return 0;
}
