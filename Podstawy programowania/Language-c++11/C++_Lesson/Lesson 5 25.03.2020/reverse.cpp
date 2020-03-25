#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v){
  for (int i = 0, j = v.size(); i < j; i++){
    --j;
    swap(v[i], v[j]);}
}

int main(){
  vector<int> v;
  for (int n; cin >> n;){
      v.push_back(n);}

  // for (int i = 0, j = v.size(); i < j; i++){
  //   --j;
  //   swap(v[i], v[j]);}

reverse(v);

  for (int i = 0; i < v.size(); i++){
      cout << v[i] << " ";}
  cout << endl;

// odwratna kolenjość
  // for (int j = v.size(); j;){
  //     --j;
  //     cout << v[j] << " ";}
  // cout << endl;
  //
}
