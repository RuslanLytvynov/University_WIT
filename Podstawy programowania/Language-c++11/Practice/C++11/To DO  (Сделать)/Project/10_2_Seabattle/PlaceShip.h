#ifndef Place_Ship
#define Place_Ship
//-----------------------------------структура для ручной расстановки----------------------------------

struct ship_user
{
     bool d;                        //расположение вертикально (0) или горизонтально (1)
     char x;                         //горизонтальная координата х или строки
     int y;                         //вертикальная координата у или колонки

};

//---------------------------прототипы функций------------------------------------------------

//-------------------------функция пользовательской ручной и автоматической расстановки кораблей---------------------------

void aruserpole (char **ar_user);                                  // поле пользователя
int chooseship ();                                                 // функция выбора кораблей
int chooseorient ( int &k);                                               // функция выбора ориентации корабля
int HorCoord (int &k);                                                   // функция горизонтальной координаты
int VerCoord (int &k);                                                   // функция вертикальной координаты
int test (char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &count, int &sh);    // функция проверки существования палуб
void shipplace ( char **ar_user, int &horCoordShip, int &verCoordShip, int &Orient, int &sh);          // функция для расстановки кораблей
int amountshipp (char **ar_user);                                   // функция подсчета палуб
void writeuser (char **ar_user);                                    // функция записи пользовательского поля
void readuser (char **ar_user);                                     // функция считывания пользовательского поля
int testone (int &horCoordShip, int &verCoordShip, char **ar_user); // функция тестирования для однопалубника
void placeone (int &horCoordShip, int &verCoordShip, char **ar_user); //функция расстановки однопалубника
int onehorCoord ();                                                   //горизонтальная координата для однопалубника
int oneverCoord ();                                                   //вертикальная координата для однопалубника
void upload ();                                                       //функция загрузки

//-------------------------функции пользовательской ручной и автоматической расстановки кораблей -----------------------


//-------------------------функции автоматической расстановки для компьютера-------------------------
void arpole (char **ar);                                           // поле компьютера
int orientKomp ();                  //функция ориентации корабля компьютера
int HorCoordK ();                   //функция горизонтальной координаты
int VerCoordK ();                   //функция вертикальной координаты
int testK (char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &counter, int &Ship); //функция проверки существования палуб
void shipplaceK ( char **ar, int &horCoordShip, int &verCoordShip, int &Orient, int &Ship);        //функция для расстановки кораблей
int amountshippK (char **ar);                //функция подсчета палуб
void writeK (char **ar);                     //функция записи для компьютера
void readK (char **ar);                      //функция считывания для компьютера
int testoneK (int &horCoordShip, int &verCoordShip, char **ar);   // функция тестирования существования палуб для однопалубника
void placeoneK (int &horCoordShip, int &verCoordShip, char **ar); //функция расстановки однопалубника
int onehorCoordK ();
int oneverCoordK ();


//-----------------------прототипы функций--------------------------------------
#endif