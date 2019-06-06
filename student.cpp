#include "student.h"
int Student::goodstudentcount = 0;

string Student::getName()
{
  return this -> name;
};

string Student::getNo()
{
  return this -> no;
};

float Student::getGrade()
{
  return this -> grade;
};



void Student::getInfo()
{
  cout << "Student Information: " << endl;
  cout << "  Name: " << getName() << endl;
  cout << "  No.: " << getNo() << endl;
  cout << "  Grade: " << getGrade() << endl;
};


void Student::addStudent(string name, string no, float grade)
{
  this -> name = name;
  this -> no = no;
  this -> grade = grade;
};

void Student::computeAveGrade(Student S[], int studentnumber)
{
  int all = 0;
  for (int i=0; i < studentnumber; i++){
    all += S[i].getGrade();
  };
  cout << "Average: " << (float) all / studentnumber << endl;
};

void Student::queryStudentByName(Student S[], string querystudentname, int studentnumber)
{
  // query Student by Name
  int found = 0;
  for (int i=0; i < studentnumber; i++){
    if (S[i].getName() == querystudentname){
      S[i].getInfo();
      found = 1;
      break;
    };
  };

  if (found == 0) {
    cout << "Sorry, Student Name: " << querystudentname << " is not found..." << endl;
  };
};
void Student::queryStudentByNo(Student S[], string querystudentno, int studentnumber)
{
  // query Student by Name
  int found = 0;
  for (int i=0; i < studentnumber; i++){
    if (S[i].getNo() == querystudentno){
      S[i].getInfo();
      found = 1;
      break;
    };
  };

  if (found == 0) {
    cout << "Sorry, Student No. " << querystudentno << " is not found..." << endl;
  };
};


void Student::sortStudentGrade(Student S[], int studentnumber)
{
  sort(S, S + studentnumber, judgeClass);

  for (int i=0; i < studentnumber; i++){
    // print out the sorted results
    cout << "  " << S[i].getName() << " (" << S[i].getGrade() << ") " << endl;
  };
};


bool Student::judgeClass(Student m, Student n)
{
  // rules for sorting
  if (m.getGrade() > n.getGrade())
  {
    return 1;
  } else {
    return 0;
  };
};



string Student::removeSpecial(string m, char special)
{
  // helper function for remove special characters like blank space in string
  if (m.size() == 0)
  {
    return "";
  } else if (m[0] == special)
  {
    string newString(m.begin() + 1, m.end());
    return removeSpecial(newString, special);
  } else
  {
    string newString(m.begin() + 1, m.end());
    return m[0] + removeSpecial(newString, special);
  };
};

bool Student::checkValidGrade(string m)
{
  // check string of grade is valid
  regex r(".*([a-zA-Z]+).*");
  if (regex_match(m, r) || (count(m.begin(), m.end(), '.') > 1))
  {
    return 0;
  } else
  {
    return 1;
  };
};



void Student::addGoodCount()
{
  Student::goodstudentcount += 1;
};
int Student::getGoodCount()
{
  return Student::goodstudentcount;
};



bool Student::checkValidNumber(string m)
{
  // check m is digits only
  regex r("[\\d]+");
  return (regex_match(m, r));
};
