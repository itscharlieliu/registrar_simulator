/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Student.h"

class Window
{
public:
  unsigned int idleTime;
  bool isOpen;
  bool isBusy;

  Student student;

  Window();

  ~Window();
};



#endif
