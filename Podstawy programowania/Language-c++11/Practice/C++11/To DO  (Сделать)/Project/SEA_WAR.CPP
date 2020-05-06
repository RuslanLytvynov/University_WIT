
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

int x=50,y=50,pred_x,pred_y,ship=1,step=0,ex=0,fon=0;//Глобальные для direct
//step==0 для функции fire(int,int,int) и необходима в том случае, если
//первая нажатая во время боя клавиша - SPACEBAR. Так в случае отсутствия
//принятой меры функция floodfill зальёт весь экран.
//Переменная ship - номер корабля (1 - 7).
//fon - цвет фона.

int matrix01[10][10];
int matrix02[10][10];

void init_matrix(void);// Инициализация матриц.
void graph(void); // Избавляет main() от огорда с обьявлением графики.
void table(void); // Рисует рамку 640х480.
void init_player_field(void); //Выводит на экран поле игрока.
void init_computer_field(void);//Выводит на экран поле компьютера.
void to_make_fleet(void); //Построить флот.
void field(int x,int y,int ship);//Рисует серый прямоугольник.
void no_field(int x,int y,int ship);//Рисут синий прямогольник.
void direct(char ch,int ship);//Регистрирует направление перемещения
// прямоугольника-указателя и перемещает его. Дествует при расстановке
// кораблей игрока.
int change_ship(int ship); //Изменяет расположение кораблей игрока с
// вертикального на горизонтальное.
void make_ship(int x,int y,int ship); //Регистрирует корабль на поле игрока.
int change_pal(int count); //Вводит новый тип корабля.
void computer_fleet(void); //Строит флот компьютера.
void c_ship(int count);//Регистрирует корабль на поле компьютера.
void get_player_move(void);//Ход игрока во время боя.
void p_direct(char to);//Регистрирует направление перемещения
// прямоугольника-указателя и перемещает его. Дествует при бое.
void wfield(int x,int y);//Рисует серый квадрат 20х20.
void no_wfield(int x,int y);//Рисует синий квадрат 20х20.
int victory(void);//Проверяет есть ли победитель.
void fire(int x,int y,int step);//Атака игрока на квадрат.
void get_computer_move(void);//Атака компьютера на квадрат.
int exit_game(void);//Сложная функция выхода из программы.
void s(int x,int y);//Рисует букву 's' в указанном x,y месте.
void e(int x,int y);//Рисует букву 'e' в указанном x,y месте.
void a(int x,int y);//Рисует букву 'a' в указанном x,y месте.
void w(int x,int y);//Рисует букву 'w' в указанном x,y месте.
void r(int x,int y);//Рисует букву 'r' в указанном x,y месте.
void y01(int x,int y);//Рисует букву 'y' в указанном x,y месте.
void o(int x,int y);//Рисует букву 'o' в указанном x,y месте.
void u(int x,int y);//Рисует букву 'u' в указанном x,y месте.
void w01(int x,int y);//Рисует букву 'w' в указанном x,y месте.
void i(int x,int y);//Рисует букву 'i' в указанном x,y месте.
void a01(int x,int y);//Рисует букву 'a' в указанном x,y месте.
void n(int x,int y);//Рисует букву 'n' в указанном x,y месте.
void m(int x,int y);//Рисует букву 'm' в указанном x,y месте.
void c(int x,int y);//Рисует букву 'c' в указанном x,y месте.
void titul(void);//Оформляет титульный лист программы.
void you_win(void);//Оформляет победу игрока.
void mac_win(void);//Оформляет победу компьютера.
void st_menu(void);//Вывод на экран стартового меню.
void secret01(int x,int y);//Помощь игроку.
void secret02(void);
void secret03(void);
void show_next_ship(int num);// Работает при расстановке кораблей игрока.


int main(void)
{
   int i,j,vic;

   graph();
   titul();
   delay(5000);

START:
   vic=0,x=50,y=50,ship=1,step=0,ex=0;
   setcolor(WHITE);
   init_matrix();
   cleardevice();
   st_menu();
   cleardevice();
   table();
   init_player_field();
   init_computer_field();
   to_make_fleet();
   if(ex==1) goto START;
   computer_fleet();

   while(vic==0)
     {
     get_player_move();
     if(ex==1)
       goto START;
     vic=victory();
     if(vic==2)
       break;
     get_computer_move();
     vic=victory();
     if(vic==1)
       break;
     }

   getch();

  if(vic==2)
    {
    cleardevice();
    you_win();
    delay(5000);
    }
  else
    {
    cleardevice();
    mac_win();
    delay(5000);
    }

  goto START;

//   return 0;
}

void init_matrix(void)
{
  int i,j;

  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      matrix01[i][j]=0;

  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      matrix02[i][j]=0;
}

/************************************************************************/
/*    Функция GRAPH избавляет main от огорода с обявлением графики.     */
/************************************************************************/
void graph(void)
{
  /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
}

void table(void)
{
 rectangle(0,0,639,479); // Рамка.
 outtextxy(51,41,"Player's field");
 outtextxy(351,41,"Machine's field");
 outtextxy(51,281,"C - To turn ship.");
 outtextxy(51,301,"SPACEBAR - To make ship.");
 outtextxy(51,321,"    - direction.");

 outtextxy(351,301,"SPACEBAR - To attack on sector.");
 outtextxy(351,321,"    - direction.");

// s(120,350);e(180,350);a(240,350);w(340,350);a(400,350);r(460,350);

}

