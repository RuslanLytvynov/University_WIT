#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]){
  ifstream file(argv[1]);
  int words = 0, chars = 0;
  for (char p = ' ', c; file.get(c); p = c){
    if ( isspace(p) && !isspace(c)){
      words++;}
    chars++;}
  file.close();
  cout << words << " " << chars << endl;}
