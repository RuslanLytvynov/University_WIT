#include <iostream>
#include <cmath>
using namespace std;

void fraction(double &integral, double &fractional, double num){
    if (num >= 0) {
        integral = floor(num);
        fractional = num - integral;
    }
}

int main() {
    double integral, fractional;
    fraction(integral, fractional, 3.14159);
    cout << integral << " " << fractional << std::endl;
}

// #include <iostream>
// #include <cmath>
// using namespace std;
//
// double fraction(double &a, double &b, double c){
//   int g = c;
//   b = c - g;
//   a = g;
//   return a , b ;
// }
//
// int main() {
// double integral, fractional;
// fraction(integral, fractional, 3.14159);
// cout << integral << " " << fractional << endl; }
