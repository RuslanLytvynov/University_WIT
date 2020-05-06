#include<iostream>
#include <Windows.h>
#include <conio.h>
#include<ctime>

//Макрос для режима установки кораблей "Игрок"
#define Manual_a switch(k){\
        case 'a':\
            if(kj>1&&gamer[ki][kj-1]==1){\
            kj-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=1;\
            break;}\
            else if(kj>1&&gamer[ki][kj-1]==2){\
            kj-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=2;\
            break;}\
            else if(kj>1&&gamer[ki][kj-1]==3){\
            kj-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=3;\
            break;}\
            else if(kj>1&&gamer[ki][kj-1]==4){\
            kj-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=4;\
            break;}\
            else if(kj>1&&gamer[ki][kj-1]==11){\
            kj-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=11;\
            break;}\

#define Manual_d case 'd':\
            if(kj<10&&gamer[ki][kj+1]==1){\
            kj+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=1;\
            break;}\
            else if(kj<10&&gamer[ki][kj+1]==2){\
            kj+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=2;\
            break;}\
            else if(kj<10&&gamer[ki][kj+1]==3){\
            kj+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=3;\
            break;}\
            else if(kj<10&&gamer[ki][kj+1]==4){\
            kj+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=4;\
            break;}\
            else if(kj<10&&gamer[ki][kj+1]==11){\
            kj+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=11;\
            break;}\

#define Manual_w case 'w':\
            if(ki>1&&gamer[ki-1][kj]==1){\
                ki-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=1;\
            break;}\
            else if(ki>1&&gamer[ki-1][kj]==2){\
                ki-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=2;\
            break;}\
            else if(ki>1&&gamer[ki-1][kj]==3){\
                ki-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=3;\
            break;}\
            else if(ki>1&&gamer[ki-1][kj]==4){\
                ki-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=4;\
            break;}\
            else if(ki>1&&gamer[ki-1][kj]==11){\
            ki-=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=11;\
            break;}\

#define Manual_s case 's':\
            if(ki<10&&gamer[ki+1][kj]==1){\
            ki+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=1;\
            break;}\
            else if(ki<10&&gamer[ki+1][kj]==2){\
            ki+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=2;\
            break;}\
            else if(ki<10&&gamer[ki+1][kj]==3){\
            ki+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=3;\
            break;}\
            else if(ki<10&&gamer[ki+1][kj]==4){\
            ki+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=4;\
            break;}\
            else if(ki<10&&gamer[ki+1][kj]==11){\
            ki+=1;\
            gamer[ki][kj]=12;\
            system("cls");\
            Print(gamer,r,s);\
            gamer[ki][kj]=11;\
            break;}\

//Макрос для определения уничтоженых кораблей
#define KillShips(a1,a2,b1,b2,c) \
    for(int a=a1;a<=a2;++a){\
         for(int b=b1;b<=b2;++b){\
               if(a>0&&a<r-1&&b>0&&b<s&&Pla_Com[a][b]!=0){\
                   arr_i_sh[++step]=a;arr_j_sh[step]=b;\
                       if(Pla_Com[a][b]!=c)\
                            Pla_Com[a][b]=0;}\
           }\
       }

//Макрос для заполнения массива проверки для всех режимов и игроков
#define CheckAddShips(a1,a2,b1,b2) \
          for(int a=a1;a<=a2;++a){\
            for(int b=b1;b<=b2;++b){\
                ig[++cg]=a;jg[cg]=b;\
            }\
        }



using namespace std;

int **Gamers_Maps(int r,int s);//Создание разметки полей для игрока и ПК
void Instruction();//Инструкция управл. игрой
void Print(int **map,int r,int s);//Вывод на екран для игрока и ПК

void Manual_Gamer_Ships(int **&gamer,int r,int s);//Ручной ввод кораблей игрока
void Gamers_Auto_Ships(int **&gamers,int r,int s);//Автоматический ввод кораблей игрока и ПК

void Gamers_Shoots_Check(int **&Pla_Com, int **&Pla_Com1, int iShoot,//Проверка на полное уничтожение кораблей игрока и ПК
    int jShoot, int arr_i_sh[], int arr_j_sh[], int &step, int &WinCheck, int &Kor4, int &Kor4_i, int r, int s);

void Gamers_Shoots(int **&gamer,int **&comp,int r,int s);//Ввод выстрелов игрока и ПК + создание логики выстрелов ПК

enum ConsoleColor
{
Black = 0,Blue = 1,Green = 2,Cyan = 3,Red = 4,Magenta = 5,Brown = 6,LightGray = 7,DarkGray = 8,
LightBlue = 9,LightGreen = 10,LightCyan = 11,LightRed = 12,LightMagenta = 13,Yellow = 14,White = 15
};

