#include <iostream> 
#include <cstdlib>
#include <ctime>

int main () {
	std::srand(std::time(nullptr));
	std::cout << std::rand() % 2 << std::endl;
}
