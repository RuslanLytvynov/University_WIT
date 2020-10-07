#include <cstdio>
///##include <stdio.h> CO1_ID_03p04_0001.c
using namespace std;


int main()
{
  int x;
  int *px;

  px = &x;

  printf("x? = "); //console output  --->
  scanf("%d", px);  //console input  <---

  printf("x = %d\n", x);

  return 0;
}
