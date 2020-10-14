#include <cstdio>
#include <cstdlib>

int main(){
  // char *z;
  // z = (char*)malloc(8);
  int *z;
  z = (int*)malloc(800*sizeof(int));
  int x = 0;

  for(int i = 0; i < 800; ++i){
      z[i] = 97+i;
      x+= i;
      printf("%3d\n", z[i] );}

  printf("x = %d\n", x );

 // z[0] = 'a';// z[0] <=> *(z+0)
// z[1] = 'b'; // z[0] <=> *(z+1)
// z[2] = 'c'; // z[0] <=> *(z+2)
// z[3] = 'd'; // z[0] <=> *(z+3)
// z[4] = 'e'; // z[0] <=> *(z+4)
// z[5] = 'f'; // z[0] <=> *(z+5)
// z[6] = 'g'; // z[0] <=> *(z+6)
// z[7] = 'f'; // z[0] <=> *(z+7)





  return 0;
}
