#include <iostream>
using namespace std;


bool prime(int num){
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    cout << boolalpha << prime(97) << endl;
}

// #include<iostream>
// #include<cstdlib>
// using namespace std;
//
// bool prime(int n)
// {
// 	if(n<2)
// 		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą
//
// 	for(int i=2;i*i<=n;i++)
// 		if(n%i==0)
// 			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
// 	return true;
// }
//
// int main()
// {
// 	int n;
//
// 	cin>>n;
//
// 	if(prime(n)) //lub prime(n)==1
// 		cout<<"true"<<endl;
// 	else
// 		cout<<"false"<<endl;
// 	return 0;
// }


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
