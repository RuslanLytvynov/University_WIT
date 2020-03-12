#include "iostream"
using namespace std;

int main ()
{

  for (int i=100; i<=999; i++)
  {
    int a=i/100; // число сотен (1-цифра)
    int b=(i/10)%10; //число десяток (2-цифра)
    int c=i%10; //число едениц (3-цифра)
    int res = a + b + c;
    if (res % 7 == 0 && (a != 3 && a!= 4 && a!= 8)
      && (b == 1 || b == 2 || b == 4 || b == 8)
      && (c == 0 || c == 2 || c == 4 || c == 6 || c == 8 )) {
      cout<<i<<" ";}
  }
}



/*
for(int i = 100; i <= 999; i++){
  int a,b,c;
  a = i % 10, b = i / 100 , c =( i % 10 ) / 100;
//  if (i % 7 == 0 )
  //{cout << i << " ";}
  if((a + b + c) % 7 == 0 )
  {cout << i << " ";}
*/
/*
int i = 100;
    while(i < 1000)
    {
        int ed = i/100;
        int dwa = (i/10)%10;
        int thre = i%10;
        if ((ed + dwa + thre) == 7){
        cout << i << " ";}
        i++;
      }
      */
      /*
      int n = i, sum = 0;
          sum += n%10;
          n /= 10;
      if ((sum == 7) &&  (sum == 14) && (sum == 21)){
          cout << i << endl;}
*/
