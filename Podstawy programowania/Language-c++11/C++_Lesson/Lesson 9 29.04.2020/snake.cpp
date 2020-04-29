  #include <iostream>
  #include <fstream>
  #include <string>
  #include <vector>
  #include <conio.h>
  #include <cstdlib>
  #include <ctime>

  int main() {
    std::srand(std::time(nullptr));
    std::vector<std::string> maze;
    std::ifstream file("snake.txt");
    for (std::string line; std::getline(file, line);){
        maze.push_back(line);}
    file.close();
    std::vector<std::vector<int>> snake = {{1,1},{1,2},{1,3},{1,4},{1,5}};
    std::vector<int> heading {+1, 0};
    std::vector<int> treat {1 + std::rand() % 18, 1 + std::rand() & 28};
    while(true){
      if (snake[0] == treat){
        snake.push_back(std::vector<int>(2));
        treat = {1 + std::rand() % 18, 1 + std::rand() & 28};
      }
      std::vector<std::string> board = maze;
      for (std::vector<int> segment : snake){
        board[segment[0]][segment[1]] = '@';}
        board[treat[0]][treat[1]] = '#';
      for (std::string line: board){
        std::cout << line << std::endl;}
      if (kbhit()){
        char key = getch();
        switch (key) {
          case 's':{heading = {+1 , 0}; break;}
          case 'w':{heading = {-1 , 0}; break;}
          case 'd':{heading = {0 , +1}; break;}
          case 'a':{heading = {0 , -1}; break;}}}
      for(int i = snake.size() - 1; i > 0; i--){
        snake[i] = snake[i - 1];}
      snake[0][0] += heading[0];
      snake[0][1] += heading[1];
      if (board[snake[0][0]][snake[0][1]] == '@'){break;}
      for (int i = 0; i < 500000000; ++i);
          std::system("cls"); //clear onsole cstdlib
         }}


         //CODE TEACHER
// #include <cstdlib>
// #include <ctime>
// #include <fstream>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <conio.h>
//
//
//
// int main() {
//     std::srand(std::time(nullptr));
//     std::vector<std::string> maze;
//     std::ifstream file("snake.txt");
//     for (std::string line; std::getline(file, line);) {
//         maze.push_back(line); }
//     file.close();
//     std::vector<std::vector<int>> snake = {
//         {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};
//     std::vector<int> heading {+1,  0};
//     std::vector<int> treat {1 + std::rand() % 18, 1 + std::rand() % 28};
//     while (true) {
//         if (snake[0] == treat) {
//             snake.push_back(std::vector<int>(2));
//             treat = {1 + std::rand() % 18, 1 + std::rand() % 28}; }
//         std::vector<std::string> board = maze;
//         for (std::vector<int> segment: snake) {
//             board[segment[0]][segment[1]] = '@'; }
//         board[treat[0]][treat[1]] = '#';
//         for (std::string line: board) {
//             std::cout << line << std::endl; }
//         if (kbhit()) {
//             char key = getch();
//             switch (key) {
//                 case 'a': {heading = {+1,  0}; break; }
//                 case 'q': {heading = {-1,  0}; break; }
//                 case 'p': {heading = { 0, +1}; break; }
//                 case 'o': {heading = { 0, -1}; break; }}}
//         for(int i = snake.size() - 1; i > 0; i--){
//             snake[i] = snake[i - 1]; }
//         snake[0][0] += heading[0];
//         snake[0][1] += heading[1];
//         if (board[snake[0][0]][snake[0][1]] == '@') {
//             break; }
//         for (int i = 0; i < 50000000; ++i);
//         std::system("cls"); }}
