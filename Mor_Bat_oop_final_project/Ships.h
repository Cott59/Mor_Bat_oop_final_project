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
};

class Kater  //������������
{
private:
public:
	Kater();
	~Kater();
	std::vector<point_ship> Points;
	//void ShowShip() override;
};

class Destroyer    //������������
{
private:
public:
	Destroyer();
	std::vector<point_ship> Points;
	//void ShowShip()override;
};

//class Cruiser :public Ship  //�����������
//{
//private:
//	bool Position = false;
//	std::vector<point_ship> Points;
//	//COORD P1, P2, P3;
//public:
//	//Cruiser(int X1, int Y1);
//};
//
//class Battleships :public Ship	//��������������
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