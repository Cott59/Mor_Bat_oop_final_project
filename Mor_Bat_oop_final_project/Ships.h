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

class Kater //однопалубный
{
private:
	std::vector<point_ship> Points;
public:
	Kater();
	~Kater();
	void Get_Point(point_ship& p_ship);
	
};

class Destroyer    //двухпалубный
{
private:
	std::vector<point_ship> Points;
public:
	Destroyer();
	
	
};

//class Cruiser :public Ship  //трёхпалубный
//{
//private:
//	bool Position = false;
//	std::vector<point_ship> Points;
//	//COORD P1, P2, P3;
//public:
//	//Cruiser(int X1, int Y1);
//};
//
//class Battleships :public Ship	//четырёхпалубный
//{
//private:
//	bool Position = false;
//	std::vector<point_ship> Points;
//	//COORD P1, P2, P3, P4;
//public:
//	//Battleships(int X1, int Y1);
//
//
//};

//bool Position = false;