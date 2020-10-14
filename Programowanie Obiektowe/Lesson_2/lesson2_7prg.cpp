#include <cstdio>
#include <cstdlib>
//Macierz wielowymiarowa
int main(){
  int *t0, *t1, *t2;
  int * *t;
  int s1=3, s2=5;
  int j;

  t = (int**)malloc(sizeof(int*)*s1);

  t0 = (int*)malloc(sizeof(int)*s2);
  t1 = (int*)malloc(sizeof(int)*s2);
  t2 = (int*)malloc(sizeof(int)*s2);

t[0] = t0;
t[1] = t1;
t[2] = t2;

for(j=0;j<s2;++j)
    t0[j] = j+0;

for(j=0;j<s2;++j)
    t1[j] = j+1;

for(j=0;j<s2;++j)
    t2[j] = j+2;

for(j=0; j<s2;++j){
    printf("[%2d]", t0[j]);
    printf("[%2d]", t1[j]);
    printf("[%2d]", t2[j]);
    printf("\n");}

*(t+0)[0] = 7;
*(*(t+0)+1) = 12;
t[0][2] = 77;

printf("\n---------------------\n");
for(j=0; j<s2;++j){
    printf("[%2d]", t0[j]);
    printf("[%2d]", t1[j]);
    printf("[%2d]", t2[j]);
    printf("\n");}

  return 0;
  }
