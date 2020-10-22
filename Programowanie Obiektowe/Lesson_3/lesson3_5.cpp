#include <cstdio>
#include <cstdlib>

typedef int ala;
///*********************************************
void MyPrint(int);
///*********************************************
void MyPrint(int x){printf("x = %d\n", x);}
///*********************************************
int main(){
  ala x = 9;
  int y;  y = x;

  MyPrint(y);    MyPrint(x);


  return 0;
}
