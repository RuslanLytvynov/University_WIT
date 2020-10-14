#include <cstdio>
#include <cstdlib>
//Macierz wielowymiarowa
int main(){
  int *t0, *t1, *t2;
  int * *t;
  int s1=3, s2=5;
  int i,j;

  t = (int**)malloc(sizeof(int*)*s1);

for(i = 0;j < s1;++i)
    t[i] = (int*)malloc(sizeof(int)*s2);

for(j=0;j<s2;++j)
    t[0][j] = j+0;

for(j=0;j<s2;++j)
    t[1][j] = j+1;

for(j=0;j<s2;++j)
    t[2][j] = j+2;

for(i = 0; i < s1;++i){
    for(j=0; j<s2;++j)
        printf("[%2d]", t[i][j]);
    printf("\n");
  }

*(t+0)[0] = 7;
*(*(t+0)+1) = 12;
t[0][2] = 77;

printf("\n---------------------\n");
for(i = 0; i < s1;++i){
    for(j=0; j<s2;++j)
        printf("[%2d]", t[i][j]);
    printf("\n");
  }

  for(i = 0; i <s1; ++i)
      free(t[i]);

  free(t);

  return 0;
  }
