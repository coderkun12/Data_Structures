// Perform Fibonacci series using stack
#include <iostream>
#include <bits.h>

using namespace std;
#define MAX 25
int fib[25];
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
} h;
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
int fibo(int lim)
{
    int t1, t2, res;
    h.push(1);
    h.push(1);
    fib[0] = 1;
    fib[1] = 1;
    int i = 0, j = 2;
    while (i < lim)
    {
        res = 0;
        t2 = h.pop();
        t1 = h.pop();
        res = t1 + t2;
        fib[j] = res;
        h.push(t2);
        h.push(res);
        i++;
        j++;
    }
    while (!h.isEmpty())
    {
        h.pop();
    }
}
int main()
{
    int range, c;
    c = 0;
    cout << "Enter number of elemtnts you wish to display from Fibonacci Series:" << endl;
    cin >> range;
    fibo(range);
    while (c < range)
    {
        cout << "\t" << fib[c];
        c++;
    }
    return 0;
}