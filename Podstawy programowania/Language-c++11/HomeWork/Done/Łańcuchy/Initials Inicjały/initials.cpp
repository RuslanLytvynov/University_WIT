// C++ program to print initials of a name
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void initials(const string& )
{
	if (string&.length() == 0)
		return;

	// Since touuper() returns int, we do typecasting
	cout << (char)toupper(name[0]);

	// Traverse rest of the string and print the
	// characters after spaces.
	for (int i = 1; i < name.length() - 1; i++)
		if (name[i] == ' ')
			cout << " " << (char)toupper(name[i + 1]);
}

// Driver code
int main() {
  // string name = "prabhat kumar singh";
    // initials(name);

 std::cout << initials("John Fitzgerald Kennedy") << std::endl;
std::cout << initials(std::string("andy warhol")) << std::endl;
}
