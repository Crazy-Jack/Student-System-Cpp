# Student System project
Author: Zheng Lingwen

Date: May 2019

### Designed features:

- Input student's information as: string student = "Zhengsan, 201812402002, 89".
- Compute Average Student scores.
- Rank student by their Grades.
- Show number of Good Students(Grade > 90).
- Query Student information by name.
- Query Student Information by Student ID No.

### Class Student
Refer to [`student.h`]('student.h') file.

### Error Handling
The following input has been handled specifically

* input = "zhengsan, 2019, (Any charater mess up with Grade)"
* input = "zhangsan, 2019, 93.4.4"
* input = "zhengsan, 2019 "
* input = "zhengsan"

### Other specific
* Class Student is implemented through header file and cpp file.
* I/O is handled by main.cpp file.
* Ranking mechanism can be changed by judgeClass member function of Class Student.
