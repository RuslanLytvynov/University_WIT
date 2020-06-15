#include <vector>
#include <iostream>
#include <functional>



void replace_if(
  std::vector<int>::iterator Begin,
  std::vector<int>::iterator End,
  std::function<bool(int)> logic,
  const int& new_value){

    for (; Begin != End; ++Begin) {
            if(logic(*Begin)) {*Begin = new_value;}
        }
  }


int main() {
  std::vector<int> vector {2, 3, 8, 1, 6, 5, 0, 7, 4, 9};
  replace_if(vector.begin(), vector.end(),
                  [](int element) {return element % 3; }, 0);
  for (auto iterator = vector.cbegin();
     iterator < vector.cend();) {
        std::cout << *iterator++ << " "; }
      std::cout << std::endl; }
