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
	bool PRK1;  // = false;// ����������� ��������:
	bool PRK2;  // = false;// true - ��������������, false - ������
	bool InCoord1;  // = true; //���� ��������� �����
	bool InCoord2;  // = false; //true - ��������������, false - ������
};

class Grafic_Menu :public Menu
{
public:
	Grafic_Menu();
	void Show_Menu();

private:


};


