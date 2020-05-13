#include <iostream>
#include "vector"

// std::vector<int>::iterator find(std::vector<int>::iterator b,
//                     std::vector<int>::iterator e, int n)
std::vector<int>::iterator find(std::vector<int>::iterator b,
                              std::vector<int>::iterator e, int n){
for (; b < e; ++b) {
  if (*b == n) {
  return b;}
}}

int main(){
  std::vector<int> v {-7, 5, 2, 2, 11, 2, 3};
  auto r = find(v.begin(), v.end(), 17);
  std::cout << r - v.begin() << std::endl;
}
