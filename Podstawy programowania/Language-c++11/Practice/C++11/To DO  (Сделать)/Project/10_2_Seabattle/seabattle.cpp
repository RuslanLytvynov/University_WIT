#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include "PlaceShip.h"
#include "Battle.h"
using namespace std;

int main()
{   
	int m = 0;
	int ship, horCoordShip, verCoordShip, Orient;

char **pole = new char *[10];
	for (int i = 0; i < 10; i ++)
		pole [i] = new char [10];
	    ppolef (pole);
	    
//--------- �������� ���� ��� ���������� � ��������� �������� ----------------
   char **ar=new char*[13];
   for(int i=0;i<13;i++)
	 ar[i]=new char[13];

     for(int i=0;i<13;i++)
	{
		for(int j=0;j<13;j++)
	   {
	      ar[i][j]=-2;
	   }
   }
//-------------------������ ����������������� �������� ����----------------------
	 char **ar_user=new char *[13];
	 for(int i=0;i<13;i++)
		 ar_user[i]=new char[13];

	for( int i = 0; i < 13; i ++)
		 for( int j = 0; j < 13; j ++)
		 {
		   ar_user [i][j] = -2;
		 }
	 cout<<endl;
//------------------ �������� ���� ��� ���������� � ������������---------------
//------------------�������� ����������� ���� ��� �� ����� ����--------------
   int k;
   int t;
      

	   char *str=new char[101];
	   char *st=new char[101];
setlocale(LC_ALL,"Russian");
    cout<<"��� ����������� ������� ���� �������� 1\n";
	cout<<"��� ������ ����� ���� �������� 2\n";
setlocale(LC_ALL,".OCP");
	cin>>t;
	switch(t)
	{
	case 1:

		readuser (ar_user);
        aruserpole (ar_user);
	
//---------------------��������� ����� ����������� ����--------------------	

		break;
case 2:
setlocale(LC_ALL,"Russian");
    cout<<"�������� ������� ����������� ��������: �������������� ��� ������\n";
	cout<<"���� ��������������, �������� - 1 \n";
	cout<<"���� ������ �����������, �������� - 0 \n";
setlocale(LC_ALL,".OCP");
    cin>>k;
//------------------------------------------------����������� �������� �������������---------------------------------	
//------------------------------------------------��������������---------------------------------------
	
setlocale(LC_ALL,"Russian");
upload ();		
setlocale(LC_ALL,".OCP");
	switch(k)
	{
	case 1:
		
		// ������������ ����������������
        do 
		{
		 int testp = 0;
		 int count = 0;
		 int ship = 4;
		 Orient = chooseorient (k);
		 horCoordShip = HorCoord (k);
		 verCoordShip = VerCoord (k);
		 do
		 {
		    testp +=test (ar_user,horCoordShip,verCoordShip,Orient,count,ship);
			count ++;
		 } while (count < 4);
		 if (testp == 0)
		  {
			shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
		  }
		 else if ( testp > 0) continue;
		 
		 int sum = amountshipp(ar_user);
		
		  if ( sum == 4) break;
		} while (1);
		
		  do 
		{
		 int testp = 0;
		 int count = 0;
		 int ship = 3;
		 Orient = chooseorient (k);
		 horCoordShip = HorCoord (k);
		 verCoordShip = VerCoord (k);
		 do
		 {
		    testp +=test (ar_user,horCoordShip,verCoordShip,Orient,count,ship);
			count ++;
		 } while (count < 3);
		 if (testp == 0)
		  {
			shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
		  }
		 else if (testp > 0) continue;
		 
		int sum = amountshipp(ar_user);
		  if ( sum == 10) break;
		} while (1);

        do 
		{
		 int testp = 0;
		 int count = 0;
		 int ship = 2;
		 Orient = chooseorient (k);
		 horCoordShip = HorCoord (k);
		 verCoordShip = VerCoord (k);
		 do
		 {
		    testp +=test (ar_user,horCoordShip,verCoordShip,Orient,count,ship);
			count ++;
		 } while (count < 2);
		 if (testp == 0)
		  {
			shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
		  }
		 else if (testp > 0) continue;
		 
          int sum = amountshipp(ar_user);
		  if ( sum == 16) break;
		} while (1);

		  do 
		{
		 int testp = 0;
		 horCoordShip = onehorCoord ();
		 verCoordShip = oneverCoord ();
		 
		 testp +=testone (horCoordShip,verCoordShip, ar_user);
			
		 if (testp == 0)
		  {
			 placeone (horCoordShip, verCoordShip,ar_user);
		  }
		 else if ( testp > 0) continue;
		 
		  int sum = amountshipp(ar_user);
		  if ( sum == 18) break;
		} while (1);

		writeuser (ar_user);
		readuser (ar_user);
	    aruserpole (ar_user);
		break;
//-------------------------------------------------------------��������������----------------------------------
//---------------------------------------------����������� �������-------------------------------------------
	case 0:                                     
setlocale(LC_ALL,"Russian");   
		cout << " ����� ���� ����. ���������� ����������� ����������� ��������" << endl;
		   
setlocale(LC_ALL,".OCP");
        aruserpole(ar_user);
		
		do
		{
		  do
		  {
			ship = chooseship ();                    // ����� ������� ��� �����������
		    if (ship == 0) cout << " Error. Try again." <<endl;
			else break;
		  } while (1);
		  switch (ship)
		  {
		  case 4:
			  do
			  {
			   int count = 0;
			   int testp = 0;
			   Orient = chooseorient ( k);                                      // ���������� ���������� �������
			   verCoordShip = VerCoord ( k);                                    // ������������ ����������
			   horCoordShip = HorCoord ( k);                                    //�������������� ����������
			   
			  do
			  {
			     
				  testp += test (ar_user,horCoordShip,verCoordShip,Orient, count, ship);  //�������� ������������� �����
                  count ++;
			  
			  } while (count < 4);
			  if ( testp > 0) continue;
			  else if (testp == 0) break;
			 
			  } while (1);
			   shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
			   writeuser (ar_user);
			   readuser (ar_user);
			   system ("cls");
			   aruserpole ( ar_user);
			   

			  break;
		  case 3:
			 do
			  {
			   int count = 0;
			   int testp = 0;
			   Orient = chooseorient ( k);                    // ���������� ���������� �������
			   verCoordShip = VerCoord ( k);                                    // ������������ ����������
			   horCoordShip = HorCoord ( k);                        //�������������� ����������
			   
               do
			  {

				  testp += test (ar_user,horCoordShip,verCoordShip,Orient, count, ship);  //�������� ������������� �����
                  count ++;
			  } while (count < 3);
			  if ( testp > 0) continue;
			  else if (testp == 0) break;
			 
			  } while (1);
			   shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
			   writeuser (ar_user);
			   readuser (ar_user);
			   system ("cls");
			   aruserpole ( ar_user);
			   
			   break;
		  case 2:
			   do
			  {
			   int count = 0;
			   int testp = 0;
			   Orient = chooseorient ( k);                    // ���������� ���������� �������
			   verCoordShip = VerCoord ( k);                                    // ������������ ����������
			   horCoordShip = HorCoord ( k);                        //�������������� ����������
			   
               do
			  {
			      testp += test (ar_user,horCoordShip,verCoordShip,Orient, count, ship);  //�������� ������������� �����
                  count ++;
			  } while (count < 2);
			  if ( testp > 0) continue;
			  else if (testp == 0) break;
			 
			  } while (1);
			   shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
			   writeuser (ar_user);
			   readuser (ar_user);
			   system ("cls");
			   aruserpole ( ar_user);

			  break;
		  case 1:
			   
			   do
			  {
			   int count = 0;
			   int testp = 0;
			   verCoordShip = VerCoord ( k);                                            // ������������ ����������
			   horCoordShip = HorCoord ( k);                                           //�������������� ����������
			   
               

			   testp += test (ar_user,horCoordShip,verCoordShip,Orient, count, ship);  //�������� ������������� �����
               if ( testp > 0) continue;
			  else if (testp == 0) break;
			 
			  } while (1);
			   shipplace (ar_user, horCoordShip,verCoordShip, Orient, ship);
			   writeuser (ar_user);
			   readuser (ar_user);
			   system ("cls");
			   aruserpole ( ar_user);
			   
			  break;
		  }
		  
		  int summa = amountshipp (ar_user);
		  if ( summa == 18) break;
		  m ++;
		} while (1);
		cout << " You've done it! " <<endl;
		
		break;
	  }

 //------------------------------------------����������� �������------------------------------------------------- 
//-----------------����������� �������� �������������----------------------------------------------------------------- 
//-----------------�������������� ����������� �������� ����������-----------
setlocale(LC_ALL,"Russian");
upload ();		
setlocale(LC_ALL,".OCP");    
        do 
		{
		 int testp = 0;
		 int counter = 0;
		 int Ship = 4;
		 Orient = orientKomp ();
		 horCoordShip = HorCoordK ();
		 verCoordShip = VerCoordK ();
		 do
		 {
		    testp +=testK (ar,horCoordShip,verCoordShip,Orient,counter,Ship);
			counter ++;
		 } while (counter < 4);
		 if (testp == 0)
		  {
			shipplaceK (ar, horCoordShip,verCoordShip, Orient, Ship);
		  }
		 else if ( testp > 0) continue;
		 
		 int sum = amountshippK(ar);
		
		  if ( sum == 4) break;
		} while (1);
		
		 do 
		{
		 int testp = 0;
		 int counter = 0;
		 int Ship = 3;
		 Orient = orientKomp ();
		 horCoordShip = HorCoordK ();
		 verCoordShip = VerCoordK ();
		 do
		 {
		    testp +=testK (ar,horCoordShip,verCoordShip,Orient,counter,Ship);
			counter ++;
		 } while (counter < 3);
		 if (testp == 0)
		  {
			shipplaceK (ar, horCoordShip,verCoordShip, Orient, Ship);
		  }
		 else if ( testp > 0) continue;
		 
		 int sum = amountshippK(ar);
		
		  if ( sum == 10) break;
		} while (1);

		 do 
		{
		 int testp = 0;
		 int counter = 0;
		 int Ship = 2;
		 Orient = orientKomp ();
		 horCoordShip = HorCoordK ();
		 verCoordShip = VerCoordK ();
		 do
		 {
		    testp +=testK (ar,horCoordShip,verCoordShip,Orient,counter,Ship);
			counter ++;
		 } while (counter < 2);
		 if (testp == 0)
		  {
			shipplaceK (ar, horCoordShip,verCoordShip, Orient, Ship);
		  }
		 else if ( testp > 0) continue;
		 
		 int sum = amountshippK(ar);
		
		  if ( sum == 16) break;
		} while (1);

		 do 
		{
		 int testp = 0;
		 horCoordShip = onehorCoordK ();
		 verCoordShip = oneverCoordK ();
		 
		    testp +=testoneK (horCoordShip,verCoordShip,ar);
		
		 if (testp == 0)
		  {
			placeoneK (horCoordShip,verCoordShip,ar);
		  }
		 else if ( testp > 0) continue;
		 
		 int sum = amountshippK(ar);
		
		  if ( sum == 18) break;
		} while (1);

	   writeK (ar);
	   readK (ar);
	   fppolef (pole);
       /*arpole (ar);*/
     break;
	}	


  
	 
	 
	 cout<<endl;
//-----------------�������������� ����������� �������� ����������----------- 
//-----------------��������� ����� ����� ����-------------------------
//----------------����� ����� ���� ��� �� �����������-------------

//---------------------------------------����������� ���------------------------------

//----------------- ���������� ������� ��� ������������ ���� -------------------------
	 char horCoord = 0;
	 int horCoor = 0;
	 int verCoord = 0;
	 int userHit = 0;
	 
	                                                     //���������� ���� � ��������� ����

//---------------------------���� ������������-------------------------------------------	
do
{   readuser (ar_user);
	sppolef(pole);

	while (1)                                                         //��� ������������
	{ 
		                                                //��������� ���� ����
setlocale(LC_ALL,"Russian");
		horCoord = hod_userhk();
	    verCoord = hod_uservk();
	    cout << endl;
	    userHit = userhit (horCoord,verCoord, ar,pole);                        //��������� ��� �� ���������
setlocale(LC_ALL,".OCP");
       if (userHit == 0) 
	   {
           sppolef(pole);
		   cout << endl;
		   pole [(int)horCoord - 65][verCoord - 1] = '*';
		   fppolef (pole);
		   system ("cls");
setlocale(LC_ALL,"Russian");
		   cout << " ����! ���������� � ��������� ���! " << endl;
setlocale(LC_ALL,".OCP");
		  break;
          
       }
	   else if (userHit == 1)
	   {

           sppolef(pole);
		   cout << endl;
		   pole [(int)horCoord - 65][verCoord - 1] = 'x';
		   fppolef (pole);
		   system ("cls");
setlocale(LC_ALL,"Russian");
	       cout << " �� ������! ������ ��� ���. " << endl;

setlocale(LC_ALL,".OCP");
		   continue;
	   }
	   else if (userHit == -1)
	   {
setlocale(LC_ALL,"Russian");
	       cout << " ���� ��� ��������. ���������� ��� ���! " << endl;
		   
setlocale(LC_ALL,".OCP");
        continue;
	   }
	}
     sppolef(pole);
	 int amountShip = amountship(pole);                                           //�������� ���������� �������� �����
setlocale(LC_ALL,"Russian");
	 switch (amountShip)
	 {
	 case 1:
		 cout << " ��... �, �������, ��������. ����������, �� - ����������!" <<endl;
		 break;
	 case 0:
		 cout << " ���������� ����. ��� �� �����������. " <<endl;
		 break;
	 }
setlocale(LC_ALL,".OCP");

// ---------------------------------���� ���������� ---------------------------------------
    do 
	{
	   

		horCoor = hod_komphk();
	    verCoord = hod_kompvk();
	    cout << endl;
	    userHit = komphit (horCoor,verCoord, ar_user);                        //��������� ��� �� ���������

       if (userHit == 0) 
	   {
           readuser (ar_user);
		   cout << endl;
		   ar_user [horCoor - 1][verCoord - 1] = '*';
		   writeuser (ar_user);
		   system ("cls");
setlocale(LC_ALL,"Russian");
		   cout << " ����! �������� � ��������� ���! " << endl;
setlocale(LC_ALL,".OCP");
		  break;
          
       }
	   else if (userHit == 1)
	   {

           readuser (ar_user);
		   cout << endl;
		   ar_user [horCoor - 1][verCoord - 1] = 'x';
		   writeuser (ar_user);
		   system ("cls");
setlocale(LC_ALL,"Russian");
	       cout << " ���!!! �����! ����� ��� ���. " << endl;

setlocale(LC_ALL,".OCP");
		   continue;
	   }
	   else if (userHit == -1)
	   {
		   
setlocale(LC_ALL,"Russian");
	       cout << "��... ���� ��� �������! ���� �� ����������, �������� ��� ���! " << endl;
		   system ("cls");
		   cout << " �������. � ���������. " << endl;
		   
setlocale(LC_ALL,".OCP");
        continue;
	   }
	
	} while (1);
	readuser (ar_user);
	aruserpole (ar_user);
	int amountShipus = amountSh(ar_user);
setlocale(LC_ALL,"Russian");
	 switch (amountShipus)
	 {
	 case 1:
		 cout << " �� ���������. ��� ����� ����." <<endl;
		 break;
	 case 0:
		 cout << " ���������� ����. ���� ���, ������������. " <<endl;
		 break;
	 }
setlocale(LC_ALL,".OCP");
   if (amountShipus == 1 || amountShip == 1) 
   {
      cout << " Game over! " <<endl;
	  break;
   }
} while (1);
//-----------------����������� ���-------------------------------
	delete []str;
	delete []st;

	

	for(int i=0;i<13;i++)
		delete[]ar_user[i];
	delete[]ar_user;

		 for(int i=0;i<13;i++)
		delete []ar[i];
	delete []ar;
    
  return 0;
}