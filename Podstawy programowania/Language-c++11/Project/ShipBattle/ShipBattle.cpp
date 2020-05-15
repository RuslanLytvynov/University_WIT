#include <iostream>
#include <string>
using namespace std;

const int Board_Width = 15;
const int Board_Height = 10;
const int Ship_Types = 5;  //Cruiser Frigate Submarine Escort Battleship

const char Sea_Point = 250; //ASCII Character Code for game board
const char Hit_Ship = 'X';  //Symbol for Hitting a Ship
const char Ship_Symb = 'S'; // Ship symbol
const char Miss_Symb = '0'; //Miss symbol

struct Point {
	//A location on the grid defined
	//by X(horizontal) Y(vertical) coordinates
	int X;
	int Y;
};

struct Ship {
	string name;  //Ship name

	int length;	//Total points on the grid

	//Coordinates of those points
	Point onGrid[5]; //0-4 max length of biggest Ship

	//Whether or not those points are a "hit"
	bool hitFlag[5];
}ship[Ship_Types];

struct Player {
	char grid[Board_Width][Board_Height];
}player[3]; //Ignore player 0, just using player's 1 & 2

enum Direction {Horizontal,Vertical};
struct PlaceShip {
	Direction direction;
	Ship shipType;
};

bool gameRunning = false;

//Functions
void LoadShips();
void ResetBoard();
void DrawBoard(int);
PlaceShip UserInputShipPlacement();
bool UserInputAttack(int&,int&,int);
bool GameOverCheck(int);

int main()
{
	LoadShips();
	ResetBoard();

	//"PLACE SHIPS" phase of game
	//Loop through each player
	for (int aplyr = 1; aplyr < 3; ++aplyr)
	{
		//Loop through each ship type to place
		for (int Type_This_Ship =0 ; Type_This_Ship < Ship_Types; ++Type_This_Ship)
		{
			//Display gameboard for player
			system("cls");
			DrawBoard(aplyr);
			//Give instructions
			cout << "\n";
			cout << "INSTRUCTIONS (Player " << aplyr << ")\n\n";
			cout << "You are about to place your ships.  Format should be:\n";
			cout << "Facing (0:Horizontal, 1:Vertical), X (top-row) coords, Y (left-side) coords\n";
			cout << "Example: 0 7 2    This would place a ship beginning at X:7 Y:2 going horizontal\n\n";
			cout << "Ship to place: " << ship[Type_This_Ship].name << " which has a length of " << ship[Type_This_Ship].length  << "\n";
			cout << "Where do you want it placed? ";

			//Get input from user and loop until good data is returned
			PlaceShip pShip;
			pShip.shipType.onGrid[0].X = -1;
			while (pShip.shipType.onGrid[0].X == -1)
			{
				pShip = UserInputShipPlacement();
			}

			//Combine user data with "this ship" data
			pShip.shipType.length = ship[Type_This_Ship].length;
			pShip.shipType.name = ship[Type_This_Ship].name;

			//Add the FIRST grid point to the current player's game board
			player[aplyr].grid[pShip.shipType.onGrid[0].X][pShip.shipType.onGrid[0].Y] = Ship_Symb;

			//Determine ALL grid points based on length and direction
			for (int i=1; i<pShip.shipType.length; ++i)
			{
				if (pShip.direction == Horizontal){
					pShip.shipType.onGrid[i].X = pShip.shipType.onGrid[i-1].X+1;
					pShip.shipType.onGrid[i].Y = pShip.shipType.onGrid[i-1].Y; }
				if (pShip.direction == Vertical){
					pShip.shipType.onGrid[i].Y = pShip.shipType.onGrid[i-1].Y+1;
					pShip.shipType.onGrid[i].X = pShip.shipType.onGrid[i-1].X; }

				//Add the REMAINING grid points to our current players game board
				player[aplyr].grid[pShip.shipType.onGrid[i].X][pShip.shipType.onGrid[i].Y] = Ship_Symb;
			}
			//Loop back through each ship type
		}
		//Loop back through each player
	}

	//********* FINISHED WITH "PLACE SHIPS" PHASE *********************************

	//Ready to play the game
	gameRunning = true;
	int thisPlayer = 1;
	do {
		//Because we are ATTACKING now, the
		//opposite players board is the display board
		int enemyPlayer;
		if (thisPlayer == 1) enemyPlayer = 2;
		if (thisPlayer == 2) enemyPlayer = 1;
		system("cls");
		DrawBoard(enemyPlayer);

		//Get attack coords from this player
		bool goodInput = false;
		int x,y;
		while (goodInput == false) {
			goodInput = UserInputAttack(x,y,thisPlayer);
		}

		//Check board; if a ship is there, set as HIT.. otherwise MISS
		if (player[enemyPlayer].grid[x][y] == Ship_Symb) player[enemyPlayer].grid[x][y] = Hit_Ship;
		if (player[enemyPlayer].grid[x][y] == Sea_Point) player[enemyPlayer].grid[x][y] = Miss_Symb;

		//Check to see if the game is over
		//If 0 is returned, nobody has won yet
		int aWin = GameOverCheck(enemyPlayer);
		if (aWin != 0) {
			gameRunning = false;
			break;
		}
		//Alternate between each player as we loop back around
		thisPlayer = (thisPlayer == 1) ? 2 : 1;
	} while (gameRunning);

	system("cls");
	cout << "\n\nCONGRATULATIONS!!!  Player " << thisPlayer << " HAS WON THE GAME!\n\n\n\n";

	system("pause");
	return 0;
}


