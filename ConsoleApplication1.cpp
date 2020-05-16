#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>      

using namespace std;


void SetColor(int text, int background)  //СОЗДАЮ ФУНКЦИЮ,КОТОРАЯ МЕНЯЕТ ЦВЕТ ТЕКСТА И ЦВЕТ ФОНА В КОНСОЛИ.
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}


void CursoreCord(int x, int y)  //СОЗДАЮ ФУНКЦИЮ,КОТОРАЯ МЕНЯЕТ ПОЛОЖЕНИЯ КУРСОРА НА КООРДИНАТЫ (X,Y)
{
	HANDLE hCon;
	COORD cPos;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	cPos.Y = y;
	cPos.X = x;
	SetConsoleCursorPosition(hCon, cPos);
}



int Key(int cursore, bool& menu)  //СОЗДАЮ ФУНКЦИЮ,КОТОРАЯ ОТНОСИТЕЛЬНО НАЖАТИЯ КЛАВИШИ ПЕРЕМЕЩАЕТ КУРСОР.
{                                  
	switch (_getch())// курсор принимает значения клавиши которую я нажал
	{
	case 'w': 
		if (cursore % 5 > 0)      //КУРСОР СМЕЩАЕТСЯ ВВЕРХ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В ВЕРХНЕЙ ТОЧКЕ
			return cursore - 1;
		else
			return cursore;
		break;
	case '214':
		if (cursore % 5 > 0)      //КУРСОР СМЕЩАЕТСЯ ВВЕРХ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В ВЕРХНЕЙ ТОЧКЕ
			return cursore - 1;
		else
			return cursore;
		break;
	case 72://КЛАВИША СТРЕЛОЧКА ВВЕРХ
		if (cursore % 5 > 0)      //КУРСОР СМЕЩАЕТСЯ ВВЕРХ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В ВЕРХНЕЙ ТОЧКЕ
			return cursore - 1;
		else
			return cursore;
		break;
	case 's': 
		if (cursore % 5 < 4)      //КУРСОР СМЕЩАЕТСЯ ВНИЗ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В НИЖНЕЙ ТОЧКЕ
			return cursore + 1;
		else
			return cursore;
		break;
	case '219':
		if (cursore % 5 < 4)      //КУРСОР СМЕЩАЕТСЯ ВНИЗ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В НИЖНЕЙ ТОЧКЕ
			return cursore + 1;
		else
			return cursore;
		break;
	case 80: //КЛАВИША СТРЕЛОЧКА ВНИЗ
		if (cursore % 5 < 4)      //КУРСОР СМЕЩАЕТСЯ ВНИЗ, ТОЛЬКО ЕСЛИ НЕ НАХОДИТСЯ В НИЖНЕЙ ТОЧКЕ
			return cursore + 1;
		else
			return cursore;
		break;
	case 13:                      //КЛАВИША Enter
		if (cursore < 5) //ПЕРЕХОДИМ К ПУНКТАМ ТОЛЬКО С ГЛАВНОГО ЭКРАНА
		{
			if (cursore == 4) //ЕСЛИ ПРОБЕЛ СРАБОТАЛ НА КНОПКЕ 4 (ВЫХОД) ТО ЗАМЕНЯЕМ MENU НА FALSE (ВЫХОДИМ ИЗ МЕНЮ)
			{
				menu = false;
				return 0;
			}
			else           //ИНАЧЕ СМЕЩАЕМ КУРСОР НА (ЕГО ПОЛОЖЕНИЕ)*5, ЧТО СООТВЕТСВУЕТ НУЖНОМУ ПУНКТУ В МАССИВЕ 
				return 5 * cursore + 5;
		}
		else if (cursore % 5 == 4) //ЕСЛИ КУРСОР СТОИТ НА КНОПКЕ "НАЗАД К ПУНКТУ_" ТО КУРСОР СМЕЩАЕТСЯ В ГЛАВНОЕ МЕНЮ
		{
			system("cls");
			return (cursore - cursore % 5) / 5 - 1;// курсор при нажатии назад , возвращается на исходное место
		}
		else
			return cursore;
		
	default:      // ЕСЛИ НИ ОДНА КЛАВИША НЕ БЫЛА НАЖАТА, ТО НИЧЕГО НЕ ПРОИСХОДИТ
		return cursore;
	}
}


int main()
{
	bool menu = TRUE;
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
	array[9] = "Вернуться к 1";

	array[10] = "Пункт 2.1";
	array[11] = "Пункт 2.2";
	array[12] = "Пункт 2.3";
	array[13] = "Пункт 2.4";
	array[14] = "Вернуться к 2";

	array[15] = "Пункт 3.1";
	array[16] = "Пункт 3.2";
	array[17] = "Пункт 3.3";
	array[18] = "Пункт 3.4";
	array[19] = "Вернуться к 3";

	array[20] = "Пункт 4.1";
	array[21] = "Пункт 4.2";
	array[22] = "Пункт 4.3";
	array[23] = "Пункт 4.4";
	array[24] = "Вернуться к 4";  //ПРОПИСЫВАЮ МАССИВ С ПУНКТАМИ

	SetColor(1, 0); 

	while (bool menu = TRUE) // ПОКА MENU == TRUE
	{
		for (int i = cursore - cursore % 5; i < cursore - cursore % 5 + 5; i++)
		{
			CursoreCord(14, 3 + i - cursore + cursore % 5); //УСТАНАВЛИВАЮ КУРСОР НА КООРДИНАТЫ
			if (i == cursore)                          //изменяю положение колонки
			{
				SetColor(4, 0);    //ЕСЛИ НА ДАННЫЙ ПУНКТ СОВПАДАЕТ С ПОЛОЖЕНИЕМ КУРСОРА,то он становится красным
				cout << array[i]<<endl; 
				SetColor(3, 0);
			}
			else
				cout << array[i] << endl;
		}

		cursore = Key(cursore, menu); //КУРСОР ИЗМЕНИЕТСЯ ЕСЛИ НАЖАТЫ СТРЕЛОЧКИ ИЛИ ПРОБЕЛ
	}
}