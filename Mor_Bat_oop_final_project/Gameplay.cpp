#include <iostream>
#include "Ships.h"
#include "Gameplay.h"
#include "Data_Info.h"
#include "Includes.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
extern int X_;
extern int Y_;
extern HANDLE console;
extern COORD CursorPosition;

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
}

void PlayerAttac(Player* player)
{
	int Ch1, Ch2;
	DataInput::gotoxy(3, 21); std::cout << player->Get_Name();
	DataInput::gotoxy(5 , 22); std::cout << "¬ведите координату удара: ";
	std::cin >> Ch1 >> Ch2;

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
		/*if (PL1->Base_Point.X == 42)// атака со второго пол€ не ведетс€, если только не комп
			Attac(PL1); //переписать
		else
			Attac(PL2);*/


		//SwapBP(PL1, PL2);

	}
}