#ifndef MyClass_H
#define MyClass_H
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class MyClass{
    public:
        MyClass();
        MyClass(int, int, int);
        void Ini(int, int, int);
        void Print(const char* = "");
        void Adr();
    private:
        int x2;
        int x1;
        int x0;
    };
#include "MyClass.cpp"
#endif // MyClass_H
