#include <cstdio>
#include <cstdlib>
///*********************************************
int MyRead(char*);
int MyMax(int,int);
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
int main(){
printf("MAX = %d\n", MyMax(MyRead("x0? ="), MyRead("x1? =")));
  return 0;
}
