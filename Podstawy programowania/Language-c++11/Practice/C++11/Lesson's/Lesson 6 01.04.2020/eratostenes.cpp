#include <iostream>
#include <vector>



std::vector<int> eratostenes(int limit) {
    std::vector<bool> sieve(limit, true);
    for (int number = 2; number < limit; ++number) {
        for (int multiple = 2 * number; multiple < limit; multiple += number) {
            sieve[multiple] = false; }}
    std::vector<int> primes;
    for (int number = 2; number < limit; ++number) {
        if (sieve[number]) {
            primes.push_back(number); }}
    return primes; }



int main() {
    int limit;
    std::cin >> limit;
    std::vector<int> primes = eratostenes(limit);
    for (int prime: primes) {
        std::cout << prime << " "; }
    std::cout << std::endl; }


// #include <iostream>
// #include <vector>  usi
// using namespace std;
// // 0 1 2 3 4 5 6 7 8 9
// // 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 0 1 0 1 0 1   2
// // 1 1 1 1 0 1 0 1 0 0   3
// vector<int> eratostenes(int limit) {
//   vector<bool> sieve(limit, true);
// for (int number = 2; number < limit; ++number){
//     for (int multiple = 2 * number; multiple < limit;multiple != number ){
//       sieve[multiple] = false;}}
//
//   vector<int> primes;
//
//   for (int number = 2; number < limit; number++){
//     if(sieve[number]){
//       primes.push_back(number);}}
//       return primes;
// }
//
// int main(){
//   int limit;
//   cin >> limit;
// vector<int> primes = eratostenes(limit);
//
//   for (int prime: primes){
//     cout << prime << " ";}
//     cout << endl;
// }
