# Student System project
Command Line Interface(CLI) for managing student information, a capstone small project for getting familiar with C++.

Date: May 2019

### Designed features:

- Input student's information as: string student = "Zhengsan, 201812402002, 89".
- Compute Average Student scores.
- Rank student by their Grades.
- Show number of Good Students(Grade > 90).
- Query Student information by name.
- Query Student Information by Student ID No.


### Usage:
#### Compile
Compile the `main.cpp` and `student.cpp` files from terminal:

On Mac/Linux/Windows, direct to the project folder and compile them in terminal:

```bash
$ g++ -o run src/main.cpp src/student.cpp
```

__Note__: C++ compiler is needed for compiling. Popular C++ compilers are [mingw-w64](http://www.mingw-w64.org) for Windows, [Clang](https://developer.apple.com/xcode/) for XCode for macOS, and [GCC](https://gcc.gnu.org/) on Linux. And also make sure the path in your computer is well configured. Check this [vedio](https://www.youtube.com/watch?v=TOeKtN6Vir4) if you are having trouble with windows configuration.

#### Run

On Mac, run it from terminal by `./run` to start using the program. On Windows, start the program by `run.exe`. Instructions are available inside.


### Class Student
Refer to [`student.h`](student.h) file.

### Error Handling
The following input has been handled specifically:

* input = "zhengsan, 2019, (Any charater mess up with Grade)"
* input = "zhangsan, 2019, 93.4.4"
* input = "zhengsan, 2019 "
* input = "zhengsan"

### Other specific
* Class Student is implemented through [`student.h`](student.h) header file and [`student.cpp`](student.cpp) cpp file.
* I/O is handled by main.cpp file.
* Ranking mechanism can be changed by judgeClass (a member function of Class Student).
