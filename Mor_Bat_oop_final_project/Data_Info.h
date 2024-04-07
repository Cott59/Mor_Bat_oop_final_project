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
	void Set_Parc_Pl1(int a)  { Parc_Pl1 = a; }
	void Set_Parc_Pl2(int a)  { Parc_Pl2 = a; }
	void Set_Attac_Pl1(int a) { Attac_Pl1 = a;}
	void Set_Attac_Pl2(int a) { Attac_Pl2 = a;}
	bool Get_Parc_Pl1() { return Parc_Pl1; }
	bool Get_Parc_Pl2() { return Parc_Pl2; }
	bool Get_Attac_Pl1(){ return Attac_Pl1;}
	bool Get_Attac_Pl2(){ return Attac_Pl2;}


private:
	int Parc_Pl1;  // = false;// расстановка кораблей:
	int Parc_Pl2;  // = false;// true 1 - автоматическая, false 0 - ручная
	int Attac_Pl1;  // = true; //ввод координат для атаки
	int Attac_Pl2;  // = false; //true - автоматическая, false - ручной
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
	Player(bool parc, bool attac);
	~Player();
	COORD Get_Base_Point() { return Base_Point; };
	void Set_Base_Point(int, int);

private:
	COORD Base_Point{ 0,0 };
	std::vector<Ship>Ship_Player;
	bool Parc;
	bool Attac;

};

class Logic_Menu
{
public:
	Logic_Menu();

	static void Set_Data_Players();


private:

};