void init_player_field(void)
{
 int i,j;
 int x=50,y=50,k=20;

 setcolor(BLUE);
 rectangle(50,50,250,250);
 setfillstyle(1,LIGHTBLUE);
 floodfill(51,51,BLUE);

 for(i=0;i<10;i++,y=y+k)
   {
   for(j=0;j<10;j++,x=x+k)
     rectangle(x,y,x+20,y+20);
   x=50;
   }

   setcolor(WHITE);
}

void init_computer_field(void)
{
 int i,j;
 int x=350,y=50,k=20;

 setcolor(BLUE);
   rectangle(350,50,550,250);
 setfillstyle(1,LIGHTBLUE);
 floodfill(351,51,BLUE);

 for(i=0;i<10;i++,y=y+k)
   {
   for(j=0;j<10;j++,x=x+k)
     rectangle(x,y,x+20,y+20);
   x=350;
   }

   setcolor(WHITE);
}


void to_make_fleet(void)
{
 char ch;
 int i,ep,count=0;
 unsigned int volume;
 void *arrow;
 show_next_ship(ship);
 field(x,y,ship);
while(count<10)
  {
M:
  show_next_ship(ship);
  pred_x=x; pred_y=y;
  ch=getch();
  if(ch==27)
    {
    volume=imagesize(199,149,470,260);
    arrow=malloc(volume);
    getimage(199,149,470,260,arrow);
    ep=exit_game();
    if(ep==1)
      {
      free(arrow);
      ex=1;
      cleardevice();
      goto ENDTMF;
      }
    else
      {
      putimage(199,149,arrow,0);
      free(arrow);
      }
    }
  if(ch==0)
    ch=getch();
  if(ch=='c'||ch=='C')
    {
    if(ship==1&&y<=170)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    if(ship==2&&y<=190)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    if(ship==3&&y<=210)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    if(ship==4&&x<=170)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    if(ship==5&&x<=190)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    if(ship==6&&x<=210)
      {
      no_field(x,y,ship);
      ship=change_ship(ship);
      field(x,y,ship);
      goto M;
      }
    }
    direct(ch,ship);
    if(ch==32)
      {
      int k = x,k1 = y,col=0;
      if(ship==1)
        {
        for(i=0;i<4;i++,k=k+20)
        if(getpixel(k+1,y+1)!=GREEN)
          col++;
        if(col==4)
          {
          make_ship(x,y,ship);
          count++;
     //     x=50; y=50;
          ship=change_pal(count);
          }
        }

      if(ship==2)
        {
        for(i=0;i<3;i++,k=k+20)
        if(getpixel(k+1,y+1)!=GREEN)
          col++;
        if(col==3)
          {
          make_ship(x,y,ship);
          count++;
          no_field(x,y,ship);
       //   x=50; y=50;
          ship=change_pal(count);
          }
        }

      if(ship==3)
        {
        for(i=0;i<2;i++,k=k+20)
        if(getpixel(k+1,y+1)!=GREEN)
          col++;
        if(col==2)
          {
          make_ship(x,y,ship);
          count++;
       //   x=50; y=50;
          ship=change_pal(count);
          }
        }

      if(ship==4)
        {
        for(i=0;i<4;i++,k1=k1+20)
        if(getpixel(x+1,k1+1)!=GREEN)
          col++;
        if(col==4)
          {
          make_ship(x,y,ship);
          count++;
       //   x=50; y=50;
          ship=change_pal(count);
          }
        }

      if(ship==5)
        {
        for(i=0;i<3;i++,k1=k1+20)
        if(getpixel(x+1,k1+1)!=GREEN)
          col++;
        if(col==3)
          {
          make_ship(x,y,ship);
          count++;
    //       x=50; y=50;
          ship=change_pal(count);
          }
        }

      if(ship==6)
        {
        for(i=0;i<2;i++,k1=k1+20)
        if(getpixel(x+1,k1+1)!=GREEN)
          col++;
        if(col==2)
          {
          make_ship(x,y,ship);
          count++;
      //    x=50; y=50;
          ship=change_pal(count);
          }
        }
      if(ship>6)
        if(getpixel(x+1,y+1)!=GREEN)
          {
          make_ship(x,y,ship);
          count++;
       //   x=50; y=50;
          ship=change_pal(count);
          }
      }
  }
ENDTMF:
}

