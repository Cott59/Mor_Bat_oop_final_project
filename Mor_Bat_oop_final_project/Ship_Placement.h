#pragma once
#include"Data_Info.h"
#include"Ships.h"

class Grafic_Ship_Placement
{
public:
	Grafic_Ship_Placement(int,int);
	COORD Base_Point = { 0,0 };
	void Border_1();
	void Border_2();
	void Plean();
	void Hedder_Pl1();
	void Hedder_Pl2();

private:


};