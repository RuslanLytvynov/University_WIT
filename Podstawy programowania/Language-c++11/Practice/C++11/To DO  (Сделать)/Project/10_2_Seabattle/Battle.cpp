#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#include "Battle.h"
using namespace std;
//----------------------------------------������� ������������--------------------------
//----------------------------------------������� �������� ���� ����������------------------------
void ppolef ( char **pole )
{
	 
	//�������� ����
	 for ( int i = 0; i < 10; i ++)
		 for ( int j = 0; j < 10; j ++ )
			 pole [i][j] = -2;


}
//----------------------------------������� ������ ����� ������������------------------------------

void fppolef (char **pole)                                        // ������� ������ ����
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
         cout << " ������. �� ���� ������� ����. " << endl;
   }
  
   fclose (f);
}
//----------------------------------������� ���������� ����� ������������------------------------------

void sppolef (char **pole)                                       // ������� ���������� ����
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
         cout << " ������. �� ���� ������� ����. " << endl;
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
//--------------------------------------������� �������� �������� ������������� ��������-----------------------------
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
//-----------------------------------------��� ������������ - �������������� ����������------------------------------
char hod_userhk ( )    //�������������� ����������

{
    
	char a;
	
    cout << " ������� ���������� " << endl;

	cout << " ��� �������������� ���������� ������� ����� ���������� �������� (�� A �� K - � ������� ��������) " << endl;

while (1)
{
	cin >> a;
	if (((int) a < 65) || ((int) a > 74) )
		{
			cout << " ������. �� ����� �������� ����������! ���������� ��� ���. " << endl;
			
			continue;
	    }
	else
	    {
           cout << " �������������� ���������� - " << a;

		   break;
	    }

}
  return a;
}
//----------------------------------------��� ������������ - ������������ ����������--------------------------
int hod_uservk ()                                        //��� ������������ ����������
{
	int k;	
	
	cout << " ��� ������������ ���������� ������� ����� ( �� 1 �� 10 ) " << endl;

while (1)
{
   cin >> k;

   if ( k < 1 || k > 10)
   {
      cout << " ������. �� ����� �������� ����������! ���������� ��� ���. " << endl;

	  continue;
   }
   else 
   {
      cout << " ������������ ���������� " << k << endl;

	  break;
   }
}
   
   return k;
}
//--------------------------------------------������� �������� ���������-------------------------------------------------------
int userhit ( char &horCoord, int &verCoord, char ** ar,char **pole)                             //�������� ���� ������������ ������ ���������
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

//--------------------------------������� ����������---------------------------------------
//--------------------------------��� ���������� - �������������� ����������--------------------
int hod_komphk ()
{
   
   int ar_time [100];
   srand (time (NULL));

   for (int i = 0; i < 99; i++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//----------------------------------��� ���������� - ������������ ����������-----------------------
int hod_kompvk ()
{
   int ar_time [100];
   srand (time (NULL));

   for (int i = 0; i < 99; i ++)
	   ar_time [i] = rand ()%10 + 1;

   return ar_time [rand ()%100];
}
//------------------------------------  �������� ��������� ����������-----------------------------------
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
