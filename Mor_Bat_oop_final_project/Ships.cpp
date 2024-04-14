#include "Ships.h"
#include <iostream>
#include"Data_Info.h"
#include"Includes.h"

extern int X_;
extern int Y_;

Kater::Kater()
{
}

Kater::~Kater()
{
}

//void Kater::ShowShip()
//{
//	DataInput::gotoxy(1, 1); std::cout << 'X';
//}
//
//void Destroyer::ShowShip()
//{
//	DataInput::gotoxy(1, 1); std::cout << 'X';
//	DataInput::gotoxy(2, 1); std::cout << 'X';
//
//}

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
