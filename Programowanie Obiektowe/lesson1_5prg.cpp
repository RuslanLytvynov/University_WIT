#include <cstdio>
///##include <stdio.h> CO1_ID_03p04_0001.c
using namespace std;


int main()
{
  int x, y;
  int *px, *py;

  px = &x; py = &y;

  printf("x? = "); //console output  --->
  scanf("%d", px);  //console input  <---

  printf("y? = ");
  scanf("%d", py);

//Code Teacher
int *pt = px; px = py; py = pt;
//

//My Code
// int *nv; nv = px;
// px = py;  py = nv;
//

  printf("x = %d, y = %d\n", x, y);
  printf("x = %d, y = %d\n", *px, *py);

  // *px = 12;  *py = 99;
  //
  // printf("x = %d, y = %d\n", x, y);
  // printf("x = %d, y = %d\n", *px, *py);

  return 0;
}

// x? = 7
// y? = 5
// x=7, y=5
// x=5, y=7
