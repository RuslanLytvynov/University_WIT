#include <iostream>
#include <cstdio>
// #include <locale.h>

using namespace std;

class Tictactoe
{
    char* field;
    int size;
public:

    Tictactoe(int sies) // ñonstructor
    {     size=sies;
          // przydzielamy pamiec pod tablice z size wskaznikow do tablic
        field=new char[size*size];

    }
    //destruktor
    ~Tictactoe()
    {
        delete[] field;
    }
    // przeciazenie operatora [] wykonane w celu szybszego dzia³ania tablicy podczas wprowadzania bardzo duzego wymiaru pola
    // zasada alokacji pamieci jak przy tworzeniu zwyklej tablicy dwuwymiarowej tylko bez masy petli
    char* operator[](int row)
    {
        return field+row*size;
    }

    // Funkcja wyjscia pola
    // przekazujemy do funkcji nasze Pole objawione w main moze byc nazywane w mainie nie tylko field, w tym przypadku jest to zmienna, która jest uzywana tylko w tej funkcji
void print(Tictactoe &field) {

  // Czyszczenie ekranu
  system("cls");

  // górna granica pola
  for (int j = 0; j < size; j++) {
      cout<<"--";

  }
  cout<<"-\n";


  //wyswietlamy po kolei wszystkie rzedy i podzialy
  for (int i = 0; i < size; i++) {

    // seria znaków
    for (int j = 0; j < size; j++) {
        cout<<"|"<<field [i][j];
    }
      cout<<"|\n";


    // dzielenia
    for (int j = 0; j < size; j++) {
      cout<<"--";
    }
    cout<<"-\n";
  }
}


//jesli jeden z graczy wypelnil cala pozioma / pionowa / ukosna,Zwraca znak, którym gra

//jesli nikt inny na wypelnionej linii, zwraca spacje

// funkcja sprawdzania zwyciezcy (zasada przekazywania zmiennej jest taka sama jak w przypadku funkcji print
int check(Tictactoe &field) {
  // pierwszy znak w poziomie i pierwszy w pionie
  int g, v;
  // diagonal
  int d1, d2;

  // rozpoczyna sie petla w n przebiegow, n jest rowna wielkosci pola
  for (int i = 0; i < size; i++) {
    // kontrola pozioma
    // zapamiêtujemy znak z pocz¹tku i wiersza pola
    g = field[i][0];

    // przejdŸ przez i wiersz pola
    for (int j = 0; j < size; j++) {
      // jeœli natkniemy siê na rozbie¿noœæ z pierwszym symbolem
      // lub jeœli pierwszy znak by³ spacji, to
      if (field[i][j] != g || g == ' ') {
        // punktacja do sprawdzenia, zapisz w symbolu g ' '
        g = ' ';
        // opuszczamy petle przymusowo
        break;
      }
    }

    // jesli w g przechowywany jest znak inny niz spacja, oznacza to, ze na poczatku
    // ciag byl krzyz lub kolo i przechodzac przez caly ciag (w petli powyzej)
    // nie natknelismy sie na symbol inny niz na poczatku
    // innymi slowy, jeden z graczy wypelnil caly wiersz jednym symbolem
    //wygralem
    if (g != ' ') {
      // jesli ten warunek zostanie spelniony, po prostu zwroc znak, ktory
      // caly wiersz jest wypelniony
      return g;
    }

    // sprawdzanie w pionie
    // zapisujemy znak z poczatku i kolumny pola
    v = field[0][i];

    // przechodzimy przez i kolumne
    for (int j = 0; j < size; j++) {
      // jesli nateniamy sie na niedopasowanie z pierwszym symbolem
      // lub jesli pierwszy znak byl spacja, to
      if (field[j][i] != v || v == ' ') {
        //punktacja do sprawdzenia, zapisujemy w symbolu v ' '
        v = ' ';
        // wyprowadzamy z petli przymusowo
        break;
      }
    }

    // jesli v zawiera znak inny niz spacja, oznacza to, ze na poczatku
    // ciag byl krzyzyk lub kolko i przechodzac przez caly ciag (w petli powyzej)
    // nie natknelismy sie na symbol inny niz na poczatku
    // innymi slowy, jeden z graczy wypelnil caly wiersz jednym symbolem
    // i wygralem
    if (v != ' ') {
      // w takim przypadku zwracamy ten symbol
      // oznacza to, ze gracz z tym symbolem wygral
      return v;
    }
  }

  // zapisujemy, które znaki na poczatku glównej i bocznej przekatnej
  d1 = field[0][0];
  d2 = field[0][size - 1];
  // sprawdzanie po glownej kolumnie
  // ?##
  // #?#
  // ##?
  for (int i = 0; i < size; i++) {
    // jesli natkniemy sie na niedopasowanie
    if (field[i][i] != d1) {
      //nie sprawdzamy zapisu w symbolu d1 ' '
      d1 = ' ';
      // wymuszone wyjscie z cyklu
      break;
    }
  }

  // jesli wszystkie znaki na przekatnej sa takie same, a znak nie jest spacja, zwracamy znak
  if (d1 != ' ') {
    return d1;
  }

  // sprawdz przekatna boczna
  // ##?
  // #?#
  // ?##
  for (int i = 0; i < size; i++) {
    // jesli natkniemy sie na niedopasowanie
    if (field[i][size - 1 - i] != d2) {
      // niesprawdzamy po prostu, zapisujemy w d1 symbol ' '
      d2 = ' ';
      // wymuszone wyjscie z cyklu
      break;
    }
  }

  // jesli wszystkie znaki na przekatnej sa takie same, a znak nie jest spacja, zwracamy znak
  if (d2 != ' ') {
    return d2;
  }

  // jesli zaden z pasków nie jest wypelniony, zwracamy spacje
  return ' ';
}

// funkcja samej gry zasada przekazywania zmiennej jest taka sama jak w przypadku funkcji print
void game(Tictactoe &field)
{
        // obecny gracz
  int player = 'x';

  // wynik testu pola gry na wypelnienie pola
  char result;

  // wskaznik dzialania gry
  int running = 1;

 int i = 0,j = 0;
 bool vvod = true;
  // podczas gdy gra trwa
  while (running) {
    do {
      if(vvod == false){
        cout<<"Powtórz wpis\n";
      }
      //wyswietl pole
      field.print(field);

      // wydrukuj czyjs ruch
      if (player == 'x') {
          cout<<"Gracz x chodzi\n";
      }
      else {
          cout<<"Gracz O chodzi\n";

      }


      // Wprowadzamy wspólrzedne skoku od 1 do size
      cout<<"Wprowadz wspolrzedne skoku x y (przez spacje): ";
      cin >> i >> j;

      vvod = false;

      // jesli uzytkownik wprowadzi cos zlego, petla bedzie kontynuowana
      // i pyta ponownie
      // gdy gracz wprowadzi wspólrzedne poprawnie, petla zatrzyma sie
    } while (i > size || j > size || i < 0 || j < 0 || field[i - 1][j - 1] != ' ');

     vvod = true;
    // przekreslamy komórke pola
    field[i - 1][j - 1] = player;

    // sprawdz pole
    result = field.check(field);

    // jesli result nie jest spacja, to ktos wygral
    if (result != ' ') {
      // wyswietlamy symbol zwyciezcy przechowywany w result
      cout<<result<<" Wygral(WIN)!";

      // zatrzymaj gre
      running = 0;
    }

    // przekazujemy ruch innemu graczowi
    if (player == 'x') {
      player = 'o';
    }
    else {
      player = 'x';
    }
  }

}

};

int main()
{

  int size;
  // wprowadz rozmiar pola
   cout<<"Wprowadz rozmiar pola: ";
   cin >> size;

  // utorz pole (nazwa pola, rozmiar pola)
  Tictactoe field(size);

  // wypelniamy kazda komórke pola spacja
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++)
          field[i][j] = ' ';
    }

    // uruchom gre
    field.game(field);



  return 0;
}
