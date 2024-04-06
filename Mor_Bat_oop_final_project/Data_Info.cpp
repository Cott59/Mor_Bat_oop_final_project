#include "Data_Info.h"
#include<Windows.h>
#include <iostream>
#include<conio.h>

extern HANDLE console;
extern COORD CursorPosition;


 void DataInput::gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

Menu::Menu(){
	PRK1 = false;
	PRK2 = true;
	InCoord1 = false;
	InCoord2 = true;

}



void Grafic_Menu::Show_Menu_PL1() {
	system("cls");
	DataInput::gotoxy(35, 5); std::cout << " --------------------------- ";
	DataInput::gotoxy(35, 6);  std::cout << " |        Player 1         | ";
	DataInput::gotoxy(35, 7);  std::cout << " --------------------------- ";
	DataInput::gotoxy(40, 9);  std::cout << "    Ведение боя   ";
	DataInput::gotoxy(40, 10); std::cout << "1. Автоматическое";
	DataInput::gotoxy(40, 11); std::cout << "2. Ручное";
	DataInput::gotoxy(40, 13);  std::cout << "Select option: ";
	char ch = _getche();
}

void Grafic_Menu::Show_Menu_PL2() {
	system("cls");
	DataInput::gotoxy(35, 5); std::cout << " --------------------------- ";
	DataInput::gotoxy(35, 6);  std::cout << " |        Player 2         | ";
	DataInput::gotoxy(35, 7);  std::cout << " --------------------------- ";
	DataInput::gotoxy(40, 9);  std::cout << "    Ведение боя   ";
	DataInput::gotoxy(40, 10); std::cout << "1. Автоматическое";
	DataInput::gotoxy(40, 11); std::cout << "2. Ручное";
	DataInput::gotoxy(40, 13);  std::cout << "Select option: ";
	char ch = _getche();
}

void Grafic_Menu::Set_Player2() {
	system("cls");
	DataInput::gotoxy(35, 5); std::cout << " --------------------------- ";
	DataInput::gotoxy(35, 6);  std::cout << " |        Player 2         | ";
	DataInput::gotoxy(35, 7);  std::cout << " --------------------------- ";
	DataInput::gotoxy(38, 9);  std::cout << "Выберите второго игрока";
	DataInput::gotoxy(40, 10); std::cout << "1. Компьютер";
	DataInput::gotoxy(40, 11); std::cout << "2. Игрок";
	DataInput::gotoxy(40, 13);  std::cout << "Select option: ";
	char ch = _getche();
}


