#include <vector>
#include <iostream>
#include <functional>

std::vector<int>::iterator find_if(
std::vector<int>::iterator Begin,
std::vector<int>::iterator End,
std::function<bool(int&)> logic){

  for (; Begin != End; ++Begin) {
        if (logic(*Begin)) {
            return Begin;
        }
    }
    return End;
}


// std::vector<int>::const_iterator find_if(
// std::vector<int>::const_iterator ConstBegin,
// std::vector<int>::const_iterator ConstEnd,
// std::function<bool(const int&)> logic){
//
//   for (; ConstBegin != ConstEnd; ++ConstBegin) {
//         if (logic(*ConstBegin)) {
//             return ConstBegin;
//         }
//     }
//     return ConstEnd;
// }


int main() {
   std::vector<int> vector {3, -1, 7, 12, -5, 7, 10};
   std::vector<int>::iterator result1 = find_if(vector.begin(), vector.end(),
    [](int element) {return element > 10; });
  std::vector<int>::const_iterator result2 = find_if(vector.cbegin(), vector.cend(),
  [](int element) {return element > 10; });
   std::cout << result1 - vector.begin() << " " << result2 - vector.cbegin() << std::endl; }
