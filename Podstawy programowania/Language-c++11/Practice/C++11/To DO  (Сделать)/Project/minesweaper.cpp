#include <iostream>
#include <time.h>
//#include <windows.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
#define BOOM 10 //количество бомб на поле

//  1
void show_of_mines()
{   cout << "@ ";
}
void print_array_2D(int **Playing_field, bool ** open, const int SIZE)
{
    char strLetters[30] = {"ABCDEFGHFGHIJKLMNOPQRSTUVWXYZ"};
    cout << " ";
    for (int i = 0; i < SIZE; i++)
    {   cout << " " << strLetters[i];
    }
    cout << endl;

    for (int x = 0; x < SIZE; x++)
    {   if (x < 10) cout << x << " |";
        else        cout << x << "|";

        for (int y = 0; y < SIZE; y++)
        {
            if (open[x][y])
            {   switch(Playing_field[x][y])
                {   case -1:
                    show_of_mines();
                    break;

                    case 0:
                    cout << "* ";
                    break;

                    default:
                    cout << Playing_field[x][y] << " ";
                }
            }
            else
            {   cout << "& ";
            }
        }
        cout << endl;
    }
}

// проверяет ячейку на пустоту (true), выход за пределы массива возвращает false
bool empty(int **Playing_field, int i, int j, const int SIZE)
{   if ((i >= 0) && (i < SIZE))
    {   if ((j >= 0) && (j < SIZE))
        {   if (Playing_field[i][j] == 0) return true;
        }
    }
    return false;
}
// рекурсивная функция, которая открывает поля в точке попадания
void clean(int **Playing_field, bool **open, int i, int j, const int SIZE)
{   // проверим на выход за пределы массива
    if ((i >= 0) && (i < SIZE))
    {   if ((j >= 0) && (j < SIZE))
        {   // проверим, не было ли открыто поле раньше
            if (!open[i][j])
            {   open[i][j] = true;  //откроем
                // если поле пустое (=0), просто пооткрываем всех его соседей
                if (Playing_field[i][j] == 0)
                {   clean(Playing_field, open, i - 1, j - 1, SIZE);
                    clean(Playing_field, open, i - 1, j, SIZE);
                    clean(Playing_field, open, i - 1, j + 1, SIZE);
                    clean(Playing_field, open, i, j - 1, SIZE);
                    clean(Playing_field, open, i, j + 1, SIZE);
                    clean(Playing_field, open, i + 1, j - 1, SIZE);
                    clean(Playing_field, open, i + 1, j, SIZE);
                    clean(Playing_field, open, i + 1, j + 1, SIZE);
                }
                // если не пустое (!=0) открываем только пустых (=0) соседей
                else
                {   if (empty(Playing_field, i - 1, j - 1, SIZE)) clean(Playing_field, open,
                                i - 1, j - 1, SIZE);
                    if (empty(Playing_field, i - 1, j, SIZE)) clean(Playing_field, open, i - 1, j,
                                SIZE);
                    if (empty(Playing_field, i - 1, j + 1, SIZE)) clean(Playing_field, open, i - 1,
                                j + 1, SIZE);
                    if (empty(Playing_field, i, j - 1, SIZE)) clean(Playing_field, open, i, j - 1,
                                SIZE);
                    if (empty(Playing_field, i, j + 1, SIZE)) clean(Playing_field, open, i, j + 1,
                                SIZE);
                    if (empty(Playing_field, i + 1, j - 1, SIZE)) clean(Playing_field, open, i + 1,
                                j - 1, SIZE);
                    if (empty(Playing_field, i + 1, j, SIZE)) clean(Playing_field, open, i + 1, j,
                                SIZE);
                    if (empty(Playing_field, i + 1, j + 1, SIZE)) clean(Playing_field, open, i + 1,
                                j + 1, SIZE);
                }
            }
        }
    }
}

// проверяет ячейку на мину ; выход за пределы возвращает false
bool mine(int **Playing_field, int i, int j, const int SIZE)
{   if ((i >= 0) && (i < SIZE))
    {   if ((j >= 0) && (j < SIZE))
        {   if (Playing_field[i][j] == -1) return true;
        }
    }
    return false;
}

void empty_play_space(int **Playing_field, bool ** open, const int SIZE)
{   for (int i = 0; i < SIZE; i++)
    {   for (int j = 0; j < SIZE; j++)
        {   if (Playing_field[i][j] == -1)
            {   open[i][j] = true;
            }
        }
    }
}

bool win_or_lose(int **Playing_field, bool ** open, const int SIZE)
{   for (int x = 0; x < SIZE; x++)
    {   for (int y = 0; y < SIZE; y++)
        {   if ((Playing_field[x][y] != -1) && (!open[x][y])) return false;
        }
    }
    return true;
}

// в случае проигрыша эта функция откроет все мины
void openmines(int **Playing_field, bool ** open, const int SIZE)
{   for (int i = 0; i < SIZE; i++)
    {   for (int j = 0; j < SIZE; j++)
        {   if (Playing_field[i][j] == -1) open[i][j] = true;
        }
    }
}

void final(bool loser, int **Playing_field, bool ** open, const int SIZE)
{   system("cls");
    print_array_2D(Playing_field, open, SIZE);
    if (loser)
    {   cout << "You Lose!(";
    }
    else
    {   cout << "You Win!)";
    }
    cout << endl;
}
void inputSize(int &size)   //запрос на ввод колиство элементов массива
{   while (true)
    {   cout << "ENTER FIELD SIZE (10):" << endl << endl;
        cin >> size;
        if (cin.fail())
        {   cout << "ERROR, ENTER LESS VALUE" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size > 0) break;
    }
}

