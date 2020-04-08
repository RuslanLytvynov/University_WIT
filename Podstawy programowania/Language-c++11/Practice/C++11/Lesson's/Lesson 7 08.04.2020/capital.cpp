//pliki i znaki (kod aski) // file's and symbol's
#include <iostream>
#include <fstream>  //biblioteka dla podkly4enija fajlow

using namespace std;

char upper(char c){
  return 'a' <= c && c <= 'z' ? 'A' + c - 'a' : c;
}

int main(int argc, char *argv[]){

  ifstream input(argv[1]); // OR  // ifstream input;  input.open("input.txt");
  ofstream output(argv[2]); //,std::ofstream::app);

  char c;
    while (input.get(c)){
      output << upper(c);}
    output.close();
    input.close();
}
