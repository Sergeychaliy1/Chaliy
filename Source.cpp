//3лр
//(1)


#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    int i;


    cout << "Введите число" << endl;
    cin >> n;
    int arg = n;
    int res = 0;
    cout << "n^2= ";
    for (i = 1; i <= arg; i++)
    {
        n = (2 * i - 1);
        res += n;
        cout << n;
        if (i < arg)
        {
            cout << "+";
        }
    }
    cout << " = " << res;

    return 0;
}

//(2).

#include <iostream>

using namespace std;

int main()
{
    int n, count = 0, i = 99;

    cin >> n;

    while (++i < 1000)
        if (i % 10 + i / 10 % 10 + i / 100 == n)
            ++count;
    cout << count << endl;
}





//(4.1)
#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << n;
        }
        cout << endl;
    }

    return 0;
}

//(4.2)

#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << n;
        }
        cout << endl;
    }

    return 0;
}

//(4.3)

#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    for (int i = 1; i <= 5; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }
}


//(4.4)

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {

        for (int k = i; k >= 0; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}

