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
struct Punkt_menu
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
int Key(int cursore, int SIZE, Employee* array)
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

void add(Punkt_menu& punkt, const string point, void fun(void))
{
	punkt.name = point;
	punkt.fun = fun;
}

int main()
{
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cPos.X = 37;
	setlocale(LC_ALL, "Rus");
	int cursore = 0;
	Punkt_menu* array =new Punkt_menu[SIZE];
	add(array[0], "paint", OpenPaint);
	add(array[1], "calculator", OpenCalc);
	add(array[2], "provodnik", OpenExplorer);
        add(array[3], "exit", exitIfEscape);
	while (1)
	{
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
	delete[] array;
}
