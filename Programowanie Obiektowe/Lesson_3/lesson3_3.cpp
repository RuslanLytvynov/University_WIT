#include <cstdio>
#include <cstdlib>
///*********************************************
 int MySwap(int*, int*);
 int MySwapPt(int**, int**);
 int MySort(int*, int*, int*);
  int MySortPt(int**, int**, int**);
///*********************************************
int MySwap(int* x, int* y){
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
  return 1;
}
///*********************************************
int MySwapPt(int** x, int** y){
  int * tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
  return 1;
}
///*********************************************
int MySort(int* x, int* y, int* z){
int tmp;
if(*x>*y) MySwap(x,y);
if(*y>*z) MySwap(x,z);
if(*x>*y) MySwap(x,y);
  return 1;
}
///*********************************************
int MySortPt(int** x, int** y, int** z){
int * tmp;
if(*x>*y) MySortPt(x, y);
if(*y>*z) MySortPt(x, z);
if(*x>*y) MySortPt(x, y);
  return 1;
}
///*********************************************
int main(){
int  x0, y0, z0; int* x1, y1, z1;
printf("x? =\n"); scanf("%d", &x0);
printf("y? =\n"); scanf("%d", &y0);
printf("z? =\n"); scanf("%d", &z0);

x1 = &x0; y1 = &y0; z1 = &z0;

MySort(&x1, &y1, &z1);

printf("(%d, %d, %d) ->  (%d, %d, %d)\n", x0, y0, z0, *x1, *y1, *z1);

  return 0;
}
// x? = 5
// y? = 2
// z? = 3
// (5, 2, 3) -> (2,3,5)
