#include <iostream>
#include"Data_Info.h"
#include"Ship_Placement.h"
#include"Ships.h"
#include<conio.h>
#include"Includes.h"
#include<Windows.h>
#include<algorithm>
#include<dos.h> 

extern int X_;
extern int Y_;
extern bool PARC_PL1_;// расстановка кораблей:
extern bool PARC_PL2_;// true 1 - автоматическая, false 0 - ручная
extern bool ATTAC_PL1_; //ввод координат для атаки
extern bool ATTAC_PL2_; //true - автоматическая, false - ручной


void GrShow_Point::GrShowPoint(Ship& ship, COORD BPoint)
{
	for (auto& i : ship.vc) {
		DataInput::gotoxy(BPoint.X +(i.X*2), BPoint.Y + i.Y);
		std::cout << "X";
	}
}

void GrShow_Point::GrCleanPoint(Ship& ship, COORD BPoint)
{
	for (auto& i : ship.vc) {
		DataInput::gotoxy(BPoint.X + (i.X*2), BPoint.Y + i.Y);
		std::cout << " ";
	}

}

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
}

int CheckPoint(COORD& coordata, int arr[][12]) {
	int* pp1 = &arr[coordata.X - 1][coordata.Y - 1];
	int* pp2 = &arr[coordata.X-1][coordata.Y];
	int* pp3 = &arr[coordata.X - 1][coordata.Y + 1];
	for (int i = 1; i <= 3; i++) {
		if (*pp1 == 1) return 1;
		if (*pp2 == 1) return 1;
		if (*pp3 == 1) return 1;
		pp1++; pp2++; pp3++;
	}
	
	return 0;
}

int CheckPointToPlain(Ship& ship, int arr[][12]) {
	int check = 1;
	std::for_each(ship.vc.begin(), ship.vc.end(), [&arr,&check](COORD& coorduse) {
		check=CheckPoint(coorduse, arr); 
		if (check == 1) return 1;
		}); 
	return 0;
}

bool CheckOnePoint(Ship& ship, int arr[][12]) {
	if (arr[(ship.vc).begin()->X][(ship.vc).begin()->Y] == 1) return true;
	else return false;
}

void SetPoint(Ship& ship, int arr[][12]) {
	std::for_each(ship.vc.begin(), ship.vc.end(), [&arr](COORD& coorduse) {
		arr[coorduse.X][coorduse.Y] = 1;
		});
}

void PlayerCreatePoint() {
	std::cin >> X_;
	std::cin >> Y_;
}

void AutoCreatePoint() {
	srand(time(NULL));
	X_ = std::rand() % 10 + 1;
	Y_ = std::rand() % 10 + 1;
}

void CreateNewPoint(bool parc) {
	if (parc == 0)
		PlayerCreatePoint();
	else
		AutoCreatePoint();

}

Ship_Placement_Logic::Ship_Placement_Logic(Player* player)
{
	player_tmp = player;
}

bool InstalShip(Ship& ship, int num = 0) {
	int x = (ship.vc).begin()->X + num;
	int y = (ship.vc).begin()->Y;
	for (auto& i : ship.vc) {
		i.X = x;
		i.Y = y;
		x++;
	}
	if (x > 10) {
		return true;
	}
	else return false;
}

void Change_Max_X(Ship& ship) {
	ship.vc.begin()->X += 1;
	std::vector<COORD>::iterator p2 = ship.vc.begin();
	p2++;
	for ( auto p1 = ship.vc.begin(); p1 != ship.vc.end();p1++) {
			if (ship.PosRotation == true) {
				if (p1->X == 10) 
					p2->X=1;
				else 
					p2->X = p1->X + 1;
			}
			else {
				if (p1->X == 11) {
					p1->X = 1;
					p2->X = 1;
				}
				else
					p2->X = p1->X;
			}
			p2++;
	}
	
}
//std::for_each(ship.vc.begin(), ship.vc.end(), [&](COORD& coordnum1) { });

