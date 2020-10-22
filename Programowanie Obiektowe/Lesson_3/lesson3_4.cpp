#include <cstdio>
#include <cstdlib>
///*********************************************
void MyPrint(int);
///*********************************************
void MyPrint(int x){printf("x = %d\n", x);}
///*********************************************
int main(){

  printf("Adress MyPrint = %p\n",(void*)MyPrint);

  return 0;
}
