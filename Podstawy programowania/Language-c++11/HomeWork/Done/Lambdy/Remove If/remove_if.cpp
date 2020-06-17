//Remove_IF
#include <vector>
#include <iostream>
#include <functional>

 std::vector<int>::iterator remove_if(
   std::vector<int>::iterator start,
   std::vector<int>::iterator end,
   std::function<bool(int&)> funktor)
   {
    std::vector<int>::iterator result = start;
     while (start != end) {
       if (!funktor(*start)) {
         *result = std::move(*start); ++result;}
       ++start;} return result;}

int main() {
  std::vector<int> vector {-7, 5, 2, 2, 11, 2, 3};
  auto result = remove_if(vector.begin(), vector.end(),
   [](int element) {return element < 3; });
  for (auto iterator = vector.cbegin(); iterator < result;){
     std::cout << *iterator++ << " "; }
   std::cout << std::endl; }
