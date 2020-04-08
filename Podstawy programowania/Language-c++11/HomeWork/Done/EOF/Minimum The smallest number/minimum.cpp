#include <iostream>
using namespace std;

int main() {
    double min;
    if (cin >> min){
        for (double n; cin >> n;) {
            if (n < min) {
                min = n;
            }
        }
        cout << min << endl;
    }

}


// #include <iostream>
// using namespace std;
// int main()
// {
//         double counter, min, n;
//         cin >> n;
//         min =  n;
//         for(counter=1;cin >> n;)
//         {
//                 if (n<min) min=n;
//
//         }
//         cout <<  min << " ";
//
//
// }



// int main(){
//   int n = 15;
//   double arr[n];
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];}
//         int a = 1;
//         int min_el = 0;
//         for (int i = 1; i < n; i++){
//           if(arr[i] <= arr[a]){
//              min_el = arr[i];}
//              }
//              cout << min_el << " ";
// }
