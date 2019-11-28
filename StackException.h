#include <iostream>

using namespace std;

class StackException{
public:
  StackException(const string& err): errMsg(err){}
  string getError() {return errMsg;}
private:
  string errMsg;
};
