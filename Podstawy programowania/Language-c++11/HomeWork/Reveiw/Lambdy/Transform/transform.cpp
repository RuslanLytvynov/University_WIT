#include <vector>
#include <iostream>
#include <functional>


std::vector<int>::const_iterator transform (
  std::vector<int>::const_iterator ConstBegin,
  std::vector<int>::const_iterator ConstEnd,
  std::vector<int>::iterator Begin,
  std::function<void(int&)> action){


    while (ConstBegin != ConstEnd) {
        *Begin++ = action(*ConstBegin++);
    }
    return Begin;
}



int main() {
  const std::vector<int> vector1 {-7, 5, 1, 2, 11};
  std::vector<int> vector2(5);
   auto result = transform(vector1.cbegin(), vector1.cend(), vector2.begin(),
                            [](int element) {return element * element; });
    for (auto iterator = vector2.cbegin(); iterator < result;){
      std::cout << *iterator++ << " "; }
     std::cout << std::endl; }
