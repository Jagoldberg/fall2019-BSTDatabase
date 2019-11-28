#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class Simulation{
public:
  Simulation();
  ~Simulation();

  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;
  GenStack<BST<Student>> studentRollback;
  GenStack<BST<Faculty>> facultyRollback;
  fstream sf;
  fstream ff;
  int rollbackCount;


  void Menu();
  void recStudentDisplay(TreeNode<Student>* node);
  void recFacultyDisplay(TreeNode<Faculty>* node);
};
