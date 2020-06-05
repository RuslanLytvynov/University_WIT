#include <vector>
#include <iostream>
#include <functional>
 #include <algorithm>

int main() {
  std::vector<int> vector {-7, 5, 2, 2, 11, 2, 3};
  auto result = remove_if(vector.begin(), vector.end(),
   [](int element) {return element < 3; });
  for (auto iterator = vector.cbegin(); iterator < result;){
     std::cout << *iterator++ << " "; }
   std::cout << std::endl; }
