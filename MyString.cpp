#include"MyString.h"
 unsigned int StrLen(const char* str)
{
	int a = 0;
	for (int i = 0; str[i] != '\0';i++)
	{
		a++;
	}
	return a;
}

void StrCpy(char* dest, const char* source)

{
	for (int i = 0;i < 6; i++)
	{
		dest[i] = source[i];

	}
}
