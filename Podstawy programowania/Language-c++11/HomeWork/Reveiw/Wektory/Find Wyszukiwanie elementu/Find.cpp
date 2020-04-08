// #include <iostream>
// #include <vector>
// using namespace std;
//
// void find (std::vector<int> &v, int &a){
//   for(int i = 0; i < v.size(); i++)
//   {
//     if(a == v[i]){
//     a = i;
//     }
//     else{
//       i++;
//     }
//   }
//    }
//
// int main() {
// int result = find(std::vector<int> {3, -1, 7, 12, -5, 7, 10}, 7);
// std::cout << result << std::endl; }

#include <iostream>
#include <vector>



int find(const std::vector<int> &v, int num){
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == num) {
            return i;
        }
    }
    return v.size();
}

int main() {
int result = find(std::vector<int> {3, -1, 7, 12, -5, 7, 10}, 7);
    std::cout << result << std::endl; }
