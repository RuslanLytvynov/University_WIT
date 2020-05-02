#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char *str = new char [1024];
    int i=0;
    ifstream base("test.txt");
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }
    base.close();
    ofstream create("output.txt");
    create.close();
    delete str;
    cout << i - 1 << '\n';
    system ("pause");
}
