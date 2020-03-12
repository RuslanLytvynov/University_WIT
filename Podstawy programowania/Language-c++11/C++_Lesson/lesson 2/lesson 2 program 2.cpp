#include<iostream>

using namespace std;

int main() {
	int liczba;
	cin >> liczba;
	for(int i = 2; liczba != 1; i++){
		while(liczba % i == 0){
		liczba /= i;
		cout << i << " ";}
		
	}
}
