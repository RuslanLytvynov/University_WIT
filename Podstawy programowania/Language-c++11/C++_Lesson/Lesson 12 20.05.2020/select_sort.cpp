#include <functional>
#include <iostream>
#include <utility>
#include <vector>
void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end,
std::function<bool(int, int)> compare =
[](int element1, int element2) {return element1 < element2; }) {
while (begin != end) {
auto minimum = begin;
for (auto iterator = begin; ++iterator != end;) {
if (compare(*iterator, *minimum)) {
minimum = iterator; }}
std::iter_swap(begin++, minimum); }}
int main() {
std::vector<int> vector {13, 2, 21, 5, 8, 5, 7, 10};
selection_sort(vector.begin(), vector.begin() + 4);
selection_sort(vector.begin() + 4, vector.end(),
[](int element1, int element2) {return element1 > element2; });
for (auto iterator = vector.cbegin(); iterator != vector.cend(); ++iterator) {
std::cout << *iterator << " "; }
std::cout << std::endl; }