void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//Ф-ция создания разметки полей для игрока и ПК
int **Gamers_Maps(int r,int s)
{
    int **gamers_maps=new int*[r];
    for(int i=0;i<r;++i)
    {
        gamers_maps[i]=new int[s];
        for(int j=0;j<s;++j)
        {
            if(i!=0||j!=0)//Число 11 для пустых (нетронутых) ячеек
                gamers_maps[i][j]=11;
        }
    }
    return gamers_maps;
}

//Ф - ция вывода иструкции по управ. игрой
void Instruction()
{
    SetColor(11,0);
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t[w] - ВВЕРХ"<<
          "\n\t\t\t\t[s] - ВНИЗ"<<
          "\n\t\t\t\t[a] - ВЛЕВО"<<
          "\n\t\t\t\t[d] - ВПРАВО"<<
          "\n\n\t\t\t\t[k] - УСТАН. КОРАБЛЯ/ВЫСТРЕЛ";
    Sleep(7000);
    system("cls");
}

//Ф-ция вывода на екран для игрока и ПК
void Print(int **map,int r,int s)
{
    cout<<"\n";
    SetColor(14,0);
    cout<<"\t\t\t    1  2  3  4  5  6  7  8  9  10\n";
    for(int i=0;i<r;++i)
    {
        cout<<"\t\t\t";
        for(int j=0;j<s;++j)
        {
        if(map[i][j]==12||map[i][j]==13){
            cout<<" ";
            SetColor(0,15);
        cout<<" ";
        SetColor(10,0);
        cout<<" ";}

        //Вывод нетронутых ячеек поля при i<10 && i=10
        else if(i>0&&i<r-1&&j!=0&&map[i][j]==11){
            SetColor(11,0);
            cout<<" ~ ";
          }

        //Вывод ходов при не попадении при i<10 && i=10
        else if(i>0&&i<r-1&&j!=0&&map[i][j]==0){
            SetColor(10,0);
            cout<<" 0 ";}

        //Вывод кораблей при i<10 && i=10
        else if(i>0&&i<r-1&&j!=0&&map[i][j]>0&&map[i][j]<5){
            SetColor(7,0);
            cout<<" 1 ";}

        //Вывод ходов припопадении в корабли при i<10 && i=10
        else if(i>0&&i<r-1&&j!=0&&map[i][j]>4&&map[i][j]<9){
            SetColor(12,0);
            cout<<" X ";}

        //Вывод разметки полей
        SetColor(14,0);
        if(i==0&&j==0){

            cout<<"  _______________________________";}
        else if(i==1&&j==0)cout<<" 1|";else if(i==2&&j==0)cout<<" 2|";else if(i==3&&j==0)cout<<" 3|";
        else if(i==4&&j==0)cout<<" 4|";else if(i==5&&j==0)cout<<" 5|";else if(i==6&&j==0)cout<<" 6|";
        else if(i==7&&j==0)cout<<" 7|";else if(i==8&&j==0)cout<<" 8|";else if(i==9&&j==0)cout<<" 9|";
        else if(i==10&&j==0)cout<<"10|";
        }
        cout<<"\n";
    }
}

