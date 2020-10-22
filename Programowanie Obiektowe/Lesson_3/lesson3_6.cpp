#include <cstdio>
#include <cstdlib>
///*********************************************
typedef void (*FF01)(int a);
///*********************************************
void MyPrint0(int);
void MyPrint1(int);
void MyPrint2(int);
void AllPrint(FF01, int);
///*********************************************
void MyPrint0(int x){printf("MyPrint0 --> x = %d\n", x);}
///*********************************************
void MyPrint1(int x){printf("----MyPrint1 --> x = %d\n", x);}
///*********************************************
void MyPrint2(int x){printf("---------MyPrint2 --> x = %d\n", x);}
///*********************************************
void AllPrint(FF01 ff, int x){
  printf("Funkcja FF01 ->");
  ff(x);
}
///*********************************************
int main(){
  AllPrint(MyPrint0, 0);
  AllPrint(MyPrint1, 1);
  AllPrint(MyPrint1, 2);
// FF01 p0, p1, p2;
//
// p0 = MyPrint0; p1 = MyPrint1;  p2 = MyPrint2;
//
// printf("adr p0 = %p, adr MyPrint0 = %p\n", (void*)p0, (void*)MyPrint0);
// printf("adr p0 = %p, adr MyPrint1 = %p\n", (void*)p1, (void*)MyPrint1);
// printf("adr p0 = %p, adr MyPrint2 = %p\n", (void*)p2, (void*)MyPrint2);
// p0(0); p1(1); p2(2);

  return 0;
}
