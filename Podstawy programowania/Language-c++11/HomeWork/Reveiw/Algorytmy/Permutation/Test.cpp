#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <ctime>


std::vector<int> permutation(int a){
  std::vector<int> v(a);

  auto n = v.size();
    for (auto i = 0; i < n-1; i++){v[i] = i + 1;}

    std::random_shuffle(v.begin(), v.end());

    return v;}

int main() {
  std::srand(std::time(nullptr));
  std::vector<int> vector = permutation(5);
    for (int element: vector) { std::cout << element << " "; }
    std::cout << std::endl; }
