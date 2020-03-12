
//1лр
//(1)
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Имя:Сергей." << endl;
	cout << "Фамилия: Чалый." << endl;

	system("pause");
	return 0;
}

//(2)



#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	cout << "dec: " << dec << n << endl;
	cout << "hex: " << hex << n << endl;
	cout << "oct: " << oct << n << endl;

	return 0;
}


//(3)

#include <iostream>

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;

	cout << "In minutes: " << h * 60 + m << " minutes" << endl;

	return 0;
}




//(4)

#include <iostream>

using namespace std;

int HtoM(int hours, int minutes)
{
	return hours * 60 + minutes;
}

int main()
{
	int h, m;
	cin >> h >> m;
	cout << "Minutes: " << HtoM(h, m) << " minutes" << endl;
	return 0;
}





//(5)





(convert.cpp)
#include "convert.h"

int HtoM(int hours, int minutes)
{
	return hours * 60 + minutes;
}




(convert.h)
#pragma once

int HtoM(int hours, int minutes);





#include <iostream>
#include "convert.h"

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	cout << "Minutes: " << HtoM(h, m) << endl;
	return 0;
}

