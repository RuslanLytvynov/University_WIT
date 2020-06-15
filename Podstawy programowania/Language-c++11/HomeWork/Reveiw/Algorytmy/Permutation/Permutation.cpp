#include<iostream>
#include<vector>
#include<algorithm>
// #include <cstdlib>
 #include <ctime>


// int getNum(std::vector<int>& v)
// {
//     // Size of the vector
//     int n = v.size();
//     // Generate a random number
//     srand(time(NULL));
//     // Make sure the number is within
//     // the index range
//     std::random_shuffle(v.begin(),v.end());
//     // Get random number from the vector
//     int num = v[index];
//     // Remove the number from the vector
//     std::swap(v[index], v[n - 1]);
//     v.pop_back();
//     // Return the removed number
//     return num;
// }

std::vector<int> permutation(int n)
{

    // std::vector<int> v(n);

    // Fill the vector with the values
    // 1, 2, 3, ..., n
    for (int i = 0; i < n - 1; i++)
        v[i] = i + 1;

    // While vector has elements
    // get a random number from the vector and print it
    while (v.size()) {
        std::cout << getNum(v) << " ";
    }
}



int main() {
  std::srand(std::time(nullptr));
  std::vector<int> vector = permutation(5);
    for (int element: vector) { std::cout << element << " "; }
    std::cout << std::endl; }
