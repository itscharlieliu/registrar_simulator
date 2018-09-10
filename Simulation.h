/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Input.h"
#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "Math.h"
#include <cstdlib>

class Simulation
{
private:
  bool good;

  int windowsOpen;
  int time;
  UserInput input;
  string *inputArray;

  Window *windows;
  Queue<Student> studentQueue;
  Queue<Student> finishedStudents;

  void calculate();



  bool is_number(const std::string& s); //https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

public:
  Simulation();
  Simulation(string fileName);
  ~Simulation();


  void runSim(string fileName);





};



#endif
