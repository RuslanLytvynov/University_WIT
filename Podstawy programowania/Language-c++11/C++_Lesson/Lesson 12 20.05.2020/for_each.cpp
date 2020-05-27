#include <functional>
#include <iostream>
#include <vector>
void for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end,
std::function<void(int&)> action) {
while (begin != end) {
action(*begin++); }}
int main() {
std::vector<int> vector(5);
for_each(vector.begin(), vector.end(), [](int &element){std::cin >> element; });
int index = 0;
for_each(vector.begin(), vector.end(),
[&index](int element) {
std::cout << index++ << " " << element << std::endl; }); }
