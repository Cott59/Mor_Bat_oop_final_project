#include <iostream>
#include "Ships.h"
#include "Gameplay.h"
#include "Data_Info.h"
#include "Includes.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <ctime>

extern int X_;
extern int Y_;
extern HANDLE console;
extern COORD CursorPosition;
//extern bool PARC_PL1_;// расстановка кораблей:
//extern bool PARC_PL2_;// true 1 - автоматическа€, false 0 - ручна€
//extern bool ATTAC_PL1_; //ввод координат дл€ атаки
extern bool ATTAC_PL2_; //true - автоматическа€, false - ручной

void Grafic_Gameplay::GrShowOpenPoints(point_ship& shipPoint, COORD BPoint)
{
	if (shipPoint.Crash == false) {
		DataInput::gotoxy(BPoint.X + (shipPoint.X * 2), BPoint.Y + shipPoint.Y); 
		std::cout << "X";
	}
	else {
		SetConsoleTextAttribute(console, 12); 
		DataInput::gotoxy(BPoint.X + (shipPoint.X * 2), BPoint.Y + shipPoint.Y);
		std::cout << "X";
		SetConsoleTextAttribute(console, 15); 
	}
}

void Grafic_Gameplay::GrShowClosedPoints(point_ship& shipPoint, COORD BPoint)
{
	if (shipPoint.Crash == true) {
		SetConsoleTextAttribute(console, 12);
		DataInput::gotoxy(BPoint.X + (shipPoint.X * 2), BPoint.Y + shipPoint.Y);
		std::cout << "X";
		SetConsoleTextAttribute(console, 15);
	}

}

void Border_1(int* point_1, int* point_2) {
	
	DataInput::gotoxy(*point_1 + 1, *point_2);
	for (int i = 1; i < 11; i++)
		std::cout << ' ' << i;

}

void Border_2(int* point_1, int* point_2)
{
	for (int j = 1; j < 11; j++) {
		DataInput::gotoxy(*point_1, *point_2 + j);
		switch (j) {
		case 1: std::cout << 'A'; break;
		case 2: std::cout << 'B'; break;
		case 3: std::cout << 'C'; break;
		case 4: std::cout << 'D'; break;
		case 5: std::cout << 'E'; break;
		case 6: std::cout << 'F'; break;
		case 7: std::cout << 'G'; break;
		case 8: std::cout << 'H'; break;
		case 9: std::cout << 'I'; break;
		case 10: std::cout << 'J'; break;
		}
	}
}

void Plean(int* point_1, int* point_2) {
	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {
			COORD temp = { (SHORT)x,(SHORT)y };
			DataInput::gotoxy(*point_1 + 1, *point_2 + y);
			for (int i = 1; i < 11; i++)
				std::cout << " .";
		}
	}
}

void Grafic_Gameplay::ShowBorder()
{
	system("cls");
	for (int i = 0; i < SCREEN_HEIGHT - 10; i++) {
		for (int j = 0; j < 5; j++) {

			DataInput::gotoxy(0 + j, i); std::cout << "#";
			DataInput::gotoxy(34 + j, i); std::cout << "#";
			DataInput::gotoxy(68 + j, i); std::cout << "#";

		}
	}

	for (int i = 0; i < SCREEN_HEIGHT - 10; i++) {
		for (int j = SCREEN_WIDTH - 1; j > SCREEN_WIDTH - 6; j--) {
			DataInput::gotoxy(0 + j, i); std::cout << "#";
		}
	}

	for (int j = 0; j < SCREEN_WIDTH - 1; j++) {
		DataInput::gotoxy(j, 0); std::cout << "#";
	}
	for (int j = 0; j < SCREEN_WIDTH - 1; j++) {
		DataInput::gotoxy(j, 1); std::cout << "#";
	}
	for (int j = 0; j < SCREEN_WIDTH - 1; j++) {
		DataInput::gotoxy(j, 5); std::cout << "#";
	}
	for (int j = 0; j < SCREEN_WIDTH - 1; j++) {
		DataInput::gotoxy(j, 19); std::cout << "#";
	}
	

}

void Grafic_Gameplay::ShowBorderPlayer(int point_1, int point_2)
{
	int* p1 = &point_1;
	int* p2 = &point_2;
	Border_1(p1, p2);
	Border_2(p1, p2);
	//Plean(p1, p2);
}

Logic_Gameplay::Logic_Gameplay(Player*pl1, Player*pl2)
{
	PL1 = pl1;
	PL2 = pl2;
	Log_attac_pl1.reserve(100);
	Log_attac_pl2.reserve(100);
}

void OpenShowShip(Player* player)
{
	auto BasePt = player->Get_Base_Point();
	DataInput::gotoxy(15, 3); std::cout << player->Get_Name();
	std::for_each(player->ShipPl.begin(), player->ShipPl.end(), [&BasePt](ShipPlayer *shp) { 
		auto size_vec = (*shp).Get_Size_vector(); 
		for (int i = 0; i < size_vec; i++) { 
			point_ship temp = (*shp).Get_Point_shippl(i); 
			Grafic_Gameplay::GrShowOpenPoints(temp, BasePt); 
			
		}
	});
}

