#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
int main() {
  std::srand(std::time(nullptr));
  std::set<int> ids;
  std::ifstream input("login.txt");
      for (int id; input >> id;) { ids.insert(id); }
       input.close();
        int id:
  if (std::cin >> id) {
    std::cout << std::boolalpha << (bool)ids.count(id) << std::endl; }
  else {
   while (!ids.insert(id = rand() % 1000000).second);
   std::cout << id << std::endl; }
   std::ofstream output("login.txt");
    for (int id: ids) { output << id << " "; }
     output << std::endl;
     output.close(); }
