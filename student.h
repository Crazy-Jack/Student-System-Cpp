#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

class Student{
  private:
    string name;
    string no;
    float grade;
    static int goodstudentcount;
    static bool judgeClass(Student m, Student n);

  public:
    string getName();
    string getNo();
    float getGrade();
    void getInfo();
    void addStudent(string name, string no, float grade);
    static void computeAveGrade(Student S[], int studentnumber);
    static void queryStudentByName(Student S[], string querystudentname, int studentnumber);
    static void queryStudentByNo(Student S[], string querystudentno, int studentnumber);
    static void sortStudentGrade(Student S[], int studentnumber);
    static string removeSpecial(string m, char special);

    static void addGoodCount();
    static int getGoodCount();
    static bool checkValidGrade(string m);
    static bool checkValidNumber(string m);

};

#endif
