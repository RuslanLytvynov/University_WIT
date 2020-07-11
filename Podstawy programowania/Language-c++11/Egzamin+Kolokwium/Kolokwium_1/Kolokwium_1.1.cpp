#include <iostream>
#include <string>
#include <cctype>



std::string::iterator function(std::basic_string<char>::const_iterator x, std::basic_string<char>::const_iterator y,
  std::string::iterator z)
{
  auto c = z;
  char cached = '`';
  for (std::basic_string<char>::const_iterator i = x; i != y; ++i, ++z)
  {
    if (*i != ' ')
    {
      if (cached == '`')
      {
        cached = *i;
      }

      *z = cached;
    }
    else
    {
      *z = ' ';
      cached = '`';
    }
  }

  return c;
}

int main() {
    std::string in = "peppermint 1001 bubbles balloon gum", out(100, '*');
    auto e = function(in.cbegin(), in.cend(), out.begin());
    int n = e - out.begin();
    std::string s = out.substr(0, n);
    bool b = (s == "pppppppppp 1111 bbbbbbb bbbbbbb ggg");
    std::cout << std::boolalpha << b << std::endl; }
