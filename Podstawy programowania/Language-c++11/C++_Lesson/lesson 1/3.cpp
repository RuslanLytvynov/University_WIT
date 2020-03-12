#include <iostream> 
#include <cstdlib>
#include <ctime>

int main () {
	std::srand(std::time(nullptr));
	int player, computer = 2 * (std::rand() % 2) - 1;
	std::cin >> player;
/*	
	if (player * computer > 0 ) {
		std::cout << "true" << std::endl;}
	else { 
		std::cout << "false" << std::endl;}	
*/
	std::cout << std::boolalpha << (player * computer > 0 ? "true" : "false") << std::endl;		
}
