#include <cstdio>
#include <cstdlib>
//Ciąg Fibonacciego
//Wersja iteracyjna

int main(){​​​​
    int *z;
    int st;
    printf("n? = ");
    scanf("%d", &st);
    z = (int*)malloc(st*sizeof(int));

     if(st>0) z[0]=1;
      if(st>1) z[1]=1;

     for(int i = 2; i<st;++i)
         z[i] = z[i-1] + z[i-2];

     for(int i = 0; i<st;++i)
        printf("%3d\n",z[i]);
     return 0;}​​​​
