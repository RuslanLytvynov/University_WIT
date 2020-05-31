#include <cctype>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
bool blank(const std::string &string) {
  return std::all_of(string.cbegin(), string.cend(), [](char c) {return std::isspace(c); }); }

void trim(std::string &string) {
    auto iterator1 = std::find_if(string.begin(), string.end(),[](char c) {return !std::isspace(c); });
  string.erase(string.begin(), iterator1);
  auto iterator2 = std::find_if(string.rbegin(), string.rend(),[](char c) {return !std::isspace(c); });
  string.erase(iterator2.base(), string.end()); }

void shrink(std::string &string) {
  auto iterator = std::unique(string.begin(), string.end(),[](char c1, char c2) {
      return std::isspace(c1) && std::isspace(c2); });
      string.erase(iterator, string.end()); }

void capitalize(std::string &string) {
  std::transform(string.cbegin(), string.cend(), string.begin(),[](char c) {return std::toupper(c); }); }

void camelize(std::string &string) {
    bool flag = true;
    auto lambda = [&flag](char c)->char {
    if (flag) {
      if (std::isspace(c)) {
      return c; }
    else {
      flag = false;
      return std::toupper(c); }}
    else {
      if (std::isspace(c)) {
      flag = true;
      return c; }
    else {
    return std::tolower(c); }}};

    std::transform(string.cbegin(), string.cend(), string.begin(), lambda); }

bool contains(const std::string &string, const std::string &phrase) {
  auto iterator = std::search(string.cbegin(), string.cend(),phrase.cbegin(), phrase.cend(),[](char c1, char c2) {
    return std::toupper(c1) == std::toupper(c2); });
    return iterator != string.cend(); }


int main() {
std::vector<std::tuple<std::string, std::string, std::string>> persons;
std::ifstream file("phones.txt");
for (std::string line; std::getline(file, line);) {
if (!blank(line)) {
std::string phone, surname, name;
std::istringstream stream(line);
std::getline(stream, phone, ',');
std::getline(stream, surname, ',');
std::getline(stream, name, ',');
std::tuple<std::string, std::string, std::string> person(phone, surname, name);
persons.push_back(person); }}
file.close();
auto digitize = [](std::string &phone) {
auto iterator = std::remove_if(phone.begin(), phone.end(),
[](char c) {return !std::isdigit(c); });
phone.erase(iterator, phone.end()); };
std::for_each(persons.begin(), persons.end(),
[digitize](std::tuple<std::string, std::string, std::string> &p) {
digitize(std::get<0>(p)); });
std::for_each(persons.begin(), persons.end(),
[](std::tuple<std::string, std::string, std::string> &p) {
trim(std::get<1>(p));
shrink(std::get<1>(p));
capitalize(std::get<1>(p)); });
std::for_each(persons.begin(), persons.end(),
[](std::tuple<std::string, std::string, std::string> &p) {
trim(std::get<2>(p));
shrink(std::get<2>(p));
camelize(std::get<2>(p)); });
for (std::string phrase; std::cin >> phrase;) {
bool digits = std::all_of(phrase.cbegin(), phrase.cend(),
[](char c) {return std::isdigit(c); });
std::function<bool(const std::tuple<std::string, std::string, std::string> &)> condition;
if (digits) {
condition = [phrase](const std::tuple<std::string, std::string, std::string> &p) {
return contains(std::get<0>(p), phrase); }; }
else {
condition = [phrase](const std::tuple<std::string, std::string, std::string> &p) {
return contains(std::get<1>(p), phrase); }; }
auto iterator = std::partition(persons.begin(), persons.end(), condition);
std::sort(persons.begin(), iterator,
[](const std::tuple<std::string, std::string, std::string> &p1,
const std::tuple<std::string, std::string, std::string> &p2) {
return std::get<1>(p1) < std::get<1>(p2); });
std::for_each(persons.begin(), iterator,
[](const std::tuple<std::string, std::string, std::string> &p) {
std::cout << std::get<0>(p) << ","
<< std::get<1>(p) << ","
<< std::get<2>(p) << std::endl; }); }}
