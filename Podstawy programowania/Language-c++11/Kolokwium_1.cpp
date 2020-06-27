#include <iostream>
#include <string>

std::string::iterator function(
  std::basic_string<char>::const_iterator ConstBegin,
  std::basic_string<char>::const_iterator ConstEnd,
  std::string::iterator Begin){
    auto s = Begin;
    char strin = '`';
    for (std::basic_string<char>::const_iterator i = ConstBegin; i != ConstEnd; ++i, ++Begin)
    {
      if (*i != ' '){
        if (strin == '`')
        {
          strin = *i;}
        *Begin = strin;}
      else
      {
        *Begin = ' ';
        strin = '`';}}
    return s;}

int main() {
    std::string in = "peppermint 1001\tbubbles\t\rballoon\t\r\ngum", out(100, '*');
    auto e = function(in.cbegin(), in.cend(), out.begin());
    int n = e - out.begin();
    std::string s = out.substr(0, n);
    bool b = (s == "peppermint 1001\\tbubbles\\t\\rballoon\\t\\r\\ngum");
    std::cout << std::boolalpha << b << std::endl; }
