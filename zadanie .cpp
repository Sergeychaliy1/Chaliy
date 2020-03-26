#include <iostream>
using namespace std;
int main()
{
    char text[] = "hello world";
    char leter = 'o';
    for (int i = 0; text[i]!='\0'; i++) 
    {
        if (text[i] == leter) 
        {
            for (int j = i; text[j]!='\0'; j++)
             text[j] = text[j + 1];
               i--; 
        }
    }
    cout << "Result:" << text;

    return 0;
}