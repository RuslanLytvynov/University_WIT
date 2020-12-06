#ifndef MyClass_H
#define MyClass_H
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class MyClass{
    public:
        MyClass();///Bezargumentowy konstruktor
        MyClass(int, int, int);///Trzyargumentowy konstruktor
        void Ini(int, int, int);
        void Print(const char* ="");
        void Adr();
        int GetX2();
        int GetX1();
        int GetX0();
        int CrC();
        void SetCrC();
    private:
        int x2;
        int x1;
        int x0;

        int cRc;
    };
#include "MyClass.cpp"
#endif // MyClass_H