void field(int x,int y,int ship)
{
 int i;
 setcolor(LIGHTGRAY);
 if(ship==1)
   {
   for(i=0;i<4;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==4)
   {
   for(i=0;i<4;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==2)
   {
   for(i=0;i<3;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==5)
   {
   for(i=0;i<3;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==3)
   {
   for(i=0;i<2;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==6)
   {
   for(i=0;i<2;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship>6)
   rectangle(x,y,x+20,y+20);

 setcolor(WHITE);
}

void no_field(int x,int y,int ship)
{
 int i;
 setcolor(BLUE);
 if(ship==1)
   {
   for(i=0;i<4;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==4)
   {
   for(i=0;i<4;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==2)
   {
   for(i=0;i<3;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==5)
   {
   for(i=0;i<3;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==3)
   {
   for(i=0;i<2;i++,x=x+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship==6)
   {
   for(i=0;i<2;i++,y=y+20)
     rectangle(x,y,x+20,y+20);
   }
 else if(ship>6)
   rectangle(x,y,x+20,y+20);

 setcolor(WHITE);
}

void direct(char ch,int ship)
{
if(ch==75&&x>50)
    {
    no_field(pred_x,pred_y,ship);  // Влево
    x=x-20;
    field(x,y,ship);
    }

  if(ch==77)
    {
    if(ship==1)
      if(x<170)
        {
        no_field(pred_x,pred_y,ship);  // Вправо
        x=x+20;
        field(x,y,ship);
        }
    if(ship==2)
      if(x<190)
        {
        no_field(pred_x,pred_y,ship);  // Вправо
        x=x+20;
        field(x,y,ship);
        }
    if(ship==3)
      if(x<210)
        {
        no_field(pred_x,pred_y,ship);  // Вправо
        x=x+20;
        field(x,y,ship);
        }
    if(ship>6)
      if(x<230)
        {
        no_field(pred_x,pred_y,ship);  // Вправо
        x=x+20;
        field(x,y,ship);
        }
    }

  if(ch==77&&x<230&&(ship==4||ship==5||ship==6))
        {
        no_field(pred_x,pred_y,ship);  // Вправо
        x=x+20;
        field(x,y,ship);
        }

  if(ch==80)
    {
    if(ship==4)
      if(y<170)
        {
        no_field(pred_x,pred_y,ship);  // Вниз
        y=y+20;
        field(x,y,ship);
        }
    if(ship==5)
      if(y<190)
        {
        no_field(pred_x,pred_y,ship);  // Вниз
        y=y+20;
        field(x,y,ship);
        }
    if(ship==6)
      if(y<210)
        {
        no_field(pred_x,pred_y,ship);  // Вниз
        y=y+20;
        field(x,y,ship);
        }
    }

  if(ch==80&&y<230&&(ship==1||ship==2||ship==3||ship>6))
    {
    no_field(pred_x,pred_y,ship);  // Вниз
    y=y+20;
    field(x,y,ship);
    }

  if(ch==72&&y>50)
    {
    no_field(pred_x,pred_y,ship);  // Вверх
    y=y-20;
    field(x,y,ship);
    }
}

int change_ship(int ship)
{
 int res;
 if(ship==1)
   res=4;
 else if(ship==2)
   res=5;
 else if(ship==3)
   res=6;
 else if(ship==4)
   res=1;
 else if(ship==5)
   res=2;
 else if(ship==6)
   res=3;
 else
   res=7;

 return res;
}

void make_ship(int x,int y,int ship)
{
  int i,k=x,k1=y;

  if(ship==1)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<4;i++,k=k+20)
      {
      matrix01[(y-50)/20][(k-50)/20]=1;
      floodfill(k+1,y+1,LIGHTGRAY);
      }
    }
  if(ship==2)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<3;i++,k=k+20)
      {
      matrix01[(y-50)/20][(k-50)/20]=1;
      floodfill(k+1,y+1,LIGHTGRAY);
      }
    }
  if(ship==3)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<2;i++,k=k+20)
      {
      matrix01[(y-50)/20][(k-50)/20]=1;
      floodfill(k+1,y+1,LIGHTGRAY);
      }
    }
  if(ship==4)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<4;i++,k1=k1+20)
      {
      matrix01[(k1-50)/20][(x-50)/20]=1;
      floodfill(x+1,k1+1,LIGHTGRAY);
      }
    }
  if(ship==5)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<3;i++,k1=k1+20)
      {
      matrix01[(k1-50)/20][(x-50)/20]=1;
      floodfill(x+1,k1+1,LIGHTGRAY);
      }
    }
  if(ship==6)
    {
    setfillstyle(1,GREEN);
    for(i=0;i<2;i++,k1=k1+20)
      {
      matrix01[(k1-50)/20][(x-50)/20]=1;
      floodfill(x+1,k1+1,LIGHTGRAY);
      }
    }
  if(ship>6)
    {
    setfillstyle(1,GREEN);
    matrix01[(y-50)/20][(x-50)/20]=1;
    floodfill(x+1,y+1,LIGHTGRAY);
    }
}

int change_pal(int count)
{
  if(count==0)
    ship=1;
  else if(count==1||count==2)
    {
    no_field(x,y,ship);
    if(ship==1)
      ship=2;
    if(ship==4)
      ship=5;
    }
  else if(count==3||count==4||count==5)
    {
    no_field(x,y,ship);
    if(ship==2)
      ship=3;
    if(ship==5)
      ship=6;
    if(ship==3)
      ship=3;
    if(ship==6)
      ship=6;
    }
    else
      {
      no_field(x,y,ship);
      ship=7;
      }

 return ship;
}

void computer_fleet(void)
{
 int count=0;

 while(count<=10)
   {
   c_ship(count);
   count++;
   }
}

void c_ship(int count)
{
  int i=0,j=0,k,npr;

   randomize();
M1:
   npr=random(2);
   if(count==0&&npr==0)
     {
     i=random(7);
     j=random(10);
     matrix02[j][i]=1;
     matrix02[j][i+1]=1;
     matrix02[j][i+2]=1;
     matrix02[j][i+3]=1;
     }

   if(count==0&&npr==1)
     {
     i=random(10);
     j=random(7);
     matrix02[j][i]=1;
     matrix02[j+1][i]=1;
     matrix02[j+2][i]=1;
     matrix02[j+3][i]=1;
     setfillstyle(1,LIGHTGREEN);
     }

   if((count==1||count==2)&&npr==0)
     {
      i=random(8);
      j=random(10);
      if(matrix02[j][i]==0&&matrix02[j][i+1]==0&&matrix02[j][i+2]==0)
        {
        matrix02[j][i]=1;
        matrix02[j][i+1]=1;
        matrix02[j][i+2]=1;
        }
      else
        goto M1;
     }

    if((count==1||count==2)&&npr==1)
     {
      i=random(10);
      j=random(8);
      if(matrix02[j][i]==0&&matrix02[j+1][i]==0&&matrix02[j+2][i]==0)
        {
        matrix02[j][i]=1;
        matrix02[j+1][i]=1;
        matrix02[j+2][i]=1;
        }
      else
        goto M1;
     }

     if((count==3||count==4||count==5)&&npr==0)
     {
      i=random(9);
      j=random(10);
      if(matrix02[j][i]==0&&matrix02[j][i+1]==0)
        {
        matrix02[j][i]=1;
        matrix02[j][i+1]=1;
        }
      else
        goto M1;
     }

     if((count==3||count==4||count==5)&&npr==1)
     {
      i=random(10);
      j=random(9);
      if(matrix02[j][i]==0&&matrix02[j+1][i]==0)
        {
        matrix02[j][i]=1;
        matrix02[j+1][i]=1;
        }
      else
        goto M1;
     }
   if(count>6)
     {
      i=random(10);
      j=random(10);
      if(matrix02[j][i]==0)
        {
        matrix02[j][i]=1;
        }
      else
        goto M1;
     }
     x=350; // NEED!!!
     y=50;  // NEED!!!

}

void get_player_move(void)
{
 char ch;
 int vic=0,ep;
 unsigned int volume;
 void *arrow;
STGPM:

 vic=victory();
 if(vic==1||vic==2)
   goto ENDGPM;

 ch=getch();

  if(ch==27)
    {
    volume=imagesize(199,149,470,260);
    arrow=malloc(volume);
    getimage(199,149,470,260,arrow);
    ep=exit_game();
    if(ep==1)
      {
      free(arrow);
      ex=1;
      cleardevice();
      goto ENDGPM;
      }
    else
      {
      putimage(199,149,arrow,0);
      free(arrow);
      goto STGPM;
      }
    }

 if(ch==0)
   {
   step++;
   ch=getch();
   p_direct(ch);
   goto STGPM;
   }

 if(ch==32&&matrix02[(y-50)/20][(x-350)/20]==0)
   {
   fire(x,y,step);
   step++;
   goto ENDGPM;
   }

 if(ch==32&&matrix02[(y-50)/20][(x-350)/20]==1)
   {
   fire(x,y,step);
   step++;
   goto STGPM;
   }

 if(ch==32&&(matrix02[(y-50)/20][(x-350)/20]==2||
           matrix02[(y-50)/20][(x-350)/20]==3))
      goto STGPM;

                                          // S
 if(ch=='s'||ch=='S')                     // E
   ch=getch();                            // C
   if(ch=='e'||ch=='E')                   // R
     ch=getch();                          // E
     if(ch=='c'||ch=='c')                 // T
       ch=getch();                        //
       if(ch=='r'||ch=='R')               // |
         ch=getch();                       //
           if(ch=='e'||ch=='E')           // C
             ch=getch();                  // H
             if(ch=='t'||ch=='T')         // E
               {
               secret01(x,y);             // A
               goto STGPM;
               }

  if(ch=='i'||ch=='I')                     // E
   ch=getch();                            // C
   if(ch=='w'||ch=='W')                   // R
     ch=getch();                          // E
     if(ch=='i'||ch=='I')                 // T
       ch=getch();                        //
       if(ch=='n'||ch=='N')               // |
         ch=getch();                      //
         if(ch=='n'||ch=='N')             // C
           ch=getch();                    // H
           if(ch=='e'||ch=='E')           // E
             ch=getch();
             if(ch=='r'||ch=='R')
               {
               secret02();             // A
               goto STGPM;
               }

 if(ch=='m'||ch=='M')                   // E
   ch=getch();                            // C
   if(ch=='a'||ch=='A')                   // R
     ch=getch();                          // E
     if(ch=='c'||ch=='C')                 // T
       ch=getch();                        //
       if(ch=='w'||ch=='W')               // |
         ch=getch();                      //
         if(ch=='i'||ch=='I')
         ch=getch();
           if(ch=='n'||ch=='N')
           ch=getch();
             if(ch=='n'||ch=='N')           // C
             ch=getch();                    // H
               if(ch=='e'||ch=='E')           // E
               ch=getch();
                  if(ch=='r'||ch=='R')
                  {
                  secret03();            // A
                  goto STGPM;
                  }

 if(ch!=27&&ch!=0&&ch!=32)
   goto STGPM;

ENDGPM:
}

void p_direct(char to)
{

     if(to==80&&y!=230)           // Проверка на нажатие ВНИЗ.
       {                          // Проверка на нажатие ВНИЗ.
       no_wfield(pred_x,pred_y);  // Проверка на нажатие ВНИЗ.
       y=y+20;                    // Проверка на нажатие ВНИЗ.
       pred_x=x; pred_y=y;        // Проверка на нажатие ВНИЗ.
       wfield(x, y);              // Проверка на нажатие ВНИЗ.
       }


     if(to==72&&y!=50)          // Проверка на нажатие ВВЕРХ.
       {                        // Проверка на нажатие ВВЕРХ.
       no_wfield(pred_x,pred_y);// Проверка на нажатие ВВЕРХ.
       y=y-20;                  // Проверка на нажатие ВВЕРХ.
       pred_x=x; pred_y=y;      // Проверка на нажатие ВВЕРХ.
       wfield(x, y);            // Проверка на нажатие ВВЕРХ.
       }

     if(to==75&&x!=350)         // Проверка на нажатие ВЛЕВО.
       {                        // Проверка на нажатие ВЛЕВО.
       no_wfield(pred_x,pred_y);// Проверка на нажатие ВЛЕВО.
       x=x-20;                  // Проверка на нажатие ВЛЕВО.
       pred_x=x; pred_y=y;      // Проверка на нажатие ВЛЕВО.
       wfield(x, y);            // Проверка на нажатие ВЛЕВО.
       }

     if(to==77&&x!=530)         // Проверка на нажатие ВПРАВО.
       {                        // Проверка на нажатие ВПРАВО.
       no_wfield(pred_x,pred_y);// Проверка на нажатие ВПРАВО.
       x=x+20;                  // Проверка на нажатие ВПРАВО.
       pred_x=x; pred_y=y;      // Проверка на нажатие ВПРАВО.
       wfield(x, y);            // Проверка на нажатие ВПРАВО.
       }
}

void wfield(int x, int y)
{
     setcolor(LIGHTGRAY);
     rectangle(x,y,x+20,y+20);
     setcolor(BLUE);
}

void no_wfield(int x, int y)
{
     setcolor(BLUE);
     rectangle(x,y,x+20,y+20);
//     setcolor(LIGHTGRAY);
}

int victory(void)
{
 int i,j,count01=0,count02=0;

 for(i=0;i<10;i++)
   for(j=0;j<10;j++)
     if(matrix01[i][j]==3)
       count01++;

 for(i=0;i<10;i++)
   for(j=0;j<10;j++)
     if(matrix02[i][j]==3)
       count02++;

 if(count01==20)
   return 1;
 else if(count02==20)
   return 2;
 else
   return 0;
}

void fire(int x,int y,int step)
{
  if(matrix02[(y-50)/20][(x-350)/20]==0)
    {
    matrix02[(y-50)/20][(x-350)/20]=2;
    setcolor(LIGHTGRAY);
    setfillstyle(1,LIGHTCYAN);
    if(step==0)
      floodfill(x+1,y+1,BLUE);
    if(step!=0)
      floodfill(x+1,y+1,LIGHTGRAY);
    }

  if(matrix02[(y-50)/20][(x-350)/20]==1)
    {
    matrix02[(y-50)/20][(x-350)/20]=3;
    setcolor(LIGHTGRAY);
    setfillstyle(1,RED);
    if(step==0)
      floodfill(x+1,y+1,LIGHTGRAY);
    if(step!=0)
      floodfill(x+1,y+1,LIGHTGRAY);
    }
      setcolor(BLUE);

}

void get_computer_move(void)
{
  int i,j;
  randomize();

STGCM:

  i=random(10);
  j=random(10);

  if(matrix01[j][i]==2||matrix01[j][i]==3)
    goto STGCM;

  if(matrix01[j][i]==0)
    {
     setfillstyle(1,LIGHTCYAN);
     floodfill(i*20+51,j*20+51,BLUE);
     matrix01[j][i]=2;
    }

  if(matrix01[j][i]==1)
    {
     setfillstyle(1,RED);
     floodfill(i*20+51,j*20+51,BLUE);
     matrix01[j][i]=3;
     goto STGCM;
    }
}

int exit_game(void)
{
   char ch;

   setcolor(WHITE);
   rectangle(200,150,470,260);
   setfillstyle(1,DARKGRAY);
   floodfill(201,151,WHITE);
   outtextxy(210,160,"Do you want exit from this game?");
   line(230,190,250,220); // Y.
   line(230,190,240,190); // Y.
   line(240,190,258,217); // Y.
   line(276,190,258,217); // Y.
   line(276,190,286,190); // Y.
   line(286,190,266,220); // Y.
   line(250,220,250,250); // Y.
   line(266,220,266,250); // Y.
   line(250,250,266,250); // Y.
   outtextxy(325,220,"OR");
   line(380,190,380,250); // N.
   line(380,190,390,190); // N.
   line(390,190,390,200); // N.
   line(390,210,390,250); // N.
   line(380,250,390,250); // N.
   line(410,190,410,230); // N.
   line(410,240,410,250); // N.
   line(390,200,410,230); // N.
   line(390,210,410,240); // N.
   line(410,190,420,190); // N.
   line(410,250,420,250); // N.
   line(420,190,420,250); // N.

   setfillstyle(1,LIGHTGRAY);
   floodfill(237,191,WHITE);
   floodfill(381,191,WHITE);

   setcolor(BLUE);

   ch=getch();
     if(ch=='Y'||ch=='y')
       return 1;
     else
       return 0;
}

void s(int x,int y)
{
  setcolor(RED);

  line(x+20,y,x+30,y);
  line(x+20,y,x,y+20);
  line(x,y+20,x,y+40);
  line(x,y+40,x+40,y+70);
  line(x+40,y+70,x+40,y+80);
  line(x+40,y+80,x+30,y+90);
  line(x+30,y+90,x+20,y+90);
  line(x+20,y+90,x+10,y+80);
  line(x+10,y+80,x,y+80);
  line(x,y+80,x+20,y+100);
  line(x+30,y+100,x+20,y+100);
  line(x+30,y+100,x+50,y+80);
  line(x+50,y+80,x+50,y+60);
  line(x+50,y+60,x+10,y+30);
  line(x+10,y+30,x+10,y+20);
  line(x+10,y+20,x+20,y+10);
  line(x+20,y+10,x+30,y+10);
  line(x+30,y+10,x+40,y+20);
  line(x+40,y+20,x+50,y+20);
  line(x+50,y+20,x+30,y);

  setfillstyle(1,LIGHTRED);
  floodfill(x+25,y+1,RED);

  setcolor(WHITE);
}

void e(int x,int y)
{
 setcolor(RED);
 line(x+10,y,x+40,y);
 line(x+10,y,x,y+10);
 line(x,y+10,x,y+90);
 line(x,y+90,x+10,y+100);
 line(x+10,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y+90);
 line(x+50,y+90,x+50,y+80);
 line(x+50,y+80,x+40,y+90);
 line(x+40,y+90,x+20,y+90);
 line(x+20,y+90,x+10,y+80);
 line(x+10,y+80,x+10,y+55);
 line(x+10,y+55,x+40,y+55);
 line(x+40,y+55,x+40,y+45);
 line(x+40,y+45,x+10,y+45);
 line(x+10,y+45,x+10,y+20);
 line(x+10,y+20,x+20,y+10);
 line(x+20,y+10,x+40,y+10);
 line(x+40,y+10,x+50,y+20);
 line(x+50,y+20,x+50,y+10);
 line(x+50,y+10,x+40,y);

 setfillstyle(1,LIGHTRED);
 floodfill(x+30,y+1,RED);

 setcolor(WHITE);
}

void a(int x,int y)
{
 setcolor(RED);

 line(x+20,y,x+30,y);
 line(x+20,y,x,y+100);
 line(x,y+100,x+10,y+100);
 line(x+10,y+100,x+12,y+90);
 line(x+12,y+90,x+38,y+90);
 line(x+38,y+90,x+40,y+100);
 line(x+40,y+100,x+50,y+100);
 line(x+50,y+100,x+30,y);
 line(x+25,y+10,x+12,y+80);
 line(x+12,y+80,x+38,y+80);
 line(x+38,y+80,x+25,y+10);

 setfillstyle(1,LIGHTRED);
 floodfill(x+25,y+5,RED);

 setcolor(WHITE);
}

void w(int x,int y)
{
 setcolor(RED);

 line(x,y,x+10,y);
 line(x,y,x+10,y+100);
 line(x+10,y+100,x+20,y+100);
 line(x+20,y+100,x+25,y+50);
 line(x+25,y+50,x+30,y+100);
 line(x+30,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y);
 line(x+50,y,x+40,y);
 line(x+40,y,x+35,y+75);
 line(x+35,y+75,x+30,y+25);
 line(x+30,y+25,x+20,y+25);
 line(x+20,y+25,x+15,y+75);
 line(x+15,y+75,x+10,y);

 setfillstyle(1,LIGHTRED);
 floodfill(x+5,y+5,RED);

 setcolor(WHITE);
}

void r(int x,int y)
{
 setcolor(RED);

 line(x,y,x+10,y);
 line(x,y,x,y+100);
 line(x,y+100,x+10,y+100);
 line(x+10,y+100,x+10,y+40);
 line(x+10,y+40,x+20,y+20);
 line(x+20,y+20,x+30,y+10);
 line(x+30,y+10,x+40,y+20);
 line(x+40,y+20,x+50,y+40);
 line(x+50,y+40,x+50,y+30);
 line(x+50,y+30,x+40,y+10);
 line(x+40,y+10,x+30,y);
 line(x+30,y,x+20,y+10);
 line(x+20,y+10,x+10,y+30);
 line(x+10,y+30,x+10,y);

 setfillstyle(1,LIGHTRED);
 floodfill(x+1,y+1,RED);

 setcolor(WHITE);
}

void titul(void)
{
   int x=120,x1=180,x2=240,x3=330,x4=390,x5=450,y=150;

   s(x,y);
   e(x1,y);
   a(x2,y);
   w(x3,y);
   a(x4,y);
   r(x5,y);

   setcolor(LIGHTRED);
   outtextxy(510,260,"@");
   setcolor(WHITE);
}

void y01(int x,int y)
{
 setcolor(BLUE);
 line(x,y,x+10,y);
 line(x,y,x,y+40);
 line(x,y+40,x+10,y+50);
 line(x+10,y+50,x+40,y+50);
 line(x+40,y+50,x+40,y+80);
 line(x+40,y+80,x+30,y+90);
 line(x+30,y+90,x+10,y+90);
 line(x+10,y+90,x,y+80);
 line(x,y+80,x,y+90);
 line(x,y+90,x+10,y+100);
 line(x+10,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y+90);
 line(x+50,y+90,x+50,y);
 line(x+50,y,x+40,y);
 line(x+40,y,x+40,y+40);
 line(x+40,y+40,x+20,y+40);
 line(x+20,y+40,x+10,y+30);
 line(x+10,y+30,x+10,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+1,y+1,BLUE);

 setcolor(YELLOW);
}

void o(int x,int y)
{
 setcolor(BLUE);

 line(x+10,y,x+40,y);
 line(x+10,y,x,y+10);
 line(x,y+10,x,y+90);
 line(x,y+90,x+10,y+100);
 line(x+10,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y+90);
 line(x+50,y+90,x+50,y+10);
 line(x+50,y+10,x+40,y);

 line(x+20,y+10,x+30,y+10);
 line(x+20,y+10,x+10,y+20);
 line(x+10,y+20,x+10,y+80);
 line(x+10,y+80,x+20,y+90);
 line(x+20,y+90,x+30,y+90);
 line(x+30,y+90,x+40,y+80);
 line(x+40,y+80,x+40,y+20);
 line(x+40,y+20,x+30,y+10);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+25,y+1,BLUE);

 setcolor(WHITE);
}

