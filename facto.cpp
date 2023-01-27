#include <iostream>
#include <bits.h>

using namespace std;
#define MAX 1000
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
int factorial(int n)
{
    int prod = 1;
    while (n != 0)
    {
        s.push(n);
        n--;
    }
    while (!s.isEmpty())
    {
        prod *= s.pop();
    }
    return prod;
}
int main()
{
    int num;
    cout << "Enter a number whose factorial is to be found:" << endl;
    cin >> num;
    cout << "The value of factorial is:" << factorial(num);
    return 0;
}