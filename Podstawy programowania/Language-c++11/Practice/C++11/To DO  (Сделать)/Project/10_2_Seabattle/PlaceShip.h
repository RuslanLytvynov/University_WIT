#ifndef Place_Ship
#define Place_Ship
//-----------------------------------��������� ��� ������ �����������----------------------------------

struct ship_user
{
     bool d;                        //������������ ����������� (0) ��� ������������� (1)
     char x;                         //�������������� ���������� � ��� ������
     int y;                         //������������ ���������� � ��� �������

};

//---------------------------��������� �������------------------------------------------------

//-------------------------������� ���������������� ������ � �������������� ����������� ��������---------------------------

void aruserpole (char **ar_user);                                  // ���� ������������
int chooseship ();                                                 // ������� ������ ��������
int chooseorient ( int &k);                                               // ������� ������ ���������� �������
int HorCoord (int &k);                                                   // ������� �������������� ����������
int VerCoord (int &k);                                                   // ������� ������������ ����������
int test (char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &count, int &sh);    // ������� �������� ������������� �����
void shipplace ( char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &sh);          // ������� ��� ����������� ��������
int amountshipp (char **ar_user);                                   // ������� �������� �����
void writeuser (char **ar_user);                                    // ������� ������ ����������������� ����
void readuser (char **ar_user);                                     // ������� ���������� ����������������� ����
int testone (int &horCoordShip, int &verCoordShip, char **ar_user); // ������� ������������ ��� �������������
void placeone (int &horCoordShip, int &verCoordShip, char **ar_user); //������� ����������� �������������
int onehorCoord ();                                                   //�������������� ���������� ��� �������������
int oneverCoord ();                                                   //������������ ���������� ��� �������������
void upload ();                                                       //������� ��������

//-------------------------������� ���������������� ������ � �������������� ����������� �������� -----------------------


//-------------------------������� �������������� ����������� ��� ����������-------------------------
void arpole (char **ar);                                           // ���� ����������
int orientKomp ();                  //������� ���������� ������� ����������
int HorCoordK ();                   //������� �������������� ����������
int VerCoordK ();                   //������� ������������ ����������
int testK (char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &counter, int &Ship); //������� �������� ������������� �����
void shipplaceK ( char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &Ship);        //������� ��� ����������� ��������
int amountshippK (char **ar);                //������� �������� �����
void writeK (char **ar);                     //������� ������ ��� ����������
void readK (char **ar);                      //������� ���������� ��� ����������
int testoneK (int &horCoordShip, int &verCoordShip, char **ar);   // ������� ������������ ������������� ����� ��� �������������
void placeoneK (int &horCoordShip, int &verCoordShip, char **ar); //������� ����������� �������������
int onehorCoordK ();
int oneverCoordK ();


//-----------------------��������� �������--------------------------------------
#endif