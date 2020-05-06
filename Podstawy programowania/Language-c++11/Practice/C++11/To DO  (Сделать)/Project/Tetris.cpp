#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <random>

const int KEY_UP = 72; //определение клавиши "вверх"
const int KEY_DOWN = 80; //определение клавиши "вниз"
const int KEY_LEFT = 75; //определение клавиши "влево"
const int KEY_RIGHT = 77; //определение клавиши "вправо"
const int KEY_SPACE = 32; //определение клавиши "пробел"
const int KEY_ESC = 27; //определение клавиши "escape"
const int KEY_ENTER = 13; //определение клавиши "enter"

const int SIZEX = 16; //-ширина поля
const int SIZEY = 20; //-длина поля
const int FMAP_COUNTS = 7; //количество фигур тетриса

const char SCR_SP = (char)183; //закрашивание поля
const char SCR_OB = (char)2; //закрашивание фигуры
//char main_color[] = "color ##";
int screen[SIZEX][SIZEY] = {0}; //размер экрана
int map[4][4]; //фигура
int px(0), py(0), score(0), nextmap(0);
const char* GAME_TITLE ="###########  #########  ###########  ######## ####    ####  #########  \n"
                        "##   ##  ##  ##         ##   ##  ##  ##    ##  ##    ####   ##     ##  \n"
                        "##   ##  ##  ##         ##   ##  ##  ##    ##  ##   ## ##   ##         \n"
                        "     ##      #########       ##      ########  ##  ##  ##   ##         \n"
                        "     ##      ##              ##      ##        ## ##   ##   ##         \n"
                        "     ##      ##              ##      ##        ####    ##   ##     ##  \n"
                        "   ######    #########     ######   ####      ####    ####  #########  \n\n";

const int fmap[FMAP_COUNTS][4][4] = //инициализация фигур тетриса
{
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    },
    {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

void gotoxy(int xpos, int ypos) //прототип функции помещения курсора в точку xpos, ypos
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);//создание "ручки" для вывода на экран консоли текста и прочего
	scrn.X = xpos; scrn.Y = ypos;//-присваем значения
	SetConsoleCursorPosition(hOuput, scrn);//-ставим курсор,на нужную позицию.
}

void print() //печать
{
    int i, j;
    int buff[SIZEX][SIZEY];

    for(i = 0; i < SIZEY; i++)
		for(j = 0; j < SIZEX; j++)
			buff[j][i] = screen[j][i]; //вывод из буфера на экран
    for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(map[j][i]) buff[j + px][i + py] = 1; //если часть фигуры, то в буфере обозначить 1

    gotoxy(0, 0); //перейти в точку с координатами 0, 0
    for(i = 0; i < SIZEY; i++)
    {
        for(j = 0; j < SIZEX; j++)
        {
            putchar(buff[j][i] == 0 ? SCR_SP : SCR_OB); //если элемент в буфере не часть фигуры, то закрасить полем
        }
        putchar('\n');
    }

    gotoxy(SIZEX + 1, 0); //уйти вбок
    std::cout << "Колличество очков: %i" << score; //вывести количество очков, набираемое в ходе игры
}

void printnextmap() //напечатать следующую идущую фигуру в поле
{
	gotoxy(SIZEX + 1, 2);
    std::cout << "Next: ";

    for(int i = 0; i < 4; i++)
    {
        gotoxy(SIZEX + 2, i + 3);
        for(int j = 0; j < 4; j++)
        {
            putchar(fmap[nextmap][j][i] == 0 ? ' ' : SCR_OB); //если не часть фигуры, то закрасить пробелами, иначе закрасить фигурой
        }
    }
}

int getkey()//-пауза во время игры
{
    int c;
    if(_kbhit()) //если нажата клавиша
    {
        if((c = _getch()) == 224)
        c = _getch();
         //если нажата клавиша p (пауза), то нажать любую клавишу для продолжения игры
        return c;
    }
    return false;
}

bool valnewpos(int x, int y) //необходимость движения фигуры вниз
{
	if(x < 0) return false;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(map[j][i])
            {
                if((j + x >= SIZEX) || (i + y >= SIZEY)) return false;//-проверка не зашла ли фигура за границы нашего экрана.
                if(screen[j + x][i + y])
                {
                    return false;//-если да то вернем "фолс"
                }
            }
        }
    }
    return true;//-если нет возвращаем "тру" - фигура движется вниз.
}

int inv(int x)
{
	return 3 - x;
}

void rotatemap() //поворот фигуры
{
    /* Optimize! */
    int _map[4][4];
	int sx = 4, sy = 4;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            _map[j][i] = map[j][i];//-создае копию фигуры,для того что бы вернуть первоначальный вид.
            if(map[j][i])//цикл с услевием ЕСЛИ - фигура равна нулю ,то
            {
                if(i < sx) sx = i;//проходим по фигурке запоминаем новую координату х
                if(inv(j) < sy) sy = inv(j);//новую координату у
            }
            map[j][i] = 0;//-обнуляем матрицу с фигурой
        }

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(_map[inv(i)][j]) map[j - sx][i - sy] = 1;//рисуем перевортыш
    if(!valnewpos(px,py))
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				map[j][i] = _map[j][i];//возвращаем обратно на изначальную фигурку
}

int rnd(int max) //рандомизация
{
    max++;
	srand(time(NULL));
    return rand() % max;
}

void sleep(int milsec) //задержка
{
    clock_t t = clock();
    while(clock() - t < milsec);
}

