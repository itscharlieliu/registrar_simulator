/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#include "Student.h"

Student::Student()
{
  waitTime = 0;
  timeLeft = 0;
  arrivalTime = 0;
}

Student::Student(int at, int timeNeeded)
{
  Student();
  arrivalTime = at;
  timeLeft = timeNeeded;
}

Student::~Student()
{

}

bool Student::operator==(const Student &s1)
{
  if(s1.waitTime == 1)
  {
  }
  return false;
}
bool Student::operator!=(const Student &s1)
{
  if(s1.waitTime == 1)
  {
  }
  return true;
}
