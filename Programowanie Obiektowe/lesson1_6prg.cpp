#include <cstdio>
///##include <stdio.h> CO1_ID_03p04_0001.c
using namespace std;


int main()
{
  int x, y;
  x = 5; y = x++;
  printf("x = %d, y = %d\n", x, y);
  printf("----------------------\n");

  x = 5; y = ++x;
  printf("x = %d, y = %d\n", x, y);
  printf("----------------------\n");

  x = 5; x++;
  printf("x = %d\n", x);
  printf("----------------------\n");


  x = 5; ++x;
  printf("x = %d\n", x);
  printf("----------------------\n");


  return 0;
}
