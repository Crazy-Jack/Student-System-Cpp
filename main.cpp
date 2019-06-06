#include <iostream>
#include <string>

#include "student.h"

using namespace std;

int main()
{
  string name1 = "Zhang";
  string name2 = "Z";
  string no1 = "1234";
  string no2 = "4321";
  float grade1 = 33.3;
  float grade2 = 100;
  Student s1;
  Student s2;

  
  // test for addStudentInfo();
  //void addStudent(string name, string no, float grade);
  s1.addStudent(name1, no1, grade1);
  s2.addStudent(name2, no2, grade2);
  // test for getInfo()
  s1.getInfo();

  // test for computeAve():
  Student Ss[2] = {s1, s2};
  Student::computeAveGrade(Ss, 2);

  // test for queryName
  cout << "Test for queryName: " << endl;
  Student::queryStudentByName(Ss, "Zhang", 2);

  // test for queryNo
  cout << "Test for queryNo: " << endl;
  Student::queryStudentByNo(Ss, "4321", 2);
  Student::queryStudentByNo(Ss, "0004321", 2);

  // test for sorting
  cout << "Test for sorting: " << endl;
  Student::sortStudentGrade(Ss, 2);

  // test for removeSpecial
  cout << "Test for remove specail" << endl;
  string tttt = "2232e3rd";
  cout << "Test origin string: " << tttt << endl;
  cout << "Remove '2' : " << Student::removeSpecial(tttt, '2') << endl;
  cout << "Remove '3' : " << Student::removeSpecial(tttt, '3') << endl;
  cout << "Remove 'e' : " << Student::removeSpecial(tttt, 'e') << endl;
  cout << "Remove 'd' : " << Student::removeSpecial(tttt, 'd') << endl;


  // test for checkValidGrade
  cout << "Test for checkvalidgrade" << endl;
  cout << "Valid?<20.2>: " << Student::checkValidGrade("20.2") << endl;
  cout << "Valid?<20.e2>: " << Student::checkValidGrade("20.e2") << endl;
  cout << "Valid?<20e.2>: " << Student::checkValidGrade("20e.2") << endl;
  cout << "Valid?<e2>: " << Student::checkValidGrade("e2") << endl;
  cout << "Valid?<2d>: " << Student::checkValidGrade("2d") << endl;
  cout << "Valid?<233d2>: " << Student::checkValidGrade("233d2") << endl;

  // test for checkValidNumber
  cout << "Test for checkValidNumber" << endl;
  cout << "Valid?<20.3>: " << Student::checkValidNumber("20.3") << endl;
  cout << "Valid?<20>: " << Student::checkValidNumber("20") << endl;
  cout << "Valid?<3>: " << Student::checkValidNumber("3") << endl;
  cout << "Valid?<3ed>: " << Student::checkValidNumber("3ed") << endl;
  cout << "Valid?<e>: " << Student::checkValidNumber("e") << endl;





  // (1) input student number
  int n;
    cout << "(1) Input of student number: " ;
    cin >> n;
    cin.ignore();
    cout << endl;

  // (2) get student info
  cout << "(2) Add student information.";
  string studentinfo;
  Student S[n];
  for (int i=0; i < n; i++) 
  {
    try
    {
      cout << "Input Information for student " << i + 1 << " : ";
      getline(cin, studentinfo);
      studentinfo = Student::removeSpecial(studentinfo, ' ');

      char delimiter = ',';
      // check for delimiter times
      int dtimes = count(studentinfo.begin(), studentinfo.end(), delimiter);
      if (dtimes != 2) {throw std::invalid_argument("Not enough delimiter");};
      
      // get name
      string name = studentinfo.substr(0, studentinfo.find(delimiter));
      studentinfo.erase(0, studentinfo.find(delimiter) + 1);

      string no = studentinfo.substr(0, studentinfo.find(delimiter));
      studentinfo.erase(0, studentinfo.find(delimiter) + 1);

      // check grade is valid
      if (!Student::checkValidGrade(studentinfo)) {throw std::invalid_argument("Invalid grade");};
      float grade = stof(studentinfo);

      // Add student info
      S[i].addStudent(name, no, grade);

      // Confirmation of adding student info
      cout << "Your has successfully input student " << i + 1 << endl;
      S[i].getInfo();

      // update good Student count
      if (grade > 90)
      {
        Student::addGoodCount();
      };


    } catch (std::exception& e)
    {
      cout << e.what() << ", please try agagin ... " << endl;
      i--;
    };
  };
  cout << endl;


  // (3) Output Good Student count (Grade > 90)
  cout << "(3) Number of Good Students (Grade > 90): " << Student::getGoodCount() << endl;
  cout << endl;

  // (4) Compute the Average Score
  cout << "(4) Compute the Average Grade of input students: " << endl;
  Student::computeAveGrade(S, n);
  cout << endl;

  // (5) Sorting
  cout << "(5) Sorting by Grade:" << endl;
  Student::sortStudentGrade(S, n);
  cout << endl;

  // (6) query by name
  cout << "(6) Query by Name: ";
  string queryname;
  cin >> queryname;
  cin.ignore();
  Student::queryStudentByName(S, queryname, n);
  cout << endl;

  // (7) query by no
  cout << "(7) Query by No.: ";
  string queryno;
  cin >> queryno;
  cin.ignore();
  Student::queryStudentByNo(S, queryno, n);
  cout << endl;

};



