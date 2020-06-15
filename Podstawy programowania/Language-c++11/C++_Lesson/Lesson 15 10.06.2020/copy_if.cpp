#include <vector>
#include <iostream>
#include <functional>

std::vector<int>::iterator copy_if(
  std::vector<int>::const_iterator ConstBegin,
  std::vector<int>::const_iterator ConstEnd,
  std::vector<int>::iterator Begin,
  std::function<bool(int)> logic){

    while (ConstBegin != ConstEnd) {
        if (logic(*ConstBegin))
            *Begin++ = *ConstBegin;
        ConstBegin++;
    }
    return Begin;
  }


int main() {
   const std::vector<int> vector1 {-7, 0, 1, 0, 11};
   std::vector<int> vector2(5);
   auto result = copy_if(vector1.cbegin(), vector1.cend(), vector2.begin(),
    [](int element) {return element; });
   for (auto iterator = vector2.cbegin(); iterator < result;) {
      std::cout << *iterator++ << " "; }
    std::cout << std::endl; }
