#ifndef MyClass_H
#define MyClass_H
#include <iostream>
#include "MyUtility.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

class MyClass{
    public:
        MyClass();///Bezargumentowy konstruktor
        MyClass(int, int, int);///Trzyargumentowy konstruktor
        MyClass(const MyClass&);///Konstruktor kopiującu

        int CRC();
        int CrC();
        void SetCrC();
        string ToString();

        int x2;
        int x1;
        int x0;
    private:
        int cRc;
    };
#include "MyClass.cpp"
#endif // MyClass_H
