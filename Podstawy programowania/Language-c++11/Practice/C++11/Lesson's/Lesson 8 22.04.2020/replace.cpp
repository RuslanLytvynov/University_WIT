#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
string source = argv[1] , target = argv[2];
for(string text; getline(cin,text);){
  for( int index = 0;
    (index = text.find(source, index)) != string::npos;
     index += target.size()){
      text.replace(index, source.size(), target); }
      cout << text << endl;}}
