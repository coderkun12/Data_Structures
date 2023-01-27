// SCAN FROMLEFT TO RIGHT
// IF OPENING SYMBOL ADD TO LIST
// IF CLOSING SYMBOL, REMOVE LAST OPENING SYMBOL IN LIST
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
class STACK
{
    int top;

public:
    char a[MAX];
    STACK() { top = -1; }
    bool push(char g);
    char pop();
    char peek();
    bool isEmpty();
} s;
bool STACK ::push(char g)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = g;
        cout << g << " pushed into stack!" << endl;
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
        int x = a[top];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
bool paranthesis(char t[])
{
    int i = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '(' || t[i] == '[' || t[i] == '{')
        {
            s.push(t[i]);
            i++;
        }
        else if (t[i] == ')' || t[i] == '}' || t[i] == ']')
        {
            switch (t[i])
            {
            case ')':
            {
                char c = '(';
                char x = s.pop();
                if (c == x)
                {
                    i++;
                }
                else
                {
                    return false;
                }
                break;
            }
            case '}':
            {
                char c = '{';
                char x = s.pop();
                if (c == x)
                {
                    i++;
                }
                else
                {
                    return false;
                }

                break;
            }
            case ']':
            {
                char c = '[';
                char x = s.pop();
                if (c == x)
                {
                    i++;
                }
                break;
            }
            }
        }
        else
        {
            i++;
        }
    }
    return true;
}
int main()
{
    char str[30];
    cout << "Enter your string:" << endl;
    cin >> str;
    paranthesis(str);
    if (s.isEmpty())
    {
        cout << "\nBalanced!" << endl;
    }
    else
    {
        cout << "Unbalanced!" << endl;
    }
    return 0;
}