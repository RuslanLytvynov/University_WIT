#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a,b;
	int calc;
	cin >> calc;
	if (calc == 5)
	 {
		switch (calc)
		{
		case 5:
		cin >> a;
		cout << sqrt(a);}
	 }	
	else {
		cin >> a >> b;
		switch (calc){
			case 1:
				cout << a+b;
				break;
			case 2:
				cout << a-b;
				break;
			case 3:
				cout << a*b;
				break;
			case 4:
				cout << a/b;
				break;
			default:
				cout << "error";
				break;}
		}
}
