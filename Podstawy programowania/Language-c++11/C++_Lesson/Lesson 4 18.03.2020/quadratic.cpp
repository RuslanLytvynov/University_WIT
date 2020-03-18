#include<iostream>
#include "cmath"
using namespace std;
//void nie zwraća return!!!
// & - ampercant oznacza referenciji (inna nazwa zminnej)
//operaciji na referenciji to samo co operaciji na zminnej
// &X == x1, &Y == x2
/*void*/ double quadratic(double &X, double &Y, double a, double b, double c){
  double delta = b * b - 4 * a * c;
  if (delta >= 0){
    X = (-b - sqrt(delta)) / a / 2;   // /a * 2 zle a mozna /(a*2)
    Y = (-b + sqrt(delta)) / a / 2;}//function dziłą tilko na włacnej kopii x1 x2 a b c
  return delta;
}

int main(){
  double a, b, c; //zmienny rzeczewisty
  cin >> a >> b >> c;
  double x1, x2;
  double delta = quadratic(x1, x2, a, b, c);
        // double delta = b * b - 4 * a * c;
        // x1 = (-b - sqrt(delta)) / a / 2;   // /a * 2 zle a mozna /(a*2)
        // x2 = (-b + sqrt(delta)) / a / 2;
  if (delta >= 0){
    cout << x1 << " " << x2;}}
