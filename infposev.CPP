#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int t1, t2, num;
#define MAX 25
char output[20];
class STACK
{
    int top, top2;

public:
    char a[MAX], b[MAX];
    STACK()
    {
        top = -1;
        top2 = -1;
    }
    bool push(char x);
    bool pusht(int x);
    int popt();
    char pop();
    char peek();
    bool isEmpty();
} d;
bool STACK ::pusht(int x)
{
    if (top2 >= (MAX - 1))
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        b[++top2] = x;
    }
}
int STACK ::popt()
{
    if (top2 < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        int x = b[top2--];
        return x;
    }
}
bool STACK ::push(char x)
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
char STACK ::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        char x = a[top--];
        return x;
    }
}
char STACK ::peek()
{
    if (top < 0)
    {
        cout << "\nThe stack is empty!" << endl;
    }
    else
    {
        char x = a[top];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
int priority(char c)
{
    switch (c)
    {
    case '+':
    {
        return 1;
        break;
    }
    case '-':
    {
        return 1;
        break;
    }
    case '*':
    {
        return 2;
        break;
    }
    case '/':
    {
        return 2;
        break;
    }
    case '%':
    {
        return 2;
        break;
    }
    case '$':
    {
        return 3;
        break;
    }
    default:
        break;
    }
}
void intopos(char s[])
{
    int i, j;
    j = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            output[j] = s[i];
            j++;
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            d.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            switch (s[i])
            {
            case ')':
            {
                char y;
                y = d.pop();
                while (y != '(')
                {
                    output[j] = y;
                    j++;
                    y = d.pop();
                }
                break;
            }
            case '}':
            {
                char y;
                y = d.pop();
                while (y != '{')
                {
                    output[j] = y;
                    j++;
                    y = d.pop();
                }
                break;
            }
            case ']':
            {
                char y;
                y = d.pop();
                while (y != '[')
                {
                    output[j] = y;
                    j++;
                    y = d.pop();
                }
                break;
            }
            }
        }
        else
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '$')
            {
                if (d.isEmpty())
                {
                    d.push(s[i]);
                }
                else
                {
                    char p = d.pop();
                    if (priority(s[i]) >= priority(p))
                    {
                        d.push(p);
                        d.push(s[i]);
                    }
                    else if (priority(s[i]) < priority(p))
                    {
                        d.push(s[i]);
                        d.push(p);
                    }
                }
            }
        }
        i++;
    }
    while (!d.isEmpty())
    {
        char k = d.pop();
        output[j] = k;
        j++;
    }
    output[j] = '\0';
}
void check(char o)
{
    int ans;
    switch (o)
    {
    case '+':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = t1 + t2;
        d.pusht(ans);
        break;
    }
    case '-':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = t1 - t2;
        d.pusht(ans);
        break;
    }
    case '/':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = t1 / t2;
        d.pusht(ans);
        break;
    }
    case '%':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = t1 % t2;
        d.pusht(ans);
        break;
    }
    case '*':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = t1 * t2;
        d.pusht(ans);
        break;
    }
    case '$':
    {
        t2 = d.popt();
        t1 = d.popt();
        ans = pow(t1, t2);
        d.pusht(ans);
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
            cout << "\nEnter value of " << p[i] << " :" << endl;
            cin >> num;
            d.pusht(num);
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
    cout << "Enter the Infix expression:" << endl;
    cin >> str;
    intopos(str);
    int i = 0;
    cout << "The string in postfix format is:" << endl;
    while (output[i] != '\0')
    {
        cout << output[i];
        i++;
    }
    poeva(output);
    cout << "\nThe answer after evaluation is:" << endl;
    cout << d.popt();
    return 0;
}