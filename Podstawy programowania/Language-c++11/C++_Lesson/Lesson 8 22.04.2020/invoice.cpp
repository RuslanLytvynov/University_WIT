#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
  for (string line; getline(cin, line);){
    string word;
    for (istringstream stream(line); stream >> word) {
      cout << word << " ";}

      cout << line << endl; }}
