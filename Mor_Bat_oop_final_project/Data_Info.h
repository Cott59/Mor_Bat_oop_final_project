#pragma once
#include<Windows.h>
#include<vector>
#include"Ships.h"
#include<string>
#include<memory>

class DataInput {
public:
	static void gotoxy(int x, int y ); 
	
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
	COORD Get_Base_Point() { return Base_Point; };
	std::string Get_Name() { return Name; }
	bool Get_Parc() { return Parc; }
	bool Get_Attac() { return Attac; }
	void Set_Base_Point(int, int);
	//void Instal_Uptr_to_vector(std::unique_ptr<ShipPlayer>);
	void Instal_to_vector(ShipPlayer*);

private:
	
	//std::vector<std::unique_ptr<ShipPlayer>>ShipPl;
	std::vector<ShipPlayer*>ShipPl;
	bool Parc;
	bool Attac;
	std::string Name;
};


class Create_Players
{
public:
	Create_Players() {};
	Player* Get_PL1() { return PL1; }
	Player* Get_PL2() { return PL2; }
	void CreatePlayer();
private:
	
	Player* PL1=nullptr;
	Player* PL2=nullptr;
};

