#include <cstdio>
#include <cstdlib>
///*********************************************
int MyAdd(int, int);
int MyAdd(int, int, int);
///*********************************************
///*********************************************
int MyAdd(int x, int y){return x + y;}
int MyAdd(int x, int y, int z){return x + y + z;}
///*********************************************
int main(){
int x = 9, y = 12, z = 6;
printf("%d + %d = %d\n", x, y, MyAdd(x,y));
printf("%d + %d + %d = %d\n", x, y, z, MyAdd(x,y,z));
  return 0;
}
