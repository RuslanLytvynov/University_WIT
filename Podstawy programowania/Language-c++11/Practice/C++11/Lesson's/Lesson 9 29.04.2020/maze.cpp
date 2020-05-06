//gra labirynt w trybi tekstołym (maze - labirynt)
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <conio.h>
using namespace std;

int main() {
  std::vector<string> maze;
  std::ifstream file("maze.txt");
  for (std::string line; std::getline(file, line);){
      maze.push_back(line);}
  file.close();
  int row = 1, column = 1;
  while(true){
    std::vector<std::string> board = maze;
    board[row][column] = '&';
    for (std::string line: board){
      std::cout << line << std::endl;}
    char key = getch(); //linux NOOOOO  conio.h
    // std::cin.get(key);
    switch (key) {
                case 's': {
                    if(maze[row+1][column] == ' ')
                        ++row;
                    break; }
                case 'w': {
                    if(maze[row-1][column] == ' ')
                        --row;
                    break; }
                case 'd': {
                    if(maze[row][column+1] == ' ')
                        ++column;
                    break; }
                case 'a': {
                    if(maze[row][column-1] == ' ')
                        --column;
                    break; }
                    }
        std::system("cls"); //clear onsole cstdlib
       }}
