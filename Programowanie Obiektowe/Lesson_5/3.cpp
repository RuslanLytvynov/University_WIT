#include <iostream>

///****************************************************

using std::cout;

using std::cin;

using std::endl;

using std::string;

///****************************************************

class MyClass01{​​​​​​

public:

int x2;

int x1;

int x0;

void MyClass01Ini(int, int, int);

}​​​​​​;

///****************************************************

int MyRead(string = "x? = ");

void MyClass01Ini(MyClass01&, int, int, int);

void MyClass01Ini(MyClass01*, int, int, int);

///****************************************************

///****************************************************

void MyClass01::MyClass01Ini(int tx2, int tx1, int tx0){​​​​​​

x2 = tx2;

x1 = tx1;

x0 = tx0;

}​​​​​​

///****************************************************

///****************************************************

int MyRead(string myStr){​​​​​​

int x;

cout<<myStr;

cin>>x;

return x;

}​​​​​​

///****************************************************

void MyClass01Ini(MyClass01& myClass01, int x2, int x1, int x0){​​​​​​

myClass01.x2 = x2;

myClass01.x1 = x1;

myClass01.x0 = x0;

}​​​​​​

///****************************************************

void MyClass01Ini(MyClass01* myClass01, int x2, int x1, int x0){​​​​​​

(*myClass01).x2 = x2;

(*myClass01).x1 = x1;

(*myClass01).x0 = x0;

}​​​​​​

///****************************************************

///****************************************************

int main(){​​​​​​

MyClass01 myClass01;

MyClass01 myClass02;

MyClass01 myClass03;

cout<<"myClass01::"<<endl;

MyClass01Ini(myClass01,

MyRead("x2? = "),

MyRead("x1? = "),

MyRead("x0? = "));

cout<<"myClass02::"<<endl;

MyClass01Ini(&myClass02,

MyRead("x2? = "),

MyRead("x1? = "),

MyRead("x0? = "));



cout<<"myClass03::"<<endl;

myClass03.MyClass01Ini(

MyRead("x2? = "),

MyRead("x1? = "),

MyRead("x0? = "));



cout<<"myClass01("<<myClass01.x2<<", "

<<myClass01.x1<<", "<<myClass01.x0<<")"<<endl;

cout<<"myClass02("<<myClass02.x2<<", "

<<myClass02.x1<<", "<<myClass02.x0<<")"<<endl;

cout<<"myClass03("<<myClass03.x2<<", "

<<myClass03.x1<<", "<<myClass03.x0<<")"<<endl;

return 0;

}​​​​​​
