#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	      char str[30] ="Happy NeW year 2020";
	
	
	//#1
	
	char strstr[20]="123qwerty4444" ;
	char substr[20]="qwerty" ;
	
	cout << strstr << endl;
	cout << substr << endl;
	cout<<strstr<<endl<<substr<<endl;
	cout<<strStr(strstr, substr)<<endl<<endl;

	//#2
	
	char str1[30] ="5555a55";
	char str2[30] ="5555b55";
cout << str1 << endl;
	cout << str2 << endl;
	cout<<strCmp(str1,str2)<<endl<<endl;
	
	
	
	//#3
	
	char strLower[] = "sdjkfhsdkjlf KSLDJHFKJLSDHF dkjfhskjfh 12345678910";
	char strUpper[] = "FJKHSDKLJFHSLDK sfhksdfh SDKLFJHSKDJHF 12345678910";

	strToUpper(strLower);
	strToLower(strUpper);

	cout << strLower << endl;
	cout << strUpper << endl;


        //#4


	char someText[30];
	std::cin.getline(someText, 30);
	cout << deleteTheLetter(someText, 'o');

	system("pause");
	return 0;
  }

	char mas[] = "sdjkfhsdkjlf KSLDJHFKJLSDHF dkjfhskjfh 12345678910";
	

	
	mas=tolower(mas)

	
}
