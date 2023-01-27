// CONVERT PREFIX TO POSTFIX.
#include <iostream>
#include <bits.h>
#include <string.h>
#include <algorithm>

using namespace std;
#define MAX 50
string t1;
string t2;
class STACK
{
    int top;

public:
    string a[MAX];
    STACK() { top = -1; }
    bool push(string x);
    string pop();
    string peek();
    bool isEmpty();
} d;
bool STACK ::push(string x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        // cout << x << " pushed into stack!" << endl;
    }
}
string STACK ::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        string x = a[top--];
        return x;
    }
}
string STACK ::peek()
{
    if (top < 0)
    {
        cout << "\nThe stack is empty!" << endl;
    }
    else
    {
        string x = a[top];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
void convertt(string l)
{
    int i = 0;
    int p = 0;
    while (l[i] != '\0')
    {
        if ((l[i] <= 'z' && l[i] >= 'a') || (l[i] <= 'Z' && l[i] >= 'A'))
        {
            string r;
            char t = l[i];
            r += l[i];
            d.push(r);
        }
        else
        {
            t2 = d.peek();
            d.pop();
            t1 = d.peek();
            d.pop();
            string t = l[i] + t2 + t1;
            d.push(t);
        }
        i++;
    }
}
int main()
{
    char k[25];
    cout << "Enter prefix expression: " << endl;
    cin >> k;
    convertt(k);
    cout << "The expression in postfix is:" << endl;
    cout << d.peek();
    d.pop();
    return 0;
}