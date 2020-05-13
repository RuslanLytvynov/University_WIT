#include <iostream>
#include "vector"

oid selection_sort(std::vector<int>::iterator b,
                    std::vector<int>::iterator e, int n){

}

int main(){
  std::vector<int> v {-7, 5, 2, 2, 11, 2, 3};
  auto r = find(v.begin(), v.end(), 11);
  std::cout << r - v.begin() << std::endl;
}
