#include <iostream>
#include <vector>
// #include <algorithm>

 std::vector<int>::iterator min_element(std::vector<int>::iterator begin,
                                        std::vector<int>::iterator end){
for (; begin < end; ++begin);
  return begin;}

int main() {
  std::vector<int> vector {7, 5, 1, 12, 8};
  std::vector<int>::iterator result1 = min_element(vector.begin(), vector.end());
  std::vector<int>::const_iterator result2 = min_element(vector.cbegin(), vector.cend());
  std::cout << result1 - vector.begin() << " " << result2 - vector.cbegin() << std::endl; }