void ClosedShowShip(Player* player)
{
	auto BasePt = player->Get_Base_Point();
	DataInput::gotoxy(49, 3); std::cout << player->Get_Name();
	std::for_each(player->ShipPl.begin(), player->ShipPl.end(), [&BasePt](ShipPlayer* shp) { 
		auto size_vec = (*shp).Get_Size_vector();
		for (int i = 0; i < size_vec; i++) {
			point_ship temp = (*shp).Get_Point_shippl(i);
			Grafic_Gameplay::GrShowClosedPoints(temp, BasePt);
		}
		});
}

void AutoAttac()
{
	srand(time(NULL));
	X_ = std::rand() % 10 + 1;
	Y_ = std::rand() % 10 + 1;
}

bool Set_X_Coord(std::string ch) {
	int num = atoi(ch.c_str());
	switch (num)
	{
	case 1: X_ = 1; return true; break;
	case 2: X_ = 2; return true; break;
	case 3: X_ = 3; return true; break;
	case 4: X_ = 4; return true; break;
	case 5: X_ = 5; return true; break;
	case 6: X_ = 6; return true; break;
	case 7: X_ = 7; return true; break;
	case 8: X_ = 8; return true; break;
	case 9: X_ = 9; return true; break;
	case 10: X_ = 10; return true; break;
	default:return false;
		break;
	}
}
bool Set_Y_Coord(std::string ch) {
	char ch1 = ch[0];
	switch (ch1)
	{
	case 'A':case 'a': Y_ = 1; return true; break;
	case 'B':case 'b': Y_ = 2; return true; break;
	case 'C':case 'c': Y_ = 3; return true; break;
	case 'D':case 'd': Y_ = 4; return true; break;
	case 'E':case 'e': Y_ = 5; return true; break;
	case 'F':case 'f': Y_ = 6; return true; break;
	case 'G':case 'g': Y_ = 7; return true; break;
	case 'H':case 'h': Y_ = 8; return true; break;
	case 'I':case 'i': Y_ = 9; return true; break;
	case 'J':case 'j': Y_ = 10; return true; break;
	default:return false;
		break;
	}
}

bool foo() {
	std::string buf1;
	std::string buf2;
	try
	{
		DataInput::gotoxy(5, 22); std::cout << "¬ведите координату удара ";
		DataInput::gotoxy(30, 22); std::cout << " X:";
		std::cin >> buf1;
		if (buf1.length() > 2)
			throw 1;
		else {
			std::cin.clear();
			DataInput::gotoxy(35, 22); std::cout << " Y:";
			std::cin >> buf2;
			if (buf2.length() > 1)
				throw 1;
			std::cin.clear();
		}
	}
	catch (...)
	{
		DataInput::gotoxy(5, 22); std::cout << "                                                     ";
		DataInput::gotoxy(30, 25); std::cout << "Error";
		DataInput::gotoxy(30, 25); std::cout << "        ";
		DataInput::gotoxy(5, 22); std::cout << "                                                     ";
		foo();

	}
	bool check_X = Set_X_Coord(buf1);
	bool check_Y = Set_Y_Coord(buf2);
	if (check_X == true && check_Y == true)
		return true;
	else
		foo();
}

void PlayerAttac(Player* player)
{
	DataInput::gotoxy(3, 21); std::cout << player->Get_Name();
	bool check_foo = foo();
	if(check_foo ==true)
		DataInput::gotoxy(50, 22); std::cout << "-OK";
	
	


}

void SwapBP(Player* player1, Player* player2) {
	int tmp = player1->Base_Point.X;
	player1->Base_Point.X = player2->Base_Point.X;
	player2->Base_Point.X = tmp;
}

void ShowPlane(Player* player)
{
	if (player->Base_Point.X == 8)
		OpenShowShip(player);
	else
		ClosedShowShip(player);
}

void Attac(Player* player)
{
	if (player->Get_Attac() == 0) //ручной ввод
		PlayerAttac(player);
	else                      // автоматический ввод
		AutoAttac();
}

void Logic_Gameplay:: SetDataLog(Player* player) {
	point_ship tmp;
	tmp.X = X_;
	tmp.Y = Y_;
	if (player->Get_Name() == "Player 1")
		Log_attac_pl1.push_back(tmp);
	else
		Log_attac_pl2.push_back(tmp);
}

void SetCoordAtac(Player* player)
{
	

}

void Logic_Gameplay::Play_Game()
{
	Grafic_Gameplay::ShowBorder();
	Grafic_Gameplay::ShowBorderPlayer(8, 7);
	Grafic_Gameplay::ShowBorderPlayer(42, 7);
	//=====================================================
	PL1->Base_Point.X = 8; PL1->Base_Point.Y = 7;
	PL2->Base_Point.X = 42; PL2->Base_Point.Y = 7;
	bool GameOver = true;
	while (GameOver == true)
	{
		ShowPlane(PL1);
		ShowPlane(PL2);
		if (PL1->Base_Point.X == 8)
			Attac(PL1);
		else
			Attac(PL2);
		if(ATTAC_PL2_==true)
			Attac(PL2);
		
			


		SwapBP(PL1, PL2);

	}
}


