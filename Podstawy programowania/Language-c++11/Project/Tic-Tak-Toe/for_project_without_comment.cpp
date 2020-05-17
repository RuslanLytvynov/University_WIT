#include <iostream>
#include <string>
char board[9] = {};

void clearscreen()// clears the console window, the clear screen function returns nothing.
{
    for(int i = 0; i<100; i++)
    {
        std::cout<<std::endl;}}

void clearboard()// this function clears the board and returns nothing
{
    for(int i = 0; i<9; i++)
    {
        board[i] = '-';}}

bool has_wonQ(char player)// function bool has_wonQ (char player) which checks when the game is over. The has_wonQ function returns bool (true or false, i.e. bool is a variable with two states, either 0 (zero) if the state is false and either 1 (one) if the state is true)
{
    int wins[][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7},{2,5,8}, {0,4,8}, {2,4,6}};
    for(int i = 0; i<8; i++)
    {
        int count = 0;
        for(int j = 0; j<3; j++)
        {
            if(board[wins[i][j]] == player)
                count++;}
        if(count == 3)
        {
            return true;}}
    return false;}


void print_board(std::string indent)// function void print board () {...} which will display the board on the screen
{
    std::cout <<"Game board\n";
    std::cout<<indent<<"-"<<board[6]<<"-|-"<<board[7]<<"-|-"<<board[8]<<"- \n";
    std::cout<<indent<<"-"<<board[3]<<"-|-"<<board[4]<<"-|-"<<board[5]<<"- \n";
    std::cout<<indent<<"-"<<board[0]<<"-|-"<<board[1]<<"-|-"<<board[2]<<"- \n";}

int get_move()// The function “get move ()“ is created (get user input)
{
    std::cout<<"\nTo take a step, enter a number from 1 to 9 in the console.\n";
    std::cout<<"\nAlways the first go X, and the second 0\n";
    std::cout<<"\nMoves menu: \n";
    std::cout<<"-7-|-8-|-9-" << std::endl;
    std::cout<<"-4-|-5-|-6-" << std::endl;
    std::cout<<"-1-|-2-|-3-" << std::endl;
    std::cout<<"\n";

    print_board("");
    std::cout << "\nEnter number: ";


    int move;
    std::cin >> move;
    while(move > 9 || move < 1 || board[move-1]!= '-') {
        std::cout<<"Enter number (1 to 9):\n";
        std::cin >> move;}
    return move;}

char play_and_get_winner() // function play_and_get_winner () it will return a char (character) i.e. play the game and get the winner
{
    int turn = 1;

    while(!has_wonQ('X') && !has_wonQ('0'))
    {
        clearscreen();
        int move = get_move();

        clearscreen();
        if(turn%2 == 1)
        {
            board[move-1]='X';
            if(has_wonQ('X'))
            {
                std::cout <<"\nX,Congratulations you won!\n";
                return 'X';}}
        else
        {
            board[move-1]='0';
            if(has_wonQ('0'))
            {
                std::cout <<"\nO,Congratulations you won!\n";
                return '0';}}
        turn++;
        if(turn == 10)
        {
            std::cout << "\nDraw\n";
            return 'D';}}}

int main()// Global function main
{
    std::cout <<"Hello\n\n";
    std::string reply = "y";
    int x_wins=0, o_wins=0, ties=0;

    while(reply == "y")
    {
        clearboard();
        char winner = play_and_get_winner();
        print_board("\t  ");

        switch(winner)
        {
        case 'X':
            x_wins++;
            break;
        case '0':
            o_wins++;
            break;
        case 'D':
            ties++;
            break;}

        std::cout << "\n\t*Winer statistic*\nPlayer X: " << x_wins
                  << ", Player 0: "<<o_wins << " and Ties: "<<ties<<"\n\n";
        std::cout << "\nWould you like to play again? (y/n): ";
        std::cin  >> reply;
        while(reply != "y" && reply !="n")
        {
            std::cout << "Please inter a valid reply (y/n):";
            std::cin  >> reply;}}
    return 0;}
