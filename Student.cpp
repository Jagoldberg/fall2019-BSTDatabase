#include "Student.h"
#include <iostream>

using namespace std;


Student::Student(){
  ID = -1;
  name = "";
  level = "";
  major = "";
  GPA = -1.0f;
  advisorID = -1;
}

Student::~Student(){

}

Student::Student(int i, string n, string l, string m, double g, int a){
  ID = i;
  name = n;
  level = l;
  major = m;
  GPA = g;
  advisorID = a;
}

void Student::getInformation(){
  cout << "----------Student------------" << endl;
  cout << "Name: " << name << endl;
  cout << "ID: " << ID << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << GPA << endl;
  cout << "Advisor ID: " << advisorID << endl;
}

bool Student::operator==(const Student& s){
  bool IDCheck = (ID == s.ID);
  bool nameCheck = (name == s.name);
  bool levelCheck = (level == s.level);
  bool majorCheck = (major == s.major);
  bool GPACheck = (GPA == s.GPA);
  bool advisorCheck = (advisorID == s.advisorID);

  return (IDCheck && nameCheck && levelCheck && majorCheck && GPACheck && advisorCheck);
}

bool Student::operator<(const Student& s){
  bool IDCheck = (ID < s.ID);
  //bool nameCheck = (name < s.name);
  //bool levelCheck = (level < s.level);
  //bool majorCheck = (major < s.major);
  bool GPACheck = (GPA < s.GPA);
  bool advisorCheck = (advisorID < s.advisorID);

  return (IDCheck && nameCheck && levelCheck && majorCheck && GPACheck && advisorCheck);
}

bool Student::operator>(const Student& s){
  bool IDCheck = (ID > s.ID);
  //bool nameCheck = (name > s.name);
  //bool levelCheck = (level > s.level);
  //bool majorCheck = (major > s.major);
  bool GPACheck = (GPA > s.GPA);
  bool advisorCheck = (advisorID > s.advisorID);

  return (IDCheck && nameCheck && levelCheck && majorCheck && GPACheck && advisorCheck);
}

bool Student::operator<=(const Student& s){
  bool IDCheck = (ID <= s.ID);
  //bool nameCheck = (name <= s.name);
  //bool levelCheck = (level <= s.level);
  //bool majorCheck = (major <= s.major);
  bool GPACheck = (GPA <= s . GPA);
  bool advisorCheck = (advisorID <= s.advisorID);

  return (IDCheck && nameCheck && levelCheck && majorCheck && GPACheck && advisorCheck);
}

bool Student::operator>=(const Student& s){
  bool IDCheck = (ID >= s.ID);
  //bool nameCheck = (name >= s.name);
  //bool levelCheck = (level >= s.level);
  //bool majorCheck = (major >= s.major);
  bool GPACheck = (GPA >= s.GPA);
  bool advisorCheck = (advisorID >= s.advisorID);

  return (IDCheck && nameCheck && levelCheck && majorCheck && GPACheck && advisorCheck);
}
