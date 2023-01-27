// Write a program to concatenate the string.
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
stack<string> po;
void con(string c, string k)
{
    po.push(k);
    po.push(c);
}
int main()
{
    string s, h;
    cout << "Enter string 1:" << endl;
    cin >> s;
    cout << "Enter second string:" << endl;
    cin >> h;
    con(s, h);
    cout << "Concatenated string is:" << endl;
    while (!po.empty())
    {
        cout << po.top();
        po.pop();
    }
    return 0;
}