//Ф-ция для ввода кораблей режима "Игрок"
void Manual_Gamer_Ships(int **&gamer,int r,int s)
{
    const int size=200;
    int ig[size],jg[size];//Массивы для проверок на повторность + проверок границ (расстояние между кор. не < 1 ячейки)
    char k;
    int cg=-1;//Счетчик для проверочных массивов
    int ki=5,kj=5;//Переменные для ввода координат
    short gv;//Переменная для выбора положения расстановки кораблей 2 - 4 (гориз. , верт.)
    Print(gamer,r,s);
                                                      //Корабль (4) 1 шт.
        cout<<"\n\t\t\t  :: ВВЕДИТЕ КОРАБЛЬ (4) x1 ::\n";
        gv4:cout<<"\n\t\t\t:: ВЫБЕРИТЕ ПОЛОЖЕНИЕ КОРАБЛЯ ::\n\t\t\t   :: [1]- ГОРИЗ./[2]-ВЕРТ. ::\n\t\t\t\t::";
        cin>>gv;                  //Выбор положения корабля..
        if(gv<1||gv>2){
                   cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto gv4;}
        system("cls");
        gamer[ki][kj]=12; Print(gamer,r,s); gamer[ki][kj]=11;
        k='m';
        while(k!='k'){
        k4:k=_getch();
        switch(k){
        case 'a':
            if(kj>1){
            kj-=1;
            gamer[ki][kj]=12;
            system("cls");
            Print(gamer,r,s);
            break;
            }
            else
            goto k4;
        case 'd':
            if(kj<10){
                kj+=1;
            gamer[ki][kj]=12;
            system("cls");
            Print(gamer,r,s);
            break;
            }
            else
            goto k4;
    case 'w':
            if(ki>1){
                ki-=1;
            gamer[ki][kj]=12;
            system("cls");
            Print(gamer,r,s);
            break;
            }
            else
            goto k4;
        case 's':
            if(ki<10){
            ki+=1;
            gamer[ki][kj]=12;
            system("cls");
            Print(gamer,r,s);
            break;
            }
            else
            goto k4;
        case 'k':
            if(gv==1&&kj>7||gv==2&&ki>7){
               cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k4;}
            break;
        }
        gamer[ki][kj]=11;
        }
      if(gv==1) {//Заполнение массива проверенными корд. корабля (4) по гориз. + установка границ вокруг корабля
          CheckAddShips(ki-1,ki+1,kj-1,kj+4);
       //Заполнение массива игрового поля игрока проверенными кординатами кораблей по гориз.
       gamer[ki][kj]=4; gamer[ki][kj+1]=4; gamer[ki][kj+2]=4; gamer[ki][kj+3]=4;
       }
      else if(gv==2)
        {        //Заполнение массива проверенными  корд. корабля (4) по верт. + установка границ вокруг корабля
           CheckAddShips(ki-1,ki+4,kj-1,kj+1);

      //Заполнение массива игрового поля игрока проверенными кординатами кораблей по верт.
       gamer[ki][kj]=4;  gamer[ki+1][kj]=4; gamer[ki+2][kj]=4; gamer[ki+3][kj]=4;
       }
system("cls"); Print(gamer,r,s);

                                                       //Корабли (3) 2 шт.
       cout<<"\n\t\t\t  :: ВВЕДИТЕ КОРАБЛИ 3 (x2) ::\n";

        for(int i=0;i<2;++i)             {
        cout<<"\n\t\t\t\t::КОРАБЛЬ 3 ("<<i+1<<")::\n";
        gv3:cout<<"\n\t\t\t:: ВЫБЕРИТЕ ПОЛОЖЕНИЕ КОРАБЛЯ ::\n\t\t\t   :: [1]- ГОРИЗ./[2]-ВЕРТ. ::\n\t\t\t\t::";
        cin>>gv;
        if(gv<1||gv>2)
            {cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto gv3;}
        k='m';
        while(k!='k')
        {
k3:k=_getch();
            Manual_a
            else
            goto k3;
Manual_d
            else
            goto k3;
Manual_w
            else
            goto k3;
Manual_s
            else
            goto k3;

        case 'k':
            if(gv==1&&kj>8||gv==2&&ki>8){
               cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k3;}

                    for(int j=0;j<=cg;++j)//Проверка на границы с кораблем (3), (4)
                  {
                  if(gv==1&&ki==ig[j]&&kj==jg[j]||gv==1&&ki==ig[j]&&kj+1==jg[j]||
                     gv==1&&ki==ig[j]&&kj+2==jg[j]){                                //...по горизон.
                              cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k3;}
               else if(gv==2&&ki==ig[j]&&kj==jg[j]||gv==2&&ki+1==ig[j]&&kj==jg[j]||
                       gv==2&&ki+2==ig[j]&&kj==jg[j]){                                //...по верт.
                                  cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k3;}
                  }
                    break;
        }
        }
      if(gv==1){
          CheckAddShips(ki-1,ki+1,kj-1,kj+3);
       gamer[ki][kj]=3; gamer[ki][kj+1]=3; gamer[ki][kj+2]=3;
       }
       else if(gv==2){
           CheckAddShips(ki-1,ki+3,kj-1,kj+1);
       gamer[ki][kj]=3;  gamer[ki+1][kj]=3; gamer[ki+2][kj]=3;
       }
        system("cls"); Print(gamer,r,s);
   }
                                            //Корабли (2) 3шт.

    cout<<"\n\t\t\t  :: ВВЕДИТЕ КОРАБЛИ 2 (x3) ::\n";
    for(int i=0;i<3;++i){
        cout<<"\n\t\t\t\t::КОРАБЛЬ 2 ("<<i+1<<")::\n";
        gv2:cout<<"\n\t\t\t:: ВЫБЕРИТЕ ПОЛОЖЕНИЕ КОРАБЛЯ ::\n\t\t\t   :: [1]- ГОРИЗ./[2]-ВЕРТ. ::\n\t\t\t\t::";
        cin>>gv;
        if(gv<1||gv>2){
             cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto gv2;}
        k='m';
        while(k!='k')
        {
k2:k=_getch();
            Manual_a
            else
            goto k2;
Manual_d
            else
            goto k2;
Manual_w
            else
            goto k2;
Manual_s
            else
            goto k2;
        case 'k':
            if(gv==1&&kj>9||gv==2&&ki>9){
               cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k2;}

                    for(int j=0;j<=cg;++j)//Проверка на границы с кораблем (2)? (3), (4)
                  {
                  if(gv==1&&ki==ig[j]&&kj==jg[j]||gv==1&&ki==ig[j]&&kj+1==jg[j]){         //...по горизон.
                              cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k2;}
               else if(gv==2&&ki==ig[j]&&kj==jg[j]||gv==2&&ki+1==ig[j]&&kj==jg[j]){        //...по верт.
                                  cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k2;}
                  }
                    break;
        }
        }

      if(gv==1){
          CheckAddShips(ki-1,ki+1,kj-1,kj+2);
       gamer[ki][kj]=2;gamer[ki][kj+1]=2;
       }

       else if(gv==2){
        CheckAddShips(ki-1,ki+2,kj-1,kj+1);
       gamer[ki][kj]=2;gamer[ki+1][kj]=2;
       }
