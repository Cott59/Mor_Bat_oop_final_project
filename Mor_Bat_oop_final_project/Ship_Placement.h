#pragma once
#include"Data_Info.h"
#include"Ships.h"
#include<string>

class Grafic_Ship_Placement
{
public:
	Grafic_Ship_Placement(Player& player);
	COORD Base_Point = { 39,9 };
	void Border_1();
	void Border_2();
	void Plean();
	void Hedder_Pl();
	void Show_Borders();

	/*void Hedder_Pl2();*/
	//void ShowShipKater();
private:
	std::string name_player;

};

//void Kater::ShowShip()
//{
//	gotoxy(P1.X, P1.Y); std::cout << 'X';
//}

