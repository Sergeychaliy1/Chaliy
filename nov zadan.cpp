#include <iostream>
#include <string>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string str = "helloo"; 
    int size = 6; 
    char ch; 
    cout << "Введите удаляемый символ ";
    cin >> ch;
    for (int i = 0; i < size; i++) 
    {
        if (str[i] == ch) 
        {
            for (int j = i; j < size; j++)
            {
                str[j] = str[j + 1];
            }
            i--; 
        }
    }
    cout << str; 

    return 0;
}