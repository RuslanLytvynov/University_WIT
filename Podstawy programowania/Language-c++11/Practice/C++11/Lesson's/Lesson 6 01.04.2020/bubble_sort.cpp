#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int> &v){
  bool unordered;
do{
  unordered = false;
    for(int i = 0; i + 1 < v.size(); i++){
    if (v[i] > v[i + 1]){
      unordered = true;
      int n = v[i];
      v[i] = v[i +1];
      v[i+1] = n;
    //  swap(v[i+1],v[i])
    for(int n : v){
      cout << n << " ";

    }
    cout << endl;
  }} }
    while(unordered);
}

int main(){
  vector<int> v;
  for (int n; cin >> n;){
    v.push_back(n);}
  bubble_sort(v);

}
