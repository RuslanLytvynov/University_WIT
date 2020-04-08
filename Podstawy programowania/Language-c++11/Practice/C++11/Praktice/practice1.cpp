#include <iostream>


using namespace std;


int main()
{
  double arr[102];
  int j = 0;

  for (double number; cin >> number;){
    arr[j] = number;
    j += 1;
  }

  for ( int i = 0; i < j; i++)
    if (arr[i] != (int)arr[i])
      return 1;

  int min_el = arr[0];
  for (int i = 1; i < j;i++){
    if(arr[i] <= min_el){
      min_el = arr[i];
    }
  }
  cout << min_el << " " << endl;
  return 0;
}
