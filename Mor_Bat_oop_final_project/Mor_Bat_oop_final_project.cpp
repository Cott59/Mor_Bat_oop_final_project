﻿#include<conio.h>
#include <iostream>
#include<Windows.h>
#include"Data_Info.h"



#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition = {};


int main()
{
	setlocale(LC_ALL, "Russian");
	COORD maxWindow = { SCREEN_WIDTH,SCREEN_HEIGHT };//  размер самого большого возможного консольного окна
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0,0, 0 };
	SetConsoleWindowInfo(console, true, &minWindow);
	SetConsoleScreenBufferSize(console, maxWindow);
	SetConsoleWindowInfo(console, true, &srctWindow);
    
	Grafic_Menu::Show_Menu_PL1();
	Grafic_Menu::Set_Player2();
	Grafic_Menu::Show_Menu_PL2();


	_getch();
    return 0;
}








