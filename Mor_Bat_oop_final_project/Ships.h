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
	COORD Temp = { 0,0 };
};

class Kater :public Ship //однопалубный
{
private:
	std::vector<point_ship> Points;
	bool Position = false;
protected:
	
public:
	Kater(int X, int Y);
	~Kater();
	
};

class Destroyer :public Ship   //двухпалубный
{
private:
	bool Position = false;
	std::vector<point_ship> Points;
	//COORD P1{ 0,0 }, P2{ 0,0 };
public:
	Destroyer(int X, int Y){

	}
	
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

