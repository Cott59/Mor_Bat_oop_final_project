#include <iostream>
#include"Data_Info.h"
#include"Ship_Placement.h"

Grafic_Ship_Placement::Grafic_Ship_Placement(int x,int y)
{
	Base_Point.X = x; Base_Point.Y = y;
}

void Grafic_Ship_Placement::Border_1() {
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