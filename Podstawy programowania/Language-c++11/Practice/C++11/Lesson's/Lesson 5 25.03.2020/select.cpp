#include <iostream>
#include <vector>
using namespace std;

vector<int> select(const vector<int> &v){
    vector<int> r;
    for (int i = 0; i < v.size(); i++){
        if (v[i] < 0){
          r.push_back(v[i]);}}
      return r;}

int main(){
  vector<int> r = select(vector<int> v {7, -4, 1, -7, 6, -1});
  for (int i = 0; i < r.size(); i++){
      cout << r[i] << " ";}
      cout << endl;
}
