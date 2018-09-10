/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
  int timeLeft;
  int waitTime;
  int arrivalTime;

  Student();
  Student(int at, int timeNeeded); // arrival time
  ~Student();

  bool operator ==(const Student &s1);
  bool operator !=(const Student &s1);
};



#endif
