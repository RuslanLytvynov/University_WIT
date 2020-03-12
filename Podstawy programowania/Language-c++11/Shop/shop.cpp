#include <iostream>
using namespace std;

int main () {
	
	double a, b;
	cin >> a >> b;
	if (a==10 && b>=30 && b<60)
	{cout << "true";}
	else if  (a>10&& a<18 && b>=0 && b<60)
	{cout << "true";}
	else if (a==18 && b>= 0 && b<=30)
	{cout << "true";}
	else {cout << "false";}
}

