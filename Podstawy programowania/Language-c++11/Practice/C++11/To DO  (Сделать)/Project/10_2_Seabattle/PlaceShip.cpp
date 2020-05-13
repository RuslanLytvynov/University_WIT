#include <iostream>
#include <cstdio>
#include <ctime>
#include "PlaceShip.h"
using namespace std;

ship_user shipus;
//-------------------------------������� ��������--------------------------
void upload ()
{
   cout << " ��������� �������. ����������......" << endl;
}
// ------------------------------ �������� ���� ���������� -------------------------
void arpole ( char **ar)
{
 
	for ( int i = 1; i < 11; i ++)
	{
		for ( int j = 1; j < 11; j ++)
		{
		    cout << ar [i][j];
	    }
	cout << endl;
	}
}
//--------------------------------�������� ���� ������������---------------------------
void aruserpole ( char **ar_user)
{
   
	

     for ( int i = 0; i < 2; i ++)
		 cout << ' ';
	 for ( int i = 0; i < 10; i ++)
		 cout << i + 1;
	   cout << endl; 

	  for ( int i = 1; i < 11; i ++)
	   {
		 cout << char (i + 64) << ' ';
		for ( int j = 1; j < 11; j ++)
		{
		    cout << ar_user [i][j];
	    }
	   cout << endl;
	   }

}
//---------------------------------������� ������ ��������---------------------------------
int chooseship ()
{
setlocale(LC_ALL,"Russian");
   int m;
   cout<<"���������� ����������� 10 ��������. 1 - ���������������, 2-�������������, 3-���� ��������� � 4 - ������������\n";
   cout<<"���������� ������ ���������� ��� ��������� ������ �������.\n";
   cout<<"�������� 4, ����� ����������� ���������������\n"<<endl;
   cout<<"�������� 3 ��� ������������ ��������������\n"<<endl;
   cout<<"�������� 2 ��� ������������ ��������������\n"<<endl;
   cout<<"�������� 1 ��� ������������ ������������ ��������\n"<<endl;
   cin>>m;
setlocale(LC_ALL,".OCP");
  if (m == 4 || m == 3 || m == 2 || m == 1)
       return m;
  else return 0;
}
//---------------------------------������� ������ ���������� �������-----------------------------

int chooseorient ( int &k)
{
if ( k == 1)
{
	srand ( time (NULL));
	return rand ()%2;
	
}
else if (k == 0)
{
setlocale(LC_ALL,"Russian");
   
   cout<<"�������� 1, ���� ��� ������� ����������\n"<<endl;
   cout<<"�������� 0, ���� ��� ������� ������������\n"<<endl;
   cin>>shipus.d;
setlocale(LC_ALL,".OCP");
}                     
	return shipus.d;

}
//---------------------------------������� �������������� ����������------------------------

int HorCoord ( int &k )
{
srand (time (NULL));
if ( k == 1)
{
   return rand ()%10 + 1;
 }
else if ( k == 0 )
{
do
{
setlocale(LC_ALL,"Russian");
 cout<<"�������  �������������� ���������� ������ ������ ��������� ������� (A - J) ->"<<endl;
setlocale(LC_ALL,".OCP");
 cin>>shipus.x;  
 if (shipus.x >=65 && shipus.x <= 74) break;
 else cout << " Error. Try again." <<endl;

} while (1);
return (int)shipus.x - 64;
}

}
//---------------------------------������� ������������ ����������-----------------------
int VerCoord ( int &k)
{
srand (time (NULL));
if ( k == 1)
{
   return rand ()%10 + 1;
  }
else if ( k == 0)
{
do
{
setlocale(LC_ALL,"Russian");
cout<<"������� ������������ ���������� ������ ������ ����� �� 1 �� 10 ->"<<endl;
cin>>shipus.y;
setlocale(LC_ALL,".OCP");
if ( shipus.y > 10 || shipus.y < 1) cout << " Error. Try again." << endl;
else break;
} while (1);

return shipus.y;
}

}

