#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char *argv[]) {
    int n = std::atof(argv[1]);
    std::vector<int> nom = {1,2,5,10,20,50,100,200};
    int x = nom.size() - 1;

    while (n != 0) {
        if (nom[x] <= n) {
            std::cout << nom[x] << " ";
            n -= nom[x];
        }
        else {
            x -= 1;
        }
    }
    std::cout << std::endl;
}
