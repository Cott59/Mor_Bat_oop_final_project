#include "Gameplay.h"
#include <iostream>
#include"Data_Info.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30

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
	DataInput::gotoxy(15, 3); std::cout << "PLAYER 1";
	DataInput::gotoxy(49, 3); std::cout << "PLAYER 2";

}