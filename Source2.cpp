#include <iostream>

using namespace std;

char* deleteTheLetter(char* text, char letter)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == letter)
		{
			for (int j = i; text[j] != '\0'; j++)
				text[j] = text[j + 1];
			i--;
		}
	}
	return text;
}

int main()
{
	char someText[30];
	std::cin.getline(someText, 30);
	cout << deleteTheLetter(someText, 'o');

	return 0;
}