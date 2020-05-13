#include <iostream>
#include <string>

std::string initials(std::string a) {
	std::string ret;
	if (a[0] != ' ') {
		ret += a[0];
		for (int i = 1; i < a.size(); ++i) {
			if (a[i] == ' ') {
				if (a[i + 1] != ' ') {
					ret += a[i + 1];}}}
	}
	else {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == ' ') {
				if (a[i + 1] != ' ') {
					ret += a[i + 1];}}}}
	return ret;
}

int main() {
	 std::cout << initials("John Fitzgerald Kennedy") << std::endl;
   std::cout << initials(std::string("andy warhol")) << std::endl; }
