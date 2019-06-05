#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student{
  private:
    string name;
    string no;
    float grade;
    static int goodstudentcount;

  public:
    void getName();
    void getNo();
    void getGrade();
    void getInfo();
    void addStudent(string name, string no, float grade);
    static void computeAveGrade(Student S[], int studentnumber);
    static void queryStudentByName(Student S[], string querystudentname, int studentnumber);
    static void queryStudentByNo(Student S[], string querystudentno, int studentnumber);
    static void sortStudentGrade(Student S[], int studentnumber);
    static bool judgeClass(Student m, Student n);
};





#endif
