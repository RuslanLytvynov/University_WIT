#include <iostream>
#include <fstream>
#include <string>


int main(){
unsigned count = 1;

  std::ifstream input("input.txt");  std::ofstream output("output.txt");

   std::string word;

  while (getline(input, word))
  {
      output  << count  << " " << word << "\n";
     count ++;
  }}
