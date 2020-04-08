// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// void printVector(vector<int> &v){
//   for(int i = 0; i< v.size();i++){
//     std::cout << v[i] << " ";
//   }
//   std::cout << std::endl;
// }
//
// void sort(vector<int> &v){
// bool unordered;
// do{
//   unordered = false;
// for(int i = 0; i < v.size();i++){
//   if (v[i] > v[i+1]){
//     unordered = true;
//     swap(v[i+1],v[i]);
//     for (int n : v){
//       cout << n << " ";
//     }
//     cout << endl;
//   }
// }}
// while(unordered);}
//
// int main(){
//  vector<int> v;
//   for(int i; cin >> i;){
//     v.push_back(i);}
//     sort(v);
//   }

#include <iostream>
#include <vector>


int main() {
    std::vector<int> v;
    for (int i; std::cin >> i;) {
        v.push_back(i);
    }

    for (int i = 0; i  < (v.size()); ++i) {
        int min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min] ) {
                min = j;
            }
        }
        std::swap(v[min], v[i]);
        for (int n:v) {
            std::cout << n << " ";
        }
        std::cout<<std::endl;
    }
}
