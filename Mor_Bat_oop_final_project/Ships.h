#pragma once
#include<Windows.h>
#include<vector>


struct point_ship {
	int X;
	int Y;
	bool Crash = false;
};

class Ship {
public:
	Ship(int);
	std::vector<COORD> vc;
	void SetData();
	bool PosRotation = true;
	bool Bad = false;
};

class ShipPlayer //однопалубный
{
private:
	std::vector<point_ship> shippl;
public:
	ShipPlayer(int);
	~ShipPlayer();
	void Set_Point(point_ship& p_ship);
	
};



