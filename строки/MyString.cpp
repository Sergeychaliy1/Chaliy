#include <iostream>
#include "MyString.h"

int const LetterACSIIDifferece = 32;

unsigned int strLen(const char *str)
{
	const char *temp = str;
	while (*temp++);
	return temp - str - 1;
} 

void strCpy(char *dest, const char *source)
{
	for (int i=0; i<strLen(source); i++)
	{
		dest[i]=source[i];
	}
}

void strCat(char *dest, const char *source)
{   

	for(int i=0,d=strLen(dest);i <= strLen(source);i++)
	{
		dest[j]=source[i];    
	}
}
void strReverse(char *str)
{
char temp;
	int strLenght = strLen(str);

	for (int i = 0; i < strLenght / 2; i++)
	{
		temp = str[i];
		str[i] = str[strLenght - i - 1];
		str[strLenght - i - 1] = temp;
	}
}

void strToUpper(char *str)
{
	char temp;
int strLenght = strLen(str);
	for(int i=0;i<strLenght;i++)
	{
	  if (str[i] >= 'a'&& str[i]<='z')
	  {
		str[i]-= LetterACSIIDifferece;
	  }
	}
}
void strToLower(char *str)
{
	char temp;
	int strLenght=strLen(str);
	for(int i=0;i < strLenght;i++)
	{
if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += LetterACSIIDifferece;
		}
	}

}


int strStr(const char *str,const char *subStr)
{
int subStrPosBegin = 0;
	int strLenght = strLen(str);
	int subStrLenght = strLen(subStr);
	for(int i=0;i<=(b-a);i++)
	{
for (int i = 0; i < strLenght - subStrLenght; i++)
{
		for (int j = 0; j < subStrLenght && subStr[j] == str[j + 1]; j++)
		{
			if (j == strLenght - 1)
			{
				subStrPosBegin = i;
				i = strLenght - subStrLenght;
			}
			j = 0;
		}
	}
	return subStrPosBegin;
}


int strCmp(const char *str1,const char *str2)
{
if(strLen(str1)==strLen(str2))
{
	for (int i = 0; i < strLen(str1) && str1[i] == str2[i]; i++)
        {
	if (str1[i]>str2[i])
	{
return 1;
	}
else if (str1[i] < str2[i])
			{
				return -1;
			}

		else
			
if(strLen(str1)>strLen(str2))
{
	return 1;
}
else if(strLen(str1)<strLen(str2))
{
	return -1;
}
	}
	return 0;
}
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
	
	char* strToLowerDyn( char* str)
{
	char* newstr = new char[strlen(str)];
	strCpy(newstr, str);
        strToLower(newstr);
	return newstr;
}


char* StrReverseDyn(char* str)
{
	char* newstr = new char[strlen(str)];
	for (int i = 0; i < strlen(str); i++)
		newstr[i] = str[strlen(str)-i-1];
	return newstr;
}
