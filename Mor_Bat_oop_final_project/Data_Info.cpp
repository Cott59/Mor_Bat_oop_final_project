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
	/*Parc_Pl1 = 0;
	Parc_Pl2 = true;
	Attac_Pl1 = false;
	Attac_Pl2 = true;*/

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
	
}

Player::Player()
{
}

Player::Player(bool parc, bool attac)
{
	Parc = parc; Attac = attac;
}

Player::~Player()
{
}

void Player::Set_Base_Point(int X, int Y) {
	Base_Point.X = X;
	Base_Point.Y = Y;
}


int Set_Parametr() {
	int tmp;
	std::cin >> tmp;
	return tmp;
}


void  Logic_Menu::Set_Data_Players() {

	Grafic_Menu::Show_Menu_PL1();
	/*Set_Parc_Pl1(0);
	Set_Parc_Pl1(Set_Parametr());*/
	Menu menu;
	menu.Set_Parc_Pl1(0);
	menu.Set_Attac_Pl1(Set_Parametr());
	Grafic_Menu::Set_Player2();
	if (Set_Parametr() == 1) {
		menu.Set_Parc_Pl2(1);
		menu.Set_Attac_Pl2(1);
	}
	else {
		Grafic_Menu::Show_Menu_PL2();
		menu.Set_Parc_Pl2(0);
		menu.Set_Attac_Pl2(Set_Parametr());
	}

	Player* PL1 = new Player(menu.Get_Parc_Pl1(), menu.Get_Attac_Pl1());
	Player* PL2 = new Player(menu.Get_Parc_Pl2(), menu.Get_Attac_Pl2());



}
