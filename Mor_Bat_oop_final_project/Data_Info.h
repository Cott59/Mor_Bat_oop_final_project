#pragma once
#include<Windows.h>
#include<vector>
#include"Ships.h"


class DataInput {
public:
	static void gotoxy(int x, int y);
};

class Menu 
{
public:
	Menu();
		


private:
	bool PRK1;  // = false;// расстановка кораблей:
	bool PRK2;  // = false;// true - автоматическая, false - ручная
	bool InCoord1;  // = true; //ввод координат удара
	bool InCoord2;  // = false; //true - автоматическая, false - ручной
};

class Grafic_Menu 
{
public:
	Grafic_Menu() = delete;
	static void Show_Menu_PL1();
	static void Show_Menu_PL2();
	static void Set_Player2();

private:

};



class Player
{
public:
	Player();
	Player(int X, int Y);
	~Player();
	COORD Get_Base_Point() { return Base_Point; };

private:
	COORD Base_Point{ 0,0 };
	std::vector<Ship>Ship_Coords;

};





class Logic_Menu
{
public:
	
private:

};
