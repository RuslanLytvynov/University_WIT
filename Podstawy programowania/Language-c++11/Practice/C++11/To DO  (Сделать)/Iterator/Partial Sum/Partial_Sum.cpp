#include <vector>
#include <iostream>

std::vector<int>::const_iterator partial_sum(std::vector<int>::const_iterator ConstStart,
                                              std::vector<int>::const_iterator ConstEnd,
                                              std::vector<int>::iterator Start){
    auto  summa = 0;
    for (auto i = ConstStart; i < ConstEnd; ++i) {
        summa += *i;
        *Start++ = summa;}
    return Start;}


int main() {
    std::vector<int> vector {3, 2, -1, 3, 4};
    auto result = partial_sum(vector.cbegin(), vector.cend(), vector.begin());
    for (auto iterator = vector.cbegin(); iterator < result;) {
        std::cout << *iterator++ << " ";

    }
    std::cout << std::endl;
}
