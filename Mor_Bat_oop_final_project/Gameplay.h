#pragma once
#include <vector>
#include "Ships.h"
#include "Data_Info.h"

class Grafic_Gameplay
{
public:
	
	static void ShowBorder();
	static void ShowBorderPlayer(int point_1, int point_2);
	static void GrShowOpenPoints(point_ship& shipPoint, COORD BPoint);
	static void GrShowClosedPoints(point_ship& shipPoint, COORD BPoint);
};

class Logic_Gameplay
{
public:
	Logic_Gameplay(Player* pl1, Player* pl2);
	void Play_Game();

private:
	Player* PL1=nullptr;
	Player* PL2 = nullptr;
	std::vector<point_ship> Log_attac_pl1;
	std::vector<point_ship> Log_attac_pl2;
	
};