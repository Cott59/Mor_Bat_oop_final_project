#include<conio.h>
#include <iostream>
#include<Windows.h>
#include"Data_Info.h"
#include"Gameplay.h"
#include"Ship_Placement.h"
#include"Includes.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition = {};

bool PARC_PL1_ = false;// расстановка кораблей:
bool PARC_PL2_ = false;// true 1 - автоматическая, false 0 - ручная
bool ATTAC_PL1_ = true; //ввод координат для атаки
bool ATTAC_PL2_ = false; //true - автоматическая, false - ручной

int X_;
int Y_;


int main()
{
	setlocale(LC_ALL, "Russian");
	COORD maxWindow = { SCREEN_WIDTH,SCREEN_HEIGHT };//  размер самого большого возможного консольного окна
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0,0, 0 };
	SetConsoleWindowInfo(console, true, &minWindow);
	SetConsoleScreenBufferSize(console, maxWindow);
	SetConsoleWindowInfo(console, true, &srctWindow);
    //===========================================================================
	
	/*Menu menu;
	menu.Set_Data_Players();*/

	Create_Players cp;
	cp.Create_Player();

	Grafic_Ship_Placement GrShipPlas(*(cp.Get_PL1()));
	GrShipPlas.Border_1();
	GrShipPlas.Border_2();
	GrShipPlas.Plean();
	GrShipPlas.Hedder_Pl();
	

	

	/*int a = 15;
	int b = 49;
	
	Grafic_Gameplay::ShowBorder();
	Grafic_Gameplay::ShowBorderPlayer(8, 7);
	Grafic_Gameplay::ShowBorderPlayer(42, 7);
	Grafic_Gameplay::ShowHedderPlayer1(a, 3);
	Grafic_Gameplay::ShowHedderPlayer2(b, 3);
	_getch();
	std::swap(a, b);
	Grafic_Gameplay::ShowHedderPlayer1(a, 3);
	Grafic_Gameplay::ShowHedderPlayer2(b, 3);*/
	

	_getch();
    return 0;
}