void u(int x,int y)
{
 setcolor(BLUE);

 line(x,y,x+10,y);
 line(x,y,x,y+90);
 line(x,y+90,x+10,y+100);
 line(x+10,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y+90);
 line(x+50,y+90,x+50,y);
 line(x+50,y,x+40,y);
 line(x+40,y,x+40,y+80);
 line(x+40,y+80,x+30,y+90);
 line(x+30,y+90,x+20,y+90);
 line(x+20,y+90,x+10,y+80);
 line(x+10,y+80,x+10,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+1,y+1,BLUE);

 setcolor(WHITE);
}

void w01(int x,int y)
{
 setcolor(BLUE);

 line(x,y,x+10,y);
 line(x,y,x+10,y+100);
 line(x+10,y+100,x+20,y+100);
 line(x+20,y+100,x+25,y+50);
 line(x+25,y+50,x+30,y+100);
 line(x+30,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y);
 line(x+50,y,x+40,y);
 line(x+40,y,x+35,y+75);
 line(x+35,y+75,x+30,y+25);
 line(x+30,y+25,x+20,y+25);
 line(x+20,y+25,x+15,y+75);
 line(x+15,y+75,x+10,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+5,y+5,BLUE);

 setcolor(WHITE);
}

void i(int x,int y)
{
 setcolor(BLUE);

 line(x,y,x+50,y);
 line(x,y,x,y+10);
 line(x,y+10,x+15,y+10);
 line(x+15,y+10,x+15,y+90);
 line(x+15,y+90,x,y+90);
 line(x,y+90,x,y+100);
 line(x,y+100,x+50,y+100);
 line(x+50,y+100,x+50,y+90);
 line(x+50,y+90,x+35,y+90);
 line(x+35,y+90,x+35,y+10);
 line(x+35,y+10,x+50,y+10);
 line(x+50,y+10,x+50,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+1,y+1,BLUE);

 setcolor(WHITE);
}

