#include "Gameplay.h"
#include <iostream>
#include"Data_Info.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30

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


//Grafic_Gameplay::Grafic_Gameplay()
//{
//}

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
	//DataInput::gotoxy(15, 3); std::cout << "PLAYER 1";
	//DataInput::gotoxy(49, 3); std::cout << "PLAYER 2";

}



void Grafic_Gameplay::ShowBorderPlayer(int point_1, int point_2)
{
	int* p1 = &point_1;
	int* p2 = &point_2;
	Border_1(p1, p2);
	Border_2(p1, p2);
	Plean(p1, p2);
}

void Grafic_Gameplay::ShowHedderPlayer1(int point_1, int point_2)
{
	DataInput::gotoxy(point_1, point_2); std::cout << "PLAYER 1";
	//15, 3
}

void Grafic_Gameplay::ShowHedderPlayer2(int point_1, int point_2)
{
	DataInput::gotoxy(point_1, point_2); std::cout << "PLAYER 2";
	//49, 3
}





