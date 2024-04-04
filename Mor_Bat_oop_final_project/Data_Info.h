#pragma once


class DataInput {
public:

	static void gotoxy(int x, int y);
	
};

class Menu 
{
public:
	Menu();
		
private:
	bool PRK1;  // = false;// расстановка кораблей:
	bool PRK2;  // = false;// true - автоматическая, false - ручная
	bool InCoord1;  // = true; //ввод координат удара
	bool InCoord2;  // = false; //true - автоматическая, false - ручной
};

class Grafic_Menu :public Menu
{
public:
	Grafic_Menu();
	void Show_Menu();

private:


};


