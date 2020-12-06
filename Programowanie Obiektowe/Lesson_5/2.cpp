#include <iostream>
///****************************************************
using std::cout;
using std::cin;
using std::endl;
using std::string;
///****************************************************
class MyClass01{
public:
  int x2, x1, x0;

  void MyClass01Ini(int, int, int);
  void Print();
  MyClass01 Add(MyClass01);
};
///****************************************************
int MyRead(string = "x? = ");
///****************************************************
MyClass01 Add(MyClass01, MyClass01);
///****************************************************
void MyClass01::MyClass01Ini(int tx2, int tx1, int tx0){
x2 = tx2; x1 = tx1; x0 = tx0;
}
///****************************************************
void MyClass01::Print(){
cout<<"myClass01("<<x2<<", "<<x1<<", "<<x0<<")"<<endl;    }
///****************************************************
MyClass01 MyClass01::Add(MyClass01 mC02){
  MyClass01 tmp;
  tmp.x2 = x2 + mC02.x2;
  tmp.x1 = x1 + mC02.x1;
  tmp.x0 = x0 + mC02.x0;
  return tmp;
}
///***************************************************
int MyRead(string myStr){
int x;  cout<<myStr;
cin>>x;

return x;
}
///****************************************************
MyClass01 Add(MyClass01 mC02, MyClass01 mC01){
  MyClass01 mC03;
  mC03.x2 = mC01.x2 + mC02.x2;
  mC03.x1 = mC01.x1 + mC02.x1;
  mC03.x0 = mC01.x0 + mC02.x0;
  return mC03;
}
///****************************************************
int main(){
MyClass01 myClass01, myClass02, myClass03;

  cout<<"myClass01::"<<endl;
myClass01.MyClass01Ini(MyRead("x2? = "),MyRead("x1? = "), MyRead("x0? = "));
  cout<<"myClass02::"<<endl;
myClass02.MyClass01Ini(MyRead("x2? = "),MyRead("x1? = "),MyRead("x0? = "));

myClass04 = myClass02.Add(myClass01);
myClass03 = Add(myClass02, myClass01);
myClass03.Print();
myClass04.Print();

return 0;
}
