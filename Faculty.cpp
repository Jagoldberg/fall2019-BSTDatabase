#include "Faculty.h"
#include <iostream>

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
