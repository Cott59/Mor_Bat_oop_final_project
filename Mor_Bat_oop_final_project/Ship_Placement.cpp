#include <iostream>
#include"Data_Info.h"
#include"Ship_Placement.h"
#include"Ships.h"
#include<conio.h>
#include"Includes.h"
#include<Windows.h>
#include<algorithm>
#include<dos.h> 
#include<memory>

extern HANDLE console;
extern COORD CursorPosition;


extern int X_;
extern int Y_;
extern bool PARC_PL1_;// расстановка кораблей:
extern bool PARC_PL2_;// true 1 - автоматическая, false 0 - ручная
extern bool ATTAC_PL1_; //ввод координат для атаки
extern bool ATTAC_PL2_; //true - автоматическая, false - ручной

int Check_Plain[12][12] = { 0 };
void Clean_Check_Plain() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			Check_Plain[i][j] = 0;

}

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
	if(arr[coordata.X - 1][coordata.Y - 1] == 1 )
		return 1;
	if (arr[coordata.X - 1][coordata.Y] == 1)
		return 1;
	if (arr[coordata.X - 1][coordata.Y + 1] == 1)
		return 1;
	if (arr[coordata.X][coordata.Y - 1] == 1)
		return 1;
	if (arr[coordata.X][coordata.Y] == 1)
		return 1;
	if (arr[coordata.X][coordata.Y + 1] == 1)
		return 1;
	if (arr[coordata.X + 1][coordata.Y - 1] == 1)
		return 1;
	if (arr[coordata.X + 1][coordata.Y] == 1)
		return 1;
	if (arr[coordata.X + 1][coordata.Y + 1] == 1)
		return 1;
	return 0; 
}

int CheckPointToPlain(Ship& ship, int arr[][12]) {
	int check = 0;
	std::for_each(ship.vc.begin(), ship.vc.end(), [&](COORD& coorduse) {
		if (CheckPoint(coorduse, arr) == 1) {
			check = 1;
			ship.Bad = true;
			//return check;
		}
		}); 
	if (check == 0)
		ship.Bad = false;
	return check;
}

bool CheckOnePoint(Ship& ship, int arr[][12]) {
	bool check=false;
	std::for_each(ship.vc.begin(), ship.vc.end(), [&](COORD& coorduse){
		if (arr[coorduse.X][coorduse.Y] == 1)
			check = true; 
		});
	return check;
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
	if (ship.vc.rbegin()->X == 10)
		return;
	if(ship.vc.begin()->X<10)
		ship.vc.begin()->X += 1;
	if (ship.vc.capacity() == 1)
		return;
	std::vector<COORD>::iterator p2 = ship.vc.begin();
	p2++;
	for ( auto p1 = ship.vc.begin(); p2 != ship.vc.end();p1++) {
			if (ship.PosRotation == true) {
				p2->X = p1->X + 1;
			}
			else {// if PosRotation == false
				p2->X = p1->X;
			}
			p2++;
	}
}

void Change_Min_X(Ship& ship) {
	if (ship.vc.begin()->X == 1)
		return;
	if (ship.vc.begin()->X > 1)
		ship.vc.begin()->X -= 1;
	if (ship.vc.capacity() == 1)
		return;
	std::vector<COORD>::iterator p2 = ship.vc.begin();
	p2++;
	for (auto p1 = ship.vc.begin(); p2 != ship.vc.end(); p1++) {
		if (ship.PosRotation == true) {
			p2->X = p1->X + 1;
		}
		else {// if PosRotation == false
			p2->X = p1->X;
		}
		p2++;
	}
}

void Change_Max_Y(Ship& ship) {
	if (ship.vc.rbegin()->Y == 10)
		return;
	if (ship.vc.begin()->Y < 10) 
		ship.vc.begin()->Y += 1; 
	if (ship.vc.capacity() == 1) 
		return; 
	std::vector<COORD>::iterator p2 = ship.vc.begin(); 
	p2++; 
	for (auto p1 = ship.vc.begin(); p2 != ship.vc.end(); p1++) {
		if (ship.PosRotation == true) {
			p2->Y = p1->Y;
		}
		else {// if PosRotation == false
			p2->Y = p1->Y+1;
		}
		p2++; 
	}
}

void Change_Min_Y(Ship& ship) {
	if (ship.vc.begin()->Y == 1)
		return;
	if (ship.vc.begin()->Y > 1)
		ship.vc.begin()->Y -= 1;
	if (ship.vc.capacity() == 1)
		return;
	std::vector<COORD>::iterator p2 = ship.vc.begin(); 
	p2++; 
	for (auto p1 = ship.vc.begin(); p2 != ship.vc.end(); p1++) { 
		if (ship.PosRotation == true) { 
			p2->Y = p1->Y; 
		}
		else {// if PosRotation == false
			p2->Y = p1->Y+1;
		}
		p2++; 
	}
}

