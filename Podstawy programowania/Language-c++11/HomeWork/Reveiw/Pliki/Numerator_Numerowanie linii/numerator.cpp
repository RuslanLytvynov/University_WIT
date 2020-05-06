#include <fstream>
#include <iostream>


int main(int argc, char* argv[]) {
  int count = 1;
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    char str[256];
    while (!input.eof()) {
        input.getline(str, 1000);
        output << count << " " << str << '\n';
        ++count;

    }
   input.close();
   output.close();
}

// #include <iostream>
// #include <fstream>
// #include <string>
//
//
// int main(){
// unsigned count = 1;
//
//   std::ifstream input("input.txt");  std::ofstream output("output.txt");
//
//    std::string word;
//
//   while (getline(input, word))
//   {
//       output  << count  << " " << word << "\n";
//      count ++;
//   }}