void a01(int x,int y)
{
 setcolor(BLUE);

 line(x+20,y,x+30,y);
 line(x+20,y,x,y+100);
 line(x,y+100,x+10,y+100);
 line(x+10,y+100,x+12,y+90);
 line(x+12,y+90,x+38,y+90);
 line(x+38,y+90,x+40,y+100);
 line(x+40,y+100,x+50,y+100);
 line(x+50,y+100,x+30,y);
 line(x+25,y+10,x+12,y+80);
 line(x+12,y+80,x+38,y+80);
 line(x+38,y+80,x+25,y+10);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+25,y+5,BLUE);

 setcolor(WHITE);
}

void n(int x,int y)
{
 setcolor(BLUE);

 line(x,y,x+10,y);
 line(x,y,x,y+100);
 line(x,y+100,x+10,y+100);
 line(x+10,y+100,x+10,y+20);
 line(x+10,y+20,x+40,y+90);
 line(x+40,y+90,x+40,y+100);
 line(x+40,y+100,x+50,y+100);
 line(x+50,y+100,x+50,y);
 line(x+50,y,x+40,y);
 line(x+40,y,x+40,y+80);
 line(x+40,y+80,x+10,y+10);
 line(x+10,y+10,x+10,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+1,y+1,BLUE);

 setcolor(WHITE);
}