void Change_PosRotation(Ship& ship) {
	if (ship.vc.begin()->X > 10 - ship.vc.capacity() + 1 || ship.vc.begin()->Y > 10 - ship.vc.capacity() + 1)
		return;
	if (ship.PosRotation == true)
		ship.PosRotation = false;
	else
		ship.PosRotation = true;
}

void Change_Rotation(Ship& ship) {
	if (ship.vc.capacity() == 1)
		return;
	Ship shiptmp = ship;
	Change_PosRotation(shiptmp);
	std::vector<COORD>::iterator p2 = shiptmp.vc.begin(); 
	p2++; 
	if (shiptmp.PosRotation == false){
		for (auto p1 = shiptmp.vc.begin(); p2 != shiptmp.vc.end(); p1++) {
			p2->X = p1->X;
			p2->Y = p1->Y + 1;
			p2++; 
		}
		if (shiptmp.vc.rbegin()->Y > 10 || CheckOnePoint(shiptmp, Check_Plain) == true)
			return;
		else
			ship = shiptmp;
	}
	else {
		for (auto p1 = shiptmp.vc.begin(); p2 != shiptmp.vc.end(); p1++) {
			p2->X = p1->X + 1;
			p2->Y = p1->Y;
			p2++;
		}
		if (shiptmp.vc.rbegin()->X > 10|| CheckOnePoint(shiptmp, Check_Plain)==true)
			return;
		else
			ship = shiptmp; 
	}
		

}


bool Input_Button(Ship& ship) {
	std::cin.clear();
	char ch = _getch();
	if (ch == '\r' && ship.Bad == false)
		return true;
	else {
		if(CheckOnePoint(ship, Check_Plain) != true)
			GrShow_Point::GrCleanPoint(ship);
		switch (ch) {
		case 's': Change_Max_Y(ship);  return false; break;
		case 'w': Change_Min_Y(ship);  return false; break;
		case 'a': Change_Min_X(ship);  return false; break;
		case 'd': Change_Max_X(ship);  return false; break;
		case'\t': Change_Rotation(ship); return false; break;

		default:return false;
			break;

		}
	}
}



std::unique_ptr<ShipPlayer> Create_Player_Ship(Ship& ship) {

	auto U_Kt = std::unique_ptr<ShipPlayer> (new ShipPlayer(ship.vc.capacity()));

	std::for_each(ship.vc.begin(), ship.vc.end(), [&](COORD& coordUse) {
		point_ship temp;
		temp.X = coordUse.X;
		temp.Y = coordUse.Y;
		U_Kt->Set_Point(temp);

		}); 
	return U_Kt; 
}

ShipPlayer* Create_Player_Ship2(Ship& ship) {

	ShipPlayer* RR = new ShipPlayer(ship.vc.capacity());
	std::for_each(ship.vc.begin(), ship.vc.end(), [&](COORD& coordUse) { 
		point_ship temp; 
		temp.X = coordUse.X; 
		temp.Y = coordUse.Y; 
		RR->Set_Point(temp); 

	});
	return RR;
}



void Ship_Placement_Logic::Set_Ships_Placement()
{
	Clean_Check_Plain();
	Grafic_Ship_Placement GrShipPlac(*(player_tmp)); 
	GrShipPlac.Border_1();
	GrShipPlac.Border_2();
	GrShipPlac.Plean();
	GrShipPlac.Hedder_Pl();
	int countersShip = 1;//количество кораблей
	int j = 4;//количество палуб
	while (countersShip <= 4)
	{
		for (int i = 1; i <= countersShip; i++) {
			CreateNewPoint(1);
			Ship shipTmp(j);
			bool CheckBorder = true;
			do {
				shipTmp.SetData();
				CheckBorder = InstalShip(shipTmp);
				if (CheckBorder == 1)
					AutoCreatePoint();
			} while (CheckBorder == true);
			bool Position = true;
			bool tmp = true;
			do {
				if (CheckOnePoint(shipTmp, Check_Plain) == 0) {
					bool tmp1 = CheckPointToPlain(shipTmp, Check_Plain);
					if (tmp1 == true) {
						SetConsoleTextAttribute(console, 12);
						GrShow_Point::GrShowPoint(shipTmp);
						SetConsoleTextAttribute(console, 15);
					}
					else
						if (tmp1 == false) {
							GrShow_Point::GrShowPoint(shipTmp);
						}
				}
				tmp = Input_Button(shipTmp);
				if (tmp == 1) {
					SetPoint(shipTmp, Check_Plain);
					// создание корабля и запись в него данных из shipTmp
					//std::unique_ptr<ShipPlayer> Upt= Create_Player_Ship(shipTmp);
					//player_tmp->Instal_Uptr_to_vector(Create_Player_Ship(shipTmp));
					player_tmp->Instal_to_vector(Create_Player_Ship2(shipTmp)); 

				}
			} while (tmp == false);

		}
		countersShip++;
		j--;

	}

}








