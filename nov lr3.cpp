#include <iostream>
using namespace std;
int a;
int i;
int main()
{
    cout << "vvedite chislo" << endl;
    cin >> a;
    int abc = a;
    int res = 0;
    cout << "otvet" << "=";
    for (i = 1; i <= abc; i++)
    {
        a = (2 * i - 1);
        res += a;
        cout << a;
        if (i < abc)
        {
            cout << "+";
        }
    }
    cout << " = " << res;
}


int main()
{
    int n;
    cout << "vvedite chislo";
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


#include <iostream>
using namespace std;
int main()
{
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


#include <iostream>
using namespace std;
int main()
{
    cout << "vvedite chislo";
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



#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    for (int i = 1; i < a + 1; i++)
    {

        for (int k = i; k >= 0; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}


