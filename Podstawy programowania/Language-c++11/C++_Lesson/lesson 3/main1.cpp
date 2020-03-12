#include<iostream>
using namespace std;

int main() {
	double sum = 0;
	int count = 0;
	for (double number; cin >> number;){
		sum += number;
		++count;}
		cout << sum / count <<endl;}
