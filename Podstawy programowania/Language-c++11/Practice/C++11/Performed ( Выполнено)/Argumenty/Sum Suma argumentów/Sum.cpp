#include <iostream>
#include <cstdlib>


int main(int argc, char* argv[]) {
    double sum = 0;
    for (int i = 0; i < argc ; ++i) {
        sum += std::atof(argv[i]);
   }
    std::cout << sum << std::endl;
}
