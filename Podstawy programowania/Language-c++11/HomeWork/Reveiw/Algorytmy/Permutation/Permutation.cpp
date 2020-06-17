#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <ctime>


int RandomVector(std::vector<int>& v)
{
    int n = v.size();

    srand(time(NULL));

    int index = rand() % n;

    int num = v[index];

    std::swap(v[index], v[n - 1]);
    v.pop_back();

    return num;
}

std::vector<int> permutation(int n)
{
    std::vector<int> v(n);

    for (int i = 0; i < n - 1; i++)
        v[i] = i + 1;

      while (v.size()) {
        std::cout << RandomVector(v) << " ";}}

int main() {
  std::srand(std::time(nullptr));
  std::vector<int> vector = permutation(5);
    for (int element: vector) { std::cout << element << " "; }
    std::cout << std::endl; }
