#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]){
  double speed = atof(argv[1]);
  // cin >> speed;
  vector<double> limits {0.5, 6.5,  11.5,  19.5,  29.5,  39.5, 50.5,
                        62.5,  75.5,  87.5,  102.5,  117.5 };
  int degree = 0;
  for (; degree < limits.size() && limits[degree] < speed; degree++);
    cout << degree << endl;
// for (int i = 0; i < argc; i++){
//   cout << argv[i] << " ";
// }
}
