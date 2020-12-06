#ifndef MyUtility_H
#define MyUtility_H
#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::ostringstream;
using std::endl;

class MyUtility{
    public:
        static string ToString(int);
        static int MyRead(const char* ="x? = ");

    };

#include "MyUtility.cpp"
#endif // MyUtility_H