void m(int x,int y)
{
 setcolor(BLUE);

 line(x+10,y,x+20,y);
 line(x+10,y,x,y+100);
 line(x,y+100,x+10,y+100);
 line(x+10,y+100,x+15,y+25);
 line(x+15,y+25,x+20,y+75);
 line(x+20,y+75,x+30,y+75);
 line(x+30,y+75,x+35,y+25);
 line(x+35,y+25,x+40,y+100);
 line(x+40,y+100,x+50,y+100);
 line(x+50,y+100,x+40,y);
 line(x+40,y,x+30,y);
 line(x+30,y,x+25,y+50);
 line(x+25,y+50,x+20,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+18,y+1,BLUE);

 setcolor(WHITE);
}

void c(int x,int y)
{
 setcolor(BLUE);

 line(x+10,y,x+40,y);
 line(x+10,y,x,y+10);
 line(x,y+10,x,y+90);
 line(x,y+90,x+10,y+100);
 line(x+10,y+100,x+40,y+100);
 line(x+40,y+100,x+50,y+90);
 line(x+50,y+90,x+50,y+80);
 line(x+50,y+80,x+40,y+90);
 line(x+40,y+90,x+20,y+90);
 line(x+20,y+90,x+10,y+80);
 line(x+10,y+80,x+10,y+20);
 line(x+10,y+20,x+20,y+10);
 line(x+20,y+10,x+40,y+10);
 line(x+40,y+10,x+50,y+20);
 line(x+50,y+20,x+50,y+10);
 line(x+50,y+10,x+40,y);

 setfillstyle(1,LIGHTBLUE);
 floodfill(x+25,y+1,BLUE);

 setcolor(WHITE);
}

