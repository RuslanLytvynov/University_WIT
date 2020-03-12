#include<iostream>
using namespace std;
int main(){
  double arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

        int a = 1;
        int min_el = 0;
        for (int i = 0; i < 10; i++){
          if(arr[i] <= arr[a]){
             min_el = arr[i];}
             }
             cout << min_el << " ";
}