//---------------------------------������� �������� ������������� �����----------------------------
int test (char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &count, int &sh)
{
	int sum = 0;

switch (Orient)
{
case 1:
	switch ( sh)
     {
	case 4:
	             if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
	                {
	                  for ( int i = horCoordShip + 1 - count; i > horCoordShip - 2 - count; i --)
			  
		                      for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		                      {
		                        int d = (ar_user [i][j] == 127)? 1 : 0;
			                      sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1 + count; i < horCoordShip + 2 + count; i ++)
		                       for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		                       {
		                           int d = (ar_user [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
	  break;
	case 3:
		  if ( horCoordShip == 10 || horCoordShip == 9)
	       {
	          for ( int i = horCoordShip + 1 - count; i > horCoordShip - 2 - count; i --)
			  
		             for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		              {
		                  int d = (ar_user [i][j] == 127)? 1 : 0;
			               sum += d;
		              }
	                if (sum > 0) return 1;
	                else if (sum == 0) return 0;
	        }
	       else
	        {
	          for ( int i = horCoordShip - 1 + count; i < horCoordShip + 2 + count; i ++)
		               for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		               {
		                  int d = (ar_user [i][j] == 127)? 1 : 0;
			              sum += d;
		               }
	                   if (sum > 0) return 1;
	                   else if (sum == 0) return 0;
	        }
		break;
	case 2:
		      if ( horCoordShip == 10)
	       {
	          for ( int i = horCoordShip + 1 - count; i > horCoordShip - 2 - count; i --)
			  
		             for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		              {
		                  int d = (ar_user [i][j] == 127)? 1 : 0;
			               sum += d;
		              }
	                if (sum > 0) return 1;
	                else if (sum == 0) return 0;
	        }
	       else
	        {
	          for ( int i = horCoordShip - 1 + count; i < horCoordShip + 2 + count; i ++)
		               for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		               {
		                  int d = (ar_user [i][j] == 127)? 1 : 0;
			              sum += d;
		               }
	                   if (sum > 0) return 1;
	                   else if (sum == 0) return 0;
		     
			  }
		break;
	}
	break;
	
case 0:
	switch ( sh)
     {
	case 4:
	             if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - count; j < verCoordShip - 2 - count; j --)
		                      {
		                        int d = (ar_user [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + count; j < verCoordShip + 2 + count; j ++)
		                       {
		                           int d = (ar_user [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
	  break;
	case 3:
		  if ( horCoordShip == 10 || horCoordShip == 9)
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - count; j < verCoordShip - 2 - count; j --)
		                      {
		                        int d = (ar_user [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + count; j < verCoordShip + 2 + count; j ++)
		                       {
		                           int d = (ar_user [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
		break;
	case 2:
		       if ( horCoordShip == 10 )
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - count; j < verCoordShip - 2 - count; j --)
		                      {
		                        int d = (ar_user [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + count; j < verCoordShip + 2 + count; j ++)
		                       {
		                           int d = (ar_user [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }

		break;
	}
break;	

}
}	

//---------------------------------������� ����������� �������--------------------------
void shipplace (char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &sh)
{

 
	switch (Orient)
	{
	case 1:
	   switch (sh)
	   {
	   case 4:
		   if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 4; i --)
				  ar_user [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 4; i ++ )
				ar_user [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   case 3:
		   if ( horCoordShip == 10 || horCoordShip == 9)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 3; i --)
				  ar_user [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 3; i ++ )
				ar_user [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   case 2:
		   if ( horCoordShip == 10)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 2; i --)
				  ar_user [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 2; i ++ )
				ar_user [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   }
	   break;
	case 0:
		 switch (sh)
	   {
	   case 4:
		     if ( verCoordShip == 10 || verCoordShip == 9 || verCoordShip == 8)
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 4; i --)
					  ar_user [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 4; i ++)
					  ar_user [horCoordShip][i] = 127;
			 }
		   break;
	   case 3:
		      if ( verCoordShip == 10 || verCoordShip == 9)
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 3; i --)
					  ar_user [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 3; i ++)
					  ar_user [horCoordShip][i] = 127;
			 }
		   break;
	   case 2:
		      if ( verCoordShip == 10 )
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 2; i --)
					  ar_user [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 2; i ++)
					  ar_user [horCoordShip][i] = 127;
			 }
		   break;
	   }

	   break;
	}
   
   }


//---------------------------------������� �������� ����� ------------------------------
int amountshipp ( char **ar_user)
{
   int sum = 0;
    for ( int i = 1; i < 11; i ++)
		for ( int j = 1; j < 11; j ++)
		{
		    int k = (ar_user [i][j] == 127)? 1:0;
			sum +=k;
		}
   return sum;
}
//-------------------------------������� ������ ����������������� ����-------------------------
void writeuser (char **ar_user)               
{
    FILE *f;
	f = fopen ("seabattleuser.txt", "w");
	if (f != NULL)
	{
	 for ( int i = 0; i < 13; i ++)
		 for ( int j = 0; j < 13; j ++)
			 fputc (ar_user [i][j], f);
	}
	else cout << " Error. I can't open the file." <<endl;
	 fclose (f);

}
//---------------------------------������� ���������� ����������������� ����----------------------
void readuser (char **ar_user)
{
    FILE *f;
	f = fopen ("seabattleuser.txt", "r");
	 for ( int i = 0; i < 13; i ++)
	 {
	     
		  for ( int j = 0; j < 13; j ++)
			  ar_user [i][j] = fgetc (f);
	 
	 }
	fclose (f);


}

int testone (int &horCoordShip, int &verCoordShip, char **ar_user)
{
       int sum = 0;          
	for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
         for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		      {
		          int d = (ar_user [i][j] == 127)? 1 : 0;			              
			      sum += d;
		      }
	       if (sum > 0) return 1;
	       else if (sum == 0) return 0; 
}

void placeone (int &horCoordShip, int &verCoordShip, char **ar_user)
{
  
         ar_user [horCoordShip][verCoordShip] = 127;
   
}
 int onehorCoord ()
 {
     srand (time (NULL));
		 return rand ()%10 + 1;
 }
 int oneverCoord ()
 {
         srand (time (NULL));
		 return rand ()%10 + 1;
 }
//-----------------------------------������ �����������----------------------------


//--------------------------------------�������������� ����������� �������� ��� ����������-------------------------
//--------------------------------------���������� �������----------------------------------------
 int orientKomp ()
 {
    srand ( time (NULL));
	return rand ()%2;
 
 }
//-------------------------------------���������� �������----------------------------------------------
//-------------------------------------�������������� ����������---------------------------------------

 int HorCoordK ()
 {
	srand ( time (NULL));
    return rand ()%10 + 1;
 }
//------------------------------------�������������� ����������---------------------------------------------
 int VerCoordK ()
 {
    srand ( time (NULL));
	return rand ()%10 + 1;
 }
//------------------------------------�������������� ����������------------------------------------------------
//------------------------------------������� ��� ������������� �������---------------------------------------
 void placeoneK (int &horCoordShip, int &verCoordShip, char **ar)
{
  
         ar [horCoordShip][verCoordShip] = 127;
   
}
 int onehorCoordK ()
 {
     srand (time (NULL));
		 return rand ()%10 + 1;
 }
 int oneverCoordK ()
 {
         srand (time (NULL));
		 return rand ()%10 + 1;
 }
//---------------------------------������������ ����� ��� �������������---------------------------------------
int testoneK (int &horCoordShip, int &verCoordShip, char **ar)
{
       int sum = 0;          
	for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
         for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		      {
		          int d = (ar [i][j] == 127)? 1 : 0;			              
			      sum += d;
		      }
	       if (sum > 0) return 1;
	       else if (sum == 0) return 0; 
}
//-------------------------------------�������� ������������� �����------------------------------------------
 int testK (char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &counter, int &Ship)
 {
     int sum = 0;

switch (Orient)
{
case 1:
	switch ( Ship )
     {
	case 4:
	             if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
	                {
	                  for ( int i = horCoordShip + 1 - counter; i > horCoordShip - 2 - counter; i --)
			  
		                      for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		                      {
		                        int d = (ar [i][j] == 127)? 1 : 0;
			                      sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1 + counter; i < horCoordShip + 2 + counter; i ++)
		                       for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		                       {
		                           int d = (ar [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
	  break;
	case 3:
		  if ( horCoordShip == 10 || horCoordShip == 9)
	       {
	          for ( int i = horCoordShip + 1 - counter; i > horCoordShip - 2 - counter; i --)
			  
		             for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		              {
		                  int d = (ar [i][j] == 127)? 1 : 0;
			               sum += d;
		              }
	                if (sum > 0) return 1;
	                else if (sum == 0) return 0;
	        }
	       else
	        {
	          for ( int i = horCoordShip - 1 + counter; i < horCoordShip + 2 + counter; i ++)
		               for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		               {
		                  int d = (ar [i][j] == 127)? 1 : 0;
			              sum += d;
		               }
	                   if (sum > 0) return 1;
	                   else if (sum == 0) return 0;
	        }
		break;
	case 2:
		      if ( horCoordShip == 10)
	       {
	          for ( int i = horCoordShip + 1 - counter; i > horCoordShip - 2 - counter; i --)
			  
		             for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		              {
		                  int d = (ar [i][j] == 127)? 1 : 0;
			               sum += d;
		              }
	                if (sum > 0) return 1;
	                else if (sum == 0) return 0;
	        }
	       else
	        {
	          for ( int i = horCoordShip - 1 + counter; i < horCoordShip + 2 + counter; i ++)
		               for ( int j = verCoordShip - 1; j < verCoordShip + 2; j ++)
		               {
		                  int d = (ar [i][j] == 127)? 1 : 0;
			              sum += d;
		               }
	                   if (sum > 0) return 1;
	                   else if (sum == 0) return 0;
		     
			  }
		break;
	}
	break;
	
case 0:
	switch ( Ship)
     {
	case 4:
	             if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - counter; j < verCoordShip - 2 - counter; j --)
		                      {
		                        int d = (ar [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + counter; j < verCoordShip + 2 + counter; j ++)
		                       {
		                           int d = (ar [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
	  break;
	case 3:
		  if ( horCoordShip == 10 || horCoordShip == 9)
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - counter; j < verCoordShip - 2 - counter; j --)
		                      {
		                        int d = (ar [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + counter; j < verCoordShip + 2 + counter; j ++)
		                       {
		                           int d = (ar [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }
		break;
	case 2:
		       if ( horCoordShip == 10 )
	                {
	                  for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
			  
		                      for ( int j = verCoordShip + 1 - counter; j < verCoordShip - 2 - counter; j --)
		                      {
		                        int d = (ar [i][j] == 127)? 1 : 0;
			                    sum += d;
		                      }
	                       if (sum > 0) return 1;
	                       else if (sum == 0) return 0;
	                 }
	             else
	                 {
	                      for ( int i = horCoordShip - 1; i < horCoordShip + 2; i ++)
		                       for ( int j = verCoordShip - 1 + counter; j < verCoordShip + 2 + counter; j ++)
		                       {
		                           int d = (ar [i][j] == 127)? 1 : 0;
			                       sum += d;
		                       }
	                        if (sum > 0) return 1;
	                        else if (sum == 0) return 0;
	                 }

		break;
	}
break;	

}
 }
 //-----------------------------------------------������� ���������� ��������---------------------------------

void shipplaceK ( char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &Ship)
{

	switch (Orient)
	{
	case 1:
	   switch ( Ship )
	   {
	   case 4:
		   if ( horCoordShip == 10 || horCoordShip == 9 || horCoordShip == 8)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 4; i --)
				  ar [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 4; i ++ )
				ar [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   case 3:
		   if ( horCoordShip == 10 || horCoordShip == 9)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 3; i --)
				  ar [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 3; i ++ )
				ar [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   case 2:
		   if ( horCoordShip == 10)
		   {
		      for ( int i = horCoordShip; i > horCoordShip - 2; i --)
				  ar [i][verCoordShip] = 127;
		   }
		   else
		   {
		    for ( int i = horCoordShip; i < horCoordShip + 2; i ++ )
				ar [ i ][ verCoordShip ] = 127;
		   }
		   break;
	   }
	   break;
	case 0:
		 switch (Ship)
	   {
	   case 4:
		     if ( verCoordShip == 10 || verCoordShip == 9 || verCoordShip == 8)
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 4; i --)
					  ar [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 4; i ++)
					  ar [horCoordShip][i] = 127;
			 }
		   break;
	   case 3:
		      if ( verCoordShip == 10 || verCoordShip == 9)
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 3; i --)
					  ar [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 3; i ++)
					  ar [horCoordShip][i] = 127;
			 }
		   break;
	   case 2:
		      if ( verCoordShip == 10 )
			 {
			      for ( int i = verCoordShip; i > verCoordShip - 2; i --)
					  ar [ horCoordShip][i] = 127;
			 }
			 else 
			 {
			      for ( int i = verCoordShip; i < verCoordShip + 2; i ++)
					  ar [horCoordShip][i] = 127;
			 }
		   break;
	   }

	   break;
	}
   
}
 int amountshippK (char **ar)
 {
   int sum = 0;
    for ( int i = 1; i < 11; i ++)
		for ( int j = 1; j < 11; j ++)
		{
		    int k = (ar [i][j] == 127)? 1:0;
			sum +=k;
		}
    return sum;
 }
//---------------------------------------------������� ������ � ����������---------------------------------------
void writeK (char **ar)
{
     FILE *f;
	f = fopen ("seabattle.txt", "w");
	if (f != NULL)
	{
	 for ( int i = 0; i < 13; i ++)
		 for ( int j = 0; j < 13; j ++)
			 fputc (ar [i][j], f);
	}
	else cout << " Error. I can't open the file." <<endl;
	 fclose (f);

}
void readK (char **ar)
{
	FILE *f;
	f = fopen ("seabattle.txt", "r");
	 for ( int i = 0; i < 13; i ++)
	 {
	     
		  for ( int j = 0; j < 13; j ++)
			  ar [i][j] = fgetc (f);
	 
	 }
	fclose (f);

}
 //------------------------------------------------�������� ������������� �����--------------------------------
