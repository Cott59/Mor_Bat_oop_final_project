#include <iostream>
#include"Data_Info.h"
#include"Ship_Placement.h"
#include<conio.h>
#include"Includes.h"

extern int X_;
extern int Y_;



Grafic_Ship_Placement::Grafic_Ship_Placement(Player& player)
{
	//Base_Point.X = player.Base_Point.X; 
	//Base_Point.Y = player.Base_Point.Y;
	name_player = player.Get_Name();

}

void Grafic_Ship_Placement::Border_1() {
	system("cls");
	DataInput::gotoxy(this->Base_Point.X + 1, this->Base_Point.Y);
	for (int i = 1; i < 11; i++)
		std::cout << ' ' << i;
}

void Grafic_Ship_Placement::Border_2()
{
	for (int j = 1; j < 11; j++) {
		DataInput::gotoxy(Base_Point.X, Base_Point.Y + j);
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

void Grafic_Ship_Placement::Plean() {
	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {
			COORD temp = { (SHORT)x,(SHORT)y };
			DataInput::gotoxy(Base_Point.X + 1, Base_Point.Y + y);
			for (int i = 1; i < 11; i++)
				std::cout << " .";
		}
	}
}

void Grafic_Ship_Placement::Hedder_Pl()
{
	DataInput::gotoxy(Base_Point.X - 4, Base_Point.Y - 4); std::cout << " --------------------------- ";
	DataInput::gotoxy(Base_Point.X - 4, Base_Point.Y - 3);  std::cout << " |         "<< name_player<<"        | ";
	DataInput::gotoxy(Base_Point.X - 4, Base_Point.Y - 2);  std::cout << " --------------------------- ";
	_getch();
}

Show_Ship::Show_Ship(Ship* ship)
{
	//ship->ShowShip();
}

Ship_Placement_Logic::Ship_Placement_Logic(Player* player)
{
	player_tmp = player;
}



void Ship_Placement_Logic::Set_Ships_Placement()
{
	Grafic_Ship_Placement GrShipPlac(*(player_tmp));
	GrShipPlac.Border_1();
	GrShipPlac.Border_2();
	//GrShipPlac.Plean();
	GrShipPlac.Hedder_Pl();
	bool Check_Plain[11][11] = { false };
	
	for (int i = 1; i <= 4; i++) {
		DataInput::CheckPoint(X_, Y_, Check_Plain[][11]);
	}


}

////bool battleships::CreatePosition()
////{
////	int x = 0, y = 0;
////	CheckPoint(x, y);
////	//gotoxy(x, y);
////	while (1) {
////
////		P1.X = x;
////		P1.Y = y;
////		if (Position == true) {
////			P2.X = x + 1, P3.X = x + 2, P4.X = x + 3;
////			P2.Y = P3.Y = P4.Y = y;
////		}
////		else {
////			P2.Y = y + 1, P3.Y = y + 2, P4.Y = y + 3;
////			P2.X = P3.X = P4.X = x;
////		}
////
////		Ship();
////		//system("cls");
////		if (_kbhit()) {
////			char ch = _getch();
////			if (ch == 80)
////				y++;
////			else
////				if (ch == 72)
////					y--;
////				else
////					if (ch == 75)
////						x--;
////					else
////						if (ch == 77)
////							x++;
////						else
////							if (ch == 8)
////								Position = 1;
////							else
////								if (ch == 28)
////									exit(1);
////
////		}
////
////		Sleep(50);
////		system("cls");
////
////	}
////
////
////
////
////
////	return 1;
////}
