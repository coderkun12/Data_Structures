#include <iostream>
using namespace std;
#define MAX 32
class STACK
{
    int a[MAX];
    int top;

public:
    STACK()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    bool isEmpty();
    int peek();
} s;
bool STACK::push(int x)
{
    if (top > MAX)
    {
        cout << "\nStack overflow!";
    }
    else
    {
        a[++top] = x;
    }
}
int STACK::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!";
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
    int rem;
    while (n >= 2)
    {
        rem = n % 2;
        s.push(rem);
        n = n / 2;
    }
    s.push(n);
    cout << "The binary conversion of number is:" << endl;
    while (!s.isEmpty())
    {
        cout << s.peek();
        s.pop();
    }
}
int main()
{
    int num;
    cout << "Enter a number:" << endl;
    cin >> num;
    dec2bin(num);
    return 0;
}