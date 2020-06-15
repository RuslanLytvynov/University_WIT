#include <vector>
#include <iostream>
#include <functional>
#include <utility>


  std::vector<int>::iterator partition(
    std::vector<int>::iterator Begin,
    std::vector<int>::iterator End,
    std::function<bool(int)> logic){

      while (Begin!=End) {
    while (logic(*Begin)) {
      ++Begin;
      if (Begin==End) return Begin;
    }
    do {
      --End;
      if (Begin==End) return Begin;
    } while (!logic(*End));
    swap (*Begin,*End);
    ++Begin;
  }
  return Begin;
    }


int main() {
  std::vector<int> vector {2, 3, 8, 1, 6, 5, 0, 7, 4, 9};
   auto result = std::partition(vector.begin(), vector.end(),
    [](int element) {return element % 2; });
 std::cout << result - vector.begin() << std::endl;
  for (auto iterator = vector.cbegin(); iterator < vector.cend();) {
    std::cout << *iterator++ << " "; }
     std::cout << std::endl; }
