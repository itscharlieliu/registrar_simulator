/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC 350-02
Assignment 4 - Registrar Simulator
*/

#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <class T>
class ListNode
{


public:
  ListNode *next;
  ListNode *prev;
  T data;

  ListNode()
  {
    next = NULL;
    prev = NULL;
  };
  ListNode(T d)
  {
    ListNode();
    data = d;
  };
  ~ListNode()
  {

  };




};




#endif
