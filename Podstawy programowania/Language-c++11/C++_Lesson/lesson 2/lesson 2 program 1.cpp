#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;  //while && for 

int main(){
	srand(time(nullptr));
	for (int counter = 0; counter < 10; counter++)	{
		int a = 1 + rand() % 10, b = 1 + rand() % 10;
		int answer;
		do {		
			cout << a <<  " * " << b << " = ";
			cin >> answer; }
		while(answer != a * b);}}


