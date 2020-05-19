#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	      setlocale(LC_ALL, "Russian");
	      char str[30] ="Happy NeW year 2020";
}
  {
    cout<<"     функция 9 - возвращает индекс первого вхождения подстроки substr в str"<<endl<<endl;
	char strstr[20]="123qwerty4444" ;
	char substr[20]="qwerty" ;
	cout<<strstr<<endl<<substr<<endl;
	cout<<strStr(strstr, substr)<<endl<<endl;

	cout<<"     функция10 - 0(если строки равны), 1(если первая больше), -1(если вторая больше)"<<endl<<endl;		  
	char str1[30] ="5555a55";
	char str2[30] ="5555b55";
	cout<<str1<<endl<<str2<<endl;
	cout<<strCmp(str1,str2)<<endl<<endl;
	
	system("pause");
	return 0;
  }
}