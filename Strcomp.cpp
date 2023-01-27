// Write a code to compare two strings.
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
stack<string> po;
void con(string c)
{
    po.push(c);
}
int main()
{
    string s, h;
    cout << "Enter string 1:" << endl;
    cin >> s;
    cout << "Enter second string:" << endl;
    cin >> h;
    con(s);
    if (po.top() == h)
    {
        cout << "\nString are same!" << endl;
        po.pop();
    }
    else
    {
        cout << "\nStrings are different!" << endl;
        po.pop();
    }
    return 0;
}