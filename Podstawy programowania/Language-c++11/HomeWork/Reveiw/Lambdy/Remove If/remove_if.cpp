//Remove_IF
#include <vector>
#include <iostream>
#include <functional>

 std::vector<int>::iterator remove_if(
   std::vector<int>::iterator Begin,
   std::vector<int>::iterator End,
   std::function<bool(int&)> pred)
   {
    std::vector<int>::iterator Result = Begin;
     while (Begin!=End) {
       if (!pred(*Begin)) {
         *Result = std::move(*Begin);
         ++Result;
       }
       ++Begin;
     }
     return Result;
   }

int main() {
  std::vector<int> vector {-7, 5, 2, 2, 11, 2, 3};
  auto result = remove_if(vector.begin(), vector.end(),
   [](int element) {return element < 3; });
  for (auto iterator = vector.cbegin(); iterator < result;){
     std::cout << *iterator++ << " "; }
   std::cout << std::endl; }