system("cls"); Print(gamer,r,s);
}
                                                    //Корали (1) 4шт.
          cout<<"\n\t\t\t  :: ВВЕДИТЕ КОРАБЛИ 1 (x4) ::\n";
    for(int i=0;i<4;++i)
    {
        cout<<"\n\t\t\t\t::КОРАБЛЬ 1 ("<<i+1<<")::\n";
        k='m';
        while(k!='k')
        {
k1:k=_getch();
            Manual_a
            else
            goto k1;
Manual_d
            else
            goto k1;
Manual_w
            else
            goto k1;
Manual_s
            else
            goto k1;
        case 'k':
                for(int j=0;j<=cg;++j)//Проверка на границы с кораблем (1), (2), (3), (4)
                  {
                  if(ki==ig[j]&&kj==jg[j]){
                              cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto k1;}
                  }
                    break;
        }
        }
          CheckAddShips(ki-1,ki+1,kj-1,kj+1);
          gamer[ki][kj]=1;
          system("cls"); Print(gamer,r,s);
}
}

//Ф-ция для автозаполнения поля кораблями для игрока и ПК
void Gamers_Auto_Ships(int **&gamers,int r,int s)
{
    const int size=200;
    int ig[size],jg[size];//Массивы для проверок на повторность + проверок границ (расстояние между кор. не < 1 ячейки)

    int cg=-1;//Счетчик для проверочных массивов
    int ki,kj;//Переменные для подбора координат
    short gv;//Переменная для выбора положения расстановки кораблей 2 - 4 (гориз. , верт.)

                                             //Корабль (4) х1 шт.
    for(int i=0; i<1; ++i){
  m4:gv=rand()%2;//Случайный подбор положения кораблей
     ki=rand()%10+1;//Случайный подбор кординат кораблей
     kj=rand()%10+1;
     if(!gv&&kj>7||gv&&ki>7)//Проверка границ кординат
     goto m4;

    if(!gv){//Заполнение массива проверенными корд. корабля (4) по гориз. + установка границ вокруг корабля
              CheckAddShips(ki-1,ki+1,kj-1,kj+4);

              //Заполнение массива проверенными корд. корабля (4) по гориз. + установка границ вокруг корабля
              gamers[ki][kj]=4;  gamers[ki][kj+1]=4; gamers[ki][kj+2]=4; gamers[ki][kj+3]=4;
       }
    else{//Заполнение массива проверенными  корд. корабля (4) по верт. + установка границ вокруг корабля
              CheckAddShips(ki-1,ki+4,kj-1,kj+1);

              //Заполнение массива проверенными корд. корабля (4) по верт. + установка границ вокруг корабля
              gamers[ki][kj]=4;  gamers[ki+1][kj]=4; gamers[ki+2][kj]=4; gamers[ki+3][kj]=4;
       }
    }
                                              //Корабли (3) х2 шт.
    for(int i=0; i<2; ++i)
    {
    gv=rand()%2;
    m3:ki=rand()%10+1;
       kj=rand()%10+1;
     if(!gv&&kj>8||gv&&ki>8)
     goto m3;
     //Проверка на границы с кораблем (3), (4)
            for(int j=0;j<=cg;++j){
                  if(!gv&&ki==ig[j]&&kj==jg[j]||!gv&&ki==ig[j]&&kj+1==jg[j]||!gv&&ki==ig[j]&&kj+2==jg[j])//...по горизон.
                            goto m3;
            else if(gv&&ki==ig[j]&&kj==jg[j]||gv&&ki+1==ig[j]&&kj==jg[j]||gv&&ki+2==ig[j]&&kj==jg[j])//...по верт.
                            goto m3;
                  }
    if(!gv){
        CheckAddShips(ki-1,ki+1,kj-1,kj+3);

       //Заполнение массива игрового поля игрока проверенными кординатами кораблей по гориз.
       gamers[ki][kj]=3; gamers[ki][kj+1]=3; gamers[ki][kj+2]=3;
       }
    else {
        CheckAddShips(ki-1,ki+3,kj-1,kj+1);

    //Заполнение массива игрового поля игрока проверенными кординатами кораблей по верт.
       gamers[ki][kj]=3; gamers[ki+1][kj]=3; gamers[ki+2][kj]=3;
          }
       }
                                          //Корабли (2) 3шт.
    for(int i=0; i<3; ++i){

    m2:gv=rand()%2;
       ki=rand()%10+1;
       kj=rand()%10+1;
       if(!gv&&kj>9||gv&&ki>9)
           goto m2;
                  for(int j=0;j<=cg;++j){//Проверка на границы с кораб. (2), (3), (4)
                  if(!gv&&ki==ig[j]&&kj==jg[j]||!gv&&ki==ig[j]&&kj+1==jg[j])      //...по горизон.
                      goto m2;
                      else if(gv&&ki==ig[j]&&kj==jg[j]||gv&&ki+1==ig[j]&&kj==jg[j])  //...по верт.
                      goto m2;
                  }
       if(!gv){
       CheckAddShips(ki-1,ki+1,kj-1,kj+2);
       gamers[ki][kj]=2;  gamers[ki][kj+1]=2;
    }
       else {
       CheckAddShips(ki-1,ki+2,kj-1,kj+1);
       gamers[ki][kj]=2;  gamers[ki+1][kj]=2;
       }
   }

                                        //Корабли (1) 4шт.
    for(int i=0; i<4; ++i){
    m1:ki=rand()%10+1;
       kj=rand()%10+1;

                  for(int j=0;j<=cg;++j){
                  if(ki==ig[j]&&kj==jg[j])
                  goto m1;
                  }
             CheckAddShips(ki-1,ki+1,kj-1,kj+1);
             gamers[ki][kj]=1;
    }
}