bool GameOverCheck(int EnemyPlayer)
{
	bool winner = true;
	//Loop through enemy board
	for (int w = 0; w < Board_Width; ++w){
			for (int h=0; h<Board_Height; ++h){
				//If any ships remain, game is NOT over
				if (player[EnemyPlayer].grid[w][h] = Ship_Symb)
					{
						winner = false;
						return winner;
					}
		}}
	//If we get here, somebody won, game over!
	return winner;
}


bool UserInputAttack(int& x, int& y, int theplayer)
{
	cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
	bool goodInput = false;
	cin >> x >> y;
	if (x<0 || x>=Board_Width) return goodInput;
	if (y<0 || y>=Board_Height) return goodInput;
	goodInput = true;
	return goodInput;
}

PlaceShip UserInputShipPlacement()
{
	int d, x, y;
	PlaceShip tmp;  //time object
	//Using this as a bad return
	tmp.shipType.onGrid[0].X = -1;
	//Get 3 integers from user
	cin >> d >> x >> y;
	if (d!=0 && d!=1) return tmp;
	if (x<0 || x>=Board_Width) return tmp;
	if (y<0 || y>=Board_Height) return tmp;
	//Good data
	tmp.direction = (Direction)d;
	tmp.shipType.onGrid[0].X = x;
	tmp.shipType.onGrid[0].Y = y;
	return tmp;
}

void LoadShips()
{
	//Sets the default data for the ships
	//we plan to include in the game
	//IMPORTANT!! > MUST MATCH Ship_Types -Default=5 (0-4)
	ship[0].name = "Cruiser"; ship[0].length = 2;
	ship[1].name = "Frigate"; ship[1].length = 3;
	ship[2].name = "Submarine"; ship[2].length = 3;
	ship[3].name = "Escort"; ship[3].length = 4;
	ship[4].name = "Battleship"; ship[4].length = 5;
}
void ResetBoard()
{
	//Loop through each player
	for (int plyr=1; plyr<3; ++plyr)
	{
		//For each grid point, set contents to 'water'
		for (int w=0; w<Board_Width; ++w){
			for (int h=0; h<Board_Height; ++h){
				player[plyr].grid[w][h] = Sea_Point;
		}}
		//Loop back to next player
	}}
void DrawBoard(int thisPlayer)
{
	//Draws the board for a player (thisPlayer)
	cout << "Player " << thisPlayer << "'s GAME BOARD\n";
	cout << "----------------------\n";
	//Loop through top row (Board_Width) and number columns
	cout << "   ";
	for (int w=0; w<Board_Width; ++w) {
		if (w < 10)
			//Numbers only 1 character long, add two spaces after
			cout << w << "  ";
		else if (w >= 10)
			//Numbers 2 characters long, add only 1 space after
			cout << w << " ";}
	cout << "\n";
	//Loop through each grid point and display to console
	for (int h=0; h<Board_Height; ++h){
		for (int w=0; w<Board_Width; ++w){

			//If this is the FIRST (left) grid point, number the grid first
			if (w==0) cout << h << " ";
			//If h was 1 character long, add an extra space to keep numbers lined up
			if (w<10 && w==0) cout << " ";
			//Display contents of this grid (if game isn't running yet, we are placing ships
			//so display the ships
			if (gameRunning == false) cout << player[thisPlayer].grid[w][h] << "  ";
			//Don't show ships, BUT show damage if it's hit
			if (gameRunning == true && player[thisPlayer].grid[w][h] != Ship_Symb)
			{cout << player[thisPlayer].grid[w][h] << "  ";}
			else if (gameRunning == true && player[thisPlayer].grid[w][h] == Ship_Symb)
			{cout << Sea_Point << "  ";}
			//If we have reached the border.. line feed
			if (w == Board_Width-1) cout << "\n";
		}}}
