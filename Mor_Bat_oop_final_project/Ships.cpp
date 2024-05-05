#include "Ships.h"
#include <iostream>
#include"Data_Info.h"
#include"Includes.h"

extern int X_;
extern int Y_;



ShipPlayer::ShipPlayer(int num)
{
	shippl.reserve(num);
}

ShipPlayer::~ShipPlayer()
{
}

void ShipPlayer::Set_Point(point_ship& p_ship)
{
	shippl.push_back(p_ship);
}

Ship::Ship(int num)
{
	COORD zero = { 0,0 };
	for (int i = 1; i <= num; i++)
		vc.push_back(zero);
}

void Ship::SetData()
{
	vc.begin()->X = X_;
	vc.begin()->Y = Y_;
}
