#include<iostream>
using namespace std;
double clock(double &small, double &large, int &hour, int &minute){
{
  //  small = 30/hour ;//((30 * hour) % 360) + (hour + (minute/60)); //minutowa
  // large = 6 * minute;  // godzinowa
  small = 0.5 * (60 * hour + minute);
  if (small > 360){
      small = small - 360;
  }
  large = 6 * minute;
}
}

int main(){
  int hour, minute;
  cin >> hour >> minute;
  double small, large; //kont wychulenija wkazuwek malej i większej
  clock(small, large, hour, minute);
  cout << small << " " << large;
}
