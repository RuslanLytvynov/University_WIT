//Transform
#include <vector>
#include <iostream>
#include <functional>

std::vector<int>::const_iterator transform (
  std::vector<int>::const_iterator const_start,
  std::vector<int>::const_iterator const_end,
  std::vector<int>::iterator start,
  std::function<int(int)> funktor)
  {
    while (const_start != const_end) { *start++ = funktor(*const_start++); } return start;}

int main() {
  const std::vector<int> vector1 {-7, 5, 1, 2, 11};
  std::vector<int> vector2(5);
   auto result = transform(vector1.cbegin(), vector1.cend(), vector2.begin(),
                            [](int element) {return element * element; });
    for (auto iterator = vector2.cbegin(); iterator < result;){
      std::cout << *iterator++ << " "; }
     std::cout << std::endl; }
