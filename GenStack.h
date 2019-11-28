#include <iostream>
#include "StackException.h"

using namespace std;

template <typename E>
class GenStack
{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); // overloaded constructor
    ~GenStack(); //destructor

    void push(E d);
    E pop();
    E peek(); //AKA top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    E *myArray;
};

template <typename E>GenStack<E>::GenStack()//default constructor
{
  //Initilization of default values
  myArray = new E[128];
  size = 128;
  top = -1;
}

template <typename E>GenStack<E>::GenStack(int maxSize)
{
  myArray = new E[maxSize];
  size = maxSize;
  top = -1;
}

template <typename E>GenStack<E>::~GenStack()
{
  if(isEmpty()){
    delete [] myArray;
  }
}

template <typename E> void GenStack<E>::push(E d)
{
  //need to check error/boundary check
  //this is your job
  if (!isFull()){
    myArray[++top] = d;
  } else {
    throw StackException("Array is full, cannot add new values");
  }
}

template <typename E> E GenStack<E>::pop(){
  //error checking, make sure its not isEmpty
  if(!isEmpty()){
    return myArray[top--];
  } else {
    throw StackException("Stack is empty, nothing to return");
  }

}

template <typename E> E GenStack<E>::peek()
{
  //check if empty
  if(!isEmpty()){
    return myArray[top];
  } else {
    throw StackException("Stack is empty, nothing to return");
  }
}

template <typename E> bool GenStack<E>::isFull()
{
  return (top == size-1);
}

template <typename E> bool GenStack<E>::isEmpty()
{
  return (top == -1);
}
