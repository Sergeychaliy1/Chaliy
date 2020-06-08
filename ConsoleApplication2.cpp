#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;
#define SIZE 5
const int height = 25;
const int width = 70;
void Draw() {
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width-2)
				cout << "#";
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++)
		cout << "#";
	cout << endl;
}
enum Button
{
	ARROW_DOWN = 72,
	ARROW_UP = 80,
	ENTER = 13
};

int Key(int cursore, bool& menu)
{
	switch (_getch())
	{
	case ARROW_DOWN:
		if (cursore <4)
			return cursore + 1;
		else
			return cursore;//не изменит положение
		break;
	case ARROW_UP:
		if (cursore > 0 && cursore < 5)
			return cursore - 1;
		else
			return cursore;//чтобы не шло выше
		break;
	case ENTER:
		if (cursore < 5)
		{
			if (cursore == 4)
			{
				menu = false;
				return 0;
			}
			else
				return  cursore + 5;
		}
		else 
			return cursore -5 ;
		break;
	default:
		return cursore;
	}
}


int main()
{
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.X = 37;
	
	bool menu = true;
	setlocale(LC_ALL, "Rus");
	int cursore = 0;
	string array[2*SIZE];
	array[0] = "Пункт 1";
	array[1] = "Пункт 2";
	array[2] = "Пункт 3";
	array[3] = "Пункт 4";
	array[4] = "Выход";

	array[5] = " Вы вошли в Пункт 1";
	array[6] = " Вы вошли в Пункт 2";
	array[7] = " Вы вошли в Пункт 3";
	array[8] = " Вы вошли в Пункт 4";
	array[9] = " Нажмите Enter чтобы выйти";

	while (menu)
	{
		system("cls");//очищается и переносится на новую строку
		SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 12));
		Draw();
		SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 15));
	if (cursore < 5)
	{
		for (int i = 0; i < 5; i++)
		{
			cPos.Y = 8 + i;
			SetConsoleCursorPosition(hCon, cPos);//устанавливает курсор на поставленные координаты
			if (i == cursore)//курсор==стротке
			{
				SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 12));//цвет до 
				cout << array[i];
				SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 15));//цвет после
			}
			else
				cout << array[i];
		}
	}
	else
		{
			cPos.Y = 10;
			SetConsoleCursorPosition(hCon, cPos);
			cout << array[cursore];//курсор указывает на пункт
			cPos.Y = 12;
			SetConsoleCursorPosition(hCon, cPos);
			cout << array[9];
		}
		cursore = Key(cursore, menu);
	}
}
