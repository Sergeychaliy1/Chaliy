#include "MyString.h"
#include <iostream>
using namespace std;

int const shift;

unsigned int strLen(const char *str)
{
	const char *temp = str;
	while (*temp++);
	return temp - str - 1;
} 

void strCpy(char *dest, const char *source)
{
	for (int i=0; i<strLen(source)+1; i++)
	{
		dest[i]=source[i];
	}
}

int strnCpy(char *dest, const char *source, unsigned int len)
{
	int i=0;
	for (; i<len; i++)
	{
		dest[i] = source[i];
		if(source[i] == '\0')
		{
			break;
		}
	}
	if (len <= i) return 0;
	return (len - i );
}


void strCat(char *dest, const char *source)
{   

	for(int i=0,d=strLen(dest);i <= strLen(source)+1 ;d++,i++)
	{
		dest[d]=source[i];
	    
	}
}

void strnCat(char *dest, const char *source, unsigned int len)
{
	int i,j;
	i=strLen(dest);
	j=0;
	for(j;j<len;j++)
	{
		dest[i]=source[j];
		i++;
	}
}

void strReverse(char *str)
{
	char a;
	int b=strLen(str);
	for(int i=0 ;i<b/2 ;i++)
	{
	a=str[i];
	str[i]=str[b-i-1];
	str[b-i-1]=a;
	}
}

void strToUpper(char *str)
{
	char a;
	int b=strLen(str);
	for(int i=0;i<b;i++)
	{
	  if ('a'<=str[i] && str[i]<='z')
	  {
		str[i]-= shift;
	  }
	}
}
void strToLower(char *str)
{
	char a;
	int b=strLen(str);
	for(int i=0;i<b;i++)
	{
	if ('A'<=str[i] && str[i]<='Z')
	{
		str[i]+=shift ;
	}
	}

}


int strStr(const char *str,const char *substr)
{
	int a=strLen(substr), b=strLen(str);
	int c=-1;
	int j=0;
	for(int i=0;i<=(b-a);i++)
	{
		 for(j; j<a,substr[j]==str[j+i]; j++)
		 if (j==(a-1))
		 {
			 c=i;
			 i=b-a;
		 }
		 j=0;
	}
	
	return c;
}


int strCmp(const char *str1,const char *str2)
{
	int c=0;
	int i=0;
if(strLen(str1)==strLen(str2))
{
	while(i<strLen(str1) && str1[i]==str2[i])
	{
		i++;
	}
	if (str1[i]>str2[i])
	{
		c=1;
	}
	if (str1[i]<str2[i])
	{
		c=-1;
	}
}
if(strLen(str1)>strLen(str2))
	return 1;
else if(strLen(str1)<strLen(str2))
	return -1;
else  
	return c;
}

