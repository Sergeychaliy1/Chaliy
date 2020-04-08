#include"MyString.h"
#include<iostream>__msvc_all_public_headers.hpp
using namespace std;
int main()
{
	
    char array[] = "privet";
 cout << StrLen(array);	
 
     char text1[] = "abcde";
     char text2[5];
     StrCpy(text2, text1);
     cout << text2;
}