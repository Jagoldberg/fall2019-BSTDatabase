#include "Faculty.h"
#include <iostream>
#include <list>

using namespace std;

Faculty::Faculty(){
  ID = -1;
  name = "";
  level = "";
  department = "";

}

Faculty::~Faculty(){

}

Faculty::Faculty(int i, string n, string l, string d){
  ID = i;
  name = n;
  level = l;
  department = d;

}

void Faculty::getInformation(){
  cout << "Faculty" << endl;
  cout << "ID: " << ID << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
}

void Faculty::addAdvisee(int i){
  advisees.push_front(i);
}

int Faculty::printAdvisee(int id){
  for(std::list<int>::iterator it = advisees.begin(); it != advisees.end(); ++it){
    if(*it == id){
      return *it;
    }
  }
  return -1;//id not in the list
}

bool Faculty::operator==(const Faculty& f){
  bool IDCheck = (ID == f.ID);
  return(IDCheck);
}
bool Faculty::operator<(const Faculty& f){
  bool IDCheck = (ID < f.ID);
  return(IDCheck);
}
bool Faculty::operator>(const Faculty& f){
  bool IDCheck = (ID > f.ID);
  return(IDCheck);
}
bool Faculty::operator<=(const Faculty& f){
  bool IDCheck = (ID <= f.ID);
  return(IDCheck);
}
bool Faculty::operator>=(const Faculty& f){
  bool IDCheck = (ID >= f.ID);
  return(IDCheck);
}
