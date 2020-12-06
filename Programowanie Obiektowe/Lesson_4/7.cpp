#include <cstdio>
#include <cstdlib>
struct MyStruct02{
  double xF;
  int xI;
};

///*********************************************
int MyRead(char*);
void* MyStruct01(double, int);
double ReadStruct01Double(void*);
double ReadStruct01Int(void*);
///*********************************************
int MyRead(char *myStr){
  int x;
  printf("%s", myStr);
  scanf("%d", &x);
  return x;}
///*********************************************
void* MyStruct01(double xF, int xI){
  void* myStruct01;
  int * pI; double * pF;
  myStruct01 = malloc(sizeof(int) + sizeof(double));
  pF = (double*)myStruct01;
  pI = (int*)(pF+1);
  *pF = xF;
  *pI = xI;

  return myStruct01;
}
///*********************************************
double ReadStruct01Double(void* myStruct01){return *(double*)myStruct01;}
///*********************************************
double ReadStruct01Int(void* myStruct01){
  double * xF = (double*)myStruct01;
  int * xI;
    xI = (int*)++xF;
  return *xI;}
///*********************************************
int main(){
MyStruct02 myStruct02;

myStruct02.xF = 2.5;
myStruct02.xI = 11;
printf("xF = %lf, xI = %d\n", myStruct02.xF, myStruct02.xI);
  return 0;
}