//Ф-ция для ввода выстрелов игрока и ПК + создание логики выстрелов ПК
void Gamers_Shoots(int **&gamer, int **&comp, int r,int s)
{
    int **gamer_mask=0,**comp_mask=0; //Пустые поля для заполнения выстрелами

    gamer_mask=Gamers_Maps(r,s);//...
    comp_mask=Gamers_Maps(r,s);//...

    int iShsPla[200],jShsPla[200];//Массивы для проверки на повторные кординаты +
    int iShsCom[200],jShsCom[200];//..для заполнение границ уничтоженых кораблей

    int *iProgCom=new int[4], *jProgCom=new int[4];//Массивы для логических выстрелов ПК

    int Kor4Pla=0,Kor4_i_Pla=0,Kor4Com=0,Kor4_i_Com=0;//Переменные для проверки выстрелов по кораблю (4)
    char k;
    int iShPla=5,jShPla=5,iShCom,jShCom,WinPla=0,WinCom=0,ShStepPla=-1,ShStepCom=-1;

    int WinComKor2=4,ComProgChecker=0;//Для логики выстрелов ПК
    bool ComProg=false;//...

    SetColor(14,0);
    cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);

    cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n"; //Вывод поля врага первого выстрела игрока
    Print(comp_mask,r,s);   //...
    for(;;)
    {
        k='m';
        while(k!='k'){
        kpla:k=_getch();
        switch(k){
        case 'a':
            if(jShPla>1&&comp_mask[iShPla][jShPla-1]==0){
            jShPla-=1;
            comp_mask[iShPla][jShPla]=13;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=0;
            break;
            }
            else if(jShPla>1&&comp_mask[iShPla][jShPla-1]>9){
            jShPla-=1;
            comp_mask[iShPla][jShPla]=12;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=11;
            break;
            }
            else
            goto kpla;
        case 'd':
            if(jShPla<10&&comp_mask[iShPla][jShPla+1]==0){
                jShPla+=1;
            comp_mask[iShPla][jShPla]=13;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=0;
            break;
            }
            else if(jShPla<10&&comp_mask[iShPla][jShPla+1]>9){
                jShPla+=1;
            comp_mask[iShPla][jShPla]=12;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=11;
            break;
            }
            else
            goto kpla;
    case 'w':
            if(iShPla>1&&comp_mask[iShPla-1][jShPla]==0){
                iShPla-=1;
            comp_mask[iShPla][jShPla]=13;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=0;
            break;
            }
            else if(iShPla>1&&comp_mask[iShPla-1][jShPla]>9){
                iShPla-=1;
            comp_mask[iShPla][jShPla]=12;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=11;
            break;
            }
            else
            goto kpla;
        case 's':
            if(iShPla<10&&comp_mask[iShPla+1][jShPla]==0){
            iShPla+=1;
            comp_mask[iShPla][jShPla]=13;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=0;
               break;
            }
            else if(iShPla<10&&comp_mask[iShPla+1][jShPla]>9){
            iShPla+=1;
            comp_mask[iShPla][jShPla]=12;
            system("cls");
            cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";
            Print(gamer,r,s);
            cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";
            Print(comp_mask,r,s);
            comp_mask[iShPla][jShPla]=11;
               break;
            }
            else
            goto kpla;
        case 'k':
        for(int j=0;j<=ShStepPla;++j){                  //Проверка на повторные выстрелы игрока.
        if(iShPla==iShsPla[j]&&jShPla==jShsPla[j]){
        cout<<"\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!\n";goto kpla;}
        }
        //Ф-ция для проверки на полное уничтожение кораблей ПК
Gamers_Shoots_Check(comp_mask,comp,iShPla,jShPla,iShsPla,jShsPla,ShStepPla,WinPla,Kor4Pla,Kor4_i_Pla,r,s);
            break;
        }
        }
        system("cls");
if(ComProg==0)
      {
  com:iShCom=rand()%10+1;//Выстрелы ПК в случае не попадения или повторных выстрелов
      jShCom=rand()%10+1;


    for(int m=0;m<=ShStepCom;++m){//Проверка на повторные выстрелы
        if(iShCom==iShsCom[m]&&jShCom==jShsCom[m])
            goto com;}
  }

if(ComProg==1)//Программирование будущих выстрелов в случаях попадения ПК по кораблям игрока
{
  com_prog:iShCom=iProgCom[--WinComKor2];
           jShCom=jProgCom[  WinComKor2];
  if(iShCom<1||iShCom>10||jShCom<1||jShCom>10||gamer_mask[iShCom][jShCom]==0)
      goto com_prog;
}

//Ф-ция для проверки на полное уничтожение кораблей игрока
Gamers_Shoots_Check(gamer_mask,gamer,iShCom,jShCom,iShsCom,jShsCom,ShStepCom,WinCom,Kor4Com,Kor4_i_Com,r,s);

if(gamer_mask[iShCom][jShCom]==6)//Программирование выстрелов ПК в случае попадения по кораблям (2)
{
    ++ComProgChecker;
    if(ComProgChecker==1)
    {
    ComProg=1;
    iProgCom[0]=iShCom-1; jProgCom[0]=jShCom;
    iProgCom[1]=iShCom;   jProgCom[1]=jShCom-1;
    iProgCom[2]=iShCom;   jProgCom[2]=jShCom+1;
    iProgCom[3]=iShCom+1; jProgCom[3]=jShCom;
    }
    if(ComProgChecker==2)
    {
        ComProg=0;
        ComProgChecker=0;
        WinComKor2=4;
    }
}

if(gamer_mask[iShCom][jShCom]==7)//Программирование выстрелов ПК в случае попадения по кораблям (3)
{
    ++ComProgChecker;
    if(ComProgChecker==1)
    {
    ComProg=1;
    iProgCom[0]=iShCom-1; jProgCom[0]=jShCom;
    iProgCom[1]=iShCom;   jProgCom[1]=jShCom-1;
    iProgCom[2]=iShCom;   jProgCom[2]=jShCom+1;
    iProgCom[3]=iShCom+1; jProgCom[3]=jShCom;
    }

    else if(ComProgChecker==2)
    {
        WinComKor2=2;
        if(gamer_mask[iShCom][jShCom+1]==7)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom+2;
        iProgCom[1]=iShCom; jProgCom[1]=jShCom-1;}

        else if(gamer_mask[iShCom][jShCom-1]==7)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom+1;
         iProgCom[1]=iShCom; jProgCom[1]=jShCom-2;}

        else if(gamer_mask[iShCom+1][jShCom]==7)
        {iProgCom[0]=iShCom+2;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom-1; jProgCom[1]=jShCom;}

        else if(gamer_mask[iShCom-1][jShCom]==7)
        {iProgCom[0]=iShCom+1;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom-2; jProgCom[1]=jShCom;}

    }
        if(ComProgChecker==3)
    {
        ComProg=0;
        ComProgChecker=0;
        WinComKor2=4;
    }
}

