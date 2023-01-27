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
};
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
        cout << x << " pushed into stack!" << endl;
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
int main()
{
    class STACK s;
    s.push(100);
    s.push(10);
    s.push(45);
    cout << s.pop() << " Popped from stack!\n";
    cout << "The top element is:\n"
         << s.peek() << endl;
    cout << "\nThe elements in stack are:" << endl;
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}