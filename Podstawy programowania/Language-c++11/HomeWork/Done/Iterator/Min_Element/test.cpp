#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
   std::vector<int> vector {1,2,3};
  std::vector<int>::iterator result = min_element(vector.begin(), vector.end());
  std::cout << result - vector.begin() << std::endl;
}
