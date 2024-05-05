#include "Data_Info.h"
#include<Windows.h>
#include <iostream>
#include<conio.h>
#include"Includes.h"
#include<memory>
extern HANDLE console;
extern COORD CursorPosition;
extern bool PARC_PL1_;// расстановка кораблей:
extern bool PARC_PL2_;// true 1 - автоматическая, false 0 - ручная
extern bool ATTAC_PL1_; //ввод координат для атаки
extern bool ATTAC_PL2_; //true - автоматическая, false - ручной

int Set_Parametr();//объявление функции

 void DataInput::gotoxy(int x, int y)
{
	 CursorPosition.X = (short)x;
	 CursorPosition.Y = (short)y;
	SetConsoleCursorPosition(console, CursorPosition);
}

Menu::Menu(){
	
}

void  Menu::Set_Data_Players() {

	Grafic_Menu::Show_Menu_PL1();
	PARC_PL1_ = 0;
	ATTAC_PL1_ = Set_Parametr();
	Grafic_Menu::Set_Player2();
	if (Set_Parametr() == 1) {
		PARC_PL2_ = 1;
		ATTAC_PL2_ = 1;
	}
	else {
		Grafic_Menu::Show_Menu_PL2();
		PARC_PL2_ = 0;
		ATTAC_PL2_ = Set_Parametr();
	}
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

Player::Player(bool parc, bool attac, std::string name)
{
	Parc = parc; Attac = attac; Name = name;
	//ShipPl.reserve(10);
}

Player::~Player()
{
}

int Set_Parametr() {
	int tmp;
	std::cin >> tmp;
	return tmp;
}

void Player::Set_Base_Point(int X, int Y) {
	Base_Point.X = X;
	Base_Point.Y = Y;
}

void Player::Instal_to_vector(ShipPlayer* ptr)
{
	ShipPl.push_back(ptr);
}

//void Player::Instal_Uptr_to_vector(std::unique_ptr<ShipPlayer> U_ptr)
//{
//	ShipPl.push_back(U_ptr);
//}



void Create_Players::CreatePlayer() {
	PL1 = new Player(PARC_PL1_, ATTAC_PL1_, "Player 1");
	PL2 = new Player(PARC_PL2_, ATTAC_PL2_, "Player 2");
}

