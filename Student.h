#include <iostream>

using namespace std;

class Student{
public:
  int ID;
  string name;
  string level;
  string major;
  double GPA;
  int advisorID;

  Student();
  ~Student();
  Student(int i, string n, string l, string m, double g, int a);

  void getInformation();

  bool operator==(const Student& s);
  bool operator<(const Student& s);
  bool operator>(const Student& s);
  bool operator<=(const Student& s);
  bool operator>=(const Student& s);
  bool operator!=(const Student& s);
};
