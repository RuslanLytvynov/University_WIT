#include<iostream>
#include<cstdlib>
using namespace std;

bool prime(int n)
{
	if(n<2)
		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}

int main()
{
	int n;

	cout<<"Podaj liczbę: ";
	cin>>n;

	if(prime(n)) //lub czy_pierwsza(n)==1
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}


// #include<iostream>
// using namespace std;
//
// int prime(bool a){
//   cout << boolalpha << a << " ";
//   return a;
// }
//
// int main() {
//   bool b ;
// cin >> b;
// prime(b);
// }
