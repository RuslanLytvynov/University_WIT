//Sended to Teacher for Review.
#include<iostream>
#include<vector>
#include<algorithm>


int main(){
  std::vector<int> v;
  std::vector<int> a;
  for (int n; std::cin >> n;){
      v.push_back(n);}

      for (auto i = 0; i < v.size(); i++) {
  for (auto j = i+1; j < v.size(); j++){
    if(v[i] == v[j])   a.push_back(v[i]);}
}

std::sort(a.begin(),a.end());
auto last = std::unique(a.begin(),a.end());
a.erase(last, a.end());

  for (auto i = 0; i < a.size(); i++){
          std::cout << a[i] << " ";}
      std::cout << std::endl;
}
