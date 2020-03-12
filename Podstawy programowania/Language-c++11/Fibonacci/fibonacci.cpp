#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  double a = 1, b = 0;
  for(int i=0; i<n;i++)
  {
    cout << b << " ";
    b += a;
    a = b-a;
  }
}
