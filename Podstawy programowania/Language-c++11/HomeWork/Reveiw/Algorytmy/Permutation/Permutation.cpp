#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <ctime>


std::vector<int> permutation(
  std::vector<int> number)
{
  std::vector<int> v2 = number;
  std::iota(v2.begin(), v2.end(), number);
  std::shuffle(v2.begin(), v2.end());

return v2;
}

int main() {
  std::srand(std::time(nullptr));
  std::vector<int> vector = permutation(5);
    for (int element: vector) { std::cout << element << " "; }
    std::cout << std::endl; }
