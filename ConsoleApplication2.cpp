#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

enum Buttons
{
	ARROW_DOWN = 72,
	ARROW_UP = 80,
	ENTER = 13
};

void CursoreCord(int x, int y)
{
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	cPos.Y = y;
	cPos.X = x;
	SetConsoleCursorPosition(hCon, cPos);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}

int Key(int cursore, bool& menu)
{
	switch (_getch())
	{
	case ARROW_DOWN:
		if (cursore % 5 > 0)
			return cursore - 1;
		else
			return cursore;
		break;
	case ARROW_UP:
		if (cursore % 5 < 4)
			return cursore + 1;
		else
			return cursore;
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
				return 5 * cursore + 5;
		}
		else if (cursore % 5 == 4)
		{
			system("cls");
			return (cursore - cursore % 5) / 5 - 1;
		}
		else
			return cursore;
		break;
	default:
		return cursore;
	}
}


int main()
{
	bool menu = true;
	setlocale(LC_ALL, "Rus");
	int cursore = 0;
	string array[25];
	array[0] = "Пункт 1";
	array[1] = "Пункт 2";
	array[2] = "Пункт 3";
	array[3] = "Пункт 4";
	array[4] = "Выход";

	array[5] = "Пункт 1.1";
	array[6] = "Пункт 1.2";
	array[7] = "Пункт 1.3";
	array[8] = "Пункт 1.4";
	array[9] = "Обратно к 1";

	array[10] = "Пункт 2.1";
	array[11] = "Пункт 2.2";
	array[12] = "Пункт 2.3";
	array[13] = "Пункт 2.4";
	array[14] = "Обратно к 2";

	array[15] = "Пункт 3.1";
	array[16] = "Пункт 3.2";
	array[17] = "Пункт 3.3";
	array[18] = "Пункт 3.4";
	array[19] = "Обратно к 3";

	array[20] = "Пункт 4.1";
	array[21] = "Пункт 4.2";
	array[22] = "Пункт 4.3";
	array[23] = "Пункт 4.4";
	array[24] = "Обратно к 4";

	SetColor(15, 0);

	while (menu)
	{
		for (int i = cursore - cursore % 5; i < cursore - cursore % 5 + 5; i++)
		{
			CursoreCord(37, 10 + i - cursore + cursore % 5);
			if (i == cursore)
			{
				SetColor(7, 0);
				cout << array[i];
				SetColor(15, 0);
			}
			else
				cout << array[i];
		}

		cursore = Key(cursore, menu);
	}
}