void you_win(void)
{
   int x=120,x1=180,x2=240,x3=330,x4=390,x5=450,y=150;

   y01(x,y);
   o(x1,y);
   u(x2,y);
   w01(x3,y);
   i(x4,y);
   n(x5,y);
}

void mac_win(void)
{
   int x=120,x1=180,x2=240,x3=330,x4=390,x5=450,y=150;

   m(x,y);
   a01(x1,y);
   c(x2,y);
   w01(x3,y);
   i(x4,y);
   n(x5,y);
}

void st_menu(void)
{
 int a=0;
 char ch='a';

 while(ch!='r')
  {
  cleardevice();

  if(a==0)
      {
      setcolor(YELLOW);
      outtextxy(300,230,"NEW GAME.");
      setcolor(BROWN);
      outtextxy(300,240,"EXIT.");
      }
  else
      {
      setcolor(BROWN);
      outtextxy(300,230,"NEW GAME.");
      setcolor(YELLOW);
      outtextxy(300,240,"EXIT.");
      }

  DOS_GLUCK:
  ch=getch();
   if(ch=='r')
      goto DOS_GLUCK;

    if(ch!=0&&ch!='\r'&&ch!=27)
      continue;

    if(ch==27)
      {
      closegraph();
      exit(EXIT_SUCCESS);
      }

    if(ch==0)
      {
      ch=getch();
      if(ch==72||ch==80)
        {
        if(a==0) {a=1;continue;}
        if(a==1) {a=0;continue;}
        }
      }
    if(ch=='\r');
      break;
  }
  cleardevice();
  if(a==0)
    {
    setcolor(WHITE);
    goto ENDSTMENU;
    }
  else
    {
    closegraph();
    exit(EXIT_SUCCESS);
    }
    ENDSTMENU:
    ch='a';a=0;
}

