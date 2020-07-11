#include <iostream>
#include <string>

std::string::iterator function (std::string::const_iterator ConstFirst,
                                std::string::const_iterator ConstLast,
                                std::string::iterator First){
    if(ConstFirst < ConstLast){
        while(ConstFirst < ConstLast){
                if(*ConstFirst==*(ConstFirst-1)){
                    ConstFirst++;
                }
                else{
                    *First++=*ConstFirst++;}}
        return First;}
    else {
        return First;}}

int main() {
    std::string in = "peppermint 1001 bubbles balloon gum", out(100, '*');
    auto e = function(in.cbegin(), in.cend(), out.begin());
    int n = e - out.begin();
    std::string s = out.substr(0, n);
    bool b = (s == "pepermint 101 bubles balon gum");
    std::cout << std::boolalpha << b << std::endl; }