if(gamer_mask[iShCom][jShCom]==8)//Программирование выстрелов ПК в случае попадения по кораблям (4)
{
    ++ComProgChecker;
    if(ComProgChecker==1)
    {
    ComProg=1;
    iProgCom[0]=iShCom-1; jProgCom[0]=jShCom;
    iProgCom[1]=iShCom;   jProgCom[1]=jShCom-1;
    iProgCom[2]=iShCom;   jProgCom[2]=jShCom+1;
    iProgCom[3]=iShCom+1; jProgCom[3]=jShCom;
    }

    else if(ComProgChecker==2)
    {
        WinComKor2=2;
        if(gamer_mask[iShCom][jShCom+1]==8)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom+2;
        iProgCom[1]=iShCom; jProgCom[1]=jShCom-1;}

        else if(gamer_mask[iShCom][jShCom-1]==8)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom+1;
         iProgCom[1]=iShCom; jProgCom[1]=jShCom-2;}

        else if(gamer_mask[iShCom+1][jShCom]==8)
        {iProgCom[0]=iShCom+2;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom-1; jProgCom[1]=jShCom;}

        else if(gamer_mask[iShCom-1][jShCom]==8)
        {iProgCom[0]=iShCom+1;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom-2; jProgCom[1]=jShCom;}

    }

    else if(ComProgChecker==3)
    {
            WinComKor2=2;

        if(gamer_mask[iShCom][jShCom+1]==8&&gamer_mask[iShCom][jShCom+2]==8)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom+3;
         iProgCom[1]=iShCom; jProgCom[1]=jShCom-1;}

        else if(gamer_mask[iShCom][jShCom-1]==8&&gamer_mask[iShCom][jShCom+1]==8)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom-2;
         iProgCom[1]=iShCom; jProgCom[1]=jShCom+2;}

        else if(gamer_mask[iShCom][jShCom-1]==8&&gamer_mask[iShCom][jShCom-2]==8)
        {iProgCom[0]=iShCom; jProgCom[0]=jShCom-3;
         iProgCom[1]=iShCom; jProgCom[1]=jShCom+1;}

        else if(gamer_mask[iShCom+1][jShCom]==8&&gamer_mask[iShCom+2][jShCom]==8)
        {iProgCom[0]=iShCom+3;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom-1; jProgCom[1]=jShCom;}

        else if(gamer_mask[iShCom-1][jShCom]==8&&gamer_mask[iShCom+1][jShCom]==8)
        {iProgCom[0]=iShCom-2;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom+2; jProgCom[1]=jShCom;}

        else if(gamer_mask[iShCom-1][jShCom]==8&&gamer_mask[iShCom-2][jShCom]==8)
        {iProgCom[0]=iShCom-3;jProgCom[0]=jShCom;
         iProgCom[1]=iShCom+1; jProgCom[1]=jShCom;}

    }
    else if(ComProgChecker==4)
    {
        ComProg=0;
        ComProgChecker=0;
        WinComKor2=4;
    }
    }

    for(int p=0;p<r-1;++p)//Присвоение новых значений главного поля игрока для вывода полной инфо. о ходе игры
    {
        for(int k=0;k<s;++k)
        {
        if(gamer_mask[p][k]>=0&&gamer_mask[p][k]<=8)
            gamer[p][k]=gamer_mask[p][k];
        }
    }