void deleteline() //убить собранную линию
{
    int i, j, k, cl;

    for(i = SIZEY - 1; i >= 0; i--)
    {
        cl = 1;
        for(j = 0, cl = 1; j < SIZEX; j++)
        {
            if(!screen[j][i]) cl = 0;
        }
        if(cl)
        {
            /* Animation */
            gotoxy(0, i);
            for(k = 0; k < SIZEX; k++) putchar('_'), sleep(20);
            /* --------- */

            score += (((i * (-1)) + SIZEY) * 10);

            for(k = i; k > 0; k--)
            {
                for(j = 0; j < SIZEX; j++)
                {
                    screen[j][k] = screen[j][k - 1];
                }
            }
            i++;
            print();
        }
    }
}

void createmap() //создание фигуры
{
	for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            map[j][i] = fmap[nextmap][j][i];
    py = 0;
    px = SIZEX / 2;

    nextmap = rnd(FMAP_COUNTS - 1);
    printnextmap();
}

void clearscreen() //очистка экрана
{
	for(int i = 0; i < SIZEY; i++)
        for(int j = 0; j < SIZEX; j++)
            screen[j][i] = 0;
}

void createrndscreen() //создать случайный экран
{
	clearscreen();
    int rn = rnd(10);
    for(int i = SIZEY - 1; i >= (SIZEY - 1) - rn; i--)
        for(int j = 0; j < SIZEX; j++)
        {
            screen[j][i] = rnd(1);
        }
}

void startgame() //игра
{
	time_t tm;

    system("cls");
    px = SIZEX / 2;//значение для падения фигуры по х,выход из центра
    py = 0;
    score = 0;

    tm = clock();

    nextmap = rnd(FMAP_COUNTS - 1);//следующая фигура выбирается из 6
    createmap();//создание фигурки

    while(true)
    {
        int c = getkey();

        switch(c)
        {
        case KEY_UP:
            rotatemap();//поворот
            break;
        case KEY_SPACE:
           rotatemap();//поворот
           break;
        case KEY_DOWN://движение вниз
            for(; valnewpos(px, py + 1); py++);
            for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(map[j][i]) screen[px + j][py + i] = 1;

            print();
            deleteline();//проход по функции проверки заполнилась ли линия и её удаление
            createmap();//новая фигура
            break;
        case KEY_LEFT:
            if(valnewpos(px - 1, py)) px--;//движение влево ,уменьшаем значение пера по х
            break;
        case KEY_RIGHT:
            if(valnewpos(px + 1, py)) px++;//движение вправо ,увеличиваем значение пера по х
            break;
        case 'p'://пауза
            _getch();
            break;
        case KEY_ESC://выход
            return;
        }

        if((clock() - tm) > 720)//-время падения фигуры
        {
            tm = clock();

            if(!(valnewpos(px, py + 1)))
            {
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(map[j][i]) screen[px + j][py + i] = 1;

                createmap();
                deleteline();
            }
            else py++;//падение вниз
        }

        print();

        for(int i = 0; i < SIZEX; i++)
        {
            if(screen[i][0])//если экранный у и у фигуры совпали и равны 0,то конец игры ,поле заполнилось до верха
            {
                system("cls");
                gotoxy(2, 8);
                std::cout << "Game Over! :(";
                return;
            }
        }
    }
}

void gamemenu() //игровое меню
{
    int p = 1, c = 0;
    const char* GAME_MENU =  "                     +===============================+\n"
                             "                     |  1. Start                     |\n"
                             "                     +===============================+\n"
                             "                     |  2. СТАРТ(ПОВЫШ.УРОВЕНЬ)      |\n"
                             "                     +===============================+\n"
                             "                     |  3. УПРАВЛЕНИЕ                |\n"
                             "                     +===============================+\n"
                             "                     |  4. ВЫХОД                     |\n "
                              "                    +===============================+";
    system("cls");
	std::cout << GAME_TITLE << GAME_MENU;
	while(true) //навигация по меню
    {
        c = _getch();
        std::cout << "\a";
        switch(c)
        {
        case '1':
        case '2':
        case '3':
        case '4': p = c - '0';
        case KEY_ENTER:
            switch(p)
            {
            case 1:
                clearscreen();
                startgame();
                gotoxy(0, SIZEY);
				std::cout << "Нажми ESC для выхода в главное меню...\n";
				std::cout << "\a";
				while(_getch() != KEY_ESC);
                break;
            case 2:
                clearscreen();
                createrndscreen();
                startgame();
                gotoxy(0, SIZEY);
				std::cout << "Нажми ESC для выхода в главное меню...\n";
				std::cout << "\a";
				while(_getch() != KEY_ESC);
                break;
            case 3:
                system("cls");
                std::cout << GAME_TITLE <<
                        "+=======+=======+\n"
                        "|\x1B      |Left  |\n"
                        "|\x1A      |Right |\n"
                        "|\x19      |Down   |\n"
                        "|\x18/Space|Поворот|\n"
                        "|P      |Pause  |\n"
                        "|ESC    |Exeit  |\n"
                        "+=======+=======+\n\n"
                        "Press button...\n";
				_getch();
				std::cout << "\a";
				if(_kbhit())
					_getch();
                break;
            case 4: return;
            }
            system("cls");
			std::cout << GAME_TITLE << GAME_MENU;
            p = 1;
            break;
        case KEY_UP:
            if(p > 1) p--;
            break;
        case KEY_DOWN:
            if(p < 4) p++;
            break;
        case KEY_ESC:
            return;
        }

    }
}

int main()
{
    system("color F0");
	setlocale(LC_ALL, "Russian");
	std::cout << GAME_TITLE;
	std::cout << "              Press button ";

	_getch();
    std::cout << "\a";
    if(_kbhit())
		_getch();
    gamemenu();
	return 0;
}
