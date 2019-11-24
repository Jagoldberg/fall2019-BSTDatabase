#include <iostream>

using namespace std;

class Faculty{
public:
  int ID;
  string name;
  string level;
  string department;
  int advisorID;

  Student();
  ~Student();
  Student(int i, string n, string l, string m, double g, int a);

  void getInformation();

  bool operator==(const Faculty& s);
  bool operator<(const Faculty& s);
  bool operator>(const Faculty& s);
  bool operator<=(const Faculty& s);
  bool operator>=(const Faculty& s);
};
