#pragma once
#include<Windows.h>
#include<vector>
#include"Ships.h"
#include<string>




class DataInput {
public:
	static void gotoxy(int x, int y);
};

class Menu 
{
public:
	Menu();
	void Set_Data_Players();
};

class Grafic_Menu 
{
public:
	Grafic_Menu() = delete;
	static void Show_Menu_PL1();
	static void Show_Menu_PL2();
	static void Set_Player2();
};

class Player
{
public:
	Player(bool parc, bool attac, std::string name);
	~Player();
	COORD Base_Point{ 0,0 };
	void Set_Base_Point(int, int);
	COORD Get_Base_Point() { return Base_Point; };
	std::string Get_Name() { return Name; }
private:
	
	std::vector<Ship>Ship_Player;
	bool Parc;
	bool Attac;
	std::string Name;
};



class Create_Players
{
public:
	Create_Players();
	Player* Get_PL1() { return PL1; }
	Player* Get_PL2() { return PL2; }
	void Create_Player();
private:
	int n = 2;
	Player* PL1=nullptr;
	Player* PL2=nullptr;
};

