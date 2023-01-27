#include <iostream>
using namespace std;
#define MAX 50
int g[32];
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
} s;
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
        if (x == 5)
        {
            cout << "You are in room 5 now, please seek your passcode!" << endl;
        }
        else if (x < 5 && top < 5)
        {
            cout << "You are in " << x << " room, continue to next to find treasure passcode!" << endl;
        }
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
void dec2bin(int n)
{
    int rem, k;
    k = 0;
    while (n >= 2)
    {
        rem = n % 2;
        s.push(rem);
        n = n / 2;
        k++;
    }
    s.push(n);
    cout << "The binary conversion of passcode is:" << endl;
    int y = 0;
    while (y <= k)
    {
        g[y] = s.peek();
        cout << g[y];
        s.pop();
        y++;
    }
}
int main()
{

    int n, num;
    n = 1;
    while (n <= 5)
    {
        s.push(n);
        if (n == 5)
        {
            cout << "\nEnter passcode:" << endl;
            cin >> num;
            dec2bin(num);
        }
        n++;
    }
    cout << "\n\nReturning to room 1 now!" << endl;
    while (!s.isEmpty())
    {
        int g = s.peek();
        if (g == 1)
        {
            cout << "Now in room 1, entering the passcode in treasure safe!" << endl;
            cout << "*******************************************************************" << endl;
            cout << "Safe is now open! You have recieved 1 Million in treasure!" << endl;
        }
        else
        {
            cout << "Returned to room" << g << endl;
        }
        s.pop();
    }
    return 0;
}