void secret01(int x,int y)
{
 int i,j;

 setcolor(BLUE);

 no_wfield(x,y);

 for(i=0;i<10;i++)
   for(j=0;j<10;j++)
     if(matrix02[i][j]==1)
       {
       setfillstyle(1,YELLOW);
       floodfill(j*20+351,i*20+51,BLUE);
       }

 wfield(x,y);
}

void secret02(void)
{
 int i,j;

 for(i=0;i<10;i++)
   for(j=0;j<10;j++)
     if(matrix02[i][j]==1)
       matrix02[i][j]=3;
  outtextxy(250,450,"Bingo!!!");
}

void secret03(void)
{
 int i,j;

 for(i=0;i<10;i++)
   for(j=0;j<10;j++)
     if(matrix01[i][j]==1)
       matrix01[i][j]=3;

}

void show_next_ship(int num)// Работает при расстановке кораблей игрока.
{
 int i,j;
 outtextxy(50,360,"Next ship.");
 setcolor(BLUE);
 rectangle(50,370,130,450);
 for(i=0;i<4;i++)
   line(i*20+50,370,i*20+50,450);
 for(i=0;i<4;i++)
   line(50,i*20+370,130,i*20+370);
 for(i=0;i<4;i++)
   for(j=0;j<4;j++)
     {
     setfillstyle(1,LIGHTBLUE);
     floodfill(i*20+51,j*20+371,BLUE);
     }

   if(num==1)
     for(i=0;i<4;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(i*20+51,371,BLUE);
       }
   else if(num==4)
     for(i=0;i<4;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(51,i*20+371,BLUE);
       }
   else if(num==2)
     for(i=0;i<3;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(i*20+51,371,BLUE);
       }
   else if(num==5)
     for(i=0;i<3;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(51,i*20+371,BLUE);
       }
   else if(num==3)
     for(i=0;i<2;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(i*20+51,371,BLUE);
       }
   else if(num==6)
     for(i=0;i<2;i++)
       {
       setfillstyle(1,GREEN);
       floodfill(51,i*20+371,BLUE);
       }
   else
     {
     setfillstyle(1,GREEN);
     floodfill(51,371,BLUE);
     }
 setcolor(LIGHTGRAY);
}
