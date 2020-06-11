#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;
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
	ARROW_DOWN = 80,
	ARROW_UP = 72,
	ENTER = 13
};

int Key(int cursore, bool& menu, int SIZE)
{
	switch (_getch())
	{
	case ARROW_DOWN:
		if (cursore < 2*SIZE - 2 && !(cursore%2))
			return cursore + 2;
		else
			return cursore;//не изменит положение
		break;
	case ARROW_UP:
		if (cursore > 0 && !(cursore % 2))
			return cursore - 2;
		else
			return cursore;//чтобы не шло выше
		break;
	case ENTER:
		if (!(cursore % 2))
		{
			if (cursore == 2*SIZE - 2)
			{
				menu = false;
				return 0;
			}
			else
				return  cursore + 1;
		}
		else
			return cursore - 1;
		break;
	default:
		return cursore;
	}
}
void add(string*& arr, int & size, const string point, const string text)
{
	string* new_Array = new string[2*size + 2];
	for (int i = 0; i < 2*size-2; i++)
		new_Array[i] = arr[i];
	new_Array[2*size-2] = point;
	new_Array[2*size-1] = text;
	new_Array[2 * size]=arr[2*size-2];
	new_Array[2*size+1]=arr[2*size-1];
	delete[] arr;
	arr = new_Array;
	size++;
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
	int SIZE = 1;
	string* array = new string[2 * SIZE];
	array[0] = "выход";
	array[1] = " нажмите enter чтобы выйти";
	add(array, SIZE, "1point", "1text");
	add(array, SIZE, "2point", "2text");
	add(array, SIZE, "3point", "3text");

	while (menu)
	{
		system("cls");//очищается и переносится на новую строку
		SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 12));
		Draw();
		SetConsoleTextAttribute(hCon, (WORD)((0 << 4) | 15));
	if (!(cursore % 2))
	{
		for (int i = 0; i < 2*SIZE; i+=2)
		{
			cPos.Y = 3 + i;
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
			cout << array[2*SIZE-1];
		}
		cursore = Key(cursore, menu,SIZE);
	}
}
