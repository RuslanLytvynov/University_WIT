#include <cstdio>
#include <cstdlib>
///*********************************************
int MyRead(char*);
///*********************************************
int MyRead(char *myStr){
  int x;
  printf("%s", myStr);
  scanf("%d", &x);
  return x;
}
///*********************************************
///*********************************************
int main(){
int x = MyRead("x? =");
printf("x = %d\n",x);
  return 0;
}
