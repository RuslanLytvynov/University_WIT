#include <cstdio>
#include <cstdlib>
///*********************************************
int MyRead(char*);
int MyMax(int,int);
int MyMax(int,int,int);
int MyMax(int,int,int,int,int,int,int);
int MyMax(int,int,int,int,int,int,int,int);
///*********************************************
int MyRead(char *myStr){
  int x;
  printf("%s", myStr);
  scanf("%d", &x);
  return x;
}
///*********************************************
int MyMax(int x0, int x1){
  if(x0>x1) return x0;
  return x1;
}
///*********************************************
int MyMax(int x0, int x1, int x2){
return MyMax(MyMax(x0,x1), x2);
}
///*********************************************
int MyMax(int x0, int x1, int x2, int x3, int x4, int x5, int x6){
return MyMax(MyMax(x0,x1, x2),MyMax(x3,x4,x5),x6);
}
///*********************************************
int MyMax(int x0, int x1, int x2, int x3, int x4, int x5, int x6, int x7){
return MyMax(MyMax(x0,x1),MyMax(x2,x3),MyMax(x4,x5),MyMax(x6,x7));
}
///*********************************************
int main(){
  int x0, x1, x2, x3, x4, x5, x6, x7;
  x0 = MyRead("x0? =");
  x1 = MyRead("x1? =");
  x2 = MyRead("x2? =");
  x3 = MyRead("x3? =");
  x4 = MyRead("x4? =");
  x5 = MyRead("x5? =");
  x6 = MyRead("x6? =");
  x7 = MyRead("x7? =");

printf("MAX(%d, %d, %d) = %d\n",x0 ,x1 ,x2, MyMax(x0,x1,x2));
printf("MAX(%d, %d, %d, %d, %d, %d, %d) = %d\n",
x0,x1 ,x2,x3,x4,x5,x6, MyMax(x0,x1,x2,x3,x4,x5,x6));
printf("MAX(%d, %d, %d, %d, %d, %d, %d, %d) = %d\n",
x0,x1 ,x2,x3,x4,x5,x6, MyMax(x0,x1,x2,x3,x4,x5,x6,x7));
  return 0;
}
