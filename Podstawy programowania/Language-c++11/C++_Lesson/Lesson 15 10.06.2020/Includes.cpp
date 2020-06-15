#include <iostream>
#include <vector>

int includes(
  std::vector<int>::const_iterator Begin1,
  std::vector<int>::const_iterator End1,
  std::vector<int>::const_iterator Begin2,
  std::vector<int>::const_iterator End2){

    for (; Begin2 != End2; ++Begin1)
    {
        if (Begin1 == End1 || *Begin2 < *Begin1)
            return false;
        if ( !(*Begin1 < *Begin2) )
            ++Begin2;
    }
    return true;
  }


int main() {
   const std::vector<int> vector1, vector2 {7};
    bool result = includes(vector1.begin(), vector1.end(),
     vector2.begin(), vector2.end());
      std::cout << std::boolalpha << result << std::endl; }
