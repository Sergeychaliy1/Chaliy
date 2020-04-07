#include <iostream>
using namespace std;

int main()
{
    zadacha1();
}

void zadacha1()
{
    int number, result = 0;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        result += 2 * i + 1;
    }
    cout << number << "^2=" << result;
}

void zadacha2()
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

  
}

void zadacha3()
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
   
}


int zadacha4()
{
    cout << "vvedite chislo";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}


void zadacha5()
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


