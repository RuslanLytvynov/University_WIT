#include<iostream>
#include<iomanip>
//Tablica mnozenija przecz liczby n
using namespace std;

int main(){
	int n;
	cin >> n;
	int w = 0;
	for (int m = n * n; m; m /= 10){ //m; --> sprawdza czy m jest nie zerowy 
		w++;
	}
	//double a = (n * n) % 10; // +setw(a) dla tego zeby by³a dobra kolumna 
	for (int i = 1;i <= n;i++){
		for (int j = 1; j <= n; j++){
			cout << setw(w) << i * j << " ";}
		cout << endl;
		//int b = n * i;
		//cout << n << "*" << i << " " "=" " " << b << " " <<endl;
	}
}
