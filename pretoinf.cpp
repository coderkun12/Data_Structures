#include <iostream>
#include <bits.h>
#include <string.h>
using namespace std;
#define MAX 34
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
} j;
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
void conversion(string lo)
{
    int i = 0;
    while (lo[i] != '\0')
    {
        if ((lo[i] >= 'a' && lo[i] <= 'z') || (lo[i] >= 'A' && lo[i] == 'Z'))
        {
            string g;
            g += lo[i];
            j.push(g);
        }
        else
        {
            t2 = j.peek();
            j.pop();
            t1 = j.peek();
            j.pop();
            string t = "(" + t1 + lo[i] + t2 + ")";
            j.push(t);
        }
        i++;
    }
}
int main()
{
    char str[34];
    int i = 0;
    cout << "Entee a prefix expression:" << endl;
    cin >> str;
    strrev(str);
    conversion(str);
    cout << "The expression in infix is:" << endl
         << j.peek();
    return 0;
}