cout<<"\n\t\t\t        :: ПОЛЕ ИГРОКА ::\n";//Вывод поля игрока после выстрела
Print(gamer,r,s);

cout<<"\n\t\t\t      :: ПОЛЕ ПРОТИВНИКА ::\n";//Вывод поля ПК после выстрела
Print(comp_mask,r,s);

cout<<"\n\t\t\t\t    ИГРОК: "<<WinPla;//Вывод очков игрока
cout<<"\n\t\t\t\tПРОТИВНИК: "<<WinCom;//...ПК

    if(WinPla==20||WinCom==20)//Проверка для определения победителя
    break;
    }
    SetColor(12,0);
    WinPla<WinCom ? cout<<"\n\n\t\t\t\tПРОТИВНИК ВЫИГРАЛ!!!\n\n" : cout<<"\n\n\t\t\t\t    ВЫ ВЫИГРАЛИ!!!\n\n";

    for (int i = 0; i < r; i++) {
         delete[]gamer[i]; delete[]gamer_mask[i];
         delete[]comp[i];  delete[]comp_mask[i];
         }

         delete []iProgCom; delete []jProgCom;
}

//Ф-ция для проверки на полное уничтожение кораблей игроков
void Gamers_Shoots_Check(int **&Pla_Com, int **&Pla_Com1, int iShoot,
    int jShoot, int arr_i_sh[], int arr_j_sh[], int &step, int &WinCheck, int &Kor4, int &Kor4_i,int r, int s)
{
    Pla_Com[iShoot][jShoot]=0;
    arr_i_sh[++step]=iShoot;//Массивы для заполнения выстрелов игроков
    arr_j_sh[step]=jShoot;

    if(Pla_Com1[iShoot][jShoot]==1)//Проверка на попадение кораб. (1).
        {
        KillShips(iShoot-1,iShoot+1,jShoot-1,jShoot+1,5);
        Pla_Com[iShoot][jShoot]=5; ++WinCheck;
    }
            if(Pla_Com1[iShoot][jShoot]==2)//Проверка на попадение кораб. (2).
            {
            if(Pla_Com[iShoot][jShoot+1]==6){
                KillShips(iShoot-1,iShoot+1,jShoot-1,jShoot+2,6);
            }
                        if(Pla_Com[iShoot][jShoot-1]==6){
                KillShips(iShoot-1,iShoot+1,jShoot-2,jShoot+1,6);
            }
                     if(Pla_Com[iShoot+1][jShoot]==6){
            KillShips(iShoot-1,iShoot+2,jShoot-1,jShoot+1,6);
            }
                     if(Pla_Com[iShoot-1][jShoot]==6){
            KillShips(iShoot-2,iShoot+1,jShoot-1,jShoot+1,6);
            }
            Pla_Com[iShoot][jShoot]=6; ++WinCheck;
            }

            if(Pla_Com1[iShoot][jShoot]==3){//Проверка на попадение кораб. (3).

                     if(Pla_Com[iShoot][jShoot+1]==7&&Pla_Com[iShoot][jShoot+2]==7){
                         KillShips(iShoot-1,iShoot+1,jShoot-1,jShoot+3,7);
            }

                    if(Pla_Com[iShoot][jShoot-1]==7&&Pla_Com[iShoot][jShoot+1]==7){
                        KillShips(iShoot-1,iShoot+1,jShoot-2,jShoot+2,7);
            }

                if(Pla_Com[iShoot][jShoot-1]==7&&Pla_Com[iShoot][jShoot-2]==7){
                    KillShips(iShoot-1,iShoot+1,jShoot-3,jShoot+1,7);
            }

                if(Pla_Com[iShoot+1][jShoot]==7&&Pla_Com[iShoot+2][jShoot]==7){
                    KillShips(iShoot-1,iShoot+3,jShoot-1,jShoot+1,7);
            }

                    if(Pla_Com[iShoot-1][jShoot]==7&&Pla_Com[iShoot+1][jShoot]==7){
                        KillShips(iShoot-2,iShoot+2,jShoot-1,jShoot+1,7);
            }

                if(Pla_Com[iShoot-1][jShoot]==7&&Pla_Com[iShoot-2][jShoot]==7){
                    KillShips(iShoot-3,iShoot+1,jShoot-1,jShoot+1,7);
            }

                    Pla_Com[iShoot][jShoot]=7; ++WinCheck;
    }

int Kor_i_j=0;
if(Pla_Com1[iShoot][jShoot]==4)//Проверка на попадения в кораб. (4)
{
    ++Kor4;
    if(Kor4==1)
        Kor4_i=iShoot;
    if(Kor4==4&&Kor4_i==iShoot){
     for(int z=0;z<r-1;++z){
         for(int z1=0;z1<s;++z1){
             if(Pla_Com1[z][z1]==4||Pla_Com1[z][z1]==8)
             Kor_i_j=z1;
         }
     }
     KillShips(Kor4_i-1,Kor4_i+1,Kor_i_j-4,Kor_i_j+1,8);
    }
    if(Kor4==4&&Kor4_i!=iShoot)
    {
    for(int z=0;z<r-1;++z){
         for(int z1=0;z1<s;++z1){
             if(Pla_Com1[z][z1]==4||Pla_Com1[z][z1]==8)
                 Kor_i_j=z;
         }
    }
    KillShips(Kor_i_j-4,Kor_i_j+1,jShoot-1,jShoot+1,8);
    }
    Pla_Com[iShoot][jShoot]=8;++WinCheck;
}

}

