#include <cstdio>
#include <cstdlib>

int main(){
  int *z;
  int st = 10;
  z = (int*)malloc(st*sizeof(int));

for(int i = 0;i<st;++i)
    z[i]=0;

  z[0] = 1;
  *(z+1) = 2;

  /*
  z[i] <=> *(z+i) <=> *(i+z) <=> i[z]
  */

  2[z]=3;

  for(int i = 0;i<st;++i)
      printf("z[%d] = %d\n",i,z[i]);

free(z); //free RAM

  return 0;
  }
