#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	      setlocale(LC_ALL, "Russian");
	      char str[30] ="Happy NeW year 2020";
}
  {
    cout<<"     ������� 9 - ���������� ������ ������� ��������� ��������� substr � str"<<endl<<endl;
	char strstr[20]="123qwerty4444" ;
	char substr[20]="qwerty" ;
	cout<<strstr<<endl<<substr<<endl;
	cout<<strStr(strstr, substr)<<endl<<endl;

	cout<<"     �������10 - 0(���� ������ �����), 1(���� ������ ������), -1(���� ������ ������)"<<endl<<endl;		  
	char str1[30] ="5555a55";
	char str2[30] ="5555b55";
	cout<<str1<<endl<<str2<<endl;
	cout<<strCmp(str1,str2)<<endl<<endl;
	
	system("pause");
	return 0;
  }
}