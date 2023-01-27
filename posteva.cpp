// Postfix evaluation.
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 30
int t1, t2, num;
class STACK
{
    int top;

public:
    int a[MAX];
    STACK() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
} d;
bool STACK ::push(int x)
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
int STACK ::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int STACK ::peek()
{
    if (top < 0)
    {
        cout << "\nThe stack is empty!" << endl;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
void check(char o)
{
    int ans;
    switch (o)
    {
    case '+':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = t1 + t2;
        d.push(ans);
        break;
    }
    case '-':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = t1 - t2;
        d.push(ans);
        break;
    }
    case '/':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = t1 / t2;
        d.push(ans);
        break;
    }
    case '%':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = t1 % t2;
        d.push(ans);
        break;
    }
    case '*':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = t1 * t2;
        d.push(ans);
        break;
    }
    case '$':
    {
        t2 = d.pop();
        t1 = d.pop();
        ans = pow(t1, t2);
        d.push(ans);
        break;
    }
    default:
        break;
    }
}
void poeva(char p[])
{
    int i = 0;
    while (p[i] != '\0')
    {
        if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))
        {
            cout << "Enter value of " << p[i] << " :" << endl;
            cin >> num;
            d.push(num);
        }
        else
        {
            check(p[i]);
        }
        i++;
    }
}
int main()
{
    char str[20];
    cout << "Enter postfix expression: " << endl;
    cin >> str;
    poeva(str);
    cout << "\nThe answer after evaluation is:" << endl;
    cout << d.pop();
    return 0;
}