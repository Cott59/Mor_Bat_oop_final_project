#pragma once
#include"Data_Info.h"
#include"Ships.h"
#include<string>
#include<Windows.h>

class Grafic_Ship_Placement
{
public:

	Grafic_Ship_Placement(Player& player);
	COORD Base_Point = { 39,9 };
	void Border_1();
	void Border_2();
	void Plean();
	void Hedder_Pl();
	
private:
	std::string name_player;

};

class GrShow_Point
{
public:
	static void GrShowPoint(Ship&ship,COORD BPoint={ 39,9 });
	static void GrCleanPoint(Ship& ship, COORD BPoint = { 39,9 });
	


	
};



class Ship_Placement_Logic
{
public:
	Ship_Placement_Logic(Player* player);
	void Set_Ships_Placement();

private:
	Player* player_tmp;
};