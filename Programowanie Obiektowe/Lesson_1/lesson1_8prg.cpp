#include <cstdio>
///##include <stdio.h> CO1_ID_03p04_0001.c
using namespace std;


int main()
{
 double x;  int *p1, *p2; char *cp;

 p1 = p2 = (int*)&x;
 printf("p1 = %p, p2 = %p\n", (void*)p1, (void*)p2);
 ++p2; *p1 = 7; *p2 = 5; cp = (char*)&x;

 printf("a = %d, b = %d\n", *p1, *p2);
 printf("p1 = %p, p2 = %p\n", (void*)p1, (void*)p2);
 printf("cp = %p\n", (void*)cp);
 ++cp;
 printf("cp = %p\n", (void*)cp);

 return 0;
}
