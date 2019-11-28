#include "Simulation.h"

using namespace std;


Simulation::Simulation(){
  sf.open("studentTable", ios::in|ios::out|ios::binary);
  ff.open("facultyTable", ios::in|ios::out|ios::binary);

  if(!sf.eof()){
    sf.read((char*) &masterStudent,sizeof(masterStudent));
  }
  if(!ff.eof()){
    ff.read((char*) &masterFaculty, sizeof(masterFaculty));
  }
  rollbackCount = 0;
}

Simulation::~Simulation(){
  sf.close();
  ff.close();
  delete &masterFaculty;
  delete &masterStudent;
  delete &studentRollback;
  delete &facultyRollback;
}

void Simulation::Menu(){
  int userChoice = 0;
  bool recIndicator = true;
  cout << "Displaying Database Menu: " << endl;
  cout << "1: Print all students and their information (sorted by ascending ID)" << endl;
  cout << "2: Print all faculty and their information (sorted by ascending ID)" << endl;
  cout << "3: Find and display student information given the students ID" << endl;
  cout << "4: Find and display faculty information given the faculty ID" << endl;
  cout << "5: Given a student's ID, print the name and info of their faculty ID" << endl;
  cout << "6: Given a faculty ID, print all the names and info of their advisees" << endl;
  cout << "7: Add a new student" << endl;
  cout << "8: Delete a student given the ID" << endl;
  cout << "9: Add a new faculty member" << endl;
  cout << "10: Delete a faculty member given the ID" << endl;
  cout << "11: Change a student's advisor given the student ID and the new faculty ID" << endl;
  cout << "12: Remove an advisee from a faculty member given the IDs" << endl;
  cout << "13: Rollback" << endl;
  cout << "14: Exit" << endl;
  cout << "Enter the menu number to execute the respective operation" << endl;
  cin >> userChoice;

  switch(userChoice){
    case 1:
      {
        recStudentDisplay(masterStudent.getRoot());
        break;
      }
    case 2:
      {
        recFacultyDisplay(masterFaculty.getRoot());
        break;
      }
    case 3:
      {
        int ID;
        cout << "Enter the ID of the student you would like to display: " << endl;
        cin >> ID;
        Student s = masterStudent.search(ID);
        Student s2; //A default student(equivalent to if no information has been entered)
        if (s != s2){
          s.getInformation();
        } else {
          cout << "Student not present in the database" << endl;
        }
        break;
      }
    case 4:
      {
        int ID;
        cout << "Enter the ID of the faculty you would like to display: " << endl;
        cin >> ID;
        Faculty f = masterFaculty.search(ID);
        Faculty f2; //A default faculty(equivalent to if no information has been entered)
        if (f != f2){
          f.getInformation();
        } else {
          cout << "Faculty not present in the database" << endl;
        }
        break;
      }
    case 5:
      {
        int ID;
        cout << "Enter a student ID: " << endl;
        cin >> ID;
        Student s = masterStudent.search(ID);
        Student s2;
        if(s == s2){
          cout << "Student not present in the database" << endl;
        } else {
          Faculty f = masterFaculty.search(s.advisorID);
          f.getInformation();
        }
        break;
      }
    case 6:
      {
        int ID;
        cout << "Enter a Faculty ID: " << endl;
        cin >> ID;
        Faculty f = masterFaculty.search(ID);
        Faculty f2;
        if (f == f2){
          cout << "Faculty not present in the database" << endl;
        } else {
          for(std::list<int>::iterator it = f.advisees.begin(); it != f.advisees.end(); ++it){
            Student s = masterStudent.search(*it);
            s.getInformation();
          }
        }
        break;
      }
    case 7:
      {
        try{
          studentRollback.push(masterStudent);
        } catch (StackException e){

        }
        if(rollbackCount > 0){
          rollbackCount--;
        }
        int ID;
        string name;
        string level;
        string major;
        double GPA;
        int advisorID;
        cout << "Enter a student ID: " << endl;
        cin >> ID;
        cout << "Enter the student's name: " << endl;
        cin >> name;
        cout << "Enter the student's level(Freshman, Sophomore, etc.): " << endl;
        cin >> level;
        cout << "Enter the student's major: " << endl;
        cin >> major;
        cout << "Enter the student's GPA: " << endl;
        cin >> GPA;
        cout << "Enter the ID of the student's faculty advisor: " << endl;
        cin >> advisorID;
        Faculty f2;
        if(masterFaculty.search(ID) == f2){
          cout << "Invalid Faculty ID, aborting";
          break;
        }
        if(masterStudent.search(ID) == Student(ID, name, level, major, GPA, advisorID)){//checks if a student with that ID already exists in the database
          cout << "A student with that information already exists in the database, aborting" << endl;
          break;
        }
        masterStudent.insert(ID, Student(ID, name, level, major, GPA, advisorID));
        Faculty f = masterFaculty.search(advisorID);
        if(f.printAdvisee(ID) == -1){
          f.addAdvisee(ID);
        }
        break;
      }
    case 8:
      {
        try{
          studentRollback.push(masterStudent);
        } catch (StackException e){

        }
        if(rollbackCount > 0){
          rollbackCount--;
        }
        int ID;
        cout << "Enter the ID of the student to be deleted" << endl;
        cin >> ID;
        Student s = masterStudent.search(ID);
        Student s2;
        if(s == s2){
          cout << "Student not in database, aborting" << endl;
          break;
        } else{
          Faculty f = masterFaculty.search(s.advisorID);
          f.removeAdvisee(ID);
          masterStudent.deleteNode(ID);
        }
        break;
      }
    case 9:
      {
        try{
          facultyRollback.push(masterFaculty);
        } catch (StackException e){

        }
        if(rollbackCount > 0){
          rollbackCount--;
        }
        int ID;
        string name;
        string level;
        string department;
        cout << "Enter a faculty ID: " << endl;
        cin >> ID;
        cout << "Enter the faculty's name: " << endl;
        cin >> name;
        cout << "Enter the faculty's level(Freshman, Sophomore, etc.): " << endl;
        cin >> level;
        cout << "Enter the faculty's department: " << endl;
        cin >> department;
        if(masterFaculty.search(ID) == Faculty(ID, name, level, department)){//checks if a student with that ID already exists in the database
          cout << "A Faculty with that information already exists in the database, aborting" << endl;
          break;
        }
        masterFaculty.insert(ID, Faculty(ID, name, level, department));
        break;
      }
    case 10:
      {
        try{
          facultyRollback.push(masterFaculty);
        } catch (StackException e){

        }
        if(rollbackCount > 0){
          rollbackCount--;
        }
        int facultyID;
        cout << "Enter the ID of the faculty to be deleted" << endl;
        cin >> facultyID;
        Faculty f = masterFaculty.search(facultyID);
        Faculty f2;
        if (f == f2){
          cout << "Faculty not in the database, aborting" << endl;
          break;
        } else {
          int advisorID;
          cout << "This faculty member has advisees who need to be reassigned. Enter the new ID of the advisor";
          cin >> advisorID;
          Faculty f3 = masterFaculty.search(advisorID);
          if(f3 == f2){
            cout << "Invalid ID, aborting" << endl;
            break;
          } else {
            for(std::list<int>::iterator it = f.advisees.begin(); it != f.advisees.end(); ++it){
              Student s = masterStudent.search(*it);
              s.advisorID = advisorID;
            }
          }
          masterFaculty.deleteNode(facultyID);
        }
        break;
      }
    case 11:
      {
        int studentID;
        cout << "Enter the student ID whose advisor needs to be changed: " << endl;
        cin >> studentID;
        Student s = masterStudent.search(studentID);
        Student s2;
        if(s == s2){
          cout << "Student not found, aborting" << endl;
          break;
        }
        Faculty f = masterFaculty.search(s.advisorID);
        f.removeAdvisee(studentID);
        int advisorID;
        cout << "Enter the ID of the new faculty advisor" << endl;
        cin >> advisorID;
        Faculty f2 = masterFaculty.search(advisorID);
        Faculty f3;
        if (f2 == f3){
          cout << "Faculty not present in the database, aborting" << endl;
          break;
        }
        f2.removeAdvisee(studentID);
        s.advisorID = advisorID;
        break;
      }
    case 12:
      {
        int facultyID;
        cout << "Enter the ID of the faculty member: " << endl;
        cin >> facultyID;
        Faculty f = masterFaculty.search(facultyID);
        Faculty f2;
        if (f == f2){
          cout << "Faculty not in database, aborting" << endl;
          break;
        } else {
          int adviseeID;
          cout << "Enter the ID of the advisee to be removed: " << endl;
          cin >> adviseeID;
          Student s = masterStudent.search(adviseeID);
          Student s2;
          if (s == s2){
            cout << "Student not found in database, aborting";
            break;
          } else{
            int newAdvisorID;
            cout << "Enter the ID of the advisee's new advisor: " << endl;
            cin >> newAdvisorID;
            Faculty f3 = masterFaculty.search(newAdvisorID);
            if (f3 == f2){
              cout << "New faculty not in database, aborting";
              break;
            } else {
              s.advisorID = newAdvisorID;
              f.removeAdvisee(adviseeID);
            }
          }
        }
        break;
      }
    case 13:
      {
        if(rollbackCount < 5){
          int rollChoice;
          cout << "Rollback (1)Student, (2)Faculty, or (3)both databases? Enter the corresponding number" << endl;
          cin >> rollChoice;
          switch (rollChoice) {
            case 1:
              masterStudent = studentRollback.pop();
              break;
            case 2:
              masterFaculty = facultyRollback.pop();
              break;
            case 3:
              masterStudent = studentRollback.pop();
              masterFaculty = facultyRollback.pop();
              break;
            default:
              cout << "Invalid option, aborting" << endl;
              break;
          }
          rollbackCount++;
        } else{
          cout << "Rollback has been executed 5 times in a row, cannot roll back any further";
        }
        break;
      }
    case 14:
      {
        sf.write((char*) &masterStudent,sizeof(masterStudent));
        ff.read((char*) &masterFaculty, sizeof(masterFaculty));
        recIndicator = false;
      }
    default:
      cout << "Invalid Choice!" << endl;
  }
  if(recIndicator){
    Menu();
  }
}

void Simulation::recStudentDisplay(TreeNode<Student>* node){
  if(node == NULL){
    return;
  }

  recStudentDisplay(node -> left);
  node -> value.getInformation();
  recStudentDisplay(node -> right);
}

void Simulation::recFacultyDisplay(TreeNode<Faculty>* node){
  if(node == NULL){
    return;
  }

  recFacultyDisplay(node -> left);
  node -> value.getInformation();
  recFacultyDisplay(node -> right);
}
