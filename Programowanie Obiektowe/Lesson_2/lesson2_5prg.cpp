#include <cstdio>
#include <cstdlib>

int main(){
  int *z;
  int st=99990000;
  z = (int*)malloc(st*sizeof(int));

  for(int i = 1; i<99990000; ++i)
      for(int j = 1; j<99990000;++j)
          z = (int*)malloc(st*sizeof(int));

  return 0;
  }
