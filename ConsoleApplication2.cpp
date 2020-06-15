#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <shellapi.h>

using namespace std;
#define SIZE 4
enum Button
{
	ARROW_DOWN = 80,
	ARROW_UP = 72,
	ENTER = 13
};
struct paragraph
{
	string name;
	void (*fun)();
};
void OpenPaint()
{
	ShellExecute(NULL, L"open", L"mspaint.exe", NULL, NULL, SW_SHOW);
}
void OpenCalc()
{
	system("calc");
}
void OpenExplorer()
{
	ShellExecute(NULL, L"open", L"C://windows//explorer.exe", NULL, NULL, SW_SHOW);
}
int Key(int cursore,paragraph* array)
{
	switch (_getch())
	{
	case ARROW_DOWN:
		if (cursore < SIZE-1)
			return cursore + 1;
		else
			return cursore;
		break;
	case ARROW_UP:
		if (cursore > 0 )
			return cursore - 1;
		else
			return cursore;
		break;
	case ENTER:
		array[cursore].fun();
		return cursore;
		break;
	default:
		return cursore;
	}
}
void exitIfEscape()
{
		exit(0);
}

int main()
{
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.X = 37;
	setlocale(LC_ALL, "Rus");
	int cursore = 0;
	paragraph array[SIZE] = {
{ "paint", OpenPaint },
{ "calculator", OpenCalc },
{ "provodnik", OpenExplorer },
{ "exit", exitIfEscape}
	};
		system("cls");

	
		for (int i = 0; i <SIZE; i++)
		{
			cPos.Y = 3 + i;
			SetConsoleCursorPosition(hCon, cPos);//устанавливает курсор на поставленные координаты
			if (i == cursore)//курсор==стротке
			{
				SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 12));//цвет до 
				cout << array[i].name;
				SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 15));//цвет после
			}
			else
				cout << array[i].name;
		}	
		cursore = Key(cursore, array);
	}
}
