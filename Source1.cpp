//2λπ
//(1).
#include <iostream>
#include <clocale>
using namespace std;
int main() {
	int n = 1;
	cout << "Enter n" << endl;
	while (n > 0) {
		cin >> n;
		cout << "DEC" << dec << n << endl;
		cout << "OCT" << oct << n << endl;
		cout << "HEX" << hex << n << endl;

	}


	system("pause");
	return 0;
}
//(2).
#include <iostream>
#include <clocale>
using namespace std;
int main() {
	int n, res = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		res = res * (n - i);
	}
	cout << n << "!=" << res << endl;
	system("pause");
	return 0;
}


#include <iostream>
#include <clocale>
using namespace std;
int main() {
	int n, res = 1;
	cin >> n;
	int i = 0;
	while (i < n)
	{
		res = res * (n - i);
		i++;
	}
	cout << n << "!=" << res << endl;
	system("pause");
	return 0;
}

//(3).

#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum = 0, avg = 0, count = 0, min = INT_MAX, max = INT_MIN;

	while (cin >> n)
	{
		if (n == 0) {
			break;
		}
		sum += n;

		if (n > max)
		{
			max = n;
		}
		else if (n < min)
		{
			min = n;
		}




		count++;
	}

	avg = sum / count;

	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	cout << "sum = " << sum << endl;
	cout << "avg = " << avg << endl;

	return 0;
}

