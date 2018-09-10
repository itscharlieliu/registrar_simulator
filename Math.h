/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#ifndef MATH_H
#define MATH_H

template <class T>
class Math
{
private:
  unsigned int size;

public:
  T *numbers;

  Math()
  {
    size = 0;
  };

  Math(unsigned int s)
  {
    size = s;
    numbers = new T[size];
  };

  ~Math()
  {
    delete numbers;
  };

  unsigned int getSize()
  {
    return size;
  };

  T avg()
  {
    double sum = 0;
    for (unsigned int i = 0; i < size; ++i)
    {
      sum += numbers[i];
    }
    return sum/size;
  };

  T median()
  {
    return numbers[size/2];
  };

  T max()
  {
    T max = numbers[0];
    for (unsigned int i = 1; i < size; ++i)
    {
      if (numbers[i] > max)
      {
        max = numbers[i];
      }
    }
    return max;
  };

  void print()
  {
    for (int i = 0; i < size; ++i)
    {
      cout << numbers[i] << endl;
    }
  }


};


#endif
