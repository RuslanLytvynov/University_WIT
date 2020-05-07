#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    int s = std::atof(argv[1]);
    std::fstream input(argv[2]);
    std::ofstream output(argv[3]);

    for (char c; input.get(c);) {
        if ((c >= 'A') && (c <= 'Z') || (c >= 'a') && (c <= 'z')) {
            if ((c >= 'A') && (c <= 'Z')) {
                if (c + s < 'A') {
                    output << char(c + s + 26);
                }
                else if (c + s > 'Z') {
                    output << char(c + s - 26);
                }
                else {
                    output << char(c + s);
                }
            }
            if ((c >= 'a') && (c <= 'z')) {
                if (c + s < 'a') {
                    output << char(c + s + 26);
                }
                else if (c + s > 'z') {
                    output << char(c + s - 26);
                }
                else {
                    output << char(c + s);
                }
            }
        }
        else {
            output << c;
        }
    }

    input.close();
    output.close();

    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <cstring>
//
// int main(int argc, char* argv[]) {
//     int shift = atoi(argv[1]);
//     std::ifstream input(argv[2]);
//     std::ofstream output(argv[3]);
//     char str[256];
//     while (!input.eof()) {
//         input.getline(str, 100000);
//
//
//         for (int i = 0; i < strlen(str); ++i) {
//
//             if (str[i] <= 64 or (str[i] >= 91 && str[i] <= 96) or str[i] >= 123) {
//                 continue;
//             }
//             else{
//                 if(((islower(str[i]) and (str[i] + shift >= 123))) or
//                    (isupper(str[i]) and (str[i] + shift >= 91))){
//                     str[i] -= 25;
//
//                     continue;
//                 }
//                 if((islower(str[i]) and (str[i] + shift <= 96)) or
//                    (isupper(str[i]) and (str[i] + shift <= 64))){
//                     str[i] += 25;
//
//                     continue;
//                 }
//                 str[i] += shift;
//             }
//         }
//         output<<str;
//         output << std::endl;
//     }
//     input.close();
//     output.close();
// }
