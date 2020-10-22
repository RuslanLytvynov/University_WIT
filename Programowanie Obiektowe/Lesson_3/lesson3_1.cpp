#include <cstdio>
#include <cstdlib>
///*********************************************
int MySwap(int*, int*); //zadecladorowanie funcji
///*********************************************
int MySwap(int* a, int* b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return 2 * *a + *b;
}
///*********************************************
int main(){

int x = 2, y = 1, z;
z = MySwap(&x, &y);
printf("x=%d, y = %d, 2*%d + %d = %d\n", x, y, x, y, z);
  return 0;
}
