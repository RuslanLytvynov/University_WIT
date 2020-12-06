#ifndef MyClass01_H
#define MyClass01_H
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class MyClass01{
    public:
        MyClass01();// Konstruktor
        MyClass01(int,int,int)

        void Ini(int, int, int);
        void Print(const char* ="");
        int x2;
        int x1;
        int x0;

    }    ;
#include "MyClass01.cpp"
#endif  // MyClass01_H
