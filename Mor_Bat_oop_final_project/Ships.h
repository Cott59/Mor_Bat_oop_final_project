#pragma once
#include "Data_Info.h"
#include<Windows.h>
#include<vector>

// элемент корабля у игрока
struct point_ship {
	int X;
	int Y;
	bool Crash = false;
	bool operator==(point_ship Lobj);
};

class Ship {
public:
	Ship(int);
	std::vector<COORD> vc;
	void SetData();
	bool PosRotation = true;
	bool Bad = false;
};

class ShipPlayer //корабли у игрока
{
private:
	std::vector<point_ship> shippl;
public:
	ShipPlayer(){}
	ShipPlayer(int);
	~ShipPlayer();
	void Set_Point(point_ship& p_ship);
	point_ship Get_Point_shippl(int num); 
	size_t Get_Size_vector() { return shippl.capacity();}
};



