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
      };
///****************************************************
int MyRead(string = "x? = ");
void MyClass01Ini(MyClass01&, int, int, int);
void MyClass01Ini(MyClass01*, int, int, int);
///****************************************************
///****************************************************
void MyClass01::MyClass01Ini(int tx2, int tx1, int tx0){
  x2 = tx2;
  x1 = tx1;
  x0 = tx0;
  }
///****************************************************
///****************************************************
int MyRead(string myStr){
  int x;
  cout<<myStr;
  cin>>x;
  return x;
  }
///****************************************************
void MyClass01Ini(MyClass01& myClass01, int x2, int x1, int x0){
  myClass01.x2 = x2;
  myClass01.x1 = x1;
  myClass01.x0 = x0;
  }
///****************************************************
void MyClass01Ini(MyClass01* myClass01, int x2, int x1, int x0){
  (*myClass01).x2 = x2;
  (*myClass01).x1 = x1;
  (*myClass01).x0 = x0;
  }
///****************************************************
///****************************************************
int main(){
  MyClass01 myClass01, myClass02, myClass03;

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
               

      myClass03.Print();
  return 0;
}
