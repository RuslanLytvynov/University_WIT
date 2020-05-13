#include <iostream>
#include <vector>

// std::vector<int>::iterator find(std::vector<int>::iterator b,
//                     std::vector<int>::iterator e, int n)
std::vector<int>::iterator find_not(std::vector<int>::iterator b,
                              std::vector<int>::iterator e, int n){
for (; b < e; ++b) {
  if (*b != n) {
  return b;}}
  return e;
}

void remove(std::vector<int>::iterator b,
            std::vector<int>::iterator e, int n){

  auto i = find_not(b, e, n);
while (true){
  i = find_not(i, e, n);
  if (i == e){
    return;
  }
  *b++ = *i++;}}

int main(){
  std::vector<int> v {-7, 5, 2, 2, 11, 2, 3};
  auto r = remove(v.begin(), v.end(), 2);
  v.erase(r, b.end());
  for (auto i = v.begin(); i < v.end(); ++i){
      std::cout << *i << " ";}
    std::cout << std::endl;}
