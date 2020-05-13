#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#include "Battle.h"
using namespace std;
//----------------------------------------функции пользователя--------------------------
//----------------------------------------функция видимого поля компьютера------------------------
void ppolef ( char **pole )
{
	 
	//заполним поле
	 for ( int i = 0; i < 10; i ++)
		 for ( int j = 0; j < 10; j ++ )
			 pole [i][j] = -2;


}
//----------------------------------функция записи ходов пользователя------------------------------

void fppolef (char **pole)                                        // функция записи поля
{
   FILE *f;
   f = fopen ("seabattle1.txt", "w");
   if (f != NULL)
   {
        for ( int i = 0; i < 10; i ++)
			for( int j = 0; j < 10; j ++)
			     fputc (pole [i][j], f);
   }
   else
   {
         cout << " Ошибка. Не могу открыть файл. " << endl;
   }
  
   fclose (f);
}
//----------------------------------функция считывания ходов пользователя------------------------------

void sppolef (char **pole)                                       // функция считывания поля
{
   FILE *f;
   f = fopen ("seabattle1.txt", "r");
   if (f!=NULL)
   {
         for ( int i = 0; i < 10; i ++ )
		 {
			 for( int j = 0; j < 10; j ++)
			 {
			    pole[i][j] = fgetc(f);   
			 }
		 }
   }
   else
   {
         cout << " Ошибка. Не могу открыть файл. " << endl;
   }
fclose (f);
   for ( int i = 0; i < 2; i ++)
		 cout << ' ';
	 for ( int i = 0; i < 10; i ++)
		 cout << i + 1;
	 cout << endl;

   for ( int i = 0; i < 10; i ++)
	{
		cout << char(i + 65) << ' ';
		for ( int j = 0; j < 10; j ++)
		{
			cout <<pole [i][j];
		}
     cout <<endl;
   }

  
}
//--------------------------------------функция подсчета подбитых пользователем кораблей-----------------------------
int amountship (char **pole)
{
    int count = 0;
	int sum = 0;

	for ( int i = 0; i < 10; i ++)
		for ( int j = 0; j < 10; j ++)
		{
		     count = ( pole [i][j] == 'x')? 1:0;
			 sum += count;
		}
	if (sum == 18) return 1;
	if (sum < 18) return 0;

}
//-----------------------------------------ход пользователя - горизонтальная координата------------------------------
char hod_userhk ( )    //горизонтальная координата

{
    
	char a;
	
    cout << " Введите координаты " << endl;

	cout << " Для горизонтальной координаты введите букву латинского алфавита (от A до K - в верхнем регистре) " << endl;

while (1)
{
	cin >> a;
	if (((int) a < 65) || ((int) a > 74) )
		{
			cout << " Ошибка. Вы ввели неверную координату! Попробуйте еще раз. " << endl;
			
			continue;
	    }
	else
	    {
           cout << " Горизонтальная координата - " << a;

		   break;
	    }

}
  return a;
}
//----------------------------------------ход пользователя - вертикальная координата--------------------------
int hod_uservk ()                                        //для вертикальной координаты
{
	int k;	
	
	cout << " Для вертикальной координаты введите цифру ( от 1 до 10 ) " << endl;

while (1)
{
   cin >> k;

   if ( k < 1 || k > 10)
   {
      cout << " Ошибка. Вы ввели неверную координату! Попробуйте еще раз. " << endl;

	  continue;
   }
   else 
   {
      cout << " Вертикальная координата " << k << endl;

	  break;
   }
}
   
   return k;
}
//--------------------------------------------функция проверки попадания-------------------------------------------------------
int userhit ( char &horCoord, int &verCoord, char ** ar,char **pole)                             //проверка хода пользователя насчет попадания
{
	

	if ( ar [(int)horCoord - 65][verCoord - 1] == 127) 
	{
		return 1;
	}
	else if ( pole [(int)horCoord - 65][verCoord - 1] == '*' || pole [(int)horCoord - 65][verCoord - 1] == 'x')
	{
	    return -1;
	}
	else 
	{
        return 0;
	}
}

//--------------------------------функции компьютера---------------------------------------
//--------------------------------ход компьютера - горизонтальная координата--------------------
int hod_komphk ()
{
   
   int ar_time [100];
   srand (time (NULL));

   for (int i = 0; i < 99; i++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//----------------------------------ход компьютера - вертикальная координата-----------------------
int hod_kompvk ()
{
   int ar_time [100];
   srand (time (NULL));

   for (int i = 0; i < 99; i ++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//------------------------------------  проверка попадания компьютера-----------------------------------
int komphit (int &horCoor, int &verCoord, char **ar_user)
{
		if ( ar_user [horCoor - 1][verCoord - 1] == 127) 
	{
		return 1;
	}
	else if ( ar_user [horCoor - 1][verCoord - 1] == '*' || ar_user [horCoor - 1][verCoord - 1] == 'x')
	{
	    return -1;
	}
	else 
	{
        return 0;
	}

}

int amountSh (char **ar_user)
{
    int count = 0;
	int sum = 0;

	for ( int i = 0; i < 10; i ++)
		for ( int j = 0; j < 10; j ++)
		{
		     count = ( ar_user [i][j] == 'x')? 1:0;
			 sum += count;
		}
	if (sum == 18) return 1;
	if (sum < 18) return 0;
}
