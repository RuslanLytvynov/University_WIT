#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
	std::fstream input(argv[1]);
	std::ofstream output(argv[2]);
	int count = 1;

	for (char p = '\n', c; input.get(c); p = c) {
		if (p == '\n') {
			output << count << ' ';
			++count;
		}
		output << c;
	}
	input.close();
	output.close();
	return 0;
}
