/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#include "Simulation.h"
#include <iostream>



using namespace std;


Simulation::Simulation()
{
  time = 0;
  good = true;
}

Simulation::Simulation(string fileName)
{
  Simulation();
  runSim(fileName);

}

Simulation::~Simulation()
{

}



void Simulation::runSim(string fileName)
{
  input.addFile(fileName);

  if (input.getLines() <= 0)
  {
    good = false;

  }
  if (good)
  {
    //getting the amount of lines in the text file and setting it to an array
    inputArray = new string[input.getLines()];
    int idx = 0;
    for (int i = 0; i < input.getLines(); ++i)
    {
      inputArray[i] = "";
      while (input.getString()[idx] != '\n')
      {
        inputArray[i] += input.getString()[idx];
        ++idx;
      }
      ++idx;
    }
  }

  if (good)
  {
    //initializing all the variables
    if (atoi(inputArray[0].c_str()) <= 5 && atoi(inputArray[0].c_str()) >= 1 && good)
    {
      windowsOpen = atoi(inputArray[0].c_str());
      windows = new Window[5];
      if (windowsOpen <= 5 && windowsOpen > 0)
      {
        for (int i = 0; i < windowsOpen; ++i)
        {
          windows[i].isOpen = true;
        }
      }
    }
    else
    {
      good = false;
      cout << "ERROR: input syntax incorrect. Cannot open more than 5 windows or less than 1 window." << endl;
    }
  }




  //decrypting the array into a queue of students
  for (int i = 1; i < input.getLines() - 1 && good; ++i)
  {
    int t = atoi(inputArray[i++].c_str()); // at time t

    int numStudents = atoi(inputArray[i].c_str());

    //testing to see if syntax is correct
    if (numStudents + i > input.getLines())
    {
      cout << "ERROR: input syntax incorrect. Claimed " << numStudents << " would arrive, but only " << input.getLines() - i -1  << " arrived." << endl;
      i = input.getLines();
      good = false;
      break;
    }
    for (int j = 0; j < numStudents; ++j ) //number of students
    {

      ++i;

      if(atoi(inputArray[i].c_str()) > 0)
      {
        Student s(t, atoi(inputArray[i].c_str())); // creating a new student with arrival time t
        studentQueue.insert(s);
      }
      else
      {
        cout << "ERROR: input syntax incorrect. Unable to wait for 0 or less minutes." << endl;
        good = false;
      }
    }

  }

  if (good)
  {
  time = 0;

  int numStudents = studentQueue.getSize();
  int studentsDone = 0;



  cout << "\nStarting simulation...\n";

  //the actual simulation
  while(good && (!studentQueue.isEmpty() || studentsDone < numStudents))
  {
    cout << "Time is now " << time << endl;
    for (int i = 0; i < windowsOpen; ++i)
    {


      //incrementing time for each student at a window and removing students who have 0 time left
      if (windows[i].isBusy)
      {
        windows[i].student.timeLeft--;
        if (windows[i].student.timeLeft <= 0)
        {
          finishedStudents.insert(windows[i].student);
          windows[i].isBusy = false;
          studentsDone++;
          cout << "Student left window " << i+1 << endl;
        }


      }
      else
      {
        windows[i].idleTime++;
      }



      //simulating the arrival of each student
      if (!studentQueue.isEmpty() && studentQueue.peek().arrivalTime <= time)
      {
        if (windows[i].isOpen && !windows[i].isBusy)
        {

          windows[i].student = studentQueue.remove();
          windows[i].isBusy = true;
          windows[i].student.waitTime = time - windows[i].student.arrivalTime; //setting the waittime for each student
          cout << "Student arrived at window " << i + 1 << " for " << windows[i].student.timeLeft << " minutes after waiting " << windows[i].student.waitTime << " minutes." << endl;
        }
      }
    }
    ++time;


  }

  if (good)
  {
    cout << "End simulation\n" << endl;
    calculate();
  }


  delete[] inputArray;
}
}

void Simulation::calculate()
{
  //calculating stats for students wait time
  Math<float> s(finishedStudents.getSize());
  int temp = 0;
  for (unsigned int i = 0; i < s.getSize(); ++i)
  {
    s.numbers[i] = (float)finishedStudents.remove().waitTime;
    if (s.numbers[i] > 10)
    {
      ++temp;
    }
  }

  cout << "Mean student wait time: " << s.avg() << " minutes" << endl;
  cout << "Median student wait time: " << s.median() << " minutes" << endl;
  cout << "Longest student wait time: " << s.max() << " minutes" << endl;
  cout << "The number of students waiting over 10 minutes: " << temp << endl;


  Math<float> w(windowsOpen);
  temp = 0;
  for (unsigned int i = 0; i < w.getSize(); ++i)
  {
    w.numbers[i] = (float)windows[i].idleTime;
    if (w.numbers[i] > 5)
    {
      ++temp;
    }
  }

  cout << "\nMean window idle time: " << w.avg() << " minutes" << endl;
  cout << "Longest window wait time: " << w.max() << " minutes" << endl;
  cout << "Number of windows idle for over 5 minutes: " << temp << endl << endl;
}


bool Simulation::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
