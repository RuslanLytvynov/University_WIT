#include <cstdio>
#include <cstdlib>

int main(){
  void* x;
  x = malloc(8);
  char * z;
  z = (char*)x;

z[0] = 'a'; // z[0] <=> *(z+0)
z[1] = 'b'; // z[0] <=> *(z+1)
z[2] = 'c'; // z[0] <=> *(z+2)
z[3] = 'd'; // z[0] <=> *(z+3)
z[4] = 'e'; // z[0] <=> *(z+4)
z[5] = 'f'; // z[0] <=> *(z+5)
z[6] = 'g'; // z[0] <=> *(z+6)
z[7] = 'f'; // z[0] <=> *(z+7)

for(int i =0; i < 0; ++i)
    printf("%c\n", z[i] );


  return 0;
}
