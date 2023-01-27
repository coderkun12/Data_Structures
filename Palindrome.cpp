// Write a code to execute palindrome using stack.
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
stack<char> po;
int main()
{
    char pl[25];
    int i = 0;
    int counter = 0;
    cout << "Enter a string:" << endl;
    cin >> pl;
    int j = strlen(pl);
    while (pl[i] != '\0')
    {
        po.push(pl[i]);
        i++;
    }
    i = 0;
    while (pl[i] != '\0')
    {
        if (pl[i] == po.top())
        {
            counter += 1;
            po.pop();
        }
        i++;
    }
    cout << j << endl;
    cout << counter << endl;
    if (counter == j)
    {
        cout << "\nString is palindrome!" << endl;
    }
    else
    {
        cout << "\nThe string is not palindrome!" << endl;
    }
}