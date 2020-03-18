#include<iostream>
//algorytm Euklidesa resza dzelenija
using namespace std;
//function
int euclid(int m, int n){
  while (n)// to samo n != 0
  {
    int k = m % n; //reszta dzelenija
    m = n;
    n = k;}
    return m;}

//3 i węcej liczb
int main(){
  int d = 0;
  for (int i; cin >> i;){
    d = euclid(d, i);}
//do 2-3 liczb
  // int M, N; //local function nie równie w euclidzi m i n
  // cin >> M >> N;
  cout << d << " ";
  //cało piętli
  // while (n)// to samo n != 0
  // {
  //   int k = m % n; //reszta dzelenija
  //   m = n;
  //   n = k;}
    // cout << m << " ";
}
