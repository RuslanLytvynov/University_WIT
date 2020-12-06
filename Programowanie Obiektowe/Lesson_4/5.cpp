#include <cstdio>
#include <cstdlib>
///*********************************************
int MyRead(char*);
void SingleLine(int, char*);
int MyAdd(int,int);
int MySub(int,int);
int MyMax(int,int);
int MyMin(int,int);
int MyComp(int(*Ff)(int, int), int , int);
///*********************************************
int MyRead(char *myStr){
  int x;
  printf("%s", myStr);
  scanf("%d", &x);
  return x;
}
///*********************************************
void SingleLine(int n, char* myStr){
  for(int i=0; i<n; ++i, printf("%s", myStr));}
///*********************************************
int MyAdd(int x, int y){return x + y;}
///*********************************************
int MySub(int x, int y){return x - y;}
///*********************************************
int MyMax(int x,int y){if(x>y)return x; return y;}
///*********************************************
int MyMin(int x,int y){if(x<y)return x; return y;}
///*********************************************
///*********************************************
int MyComp(int(*Ff)(int, int), int x , int y){return Ff(x, y);}
///*********************************************
int main(){
    SingleLine(15," *");
  // SingleLine(MyRead("%n? =")," *");
  printf("\n");
  int x = MyRead("x? = "), y = MyRead("y? = ");
  printf("Result = %d\n", MyAdd(x, y));
  printf("Result = %d\n", MySub(x, y));
  SingleLine(15," *");
  printf("\n");
  printf("Result = %d\n", MyComp(MyAdd,x, y));
  printf("Result = %d\n", MyComp(MySub,x,  y));
  printf("Result = %d\n", MyComp(MyMax,x,  y));
  printf("Result = %d\n", MyComp(MyMin,x,  y));


  return 0;
}
