#include <iostream>

using namespace std;

class Faculty{
public:
  int ID;
  string name;
  string level;
  string department;


  Faculty();
  ~Faculty();
  Faculty(int i, string n, string l, string d);

  void getInformation();

  bool operator==(const Faculty& s);
  bool operator<(const Faculty& s);
  bool operator>(const Faculty& s);
  bool operator<=(const Faculty& s);
  bool operator>=(const Faculty& s);
};
