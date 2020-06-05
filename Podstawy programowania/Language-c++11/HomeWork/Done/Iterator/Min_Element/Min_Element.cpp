// Zadanie Min_Element
#include <iostream>
#include <vector>

 std::vector<int>::iterator min_element(
   std::vector<int>::iterator Begin,
   std::vector<int>::iterator End){

if (Begin == End) return Begin;
auto smallest = Begin;
++Begin;
for (; Begin != End; ++Begin) {
if (*Begin < *smallest) {
    smallest = Begin;
}
  }
  return smallest;
}

std::vector<int>::const_iterator min_element(
  std::vector<int>::const_iterator ConstBegin,
  std::vector<int>::const_iterator ConstEnd){

if (ConstBegin == ConstEnd) return ConstBegin;
auto smallest = ConstBegin;
++ConstBegin;
for (; ConstBegin != ConstEnd; ++ConstBegin) {
if (*ConstBegin < *smallest) {
   smallest = ConstBegin;
}
 }
 return smallest;
}

int main() {
  std::vector<int> vector {7, 5, 2, 12, 8};
  std::vector<int>::iterator result1 = min_element(vector.begin(), vector.end());
  std::vector<int>::const_iterator result2 = min_element(vector.cbegin(), vector.cend());
  std::cout << result1 - vector.begin() << " "
            << result2 - vector.cbegin()  << std::endl; }