//  2
void rules()
{   cout << "\t\t\t\t\t\t\t\tSAPER: RULES AND GENERAL INFORMATION" << endl << endl <<
         endl << endl;
    cout << "\tStart by opening one cell." << endl;
    cout << "\tЧисло в ячейке показывает, сколько мин скрыто вокруг данной ячейки. Это число поможет понять вам, где находятся безопасные ячейки, а где находятся бомбы."
         << endl;
    cout << "\tЕсли рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически."
         << endl;
    cout << "\tЕсли вы открыли ячейку с миной, то игра проиграна." << endl;
    cout << "\tЕсли в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг данной. Это число помогает понять, где находятся безопасные ячейки."
         << endl;
    cout << "\tИгра продолжается до тех пор, пока вы не откроете все не заминированные ячейки."
         << endl << endl << endl;
    cout << "\tУдачной игры!)" << endl << endl << endl << endl << endl << endl;
}






#include "conio.h"
int main()
{   srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "Russian");

    char choice {};
    while (true)
    {   system("cls");
        cout << "1 - Play " << endl;
        cout << "2 - GAME RULES << MINEER >> " << endl;
        cout << "0 - Exit" << endl << endl << endl;
        cout << "MAKE YOUR CHOICE:" << endl << endl;
        cin >> choice;
        cout << endl;

        cin.ignore(100, '\n');
        if (choice == '0') break;
        switch (choice)
        {   case '1':
                {   int SIZE = 0;
                    inputSize(SIZE);
                    int **Playing_field = new int *[SIZE];
                    bool **open = new bool *[SIZE];

                    for (int i = 0; i < SIZE; i++)
                    {   *(Playing_field + i) = new int[SIZE];
                    }
                    for (int i = 0; i < SIZE; i++)
                    {   *(open + i) = new bool[SIZE];
                    }


                    for (int i = 0; i < SIZE; i++)
                    {   for (int j = 0; j < SIZE; j++)
                        {   Playing_field[i][j] = 0;
                                     open[i][j] = false;
                        }
                    }

                    int i, j;
                    // заполняем массив поля минами
                    for (int c = 0; c < BOOM; c++)
                    {   do
                        {   i = rand() % SIZE;
                            j = rand() % SIZE;
                        }
                        while (Playing_field[i][j] != 0);

                        Playing_field[i][j] = -1;
                    }
                    // заполняем массив поля цифрами
                    for (int i = 0; i < SIZE; i++)
                    {   for (int j = 0; j < SIZE; j++)
                        {   if (Playing_field[i][j] != -1)
                            {   int quantity {};
                                if (mine(Playing_field, i - 1, j - 1, SIZE)) quantity++;
                                if (mine(Playing_field, i - 1, j, SIZE)) quantity++;
                                if (mine(Playing_field, i - 1, j + 1, SIZE)) quantity++;
                                if (mine(Playing_field, i, j - 1, SIZE)) quantity++;
                                if (mine(Playing_field, i, j + 1, SIZE)) quantity++;
                                if (mine(Playing_field, i + 1, j - 1, SIZE)) quantity++;
                                if (mine(Playing_field, i + 1, j, SIZE)) quantity++;
                                if (mine(Playing_field, i + 1, j + 1, SIZE)) quantity++;
                                Playing_field[i][j] = quantity;
                            }
                        }
                    }
                    while (true)
                    {   system("cls");
                        cout << "*****************************" << endl << endl;
                        cout << "* SAPER MISTAKES ONCE*" << endl << endl;
                        cout << "*****************************" << endl;
                        cout << endl << endl;
                        print_array_2D(Playing_field, open, SIZE);
                        cout << endl;
                        // запрашиваем координаты удара
                        char input_coordinate[4] { '\0' };
                        cout << "Enter strike coordinates (E7): ";
                        cin.clear();
                        cin.ignore(100, '\n');
                        cin.get(input_coordinate, 4);

                        if ((input_coordinate[0] >= 65) && (input_coordinate[0] <= 90))
                        {   j = input_coordinate[0] - 65; // буква в промежутке от A до Z
                        }
                        else if ((input_coordinate[0] >= 97) && (input_coordinate[0] <= 122))
                        {   j = input_coordinate[0] - 97; // буква в промежутке от a до z
                        }
                        else
                        {   std::cout << "Do not try to cheat!!"; _getch();
                            continue;
                        }

                        i = input_coordinate[1] - 48;
                        if(i < 0  && 9 < i)
                        {   std::cout << "Do not try to cheat!!";
                            std::cout << i;
                            _getch();
                            continue;
                        }

                        // далее проверяем все восемь окрестных полей на пустые клетки показываем некий кусок поля
                        clean(Playing_field, open, i, j, SIZE);

                        if (mine(Playing_field, i, j, SIZE))
                        {   openmines(Playing_field, open, SIZE);
                            final(true, Playing_field, open, SIZE);
                            break;
                        }
                        if (win_or_lose(Playing_field, open, SIZE))
                        {   final(false, Playing_field, open, SIZE);
                            break;
                        }
                    }

                    for (int i = 0; i < SIZE; i++)
                    {   delete[] * (Playing_field + i);
                    }
                    delete Playing_field;
                    for (int i = 0; i < SIZE; i++)
                    {   delete[] * (open + i);
                    }
                    delete open;
                }
                break;

            case '2':
                {   rules();
                }
                break;

            default:
                cout << "Error, try again, press the <Enter> button to try again"
                     << endl;
                break;
        }
        system("pause");
    }
    return 0;
}