void main()
{
    setlocale(LC_ALL, "Russian");
    srand(unsigned(time(0)));
    int **gamer=0,**comp=0;
    int r=12,s=11,choise;
    SetColor(12,0);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t::МОРСКОЙ БОЙ::";
    Sleep(2000);
    system("cls");

    gamer=Gamers_Maps(r,s);
    comp=Gamers_Maps(r,s);
    SetColor(14,0);
mode:cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t::РЕЖИМ РАССТАНОВКИ КОРАБЛЕЙ::\n\n\t\t\t  ::[1] - ИГРОК/[2] - АВТО::\n\t\t\t\t:: ";
    cin>>choise;
    if(choise<1 || choise>2)
    {system("cls"); cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tНЕВЕРНЫЙ ВЫБОР!!!";Sleep(2000);system("cls");goto mode;}
    system("cls");
    switch(choise)
        {
    case 1:
            Instruction();
            Manual_Gamer_Ships(gamer,r,s);
            break;
    case 2:
            Instruction();
            Gamers_Auto_Ships(gamer,r,s);
            cout<<"\n\n\n\n\t\t\t  :: АВТОРАССТАНОВКА КОРАБЛЕЙ ::\n\n\t\t\t\t  ::ПОЛЕ ИГРОКА::\n";
            Print(gamer,r,s);Sleep(3500);
            break;
    }
    Gamers_Auto_Ships(comp,r,s);
    system("cls");
    SetColor(12,0);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  :: ИГРАЕМ ::";
    Sleep(2500);
    system("cls");
    Gamers_Shoots(gamer,comp,r,s);
}