void Change_Min_X(Ship& ship, int num = 0) {
	int x = (ship.vc).begin()->X - num;
	int y = (ship.vc).begin()->Y;
	for (auto& i : ship.vc) {
		i.X = x;
		i.Y = y;
		x--;
	}
	
}
void Change_Max_Y(Ship& ship, int num = 0) {
	int x = (ship.vc).begin()->X ;
	int y = (ship.vc).begin()->Y + num;
	for (auto& i : ship.vc) {
		i.X = x;
		i.Y = y;
		y++;
	}
	
}
void Change_Min_Y(Ship& ship, int num = 0) {
	int x = (ship.vc).begin()->X;
	int y = (ship.vc).begin()->Y - num;
	for (auto& i : ship.vc) {
		i.X = x;
		i.Y = y;
		y--;
	}
	
}


bool Input_Button(Ship& ship) {
	std::cin.clear();
	char ch = _getch();
	switch (ch) {
	case 's':GrShow_Point::GrCleanPoint(ship); Change_Max_Y(ship, 1);  return false; break;
	case 'w':GrShow_Point::GrCleanPoint(ship); Change_Min_Y(ship, 1);  return false; break;
	case 'a':GrShow_Point::GrCleanPoint(ship); Change_Min_X(ship, 1);  return false; break;
	case 'd':GrShow_Point::GrCleanPoint(ship); Change_Max_X(ship);  return false; break;
	//case VK_TAB:  return false; break;
	//case VK_RETURN:return true; break;
	default:return true;
		break;

	}
}

void Ship_Placement_Logic::Set_Ships_Placement()
{
	Grafic_Ship_Placement GrShipPlac(*(player_tmp));
	GrShipPlac.Border_1();
	GrShipPlac.Border_2();
	GrShipPlac.Plean();
	GrShipPlac.Hedder_Pl();
	int Check_Plain[12][12] = { 0 };
	for (int i = 1; i <= 4; i++) {
		CreateNewPoint(1); 
		Ship shipTmp(2);
		bool CheckBorder=true;
		do {
			shipTmp.SetData();
			CheckBorder = InstalShip(shipTmp);
			if(CheckBorder==1)
				AutoCreatePoint();
		} while (CheckBorder==true);
		bool Position = true;
		bool tmp = true;
		do {
			if (CheckOnePoint(shipTmp, Check_Plain) == 0) {
				bool tmp1 = CheckPointToPlain(shipTmp, Check_Plain);
				if (tmp1 == 1) {
					std::cout << "error" << '\n';
				}
				else
					if (tmp1 == 0) {
						GrShow_Point::GrShowPoint(shipTmp);
					}
			}
			tmp =Input_Button(shipTmp);
			if (tmp == 1)
				SetPoint(shipTmp, Check_Plain);
		} while (tmp == false);

	}


}

////bool battleships::CreatePosition()
////{
////	int x = 0, y = 0;
////	CheckPoint(x, y);
////	
////	while (1) {
////

	/*	P1.X = x;
		P1.Y = y;
		if (Position == true) {
			P2.X = x + 1, P3.X = x + 2, P4.X = x + 3;
			P2.Y = P3.Y = P4.Y = y;
		}
		else {
			P2.Y = y + 1, P3.Y = y + 2, P4.Y = y + 3;
			P2.X = P3.X = P4.X = x;
		}*/

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
// 
////
////
////
////	return 1;
// //char ch = _getch();
	//if (_kbhit()) {
	//	
	//	if (ch == 80) {
	//		Change_Max_Y(ship, 1); GrShow_Point::GrCleanPoint(ship); return true;
	//	}
	//	else
	//		if (ch == 72) {
	//			Change_Min_Y(ship, 1); GrShow_Point::GrCleanPoint(ship); return true;
	//		}
	//		else
	//			if (ch == 75) {
	//				Change_Min_X(ship, 1); GrShow_Point::GrCleanPoint(ship); return true;
	//			}
	//			else
	//				if (ch == 77) {
	//					Change_Max_X(ship, 1); GrShow_Point::GrCleanPoint(ship); return true;
	//				}
	//				else
	//					if (ch == 8) {
	//					}
	//					else
	//						if (ch == 13 /*28*/)
	//							return false;
	//	
	//}
// 
////}



