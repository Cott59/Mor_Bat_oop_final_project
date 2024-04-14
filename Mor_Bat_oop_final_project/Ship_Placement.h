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
	/*GrShow_Point(COORD P1) {
		Show_Point.push_back(P1);
	}
	GrShow_Point(COORD P1, COORD P2) :GrShow_Point(P1) {
		Show_Point.push_back(P2);
	};
	GrShow_Point(COORD P1, COORD P2, COORD P3) :GrShow_Point(P1, P2) {
		Show_Point.push_back(P3);
	};
	GrShow_Point(COORD P1, COORD P2, COORD P3, COORD P4) :GrShow_Point(P1,P2,P3) {
		Show_Point.push_back(P4);
	};*/
	static void GrShowPoint(Ship&ship,COORD BPoint={ 39,9 });
	static void GrCleanPoint(Ship& ship, COORD BPoint = { 39,9 });
	//~GrShow_Point() {};

private:
	//std::vector<COORD> Show_Point;
	//COORD Base_Point = { 39,9 };
};



class Ship_Placement_Logic
{
public:
	Ship_Placement_Logic(Player* player);
	void Set_Ships_Placement();

private:
	Player* player_tmp;
};