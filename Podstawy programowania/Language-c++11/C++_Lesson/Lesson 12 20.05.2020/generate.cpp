#include <functional>
#include <iostream>
#include <vector>
void for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end,
std::function<void(int&)> action) {
while (begin != end) {
action(*begin++); }}
void generate(std::vector<int>::iterator begin, std::vector<int>::iterator end,
std::function<int()> value) {
while (begin != end) {
*begin++ = value(); }}
int main() {
std::vector<int> vector(5);
int index = 1;
generate(vector.begin(), vector.end(), [&index]{return index++; });
for_each(vector.begin(), vector.end(),
[](int element){std::cout << element << " "; });
std::cout << std::endl; }
