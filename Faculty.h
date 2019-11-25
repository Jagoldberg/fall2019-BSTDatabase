#include <iostream>
#include <list>

using namespace std;

class Faculty{
public:
  int ID;
  string name;
  string level;
  string department;
  std::list<int> advisees;

  Faculty();
  ~Faculty();
  Faculty(int i, string n, string l, string d);

  void getInformation();
  void addAdvisee(int i);
  int printAdvisee(int id);

  bool operator==(const Faculty& f);
  bool operator<(const Faculty& f);
  bool operator>(const Faculty& f);
  bool operator<=(const Faculty& f);
  bool operator>=(const Faculty& f);
};
