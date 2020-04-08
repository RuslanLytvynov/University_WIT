#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double x1, x2, y1, y2;
    double sum = 0;

    if(cin >> x1 >> y1){
        for (;cin>>x2>>y2;) {
              sum += sqrt(pow(x2-x1,2)+pow(y2-y1,2));
              x1 = x2; y1 = y2;
        }
        cout << sum << endl;
    }

}


// #include <iostream>
// #include <cmath>
//
// using namespace std;
//
//
// int main()
// {
//   double x1, x2, y1, y2;
//      double sum = 0;
//
//      cin >> x1 >> y1;
//      while (cin >> x2 >> y2) {
//            sum += sqrt(pow(x2-x1,2)+pow(y2-y1,2));
//            x1 = x2; y1 = y2;
//      }
//      cout << sum;
// }
